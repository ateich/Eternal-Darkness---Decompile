typedef struct InputRecord {
    void* data;
    int first;
    int second;
} InputRecord;

typedef struct InputRecordArray {
    unsigned char pad00[0x34];
    int count;
    InputRecord* records;
} InputRecordArray;

#pragma use_lmw_stmw on

extern int fn_80167FE4(void*, void*, int);
extern void* fn_8016B5CC(void*, void*, unsigned int, const char*, int);
extern void* fn_80168080(void*, void*, int);
extern const char lbl_8024FAF4[];

void fn_801681DC(void* object, InputRecordArray* array, void* input, int reverse)
{
    int count = fn_80167FE4(object, input, reverse);
    int offset;
    int i;

    array->count = count;
    array->records = fn_8016B5CC(object, 0, count * sizeof(InputRecord),
                                 lbl_8024FAF4, 118);
    i = 0;
    offset = 0;
    for (; i < count; i++) {
        *(void**)((unsigned char*)array->records + offset) =
            fn_80168080(object, input, reverse);
        *(int*)((unsigned char*)array->records + offset + 4) =
            fn_80167FE4(object, input, reverse);
        *(int*)((unsigned char*)array->records + offset + 8) =
            fn_80167FE4(object, input, reverse);
        offset += sizeof(InputRecord);
    }
}
