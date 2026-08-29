typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int u32;

extern const double lbl_80650B58;
extern const float lbl_80650B70;

void fn_80186F70(s16* output, int count, float step, float base, int range);
void fn_80193E1C(s16* output, int count, float step, int base, int range);

void fn_80194AC4(const s16* base, const float* scale, u8* state)
{
    s16* outputs[3];
    u32 flags;
    int width;
    int type;

    outputs[0] = (s16*)(state + 0x28);
    outputs[1] = (s16*)(state + 0x42);
    outputs[2] = (s16*)(state + 0x5C);
    flags = *(u32*)(state + 0x7C);
    width = (u8)(state[0xB] - 4);
    type = state[3];

    if (flags & 0x100) {
        int half = (u8)width >> 1;
        int rest = width - half;
        float step;
        int endpoint;

        fn_80186F70(outputs[0], width, scale[0], (float)base[0], type);
        fn_80186F70(outputs[1], width, scale[1], (float)base[1], type);

        step = lbl_80650B70 * scale[2];
        fn_80193E1C(outputs[2], half, step, base[2], type);
        endpoint = (int)((float)half * step + (float)base[2]);
        fn_80193E1C(outputs[2] + half, rest, scale[2] / (float)rest,
                    endpoint, type);
    } else if (flags & 0x400) {
        int half = (u8)width >> 1;
        int rest = width - half;
        int i;

        for (i = 0; i < 3; i++) {
            float step = lbl_80650B70 * scale[i];
            int endpoint;
            fn_80193E1C(outputs[i], half, step, base[i], type);
            endpoint = (int)((float)half * step + (float)base[i]);
            fn_80193E1C(outputs[i] + half, rest, scale[i] / (float)rest,
                        endpoint, type);
        }
    } else {
        int i;
        for (i = 0; i < 3; i++) {
            fn_80186F70(outputs[i], width, scale[i], (float)base[i], type);
        }
    }
}
