typedef unsigned char u8;
typedef int s32;

typedef struct QueryResult {
    u8 data[0x28];
} QueryResult;

typedef struct TemporaryDescriptor {
    u8 data[0x28];
} TemporaryDescriptor;
extern void *fn_80201BC8();
extern s32 fn_8011F598(void*, s32, s32, s32, QueryResult*, s32);
extern void fn_8013F4D0(TemporaryDescriptor*, void*, void*);
extern s32 fn_8014317C(TemporaryDescriptor*, s32, s32, s32, s32);

s32 fn_80031BE0(s32 unused, s32 query_a, s32 query_b, void* source,
                 s32 value, s32 selector)
{
    QueryResult query;
    TemporaryDescriptor descriptor;
    s32 result = 0;

    (void)unused;
    if (fn_8011F598(fn_80201BC8(), query_a, query_b, -1, &query, 1) != -1) {
        fn_8013F4D0(&descriptor, source, &query.data[8]);
        result = fn_8014317C(&descriptor, selector, value, 0, 2);
    }

    return result != 0;
}
