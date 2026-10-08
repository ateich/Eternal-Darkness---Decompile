typedef unsigned int u32;
typedef signed int s32;

extern unsigned char lbl_80332540[];
extern void* lbl_804ECE80[];
extern u32 lbl_804ECF80[];
extern float lbl_804ED080[];
extern u32 lbl_8064CEBC[2];
extern unsigned char* lbl_8064CEC4;
extern s32 lbl_8064CED0;
extern s32 lbl_8064D738;

void* fn_80120744(void* value, s32 size, float scale)
{
    unsigned char* result;
    u32 aligned;

    aligned = (size + 31) & ~31;
    result = lbl_8064CEC4;
    lbl_8064CEC4 += aligned * 6;
    lbl_8064CEBC[lbl_8064D738] += aligned;

    lbl_804ECE80[lbl_8064CED0] = value;
    lbl_804ECF80[lbl_8064CED0] = aligned;
    lbl_804ED080[lbl_8064CED0] = scale;
    lbl_8064CED0 += 1;

    if (lbl_8064CEC4 > lbl_80332540 + lbl_8064D738 * 0x3A980 + 0x3A980) {
        result = 0;
    }
    return result;
}
