typedef unsigned short u16;

typedef struct ActorState {
    char pad_000[0x64];
    void *resource;
    char pad_068[0x1FC];
    void *effect;
} ActorState;

extern int fn_80200C10(void *);
extern void* fn_80201B3C();
extern int fn_80201B54();
extern int fn_80200C20(void *);
extern void *fn_80201BC8();
extern void *fn_80201B8C();
extern void* fn_80201B94();
extern void fn_8011F114();
extern int fn_80201B44();
extern void fn_80201DD8(int, int);
extern void fn_800359A0(void *, int);
extern void fn_800A3104(ActorState *, int);
extern void fn_800A3AC4(ActorState *);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

/*
 * Honest-C work in progress for the 9,520-byte actor event dispatcher.  The
 * common setup and event-1 teardown path are recovered here; the many later
 * event branches remain to be expressed before this can be considered for a
 * matching build.
 */
int fn_800D0B74(void *object, int alternate, void *event, int value)
{
    int kind = fn_80200C10(event);
    void *source = fn_80201B3C();
    int source_id = source != 0 ? fn_80201B54(source) : -1;
    int event_value = fn_80200C20(event);
    void *resource = fn_80201BC8(object);
    ActorState *state = ((ActorState *)fn_80201B8C(object));
    int mode = (int)fn_80201B94(object);
    int object_id = fn_80201B54(object);
    float position[3];
    int active = fn_80201B44();

    fn_8011F114(position, resource);
    fn_80201DD8(mode, active);

    if (alternate == 0 && kind == 1) {
        void (**callbacks)(ActorState *, void *);
        fn_800359A0(object, 0);
        fn_80201DD8(mode, 0);
        fn_800A3104(state, 0);
        fn_800A3AC4(state);
        callbacks = *(void (***)(ActorState *, void *))state;
        callbacks[0](state, object);
        fn_80201D2C(object, 1);
        fn_80201D14(object, 1);
        return 1;
    }

    (void)source_id;
    (void)event_value;
    (void)object_id;
    (void)value;
    return 0;
}
