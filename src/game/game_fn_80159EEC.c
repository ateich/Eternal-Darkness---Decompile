typedef struct Slot {
    char pad[0xC];
    int counter;
    char tail[8];
} Slot;

extern volatile Slot lbl_805B6F80[];
extern int lbl_8064D17C;

int fn_80159EEC(void)
{
    int i;
    int best = -1;
    int result = 0;
    for (i = 0; i < lbl_8064D17C; i++) {
        if (best < lbl_805B6F80[i].counter) {
            best = lbl_805B6F80[i].counter;
            result = i;
        }
    }
    return result;
}
