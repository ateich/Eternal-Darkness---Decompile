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
extern s32 fn_80201910(s32);
extern void* memcpy(void*, const void*, unsigned long);

s32 fn_80028D54(void* output)
{
    DescriptorSet local = lbl_80300368;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (local.descriptors[i].type == 3 &&
            local.descriptors[i].resource != 0) {
            local.descriptors[i].resource =
                fn_80201910(local.descriptors[i].resource);
        }
    }
    memcpy(output, &local, sizeof(DescriptorSet));
    return 0x60;
}
