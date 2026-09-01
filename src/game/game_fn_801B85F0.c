typedef unsigned char u8;
typedef unsigned int u32;

extern u8* lbl_8064D3D0;

extern void fn_801CD424(u8);
extern void fn_801C3460(void);
extern void fn_801C0594(void*);
extern void fn_801C2148(u8);
extern int fn_801C3278(u8);

int fn_801B85F0(int command, u32 handle)
{
    u32 offset;
    int result = 0;

    switch (command) {
    case 0:
        offset = (u8)handle * 0x404;
        if (lbl_8064D3D0[offset + 0x11C] == 0) {
            fn_801CD424(handle);
            fn_801C3460();
            if (handle == *(u32*)(lbl_8064D3D0 + offset + 0xF4)) {
                fn_801C0594(lbl_8064D3D0 + offset);
            }
        }
        break;
    case 1:
        fn_801C2148(handle);
        break;
    case 2:
        result = fn_801C3278(handle);
        break;
    case 3:
        fn_801CD424(handle);
        fn_801C3460();
        break;
    }
    return result;
}
