typedef unsigned char u8;

typedef struct QueryResult {
    u8 pad[0x28];
} QueryResult;

typedef struct InstanceList {
    u8 pad0[8];
    void *first;
    u8 padC[0x3C];
    void *second;
    u8 pad4C[0x3C];
    void *linked;
} InstanceList;

typedef struct Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color;

extern void *fn_80156938(void *);
extern void *fn_80201BC8(void *);
extern int fn_8011F6A4(void *, void *, void *, int, QueryResult *, int);
extern void *fn_8017FDA8(void *, int);
extern void fn_80149B60(void *, void *, void *, void *, int);
extern void *fn_8017FE04(void *);
extern unsigned short fn_8012DBE8(void *, int, Color *);

void fn_80148874(void *object, void *other)
{
    Color color;
    QueryResult result;
    void *runtime;
    InstanceList *list;
    void *model;
    u8 *linked;

    runtime = fn_80156938(other);
    list = fn_80156938(object);
    model = fn_80201BC8(runtime);
    if (model != 0) {
        fn_8011F6A4(model, list->first, list->second, -1, &result, 1);
        if (list->linked != 0) {
            fn_80149B60(runtime, fn_8017FDA8(list->linked, 0),
                        *(void **)((u8 *)&result + 4),
                        *(void **)&result, 0);
            linked = fn_8017FE04(list->linked);
            fn_8012DBE8(model, 15, &color);
            linked[3] = color.a;
        }
    }
}
