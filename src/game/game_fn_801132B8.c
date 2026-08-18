typedef struct RandomLimits {
    unsigned char pad[0x10];
    int horizontal;
    int vertical;
} RandomLimits;

extern RandomLimits lbl_80331A08;
extern unsigned int lbl_80331748[];

extern int fn_801E8D34(int);
extern int fn_80201B44();
extern void *fn_80201814();
extern unsigned int fn_8020216C(void);

int fn_801132B8(int mode)
{
    int index = fn_801E8D34(lbl_80331A08.vertical) * 3 +
                fn_801E8D34(lbl_80331A08.horizontal);
    switch (mode) {
    case 0:
    case 1:
        if ((lbl_80331748[index + 2] & 0x04000000) != 0 ||
            (fn_80201B44(), fn_80201814(), (fn_8020216C() & 0x4000) != 0)) {
            return 1;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}
