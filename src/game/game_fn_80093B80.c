typedef unsigned char u8;

typedef struct Runtime80093B80 {
    u8 pad00[0x8C];
    void* state;
} Runtime80093B80;

extern int fn_800359A0(void*, int);
extern Runtime80093B80*fn_80201B8C();
extern void fn_800BDEE4(void*, void*);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

int fn_80093B80(register void* object, void* unused1, void* unused2,
                int flags1, int flags2)
{
    register int result = 0;

    if ((flags1 & flags2) == 0 && fn_800359A0(object, 0) != 0) {
        fn_800BDEE4(object, fn_80201B8C(object)->state);
        fn_80201D2C(object, 3);
        fn_80201D14(object, 1);
        result = 1;
    }
    return result;
}
