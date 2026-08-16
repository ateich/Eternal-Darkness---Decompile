typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Transform {
    Vec3 position;
} Transform;

typedef struct SceneEntry {
    int mode;
    short unused0;
    short unused1;
    short second;
    short third;
    unsigned char pad[4];
} SceneEntry;

typedef struct Wrapper {
    void* object;
} Wrapper;

typedef struct Runtime {
    unsigned char pad[0x8C];
    void* resource;
} Runtime;

extern SceneEntry lbl_8031D3F8[][2][4];
extern int lbl_8064C560;
extern int lbl_8064C564;
extern int lbl_8064C578;
extern int lbl_8064C55C;

extern void fn_800DD314(void*, int, int, int);
extern void* fn_8008F224(void*, int, int);
extern void *fn_80201814();
extern void fn_80201E78(Transform*, void*);
extern void fn_80072618(Transform*, Vec3*, int, int);
extern void fn_8011F0E8(void*, Vec3*);
extern void fn_80048708(void*);
extern void fn_8012B7D0(void*, Vec3*);
extern void fn_8012B7A0(void*);
extern void fn_800BD2DC(void*, void*);
extern void fn_80201DD8(void*, void*);
extern int fn_80036D5C(void*);
extern void fn_80036DA4(void*, int);
extern void fn_80201D34(void*, int);
extern void fn_80201D1C(void*, int);
extern Wrapper* fn_800BC100(int, int, int*, int, int, int, int);
extern void fn_800BD194(void*, void*);
extern void fn_800BCCC4(void*, Vec3*);
extern void fn_80201F44(void*, Vec3*);
extern void fn_800BDEE4(void*, void*);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern int fn_800DE298(void*);
extern void fn_801261F4(void*);
extern void fn_800DFD54(int, void*, void*, int);

void fn_8008F5B4(void* object, void* actor, void* unused3, void* unused4,
                 int* link, void* state, void* unused7, Runtime* runtime,
                 void* resource, void* target)
{
    Transform transform;
    Vec3 position;
    Vec3 collision;
    Vec3 destination;
    Vec3 source;
    Vec3 copied;
    int id;
    Wrapper* wrapper;

    fn_800DD314(object, 15, 255, 0);
    if (lbl_8031D3F8[lbl_8064C578][lbl_8064C560][lbl_8064C564].mode == 1) {
        void* owner = fn_8008F224(target, 1, 1);
        void* value = fn_80201814(owner);
        fn_80201E78(&transform, value);
        fn_80072618(&transform, &position, 0, 1);
        fn_8011F0E8(actor, &position);
        fn_80048708(actor);
        source = transform.position;
        fn_8012B7D0(actor, &source);
        fn_8012B7A0(actor);
        fn_800BD2DC(object, resource);
        if (lbl_8064C55C != 0) {
            fn_800DD314(object, 15, 255, 0);
            fn_80201DD8(state, owner);
        } else {
            fn_80036DA4(object, fn_80036D5C(object) | 0x100000);
            link[5] = (int)owner;
            fn_80201D34(object, 9);
            fn_80201D1C(object, 1);
        }
    } else {
        id = lbl_8031D3F8[lbl_8064C578][lbl_8064C560][lbl_8064C564].third;
        wrapper = fn_800BC100(0, 0, &id, 16, 0, 0, 0);
        fn_800BD194(object, resource);
        fn_800BCCC4(wrapper->object, &collision);
        fn_80201DD8(state, (void*)-1);
        copied = collision;
        fn_80201F44(object, &copied);

        id = lbl_8031D3F8[lbl_8064C578][lbl_8064C560][lbl_8064C564].second;
        wrapper = fn_800BC100(0, 0, &id, 16, 0, 0, 0);
        fn_800BCCC4(wrapper->object, &destination);
        fn_8011F0E8(actor, &destination);
        fn_80048708(actor);
        fn_800BDEE4(object, runtime->resource);
        fn_80201D2C(object, 3);
        fn_80201D14(object, 1);
        if (fn_800DE298(object)) {
            fn_801261F4(actor);
            fn_800DFD54(1, object, actor, 0);
        }
    }
}
