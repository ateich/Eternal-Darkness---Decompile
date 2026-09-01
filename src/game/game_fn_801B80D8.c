typedef unsigned char u8;
typedef unsigned int u32;

extern u8 lbl_8064D3A0;
extern u8* lbl_8064D3D0;

extern u32 fn_801C14D0(void);
extern void fn_801C0644(void*);

u32 fn_801B80D8(void* object)
{
    u8 index;
    u32 found = 0;

    if (lbl_8064D3A0 != 0) {
        u32 handle = fn_801C14D0();

        while (handle != -1) {
            index = handle;

            if (handle == *(u32*)(lbl_8064D3D0 + index * 0x404 + 0xF4)) {
                fn_801C0644(lbl_8064D3D0 + index * 0x404);
                found = 1;
            }
            handle = *(u32*)(lbl_8064D3D0 + index * 0x404 + 0xEC);
        }
    }
    return found;
}
