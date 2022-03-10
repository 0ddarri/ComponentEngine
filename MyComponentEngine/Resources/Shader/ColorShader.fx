float4x4 gWorldViewProjectionMatrix;

struct VS_INPUT
{
    float4 mPosition : POSITION;
};

struct VS_OUTPUT
{
    float4 mPosition : POSITION;
};

VS_OUTPUT vs_main(VS_INPUT Input)
{
    VS_OUTPUT Output;
    Output.mPosition = mul(Input.mPosition, gWorldViewProjectionMatrix);

    return Output;
}

float4 gSurfaceColor;

float4 ps_main() : COLOR
{
    return gSurfaceColor;
}

technique colorShader
{
    pass pass_0
    {
        VertexShader = compile vs_3_0 vs_main();
        PixelShader = compile ps_3_0 ps_main();
    }
}