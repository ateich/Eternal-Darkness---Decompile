typedef struct Entry {
    char data[0xE0];
} Entry;

extern Entry lbl_80313120[];

Entry *fn_80072354(int index)
{
    return &lbl_80313120[index];
}
