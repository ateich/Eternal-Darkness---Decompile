typedef signed short s16;
typedef unsigned short u16;

typedef struct Entry {
    s16 id;
    u16 value2;
    u16 value4;
    u16 value6;
} Entry;

extern Entry lbl_805FAA60[10];
extern void fn_8016B400(s16, int, int);

void fn_8016AF2C(void)
{
    int i;

    i = 0;

    do {
        if (lbl_805FAA60[i].id != 0 && lbl_805FAA60[i].value4 != 0) {
            lbl_805FAA60[i].value4--;
            if (lbl_805FAA60[i].value4 == 0) {
                fn_8016B400(lbl_805FAA60[i].id, 0, 0);
            }
        }
        i++;
    } while (i < 10);
}
