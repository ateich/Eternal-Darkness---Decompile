typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_80181A00(void*, void*, void*, void*);
extern void fn_80181BD8(void*, void*);
extern void fn_80181E30(void);
extern void fn_8018DE9C(void);

void fn_8018199C(u8* object, void* arg1, void* arg2, u8* arg3)
{
    fn_80181A00(object, arg1, arg2, arg3);
    fn_80181BD8(object, arg3 + 0x14);
    *(void (**)(void))(object + 0x14C) = fn_80181E30;
    *(void (**)(void))(object + 0x148) = fn_8018DE9C;
    *(u16*)(object + 0x22) = 4;
}
