typedef signed char s8;

extern int lbl_8064C990;
extern void *fn_80201814();
extern void*fn_80201B8C();

int fn_800AD4E8(void)
{
    int result;
    void* runtime = fn_80201814(lbl_8064C990);
    result = 0;
    if (runtime != 0) {
        char* state_object = *(char**)((char*)fn_80201B8C(runtime) + 0x5C);
        result = (s8)state_object[0xA4] == 1;
    }
    return result;
}
