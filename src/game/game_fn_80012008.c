typedef int s32;
typedef unsigned short u16;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814();
extern s32 fn_800360B0(void*, u16*);
extern void fn_80036060(void*, u16);

s32 fn_80012008(void* script)
{
    s32 handle;
    void* entry;
    s32 mode;
    s32 bits;
    s32 new_flags;
    void* parser;
    u16 flags;

    parser = script;
    if (fn_8016A598(parser) != 3) {
        fn_80163BB4(parser, lbl_8023BEF8, 3, fn_8016A598(parser));
        return 0;
    }

    handle = (s32)fn_8016A694(parser, 1);
    mode = (s32)fn_8016A694(parser, 2);
    bits = (s32)fn_8016A694(parser, 3);
    entry = fn_80201814(handle);
    if (entry != 0) {
        flags = 0;
        if (fn_800360B0(entry, &flags) != 0) {
            if (mode == 0) {
                new_flags = flags | (u16)bits;
            } else {
                new_flags = flags & ~(u16)bits;
            }
            flags = new_flags;
            fn_80036060(entry, flags);
        }
    }
    return 0;
}
