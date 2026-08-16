typedef struct Object {
    unsigned char pad_000[0x84];
    unsigned short flags;
} Object;

extern void *fn_80201BC8(void *);
extern void fn_800A2D78(void *);
extern void fn_800A2598(void *);
extern void fn_8012B344(void *);
extern void fn_800DA278(void *, int);
extern void fn_800D9D64(void *, void *);

void fn_800D6974(Object *object, void *handle)
{
    void *runtime = fn_80201BC8(handle);

    fn_800A2D78(object);
    fn_800A2598(object);
    fn_8012B344(runtime);
    if (object->flags & 0x10) {
        fn_800DA278(object, 1);
        object->flags &= ~0x10;
    } else if (object->flags & 0x400) {
        fn_800D9D64(runtime, handle);
        object->flags &= ~0x400;
    }
}
