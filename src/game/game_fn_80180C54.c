typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned char* lbl_8064D220;
extern u32 fn_8017FFA8(void);
extern void* memset(void*, int, unsigned long);

void fn_80180C54(u32 count)
{
    u32 size = fn_8017FFA8();
    memset(lbl_8064D220, 0, (u16)count * size);
}
