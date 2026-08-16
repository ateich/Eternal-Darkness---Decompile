typedef struct Entry {
    char data[32];
} Entry;

extern Entry lbl_80248DA8[];

Entry *fn_800E4594(int index)
{
    Entry *result = 0;

    if (index >= 0 && index < 166)
        result = &lbl_80248DA8[index];
    return result;
}
