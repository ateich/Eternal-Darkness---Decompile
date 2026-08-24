extern int fn_8016A598(void*);
extern int fn_8016A650(void*, int);
extern void* fn_8016A5F4(void*, int);
extern void* fn_8016A628(void*, void*);
extern int fn_800FD228(void*, const char*);
extern const char lbl_8024FFF8[];

int fn_8016E7B8(void* state)
{
    int count = fn_8016A598(state);
    int i;

    for (i = 1; i <= count; i++) {
        if (fn_8016A650(state, i) == 0) {
            fn_800FD228(fn_8016A628(state, fn_8016A5F4(state, i)), lbl_8024FFF8);
        }
    }
    return 0;
}
