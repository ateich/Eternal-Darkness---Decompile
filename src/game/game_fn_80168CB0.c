typedef struct Record {
    void* payload;
    char pad04[8];
    unsigned short flag;
} Record;

extern Record* fn_80168BAC(void*, int);

void fn_80168CB0(void* state, void* payload, int count)
{
    Record* record = fn_80168BAC(state, count);
    record->payload = payload;
    record->flag = 0;
}
