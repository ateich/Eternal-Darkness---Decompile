typedef signed short s16;

typedef struct Entry {
    s16 id;
    char pad02[0x16];
} Entry;

extern int lbl_8064D17C;
extern Entry lbl_805B6F80[];

int fn_80158E88(int id)
{
    int i;

    for (i = 0; i < lbl_8064D17C; i++) {
        if (lbl_805B6F80[i].id == id) {
            return i;
        }
    }
    return -1;
}
