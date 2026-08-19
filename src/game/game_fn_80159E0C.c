typedef struct Slot {
    char pad[0xC];
    int counter;
    char tail[8];
} Slot;

extern Slot lbl_805B6F80[];
extern int lbl_8064D17C;

void fn_80159E0C(void)
{
    int i;
    for (i = 0; i < lbl_8064D17C; i++) {
        lbl_805B6F80[i].counter++;
    }
}
