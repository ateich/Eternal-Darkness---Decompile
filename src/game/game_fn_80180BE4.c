typedef unsigned char u8;
typedef unsigned int u32;

extern u32 lbl_8064D21C;
extern u8* lbl_8064D220;
extern void fn_8017FD8C(void*);

void fn_80180BE4(void)
{
    u32 count = lbl_8064D21C;
    u32 i = 0;
    u8* object = lbl_8064D220;

    while (i < count) {
        if (object[5] == 1) {
            fn_8017FD8C(object);
        }
        object += 0x150;
        i++;
    }
}
