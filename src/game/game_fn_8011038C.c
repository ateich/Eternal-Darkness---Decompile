typedef struct SelectionEntry {
    int field_0;
    int value;
    int field_8;
    int field_C;
    int field_10;
} SelectionEntry;

extern unsigned int lbl_80331738[];
extern unsigned int lbl_8024E388[];
extern SelectionEntry lbl_8024C0CC[];
extern int lbl_8064CD20;
extern int lbl_8064CD1C;
extern int lbl_8064CD84;

extern int fn_80201B44();
extern void* fn_80201814();
extern unsigned int fn_8020216C(void);
extern int fn_801E8D34(unsigned int);
extern int fn_801E8D44(unsigned int);
extern int fn_801E7B24(unsigned int*, int, int);
extern void fn_8010F9D8(short, int);

void fn_8011038C(void* event, int kind)
{
    int current;
    int previous;
    int upper;
    int allow = 1;

    if (kind != 1) {
        return;
    }
    if (lbl_8064CD20 != 2) {
        lbl_8064CD1C = -1;
        return;
    }
    fn_80201B44();
    fn_80201814();
    current = fn_801E8D34(lbl_80331738[2]);
    if (!(fn_8020216C() & 0x80000)) {
        current = fn_801E7B24(lbl_8024E388, 3, current);
    }
    if (current == -1) {
        return;
    }
    fn_80201B44();
    fn_80201814();
    previous = fn_801E8D34(lbl_80331738[2]) - 1;
    if (!(fn_8020216C() & 0x80000)) {
        previous = fn_801E7B24(lbl_8024E388, 3, previous);
    }
    upper = fn_801E7B24(lbl_8024E388, 3, fn_801E8D44(lbl_80331738[2]));
    if (current < upper) {
        allow = 0;
    }
    if (lbl_8064CD1C != -1 &&
        ((!allow || lbl_8064CD1C <= lbl_8024C0CC[current].value)) &&
        (lbl_8024C0CC[current].value == lbl_8024C0CC[previous].value ||
         lbl_8064CD1C == lbl_8024C0CC[current].value)) {
        fn_8010F9D8((short)((lbl_8064CD1C - lbl_8024C0CC[current].value) * 2), 0);
    } else if (lbl_8064CD84 == 0) {
        lbl_8064CD1C = -1;
    }
}
