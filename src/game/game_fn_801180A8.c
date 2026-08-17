extern int lbl_8064D18C;
extern int lbl_8064D738;
extern unsigned char lbl_80332158[];
extern unsigned char lbl_805B6FE0[];

extern unsigned char *fn_8015C28C(int);
extern unsigned short fn_801F668C(void *);
extern unsigned short fn_8012BA84(void *);
extern unsigned short fn_801E8FAC(void *);
extern unsigned short fn_801FABA4(void *, int);
extern void fn_801A7F94(void *);
extern void fn_800AFBA8(void *);
extern void *fn_8015AB00(void *);
extern void *memcpy(void *, const void *, unsigned int);
extern void fn_801EF3EC(void *, void *);
extern int fn_801ECC44(void);

void fn_801180A8(void)
{
    unsigned char *context = fn_8015C28C(2);
    unsigned char *base;
    unsigned int offset;
    unsigned int length;
    int index;
    void *snapshot;

    *(int *)(lbl_80332158 + 0x0) = lbl_8064D18C;
    if (context == 0) {
        return;
    }
    if ((signed char)context[0x8143] == 0) {
        return;
    }
    if ((signed char)context[0x8142] == 0) {
        return;
    }

    index = lbl_8064D738;
    *(int *)(lbl_80332158 + 0x4) = index;
    context += index * 4;
    base = *(unsigned char **)(context + 0x128);
    *(unsigned char **)(lbl_80332158 + 0x150) = base;

    offset = fn_801F668C(base);
    *(unsigned short *)(lbl_80332158 + 0x160) = offset;
    *(unsigned char **)(lbl_80332158 + 0x154) = base + (unsigned short)offset;

    length = fn_8012BA84(base + (unsigned short)offset);
    offset = (unsigned short)offset + length;
    *(unsigned short *)(lbl_80332158 + 0x162) = length;
    *(unsigned char **)(lbl_80332158 + 0x158) = base + (unsigned short)offset;

    *(unsigned short *)(lbl_80332158 + 0x164) =
        fn_801E8FAC(*(unsigned char **)(lbl_80332158 + 0x158));
    offset += *(unsigned short *)(lbl_80332158 + 0x164);
    *(unsigned char **)(lbl_80332158 + 0x15C) = base + (unsigned short)offset;

    *(unsigned short *)(lbl_80332158 + 0x166) =
        fn_801FABA4(*(unsigned char **)(lbl_80332158 + 0x15C), 0);
    offset += *(unsigned short *)(lbl_80332158 + 0x166);
    fn_801A7F94(base + (unsigned short)offset);

    fn_800AFBA8(lbl_80332158 + 8);
    snapshot = fn_8015AB00(*(void **)lbl_805B6FE0);
    *(int *)(lbl_80332158 + 0x24) = snapshot != 0;
    if (*(int *)(lbl_80332158 + 0x24) != 0) {
        snapshot = fn_8015AB00(*(void **)lbl_805B6FE0);
        memcpy(lbl_80332158 + 0x28, snapshot, 0x11C);
        fn_801EF3EC(lbl_80332158 + 0x144, lbl_80332158 + 0x148);
        *(int *)(lbl_80332158 + 0x14C) = fn_801ECC44();
    }
}
