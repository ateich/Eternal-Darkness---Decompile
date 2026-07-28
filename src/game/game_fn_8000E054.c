typedef int s32;

extern s32 fn_800CAB80(void);
extern s32 fn_8016A598(void*);
extern void fn_8016A830(void*, double);

s32 fn_8000E054(void* script)
{
    s32 value;

    fn_8016A598(script);
    value = fn_800CAB80();
    fn_8016A830(script, (double)value);
    return 1;
}
