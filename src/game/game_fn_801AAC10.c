typedef struct Record {
    unsigned char pad[0x8F];
    signed char active;
    unsigned char tail[8];
} Record;

extern Record lbl_806080E0[];
extern void fn_801AA9FC(int);

Record* fn_801AAC10(void)
{
    Record* record;
    int i;

    record = lbl_806080E0;
    i = 0;
    while (record->active != 0) {
        record++;
        i++;
        if (i >= 80) {
            fn_801AA9FC(1);
            return 0;
        }
    }
    return record;
}
