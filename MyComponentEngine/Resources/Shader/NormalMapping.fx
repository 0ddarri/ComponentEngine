float4x4 gWorldViewProjectionMatrix;
float4x4 gWorldMatrix;
float4 worldPos;

float4 gWorldCameraPosition;
//float4 gWorldLightPosition;

struct Light // 빛 구조체
{
    float3 WorldLightPos; // 위치
    float4 LightColor; // 색상
    float specularPower; // 힘
    // 이 변수 3개가 전부 초기화가 되었다고?
    //음.. 초기화라기보단 저기서 값을 주는거죵
    // 뭐야 이게 됨?
    // 몰라요ㅋㅋ 예제코드에서 잘쓰던뎅
    // ㄷ 한번도 본적이없어서
    // 예제코드 함 보여줘바
};

Light lights[2]; // 빛 배열 -> 얘를 쓰면 팅겨요

struct VS_INPUT
{
    float4 mPosition : POSITION;
    float2 mUV : TEXCOORD0;
    float3 mNormal : NORMAL;
    float3 mTangent : TANGENT;
    float3 mBinormal : BINORMAL;
};

struct VS_OUTPUT
{
    float4 mPosition : POSITION;
    float2 mUV : TEXCOORD0; // UV Mapping
    float3 mViewDir : TEXCOORD1;
    //float3 mLightDir[2] : TEXCOORD2;
    float3 T : TEXCOORD3;
    float3 B : TEXCOORD4;
    float3 N : TEXCOORD5;
};

VS_OUTPUT vs_main(VS_INPUT Input)
{
    VS_OUTPUT Output;

    Output.mPosition = mul(Input.mPosition, gWorldViewProjectionMatrix);
    Output.mUV = Input.mUV;

    float4 worldPosition = mul(Input.mPosition, gWorldMatrix);

    float3 viewDir = worldPosition.xyz - gWorldCameraPosition.xyz;
    Output.mViewDir = normalize(viewDir);

    // for(int i = 0; i < 2; i++)
    // {
    //     float3 lightDir = worldPosition.xyz - lights[i].WorldLightPos.xyz;
    //     Output.mLightDir[i] = normalize(lightDir);
    // }

    float3 worldNormal = mul(Input.mNormal, (float3x3)gWorldMatrix);
    Output.N = normalize(worldNormal);

    float3 worldTangent = mul(Input.mTangent, (float3x3)gWorldMatrix);
    Output.T = normalize(worldTangent);

    float3 worldBinormal = mul(Input.mBinormal, (float3x3)gWorldMatrix);
    Output.B = normalize(worldBinormal);

    return Output;
}

struct PS_INPUT
{
    float4 mPosition : POSITION;
    float2 mUV : TEXCOORD0;
    float3 mViewDir : TEXCOORD1;
    //float3 mLightDir[2] : TEXCOORD2;
    float3 T : TEXCOORD3;
    float3 B : TEXCOORD4;
    float3 N : TEXCOORD5;
};

texture DiffuseMap;
sampler2D DiffuseSampler
{
    Texture = DiffuseMap;
    MINFILTER = LINEAR;
    MAGFILTER = LINEAR;
};

texture SpecularMap;
sampler2D SpecularSampler
{
    Texture = SpecularMap;
    MINFILTER = LINEAR;
    MAGFILTER = LINEAR;
};

texture NormalMap;
sampler2D NormalSampler
{
    Texture = NormalMap;
    MINFILTER = LINEAR;
    MAGFILTER = LINEAR;
};

//float4 gLightColor;
//float gSpecularPower;

float4 ps_main(PS_INPUT Input) : COLOR
{
    float3 resultColor = float3(0,0,0);

    float3 tangentNormal = tex2D(NormalSampler, Input.mUV).xyz;
    tangentNormal = normalize(tangentNormal * 2 - 1);

    float3x3 TBN = float3x3(normalize(Input.T), normalize(Input.B), normalize(Input.N));
    TBN = transpose(TBN);
    float3 worldNormal = mul(TBN, tangentNormal);

    float4 albedo = tex2D(DiffuseSampler, Input.mUV);
    float4 specularIntensity = tex2D(SpecularSampler, Input.mUV);

    float3 resultDiffuse = 0;
    float3 resultSpecular = 0;

    for(int i = 0; i < 2; i++)
    {
        float3 worldLightDir = float3(0,1,0);
        worldLightDir = worldPos.xyz - lights[i].WorldLightPos;
        worldLightDir = normalize(worldLightDir);

        float3 lightDir = normalize(worldLightDir);
        float3 diffuse = saturate(dot(worldNormal, -lightDir));

        diffuse = lights[i].LightColor.rgb * diffuse; // 근데 얘느 왜 안터졌지
        resultDiffuse += diffuse;

        float3 specular = 0;
        if(diffuse.x > 0)
        {
            float3 reflection = reflect(lightDir, worldNormal);
            float3 viewDir = normalize(Input.mViewDir);

            specular = saturate(dot(reflection, -viewDir));
            specular = pow(specular, lights[i].specularPower);

            specular *= lights[i].LightColor.rgb; // 지금이거가 
            resultSpecular += specular;
        }
    }

    resultDiffuse *= albedo.rgb;
    resultSpecular *= specularIntensity.rgb;
    float3 ambient = float3(0.1f,0.1f,0.1f) * resultDiffuse;

    resultColor = resultDiffuse + resultSpecular + ambient;

    // albedo, specularIntensity, ambient;

    return float4(resultColor, 1);
}

technique normalMap
{
    pass pass_0
    {
        VertexShader = compile vs_3_0 vs_main();
        PixelShader = compile ps_3_0 ps_main();
    }
}