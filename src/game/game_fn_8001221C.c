typedef int s32;

extern s32 lbl_8064D18C;
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_800073D8(s32);

s32 fn_8001221C(void* script)
{
    s32 value;
    void* parser;

    parser = script;
    if (fn_8016A598(parser) != 0) {
        value = (s32)fn_8016A694(parser, 1);
    } else {
        value = lbl_8064D18C;
    }
    fn_800073D8(value);
    return 0;
}
