typedef unsigned int u32;

typedef struct State {
    u32 zero;
    u32 size;
    unsigned char pad08[4];
    int index0;
    unsigned char pad10[0x2A8];
    int index1;
    unsigned char pad2BC[0x3C];
    unsigned char* start;
    unsigned char pad2FC[0xC];
    int index2;
    unsigned char pad30C[0x3C];
    unsigned char* end;
    unsigned char pad34C[0xC];
} State;

extern State lbl_805AE020;
extern int lbl_8064CFC4;
extern u32 lbl_8064CFE0;
extern u32 lbl_8064CFE4;
extern u32 lbl_8064CFE8;
extern unsigned char* lbl_8064CFD8;

extern void* memset(void*, int, u32);
extern int fn_80046104(void);

void fn_80138E9C(void)
{
    unsigned char* start;
    unsigned char* end;

    if (lbl_8064CFC4 == 1) {
        start = lbl_805AE020.start;
        end = lbl_805AE020.end;
    } else {
        lbl_8064CFE8 = 0;
        lbl_8064CFE4 = 0;
        lbl_8064CFE0 = 0;
    }

    memset(&lbl_805AE020, 0, sizeof(State));
    lbl_805AE020.index0 = -1;
    lbl_805AE020.index1 = -1;
    lbl_805AE020.index2 = -1;

    if (fn_80046104() == 0) {
        lbl_805AE020.size = 0xCF860;
        if (lbl_8064CFC4 == 0) {
            lbl_805AE020.start = (unsigned char*)lbl_8064CFD8;
            lbl_805AE020.end = (unsigned char*)lbl_8064CFD8 + 0xCF860;
        } else {
            lbl_805AE020.start = start;
            lbl_805AE020.end = end;
        }
    }
    lbl_8064CFC4 = 1;
}
