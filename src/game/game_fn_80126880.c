typedef unsigned char u8;
typedef unsigned int u32;

extern u32 lbl_8064CF20;
extern u32 lbl_8064CF24;
extern void fn_8011EB24(void*);
extern void fn_80126718(void);

void fn_80126880(void* object)
{
    u8* self = object;
    u32 zero;
    u32* entry;

    if (*(u32**)(self + 0x2A0) != 0) {
        fn_8011EB24(self);
        zero = 0;
        *(u32*)(self + 0x160) = zero;
        *(u32*)(self + 0x154) = zero;
        *(u32*)(self + 0x158) = zero;
        *(u32*)(self + 0x29C) = zero;
        *(u32*)(self + 0x2A8) = zero;
        *(u32*)(self + 0x40) = zero;
        if (*(u32*)(self + 0x254) & 0x10000000) {
            entry = *(u32**)(self + 0x2A0);
            entry[0] = zero;
            entry[2] = zero;
            *(u32*)(self + 0x254) &= 0xEFFFFFFF;
            lbl_8064CF20--;
        } else {
            entry = *(u32**)(self + 0x2A0);
            entry[0] = zero;
            entry[2] = zero;
            lbl_8064CF24--;
        }
        *(u32**)(self + 0x2A0) = 0;
    }
    fn_80126718();
}
