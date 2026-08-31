typedef struct Record {
    unsigned char pad00[0x8F];
    signed char active;
    signed char priority;
} Record;

extern void fn_801AB048(Record*);

void fn_801AB0C4(Record* record, signed char priority, signed char active)
{
    if (record != 0 && record->active != 0) {
        if (priority == 0 && active == 4) {
            fn_801AB048(record);
        } else if (record->active == active) {
            record->priority = priority < record->priority
                                   ? priority
                                   : record->priority;
        } else {
            record->active = active;
            record->priority = priority;
        }
    }
}
