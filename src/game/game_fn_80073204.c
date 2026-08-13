typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

#pragma use_lmw_stmw on

typedef struct EffectRecordTable {
    u8 pad_00[0x10];
    u16 capacity;
    u8 pad_12[2];
    void *secondary_records;
    u8 pad_18[0x1C];
    u16 count;
    u8 pad_36[2];
    void *records;
} EffectRecordTable;

extern char lbl_802446B0[];
extern EffectRecordTable *fn_8015C390(s32);
extern s32 fn_801E741C(char *);
extern s32 fn_80073368(void *, u16, void *, u16, s32, s32, s32, s32,
                       s32, s32, s32, s32);

s32 fn_80073204(s32 x, s32 y, s32 z, s32 arg3, s32 arg4)
{
    EffectRecordTable *table;
    void *records;
    u16 capacity;
    s32 name_hash;
    s32 result;

    table = fn_8015C390(2);
    result = 0;
    if (table != 0 && table->count != 0) {
        records = table->secondary_records;
        capacity = table->capacity;
        name_hash = fn_801E741C(lbl_802446B0);
        result = fn_80073368(records, capacity, table->records, table->count,
                             x, y, z, 0x258, z, name_hash, arg3, arg4);
        if (result != 0) goto done;
        result = fn_80073368(records, capacity, table->records, table->count,
                             x, y, z, 0x384, 0x258, name_hash, arg3, arg4);
        if (result != 0) goto done;
        result = fn_80073368(records, capacity, table->records, table->count,
                             x, y, z, 0x4B0, 0x384, name_hash, arg3, arg4);
        if (result != 0) goto done;
        result = fn_80073368(records, capacity, table->records, table->count,
                             x, y, z, -1, 0x4B0, name_hash, arg3, arg4);
    }
done:
    return result;
}
