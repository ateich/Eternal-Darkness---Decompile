typedef unsigned char u8;
typedef unsigned int u32;

extern void* lbl_8064C6E0;

extern u32 fn_80052218(void*);
extern void fn_801A94E4(void*, void*, u8, u32);

u32 fn_8002487C(void* object, void* value)
{
    u8 kind = fn_80052218(object);
    fn_801A94E4(lbl_8064C6E0, value, kind, 0);
    return 0;
}
