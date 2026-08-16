extern void* lbl_80331720[6];
extern int lbl_8064CCC4;
extern int fn_801E8D34(void*);
extern void fn_801E8B24(void*, int, int);

int fn_8010B45C(int offset)
{
    void** objects = lbl_80331720;
    if (2 * offset + fn_801E8D34(objects[3]) >= lbl_8064CCC4) {
        fn_801E8B24(objects[3], 0, 0);
    }
    return 1;
}
