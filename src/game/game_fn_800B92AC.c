typedef struct Color {
    unsigned int value;
} Color;

extern void *lbl_8064C9F8;
extern int lbl_8064CDC8;
extern void *lbl_8064C51C;
extern Color lbl_8064C2B0;
extern Color lbl_8064F0C0;
extern void *fn_801E6CA0(void *, unsigned short, unsigned short, unsigned int, int);
extern Color *fn_801E5D08(void *);

void fn_800B92AC(void)
{
    if (lbl_8064C9F8 == 0) {
        if (lbl_8064CDC8 == 3) {
            lbl_8064C9F8 = fn_801E6CA0(lbl_8064C51C, 0, 8, 8, 1);
            *fn_801E5D08(lbl_8064C9F8) = lbl_8064C2B0;
        } else {
            lbl_8064C9F8 = fn_801E6CA0(lbl_8064C51C, 0, 8, 0x2008, 1);
            {
                Color color = lbl_8064F0C0;
                *fn_801E5D08(lbl_8064C9F8) = color;
            }
        }
    }
}
