typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct QueryResult {
    unsigned char pad[8];
    Vec3 position;
    unsigned char tail[0x18];
} QueryResult;

extern const Vec3 lbl_80239860;

extern void *fn_80201BC8(void *);
extern int fn_80201B5C(void *);
extern int fn_8011F6A4(void *, int, int, int, QueryResult *, int);
extern void *fn_8011F114(Vec3 *, void *);

void fn_800C43AC(Vec3 *out, void *object)
{
    void *state = fn_80201BC8(object);
    Vec3 position;
    Vec3 resolved;
    Vec3 fallback;
    QueryResult result;
    Vec3 *source_ptr;

    if (fn_80201B5C(object) == 0x55 || fn_80201B5C(object) == 0x39) {
        fn_8011F6A4(state, 0, 1, -1, &result, 1);
        position = result.position;
    } else {
        if (state != 0) {
            fn_8011F114(&resolved, state);
            source_ptr = &resolved;
        } else {
            fallback = lbl_80239860;
            source_ptr = &fallback;
        }
        position = *source_ptr;
    }
    *out = position;
}
