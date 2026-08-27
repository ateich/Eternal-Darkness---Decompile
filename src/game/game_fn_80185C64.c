typedef signed short s16;
typedef unsigned char u8;

extern void* fn_80185AE8(s16*, void*, u8*);
extern void fn_8017FE14(void*, void (*)(void));
extern void fn_801861C4(void);

void* fn_80185C64(s16* position, void* second, u8* data)
{
    void* result = fn_80185AE8(position, second, data);

    if (result != 0)
        fn_8017FE14(result, fn_801861C4);
    return result;
}
