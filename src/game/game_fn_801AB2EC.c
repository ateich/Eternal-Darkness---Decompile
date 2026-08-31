typedef struct Record {
    unsigned char pad00[0x84];
    unsigned short room;
    unsigned char pad86[2];
    unsigned char priority;
    unsigned char pad89[5];
    unsigned char flags;
    signed char active;
    unsigned char pad90[2];
    signed char kind;
    unsigned char pad93[5];
} Record;

extern Record lbl_806080E0[];
extern int lbl_8064D18C;

Record* fn_801AB2EC(void)
{
    Record* result = 0;
    Record* record = lbl_806080E0;
    unsigned char priority = 0;
    int room = lbl_8064D18C;
    int i;

    for (i = 0; i < 80; i++, record++) {
        if (record->active != 0 && record->kind == 1 &&
            record->priority > priority && (record->flags & 0x20) != 0 &&
            record->room == room) {
            priority = record->priority;
            result = record;
        }
    }
    return result;
}
