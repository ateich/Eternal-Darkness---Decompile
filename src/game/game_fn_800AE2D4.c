typedef unsigned char u8;

typedef struct Entry800AE2D4 {
    u8 pad0[0x1C];
    int handle;
} Entry800AE2D4;

extern Entry800AE2D4 lbl_8031F718[5];
extern int lbl_8064B638;
extern int lbl_8064C9D0;
extern int lbl_8064C9D4;
extern int lbl_8064C9D8;
extern int lbl_8064C9DC;
extern int lbl_8064C9E0;
extern void* memset(void*, int, unsigned int);

void fn_800AE2D4(void)
{
    int i;

    lbl_8064C9D8 = 20;
    lbl_8064C9D4 = 127;
    memset(lbl_8031F718, 0, sizeof(lbl_8031F718));
    lbl_8064C9E0 = 0;
    lbl_8064C9DC = 0;
    lbl_8064B638 = -1;
    for (i = 0; i < 5; i++) {
        lbl_8031F718[i].handle = -1;
    }
    lbl_8064C9D0 = 0;
}
