extern unsigned int lbl_80331748[];
extern unsigned int lbl_8064CD48;
extern unsigned int lbl_8064CD4C;

extern int fn_80201B44(void);
extern void* fn_80201814(void);
extern unsigned int fn_8020216C(void);
extern int fn_80113E48(unsigned int);
extern int fn_80113BC0(unsigned int);

void fn_80113F54(unsigned int value)
{
    unsigned int packed;
    int index;

    fn_80201B44();
    fn_80201814();
    if ((fn_8020216C() & 0x4000) != 0) {
        lbl_8064CD4C = 0x3FFF3FFF;
        lbl_8064CD48 = 0x70000;
    } else {
        lbl_8064CD4C = lbl_80331748[0];
        lbl_8064CD48 = lbl_80331748[1];
    }

    packed = value & 0xF1FFFFFF;
    index = fn_80113E48(packed);
    if (index != -1) {
        if ((value & 0x08000000) != 0) {
            lbl_80331748[index + 2] |= packed | 0x08000000;
        }
        if ((value & 0x04000000) != 0 && fn_80113BC0(value) != 0) {
            lbl_80331748[index + 2] |= packed | 0x04000000;
        }
    }
}
