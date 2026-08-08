typedef int s32;
typedef unsigned char u8;

typedef struct Descriptor {
    s32 type;
    u8 unknown_04[0x18];
    s32 resource;
} Descriptor;

typedef struct DescriptorSet {
    Descriptor descriptors[2];
    u8 unknown_40[4];
} DescriptorSet;

extern DescriptorSet lbl_80300368;
extern s32 lbl_8064D18C;
extern s32 fn_802019EC(s32, s32);
extern void* memcpy(void*, const void*, unsigned long);

s32 fn_80028E0C(const void* input)
{
    s32 i;

    memcpy(&lbl_80300368, input, sizeof(DescriptorSet));
    for (i = 0; i < 2; i++) {
        if (lbl_80300368.descriptors[i].type == 3) {
            lbl_80300368.descriptors[i].resource =
                fn_802019EC(lbl_80300368.descriptors[i].resource,
                            lbl_8064D18C);
        }
    }
    return 0x60;
}
