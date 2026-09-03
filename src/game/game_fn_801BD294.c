typedef unsigned short u16;

extern u16 lbl_8064D3F0;
extern u16 lbl_8064D3F2;
extern u16 lbl_8064D3F4;
extern u16 lbl_8064D3F6;
extern u16 lbl_8064D3F8;
extern u16 lbl_8064D3FA;
typedef struct Pair {
    u16 first;
    u16 second;
} Pair;

extern Pair lbl_80622148[];
extern void fn_801CD284(void);

void fn_801BD294(void)
{
    int i;

    i = 0;
    lbl_8064D3F0 = 0;
    lbl_8064D3F2 = 0;
    lbl_8064D3F4 = 0;
    lbl_8064D3F6 = 0;
    lbl_8064D3FA = 0;
    lbl_8064D3F8 = 0;
    while (i < 512) {
        lbl_80622148[i].first = 0;
        lbl_80622148[i].second = 0;
        i++;
    }
    fn_801CD284();
}
