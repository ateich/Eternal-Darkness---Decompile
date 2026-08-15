extern void *lbl_8064C51C;
extern void *lbl_8064CA10[2];
typedef struct Color {
    unsigned int value;
} Color;
extern Color lbl_80651A50;
extern void *fn_801E6CA0(void *, int, int, int, int);
extern Color *fn_801E5D08(void *);

void fn_800B7C80(int initialize)
{
    int i;

    lbl_8064CA10[0] = fn_801E6CA0(lbl_8064C51C, 0, 9, 8, 1);
    lbl_8064CA10[1] = fn_801E6CA0(lbl_8064C51C, 0, 10, 8, 1);
    if (initialize != 0) {
        for (i = 0; i < 2; i++) {
            Color value = lbl_80651A50;
            *fn_801E5D08(lbl_8064CA10[i]) = value;
        }
    }
}
