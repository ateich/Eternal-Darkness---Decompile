typedef struct Entry {
    char data[0xE0];
} Entry;

extern Entry lbl_80313120[];
extern int fn_80072368(int);
extern void *memcpy(void *, const void *, unsigned int);

int fn_8007249C(int id, Entry *output)
{
    int index = fn_80072368(id);
    int result = 0;

    if (index != -1) {
        memcpy(output, &lbl_80313120[index], sizeof(Entry));
        result = 1;
    }
    return result;
}
