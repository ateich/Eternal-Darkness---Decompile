typedef struct Slot {
    short id;
    short state;
    char pad[8];
    int counter;
    char tail[8];
} Slot;

extern Slot lbl_805B6F80[];
extern int lbl_8064D17C;

int fn_8015A12C(void)
{
    int i;
    int result = -1;
    for (i = 0; i < lbl_8064D17C; i++) {
        if (lbl_805B6F80[i].id != -1 && lbl_805B6F80[i].state == 0) {
            result = i;
            break;
        }
    }
    return result;
}
