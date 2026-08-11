typedef unsigned char u8;
typedef signed int s32;

extern void* fn_801A7778(void);
extern void* fn_8020499C(void);
extern void* fn_80201B8C();

s32 fn_80049694(void)
{
    s32 result = 0;

    if (fn_801A7778() != 0 && fn_8020499C() != 0) {
        result = ((u8*)fn_80201B8C())[0x9F] == 0x12;
    }
    return result;
}
