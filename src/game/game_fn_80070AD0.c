typedef struct GlobalState {
    char pad_00[8];
    int level;
} GlobalState;

extern int lbl_8024A2B8[44];
extern GlobalState lbl_803003C8;
extern void *lbl_8064C4E0;
extern void fn_801E7974(void *, int);

int fn_80070AD0(void)
{
    int i;
    int result = -1;

    for (i = 0; i < 44; i++) {
        if (lbl_8024A2B8[i] != 0) {
            result = i;
            if (i == 36) {
                fn_801E7974(lbl_8064C4E0, 0x3AA);
                result = -1;
            }
            if (lbl_803003C8.level == 5 && result == 34) {
                fn_801E7974(lbl_8064C4E0, 0x466);
                result = -1;
            }
            break;
        }
    }
    return result;
}
