typedef unsigned char u8;

extern void *lbl_803251E4[3];
extern u8 lbl_80325120[0xC4];

extern void *fn_801A717C(void);
extern void fn_801A743C(void *, int);
extern void *memset(void *, int, unsigned long);

void fn_800C3D24(void)
{
    int i;

    for (i = 0; i < 3; i++) {
        lbl_803251E4[i] = fn_801A717C();
        fn_801A743C(lbl_803251E4[i], 1);
    }
    memset(lbl_80325120, 0, sizeof(lbl_80325120));
}
