typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct ObjectVtable {
    unsigned char pad[0x38];
    void (*get_position)(void *, Vec3 *);
} ObjectVtable;

typedef struct Object {
    ObjectVtable *vtable;
    unsigned char pad04[0xA8];
    Vec3 position;
    Vec3 raised_position;
} Object;

extern void *fn_801A7468(void *);
extern void fn_800A30F4(Object *, int);
extern void fn_801287C4(void *, void (*)(void), void *, int);
extern void fn_800A1A24(void);
extern void fn_800A1A04(void);
extern void fn_800D9FE0(void);
extern void fn_800D9A14(void);
extern void fn_800D9E10(void);
extern void fn_800D9614(void);
extern void fn_800D9BE0(void);
extern void fn_800D9BB8(void);
extern const float lbl_8064F428;

void fn_800D8CB8(Object *object, void *owner, void *created, void *context,
                  Vec3 *position)
{
    void *resource;
    Vec3 local_position;
    int event;

    resource = fn_801A7468(context);
    object->vtable->get_position(resource, &local_position);
    object->position = *position;
    object->raised_position = *position;
    object->raised_position.z += lbl_8064F428;
    fn_800A30F4(object, 1);
    fn_801287C4(created, fn_800A1A24, object, 5);
    for (event = 0x3D; event < 0x48; event += 4) {
        fn_801287C4(created, fn_800D9FE0, context, event);
    }
    fn_801287C4(created, fn_800D9A14, context, 0x14);
    fn_801287C4(created, fn_800D9E10, context, 0x39);
    fn_801287C4(created, fn_800D9614, owner, 0x3B);
    fn_801287C4(created, fn_800D9BE0, owner, 0x3C);
    fn_801287C4(created, fn_800D9BB8, object, 0x4E);
    fn_801287C4(created, fn_800A1A04, (void *)0x16666, 2);
}
