typedef struct Entry {
    int sentinel;
    char pad04[0x194];
} Entry;

extern Entry lbl_805B4E10[];
extern void* memset(void*, int, unsigned int);

Entry* fn_80158598(int value, int create)
{
    Entry* found = 0;
    int index;

    for (index = 0; index < 20 && found == 0; index++) {
        if (lbl_805B4E10[index].sentinel == value) {
            found = &lbl_805B4E10[index];
        }
    }
    if (found == 0 && create != 0) {
        for (index = 0; index < 20 && found == 0; index++) {
            if (lbl_805B4E10[index].sentinel <= 0) {
                found = &lbl_805B4E10[index];
            }
        }
        if (found != 0) {
            memset(found, 0, sizeof(Entry));
            found->sentinel = value;
        }
    }
    return found;
}
