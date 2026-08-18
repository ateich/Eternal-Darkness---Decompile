extern void* fn_80201B9C(void*);
extern void* fn_80201BC8(void*);
extern void* fn_80201B94(void*);
extern void* fn_80201BC0(void*);
extern void* fn_80201E48(void);
extern void* fn_8011F130(void*);
extern void fn_80155814(void*, void*, void*, int);

typedef struct Object {
    char pad00[0xc];
    float point[3];
} Object;

void fn_80155ABC(Object* object, int alternate)
{
    void* cursor;
    void* payload;
    void* work;
    void* info;

    cursor = fn_80201B9C(object);
    while (cursor != 0) {
        payload = fn_80201BC8(cursor);
        if (fn_80201B94(cursor) != 0 && payload != 0 &&
            (work = fn_80201E48()) != 0 &&
            (info = fn_8011F130(payload)) != 0)
            fn_80155814(work, info, object->point, alternate);
        cursor = fn_80201BC0(cursor);
    }
}
