typedef unsigned char u8;

extern void fn_8018E230(void*, u8*, int, u8, void*, int);
extern void fn_8019B8B4(void);

void fn_80190508(u8* object, void* value)
{
    u8* state = *(u8**)(object + 0x4C);

    fn_8018E230(state, state + 0x2B, 1, state[0x2B], value, 0);
    *(void (**)(void))(object + 0x14C) = fn_8019B8B4;
}
