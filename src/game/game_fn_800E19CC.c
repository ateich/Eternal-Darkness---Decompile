extern void *lbl_8064C4E0;
extern const float lbl_8064F61C;
extern const float lbl_8064F620;
extern const float lbl_8064F624;
extern int fn_80201B54();
extern void *fn_80201B8C();
extern void fn_801E7974(void *, int);
extern void fn_801593FC(int);
extern void fn_800E1BF4(void *);
extern void fn_800E193C(void *);
extern void fn_8020104C(int, void *, void *, int, float);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

void fn_800E19CC(void *object)
{
    void **resource;
    void *id;

    ((void *)fn_80201B54());
    id = ((void *)fn_80201B54(object));
    resource = *(void ***)((unsigned char *)fn_80201B8C(object) + 0x78);
    fn_801E7974(lbl_8064C4E0, 0x468);
    fn_801593FC(0x7D);
    fn_800E1BF4(object);
    fn_800E193C(object);
    fn_8020104C(0x10, id, *resource, 0x0E, lbl_8064F61C);
    fn_8020104C(0x97, id, id, 0, lbl_8064F620);
    fn_8020104C(0x39, id, id, 0, lbl_8064F624);
    fn_80201D2C(object, 11);
    fn_80201D14(object, 1);
}
