typedef struct Record {
    unsigned char pad00[0x74];
    int handle;
    unsigned char pad78[0x17];
    signed char active;
    unsigned char pad90[2];
    signed char kind;
    unsigned char pad93[5];
} Record;

extern Record lbl_806080E0[];

Record* fn_801AB3CC(void)
{
    Record* result = 0;
    Record* record = lbl_806080E0;
    int i;

    for (i = 0; i < 80; i++, record++) {
        if (record->active != 0 && record->kind == 1 &&
            record->handle != -1) {
            result = record;
            break;
        }
    }
    return result;
}
