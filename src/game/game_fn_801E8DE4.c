typedef unsigned long long u64;

extern u64 lbl_8064D5C8;
extern u64 lbl_8064D5D0;

extern u64 OSGetTime(void);

void fn_801E8DE4(u64 value)
{
    lbl_8064D5D0 = OSGetTime();
    lbl_8064D5C8 = value;
}
