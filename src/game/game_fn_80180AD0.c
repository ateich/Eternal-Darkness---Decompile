typedef unsigned char u8;
typedef unsigned int u32;

extern u32 lbl_8064D21C;
extern u8* lbl_8064D220;
extern void fn_80226D28(int);
extern int fn_801800F8(void*);
extern void fn_8018812C(void*);
extern void fn_801EA9F8(void);

void fn_80180AD0(void)
{
    u32 count = lbl_8064D21C;
    u32 i = 0;
    u8* object = lbl_8064D220;

    fn_80226D28(0);
    while (i < count) {
        if (fn_801800F8(object) && object[5] == 1) {
            fn_8018812C(object);
            fn_801EA9F8();
        }
        object += 0x150;
        i++;
    }
    fn_80226D28(1);
}
