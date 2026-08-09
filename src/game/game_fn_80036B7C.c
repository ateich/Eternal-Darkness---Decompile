typedef unsigned char u8;
typedef int s32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct QueryResult {
    u8 pad00[8];
    Vec3 position;
    u8 pad14[0x10];
} QueryResult;

extern s32 fn_8011F6A4(void*, s32, s32, s32, QueryResult*, s32);
extern s32 fn_8012FD1C(void*, s32, Vec3*);

s32 fn_80036B7C(register void* object, register s32 value,
                 register Vec3* position)
{
    register s32 result;
    QueryResult query;

    result = 0;
    if (fn_8011F6A4(object, 0, value, -1, &query, 1) != -1) {
        *position = query.position;
        result = 1;
    } else if (fn_8012FD1C(object, value, &query.position) != 0) {
        *position = query.position;
        result = 1;
    }
    return result;
}
