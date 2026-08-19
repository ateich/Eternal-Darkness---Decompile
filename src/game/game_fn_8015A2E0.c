typedef struct Record {
    char bytes[0x20A0];
} Record;

extern Record lbl_805B70A0[];

int fn_8015A2E0(Record* record)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (&lbl_805B70A0[i] == record) {
            return i;
        }
    }
    return -1;
}
