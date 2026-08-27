typedef unsigned char u8;

extern u8 fn_8018E26C(void*, void*);
extern void fn_80187E40(void);

int fn_80187DF4(u8* self)
{
    u8* entry = *(u8**)(self + 0x4C);
    if (fn_8018E26C(entry, entry + 0x2B) == 0) {
        *(void (**)(void))(self + 0x14C) = fn_80187E40;
    }
    return 0;
}
