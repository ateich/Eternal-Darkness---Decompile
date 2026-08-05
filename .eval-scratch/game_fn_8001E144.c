extern unsigned char lbl_8023D020[];
extern unsigned char lbl_80302400[];
extern int lbl_8064C6C8;
extern int lbl_8064C6C4;
extern int lbl_8064C670;
extern int lbl_8064C6D0;
extern int lbl_8064C504;
extern int lbl_8064C51C;
extern int lbl_8064CA68;
extern int lbl_80238978[];
extern int lbl_80238998[];

extern void fn_8022A814(int, int);
extern void *memset(void *, int, int);
extern void fn_8020EF54(void *, void *);
extern void fn_8001DE84(int, int);
extern void fn_801AD4B4(int, int, int, int);
extern void fn_8001D56C(void);
extern void fn_801A99B4(void);
extern int fn_80138164(void);
extern int fn_80024638(char *, int, int *);
extern void fn_8015DAB0(int);
extern int fn_8015AA14(void);
extern void fn_8015D458(char *, int, int);
extern int fn_8015AA0C(void);
extern int fn_801E6CA0(int, int, int, int, int);
extern void fn_801E6F9C(int, int);
extern void fn_801E85A8(void);
extern void fn_800B177C(int, void (*)(void));
extern void fn_800B689C(int, int);
extern void fn_800B2548(int, int);
extern int fn_801A98F4(int, int);
extern void fn_80042EDC(void);
extern void fn_80042E3C(void);
extern void fn_801EFE84(int);
extern void fn_80023B40(void);

void fn_8001E144(int arg)
{
    unsigned char *base = lbl_80302400;
    unsigned char *data = lbl_8023D020;
    unsigned char *g = base + 0x1c;
    int *arr = (int *)(base + 0x2cc);
    int local[5];
    int tmp, tmp2, tmp3, tmp4;

    fn_8022A814(0, 0);
    memset(g, 0, 0x44);
    *(unsigned char *)(g + 0x40) = 0xc8;
    *(unsigned short *)(g + 0x3c) = 7;
    *(int *)(g + 0x14) = 0xff;
    lbl_8064C6C8 = 0;
    lbl_8064C6C4 = 0;
    lbl_8064C670 = 0;
    *(int *)(g + 0x18) = arg;
    *(int *)(g + 0x30) = 0;
    fn_8020EF54(base + 0x60, data + 0x83c);
    lbl_8064C6D0 = 0;
    fn_8001DE84(3, 0);
    fn_8001DE84(3, 0);
    *(int *)(g + 0x14) = 0xff;
    *(int *)(g + 0x30) |= 0x20;
    arr[0] = 0x7d0;
    arr[1] = 0x3e8;
    arr[2] = 0x3e8;
    arr[3] = 0x3e8;
    if (arg == 0) {
        fn_801AD4B4(7, 0, 0, 0);
        fn_8001D56C();
        fn_801A99B4();
    }
    *(int *)(g + 0xc) = 0;
    *(int *)(g + 0x10) = 0;
    if (arg > 14) goto end;

    switch (arg) {
    case 0:
        fn_8001DE84(1, 0);
        fn_8001DE84(1, 0);
        *(int *)(g + 0x14) = 0xff;
        *(int *)(g + 0x30) |= 0x1;
        *(int *)(g + 0x30) |= 0x10;
        arr[1] = 0xbb8;
        arr[2] = 0x5dc;
        arr[3] = 0x5dc;
        tmp = fn_80138164();
        *(int *)(g + 0xc) = fn_80024638(data + 0x848, tmp, &local[4]);
        fn_8015DAB0(*(int *)(g + 0xc));
        *(int *)(g + 0x10) = tmp + ((local[4] + 0x1f) & ~0x1f);
        if (*(int *)(g + 0x30) & 0x4) {
            *(int *)(g + 0x38) = fn_801A98F4(0x275, 0x64);
            fn_8001DE84(0x19, 0);
            *(int *)(g + 0x14) = 0xff;
            *(int *)(g + 0x30) |= 0x1;
        }
        fn_80042EDC();
        fn_80042E3C();
        break;
    case 1:
        tmp = fn_80138164();
        *(int *)(g + 0xc) = fn_80024638(data + 0x848, tmp, &local[3]);
        fn_8015DAB0(*(int *)(g + 0xc));
        *(int *)(g + 0x10) = tmp + ((local[3] + 0x1f) & ~0x1f);
        tmp2 = fn_8015AA14();
        fn_8015D458(data + 0x858, *(int *)(g + 0x10), tmp2);
        fn_8015DAB0(*(int *)(g + 0x10));
        *(unsigned char *)(g + 0x3e) = 0xfd;
        break;
    case 2:
        tmp = fn_80138164();
        *(int *)(g + 0xc) = fn_80024638(data + 0x848, tmp, &local[2]);
        fn_8015DAB0(*(int *)(g + 0xc));
        *(int *)(g + 0x10) = tmp + ((local[2] + 0x1f) & ~0x1f);
        tmp2 = fn_8015AA14();
        fn_8015D458(data + 0x858, *(int *)(g + 0x10), tmp2);
        fn_8015DAB0(*(int *)(g + 0x10));
        tmp3 = fn_801E6CA0(lbl_8064C504, 0, 0x27, 0, 1);
        fn_801E6F9C(tmp3, 0);
        *(unsigned char *)(g + 0x3e) = 0xfe;
        break;
    case 3:
        tmp = fn_8015AA0C();
        tmp2 = fn_80138164();
        *(int *)(g + 0xc) = fn_80024638(data + 0x848, tmp2, &local[1]);
        fn_8015DAB0(*(int *)(g + 0xc));
        *(int *)(g + 0x10) = tmp2 + ((local[1] + 0x1f) & ~0x1f);
        tmp3 = fn_8015AA14();
        fn_8015D458(data + 0x858, *(int *)(g + 0x10), tmp3);
        fn_8015DAB0(*(int *)(g + 0x10));
        lbl_8064C51C = fn_80024638(data + 0x864, tmp, &local[1]);
        fn_801E85A8();
        lbl_8064CA68 = 1;
        fn_800B177C(1, fn_80023B40);
        fn_800B689C(0, 1);
        fn_800B2548(0xc, 0);
        {
            int *src1 = lbl_80238978;
            int *src2 = lbl_80238998;
            unsigned char *dst = data + 0x75c;
            int i;
            for (i = 0; i < 8; i++) {
                *(int *)(dst + 0x60 + i * 4) = src1[i];
                *(int *)(dst + 0x80 + i * 4) = src2[i];
            }
        }
        fn_8001DE84(0x1b, 0);
        fn_8001DE84(6, 0);
        lbl_8064C6C8 = 1;
        break;
    case 4:
        tmp = fn_80138164();
        *(int *)(g + 0xc) = fn_80024638(data + 0x848, tmp, &local[0]);
        fn_8015DAB0(*(int *)(g + 0xc));
        *(int *)(g + 0x10) = tmp + ((local[0] + 0x1f) & ~0x1f);
        tmp2 = fn_8015AA14();
        fn_8015D458(data + 0x858, *(int *)(g + 0x10), tmp2);
        fn_8015DAB0(*(int *)(g + 0x10));
        *(unsigned char *)(g + 0x3e) = 0xfc;
        fn_8001DE84(0x1b, 0);
        fn_8001DE84(0xfc, 0);
        fn_801EFE84(0);
        break;
    default:
        break;
    }
end:
    fn_8001DE68();
}
