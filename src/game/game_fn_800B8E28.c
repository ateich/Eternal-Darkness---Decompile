typedef signed short s16;
typedef struct Color {
    unsigned int value;
} Color;

extern void *lbl_8064CA08;
extern void *lbl_80320B48[3];
extern Color lbl_8064C2AC;
extern Color lbl_8064C2B0;
extern Color lbl_8064F0B4;
extern int lbl_8064CDC8;
extern int fn_800B8F38(void);
extern void fn_801E8B6C(void *, s16);
extern int fn_801E8D44(void *);
extern Color *fn_801E5D08(void *);

void fn_800B8E28(s16 amount)
{
    int old_selection;
    int new_selection;
    int i;

    if (lbl_8064CA08 != 0) {
        old_selection = fn_800B8F38();
        fn_801E8B6C(lbl_8064CA08, amount / (amount < 0 ? -amount : amount));
        new_selection = fn_800B8F38();
        if (new_selection != old_selection) {
            for (i = 0; i < fn_801E8D44(lbl_8064CA08) + 1; i++) {
                if (lbl_80320B48[i] != 0) {
                    if (i == old_selection) {
                        *fn_801E5D08(lbl_80320B48[i]) = lbl_8064C2AC;
                    } else if (i == new_selection) {
                        if (lbl_8064CDC8 == 3) {
                            *fn_801E5D08(lbl_80320B48[i]) = lbl_8064C2B0;
                        } else {
                            Color color = lbl_8064F0B4;
                            *fn_801E5D08(lbl_80320B48[i]) = color;
                        }
                    }
                }
            }
        }
    }
}
