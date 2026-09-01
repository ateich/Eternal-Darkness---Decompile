typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry Entry;
struct Entry {
    u8* first;
    u8* second;
    u8 padding08[316];
    int value144;
    int value148;
    u8 padding14C[16];
    int value15C;
    u8 padding160[16];
    u8 flag170;
    u8 padding171[9];
    u8 flag17A;
    u8 padding17B[9];
};

extern Entry lbl_8060B5E0[4];
extern u8 lbl_8060BC00[];
extern u32 lbl_8064D314;
extern u32 lbl_8064D310;
extern void fn_801ADD5C(void);
extern void fn_801B0D30(int);
extern void* memset(void*, int, unsigned int);

void fn_801AF000(int arg0)
{
    if (arg0 == 0) {
        fn_801ADD5C();
    } else {
        fn_801B0D30(arg0);
    }
    memset(lbl_8060B5E0, 0, 0x610);

    lbl_8060B5E0[0].flag17A = 0;
    lbl_8060B5E0[0].value144 = -1;
    lbl_8060B5E0[0].value148 = -1;
    lbl_8060B5E0[0].value15C = -1;
    lbl_8060B5E0[0].first = lbl_8060BC00;
    lbl_8060B5E0[0].second = lbl_8060BC00 + 0x60;

    lbl_8060B5E0[1].flag17A = 0;
    lbl_8060B5E0[1].value144 = -1;
    lbl_8060B5E0[1].value148 = -1;
    lbl_8060B5E0[1].value15C = -1;
    lbl_8060B5E0[1].first = lbl_8060BC00 + 0xC0;
    lbl_8060B5E0[1].second = lbl_8060BC00 + 0x120;

    lbl_8060B5E0[2].flag17A = 0;
    lbl_8060B5E0[2].value144 = -1;
    lbl_8060B5E0[2].value148 = -1;
    lbl_8060B5E0[2].value15C = -1;
    lbl_8060B5E0[2].first = lbl_8060BC00 + 0x180;
    lbl_8060B5E0[2].second = lbl_8060BC00 + 0x1E0;

    lbl_8060B5E0[3].flag17A = 0;
    lbl_8060B5E0[3].value144 = -1;
    lbl_8060B5E0[3].value148 = -1;
    lbl_8060B5E0[3].value15C = -1;
    lbl_8060B5E0[3].first = lbl_8060BC00 + 0x240;
    lbl_8060B5E0[3].second = lbl_8060BC00 + 0x2A0;

    lbl_8064D314 = 1;
    lbl_8064D310 = 0;
}
