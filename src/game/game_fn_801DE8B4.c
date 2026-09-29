typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Vec3 { float x, y, z; } Vec3;

typedef struct ObjectState {
    u8 pad00[0x1d];
    u8 index;
    u8 pad1e[2];
    short search_distance;
    u8 pad22[0x12];
    int value34;
    int value38;
    int types[4];
    Vec3 position;
    Vec3 candidates[1];
} ObjectState;

typedef struct SpawnRequest {
    Vec3 position;
    float scale;
    int value10;
    int value14;
    int value18;
    int value1c;
    int value20;
    int value24;
    int mode;
    int value2c;
    int value30;
    int value34;
} SpawnRequest;

extern void* fn_80201B9C(void);
extern void* fn_80201BC8(void*);
extern void* fn_80201BC0(void*);
extern int fn_80201EB8(void*);
extern int fn_80201B4C(void*);
extern void fn_8011F114(Vec3*, void*);
extern u32 fn_80178E94(Vec3*, Vec3*);
extern int fn_80072A2C(Vec3*, Vec3*, int, int);
extern int fn_801D38E8(int);
extern int fn_800CAC5C(int, int, int*, int*, int*);
extern void fn_80043F44(SpawnRequest*);
extern void* fn_80034708(SpawnRequest*);
extern void fn_801261F4(void);
extern void fn_80201D54(void*, int);
extern void fn_80201D24(void*, int);
extern void fn_802015A4(void*);
extern void fn_8012C62C(void*, int, int*, int*, int*, int);
extern void fn_8011FA8C(void*, int, int);
extern int fn_80201B54(void*);
extern void fn_8020123C(int, int, int, int);
extern void* fn_80036D38(void*);
extern int fn_8012A100(void*, int);
extern void fn_801DDB84(Vec3*, int, int, void*);
extern void* fn_801294DC(void*, int, int, int);
extern void fn_80128C44(void*, void*, int);
extern void fn_80128C28(void*, void*, int);
extern int fn_801DE8AC(void);
extern void fn_801DE7FC(void*, int);
extern void fn_801DE7A0(int);
extern void fn_8012B7A0(void*, float);
extern void fn_80048708(void*);
extern void fn_801E8328(int, void*);
extern void fn_801AC9F4(int, int, Vec3*, int);
extern int fn_801D3A34(int, int);
extern int fn_801CEB2C(int);
extern void fn_8014F3A4(Vec3*, int, int, int, void*);
extern int lbl_8064D5A8, lbl_8064C308;
extern int lbl_80651F14, lbl_80651F18, lbl_80651F1C;

/* The search policy has a fixed radius for categories 2 and 8; other
 * categories use the signed state radius, compared as an unsigned distance. */
int fn_801DE8B4(void* object, int variant, int skip_search, float scale)
{
    u8* base = object;
    ObjectState* state = (ObjectState*)(base + 0xbc);
    void* iterator;
    int ok = 1;
    void* selected = 0;
    enum SearchRadius { DEFAULT_RADIUS = 120 };
    int found;
    u32 distance;
    int category;
    int is_six, is_four;
    void* spawned;
    int a, b, c;
    int red, green, blue;
    int handle;
    int sound_time, volume, offset;
    void* runtime;
    void* callback;
    SpawnRequest args;
    Vec3 candidate_pos, pos, search_pos;

    if (!skip_search) {
        iterator = fn_80201B9C();
        found = 0;
        distance = (enum SearchRadius)((*(int*)(base + 8) == 2 || *(int*)(base + 8) == 8)
                       ? DEFAULT_RADIUS : state->search_distance);
        while (iterator && !found) {
            void* candidate = fn_80201BC8(iterator);
            if (candidate) {
                int candidate_category;
                int candidate_state;
                fn_8011F114(&search_pos, candidate);
                candidate_pos = search_pos;
                candidate_category = fn_80201EB8(iterator);
                candidate_state = fn_80201B4C(iterator);
                if (*(int*)(base + 8) == candidate_category &&
                    fn_80178E94(&state->candidates[state->index], &candidate_pos) < distance &&
                    ((u32)candidate_state <= 1 || candidate_state == 2))
                    found = 1;
            }
            iterator = fn_80201BC0(iterator);
        }
        if (found) {
            ok = fn_80072A2C(&state->candidates[state->index],
                             &state->position, distance, 1);
            if (!ok && *(int*)(base + 8) != 2 && *(int*)(base + 8) != 8)
                ok = fn_80072A2C(&state->candidates[state->index],
                                 &state->position, 150, 1);
        } else {
            state->position = state->candidates[state->index];
        }
    } else {
        state->position = state->candidates[state->index];
    }
    if (!ok) goto done;

    category = fn_801D38E8(*(int*)(base + 4));
    if (fn_800CAC5C(state->types[state->index], category, &a, &b, &c) == 1) {
        is_six = state->types[state->index] == 6;
        is_four = state->types[state->index] == 4;
        fn_80043F44(&args);
        args.position = state->position;
        args.value10 = a;
        args.value14 = b;
        args.scale = scale;
        args.value24 = state->value38;
        args.value20 = state->value34;
        if (variant) {
            if (is_six || is_four)
                args.mode = 0;
            else
                args.mode = 0x28;
        } else {
            args.mode = 0x28;
        }
        spawned = fn_80034708(&args);
        if (spawned) {
            selected = fn_80201BC8(spawned);
            if (selected) {
                fn_801261F4();
                fn_80201D54(spawned, *(int*)(base + 8));
                fn_80201D24(spawned, 1);
                fn_802015A4(spawned);
                blue = lbl_80651F1C;
                green = lbl_80651F18;
                red = lbl_80651F14;
                fn_8012C62C(selected, 15, &red, &green, &blue, 4);
                fn_8011FA8C(selected, 0x100, 0);
                handle = fn_80201B54(spawned);
                *(int*)((u8*)state + 0x24) = handle;
                *(int*)((u8*)state + 0x80) = c;
                if (args.mode == 0x28) {
                    fn_8020123C(0x10, handle, handle, 0);
                    fn_8011FA8C(selected, 0, 0x100);
                    runtime = fn_80036D38(spawned);
                    if (fn_8012A100(selected, 0x8a))
                        *(int*)((u8*)runtime + 0x84) = 0;
                    else
                        *(int*)((u8*)runtime + 0x84) = c;
                }
                if (*(int*)((u8*)state + 0x18)) {
                    int effect;
                    if (is_six)
                        effect = 2;
                    else if (is_four)
                        effect = 3;
                    else
                        effect = 1;
                    fn_801DDB84(&state->position, category, effect, selected);
                }
                if ((!variant || (!is_six && !is_four)) && fn_8012A100(selected, 0x8a)) {
                    if (args.mode == 0x28) {
                        callback = fn_801294DC(selected, 0x8a, 0x20, 9);
                        if (callback) {
                            fn_80128C44(callback, fn_801DE8AC, 0);
                            fn_80128C28(callback, fn_801DE7FC, handle);
                        }
                    } else {
                        fn_801DE7A0(handle);
                    }
                }
                fn_8012B7A0(selected, args.scale);
                fn_80048708(selected);
                if (*(void (**)(void*, int))(base + 0x28))
                    (*(void (**)(void*, int))(base + 0x28))(object, *(int*)(base + 0x2c));
                fn_801E8328(1, spawned);

            } else {
                fn_801E8328(28, spawned);
                ok = 0;
            }
        } else {
            ok = 0;
        }
    } else {
        ok = 0;
    }
    if (!ok)
        goto done;

    sound_time = lbl_8064D5A8;
    volume = 100;
    if (sound_time - 20 < lbl_8064C308)
        volume = 20;
    lbl_8064C308 = sound_time;
    fn_801AC9F4(0x168, volume, &state->position, 2);
    category = state->types[state->index];
    switch (category) {
    case 6: offset = 125; break;
    case 4: offset = 500; break;
    default: offset = 350; break;
    }
    pos = state->position;
    pos.z += offset;
    fn_8014F3A4(&pos, (u8)fn_801CEB2C(*(int*)(base + 4)),
                 fn_801D3A34(*(int*)(base + 4), 0x35),
                 fn_801D3A34(*(int*)(base + 4), 0x4e), (u8*)state + 0x84);
done:
    return selected != 0;
}
