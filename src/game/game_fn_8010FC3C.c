typedef struct SelectionEntry {
    int field_0;
    int value;
    int field_8;
    int field_C;
    int field_10;
} SelectionEntry;

extern unsigned int lbl_80331738[];
extern SelectionEntry lbl_8024C0CC[];
extern unsigned int lbl_8024E388[];
extern int lbl_8064CD20;
extern int lbl_8064CD1C;

extern void fn_80144C40(void);
extern int fn_80201B44(void);
extern void* fn_80201814(void);
extern unsigned int fn_8020216C(void);
extern int fn_801E8D34(unsigned int);
extern int fn_801E7B24(unsigned int*, int, int);

static int current_selection(void)
{
    int value = fn_801E8D34(lbl_80331738[2]);
    if (fn_8020216C() & 0x80000) {
        return value;
    }
    return fn_801E7B24(lbl_8024E388, 3, value);
}

void fn_8010FC3C(short amount)
{
    int index;
    int selected;
    int next;

    if (lbl_8064CD20 != 2) {
        return;
    }
    fn_80144C40();
    fn_80201B44();
    fn_80201814();
    index = current_selection();
    if (index == -1) {
        return;
    }
    selected = index;

    if (amount > 0) {
        lbl_8064CD1C = lbl_8024C0CC[index].value;
        fn_80201B44();
        fn_80201814();
        if (fn_8020216C() & 0x80000) {
            lbl_8064CD1C++;
        } else {
            next = fn_801E8D34(lbl_80331738[2]) + 1;
            while ((index = fn_801E7B24(lbl_8024E388, 3, next)) >= 0) {
                if (lbl_8024C0CC[index].value > lbl_8064CD1C) {
                    lbl_8064CD1C = lbl_8024C0CC[index].value;
                    break;
                }
                next++;
            }
            if (index < 0) {
                lbl_8064CD1C = lbl_8024C0CC[53].value + 1;
            }
        }
        if (lbl_8064CD1C == lbl_8024C0CC[selected].value) {
            lbl_8064CD1C = -1;
        } else if (lbl_8064CD1C < 0) {
            lbl_8064CD1C = 0;
        } else if (lbl_8064CD1C > lbl_8024C0CC[53].value + 1) {
            lbl_8064CD1C = lbl_8024C0CC[53].value + 1;
        }
    } else {
        fn_80201B44();
        fn_80201814();
        next = fn_801E8D34(lbl_80331738[2]) - 1;
        if (!(fn_8020216C() & 0x80000)) {
            next = fn_801E7B24(lbl_8024E388, 3, next);
        }
        if (next == -1) {
            lbl_8064CD1C = lbl_8024C0CC[selected].value;
        } else {
            lbl_8064CD1C = lbl_8024C0CC[next].value;
            if (lbl_8064CD1C < 0) {
                lbl_8064CD1C = 0;
            } else if (lbl_8064CD1C > lbl_8024C0CC[53].value) {
                lbl_8064CD1C = lbl_8024C0CC[53].value;
            }
        }
    }
}
