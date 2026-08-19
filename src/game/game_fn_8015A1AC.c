typedef struct Record {
    char pad[0x204C];
    int active;
    char pad2050[0x20];
    int value;
    int callback;
} Record;

void fn_8015A1AC(Record* record)
{
    record->value = 0;
    record->callback = 0;
    record->active = 0;
}
