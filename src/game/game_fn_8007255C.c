typedef struct Entry {
    char data[0xE0];
} Entry;

extern Entry lbl_8031CA40;
extern int fn_80072368(int);
extern int fn_800723A8(int, Entry *);
extern int fn_8007249C(int, Entry *);
extern int fn_800724F8(Entry *);
extern void *memcpy(void *, const void *, unsigned int);

int fn_8007255C(int id, Entry *output)
{
    int result = 0;
    int index;
    unsigned int found;

    index = fn_80072368(id);
    found = ((unsigned int)((-1 - index) | (index + 1))) >> 31;
    if (found == 0) {
        if (fn_800723A8(id, &lbl_8031CA40) != 0) {
            result = 1;
            fn_800724F8(&lbl_8031CA40);
            if (output != 0) {
                memcpy(output, &lbl_8031CA40, sizeof(Entry));
            }
        }
    } else {
        result = 1;
        if (output != 0) {
            fn_8007249C(id, output);
        }
    }
    return result;
}
