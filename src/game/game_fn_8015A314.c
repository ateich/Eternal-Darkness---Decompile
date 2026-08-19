typedef struct Record {
    char bytes[0x20A0];
} Record;

extern Record lbl_805B70A0[];

Record* fn_8015A314(int index)
{
    if (index >= 2 || index < 0) {
        return 0;
    }
    return &lbl_805B70A0[index];
}
