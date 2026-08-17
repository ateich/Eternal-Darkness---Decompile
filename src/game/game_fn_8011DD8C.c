typedef struct Entry8011DD8C {
    int field_0;
    int field_4;
    int field_8;
    void* field_C;
    int field_10;
    int field_14;
    int field_18;
} Entry8011DD8C;

extern Entry8011DD8C lbl_80332428[];
extern void (*lbl_8064CEA0)(void*, int);
extern void* memset(void*, int, unsigned long);

void fn_8011DD8C(int index, int release)
{
    if (release != 0) {
        lbl_8064CEA0(lbl_80332428[index].field_C, index);
    }
    memset(&lbl_80332428[index], 0, sizeof(Entry8011DD8C));
    lbl_80332428[index].field_8 = -1;
    lbl_80332428[index].field_14 = -1;
    lbl_80332428[index].field_4 = -1;
}
