typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

typedef struct FourWords {
    u32 words[4];
} FourWords;

typedef union RotationValue {
    Vec4 vector;
    FourWords words;
} RotationValue;

typedef struct QueryResult {
    u8 pad_0[8];
    Vec3 position;
    Vec3 direction;
    u8 pad_20[8];
} QueryResult;

typedef struct EntryRecord {
    u8 pad_0[0xE];
    u16 record_index;
} EntryRecord;

typedef struct Entry {
    u8 pad_0[4];
    EntryRecord* record;
} Entry;

typedef struct ObjectRecord {
    u8 pad_0[0x48];
    void* value;
} ObjectRecord;

typedef struct Object {
    u8 pad_0[0x160];
    ObjectRecord* records;
    u8 pad_164[0xDC];
    Entry** entries;
} Object;

extern void fn_80125ECC(void*);
extern int fn_8011F6A4(void*, int, int, int, void*, int);
extern int fn_8012EF98(void*, int, QueryResult*, QueryResult*,
                       const Vec3*, Vec4*, float);
extern void fn_8012CEA4(u8*, int, Vec4*);
extern float fn_8017A5A8(const Vec4*, const Vec4*, float);
extern void fn_8017A7D4(const Vec4*, const Vec4*, float, Vec4*);
extern void fn_8012CDF0(u8*, int, FourWords, int);

int fn_8012EC50(void* object, int index, Vec3* target, int query_key,
                float blend_limit, float query_limit)
{
    QueryResult first;
    QueryResult second;
    Vec4 desired;
    Vec4 current;
    RotationValue blended;
    Entry* entry;

    fn_80125ECC(object);
    entry = ((Object*)object)->entries[index];
    if (entry != 0) {
        float amount;

        ((Object*)object)->records[entry->record->record_index].value = 0;
        fn_8011F6A4(object, query_key, index, -1, &first, 1);
        fn_8011F6A4(object, query_key, index, -1, &second, 4);
        if (fn_8012EF98(object, index, &first, &second, target, &desired,
                        query_limit)) {
            fn_8012CEA4((u8*)object, index, &current);
            amount = fn_8017A5A8(&current, &desired, blend_limit);
            fn_8017A7D4(&current, &desired, amount, &blended.vector);
            fn_8012CDF0((u8*)object, index, blended.words, 0);
        }
    }
    return 0;
}
