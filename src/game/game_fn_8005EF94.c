typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

#pragma use_lmw_stmw on

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Segment {
    Vec3 first, second, axis;
    float length;
} Segment;

typedef struct InnerObject {
    u8 pad[0xB8];
    void *object;
} InnerObject;

typedef struct SVec3 {
    s16 x, y, z;
} SVec3;

typedef struct Pair {
    s32 first, second;
} Pair;

typedef struct RuntimeObject {
    u8 pad0[8];
    void *object;
    u8 padC[0x18];
    InnerObject *inner;
    u8 pad28[0x64];
    u32 *flags;
    u8 pad90[4];
    s32 type;
    u8 pad98[6];
    u8 mode;
    u8 variant;
} RuntimeObject;

typedef struct ObjectData {
    u8 pad[0x86];
    s16 timer;
} ObjectData;

extern s32 lbl_8064D18C;
extern s32 lbl_8064C888;
extern s32 lbl_8064C88C;
extern s8 lbl_8064C590;
extern const float lbl_8064E5B8;
extern const float lbl_8064E5BC;
extern const u32 lbl_8064E5C8;
extern const u32 lbl_8064E5CC;
extern const float lbl_8064E5D0;
extern const float lbl_8064E5D4;
extern const float lbl_8064E5D8;
extern Pair lbl_80243CE4[];
extern Pair lbl_80243D24[];
extern u8 lbl_8030F820[];

extern void *fn_80201B9C();
extern int fn_80201B54();
extern void *fn_80201BC8();
extern void *fn_80201B8C();
extern void *fn_80201BC0(void *);
extern int fn_80201EB8();
extern void fn_80201E78(Vec3 *, void *);
extern void fn_8011F114();
extern void fn_8012AB2C(void *);
extern unsigned long long fn_8020123C();
extern u32 fn_80178F14(s32, s32, s32, s32, s32, s32);
extern void fn_8013F4D0(void *, Vec3 *, Vec3 *);
extern void *fn_8014317C(void *, Vec3 *, void *, s32, s32);
extern s32 fn_801DA27C(s32);
extern void *fn_80201814(s32);
extern s32 fn_80066BB8(void *, s32);
extern s32 fn_80066D04(void *, s32);
extern s32 fn_8005EE9C(s32, s32, s32 *);
extern void *fn_801D38E8(void *);
extern void fn_8002D8C8(void *, s16 *, s16 *, s32 *);
extern void fn_8014BEC4(s32, Vec3 *, void *, void *, s32);
extern void fn_8005F758(void *, s32, Vec3 *, s32, s32, s32, u8, u8, s32, u8);
extern void *fn_801D62D0(u32, s32, s32, u32, s32, s32, s32, s32, s32, u8,
                        u8, u8, u8, u8, s32, s32, u8, u8, u8, u8,
                        u8, s32, u16, s32, s32, u8);
extern void fn_801AAE68(float, s32, s32, s32, Vec3 *, s32, s32, s32, u16, s32);
extern s32 fn_801D39E0(s32);
extern void fn_8020104C(s32, s32, s32, s32, float);
extern void fn_801E2A48(void *, Vec3 *, s32 *, s32);

s32 fn_8005EF94(void *head, s32 limit, s32 *count, s32 create,
                s32 amount)
{
    s32 main_flag;
    void *selected;
    void *main_object;
    s32 best;
    s32 result;
    s32 did_work;
    void *node;
    s32 main_id;
    RuntimeObject *main_state;
    Vec3 main_position;
    Vec3 other_position;
    Vec3 query_position;
    Segment volume;
    s32 state;
    s32 selection_state;
    s16 kind;
    s32 collision;
    s32 last_node_id;

    node = fn_80201B9C();
    selected = 0;
    best = limit == -1 ? -1 : limit;
    result = 0;
    did_work = 0;
    main_id = fn_80201B54(head);
    main_object = fn_80201BC8(head);
    main_state = fn_80201B8C(head);
    last_node_id = 0;
    fn_8011F114(&main_position, main_object);
    fn_8012AB2C(main_object);
    switch (main_state->type) {
    case 1: kind = 9; break;
    case 2: kind = 5; break;
    case 3: kind = 3; break;
    }

    {
        main_flag = main_state && main_state->flags ?
            ((*main_state->flags >> 22) & 1) : 0;
        if (count && !create) {
            *count = 0;
        }

        while (node) {
            s32 owner = fn_80201EB8(node);
            s32 node_id = fn_80201B54(node);
            s32 i;
            void *object = fn_80201BC8(node);
            void *spawn;
            s32 slot;
            RuntimeObject *object_state = fn_80201B8C(node);
            s32 object_flag = object_state && object_state->flags ?
                (s32)((*object_state->flags >> 22) & 1) : 0;
            last_node_id = node_id;

            if (lbl_8064D18C == owner && object && object_state && head != node &&
                ((object_state->mode == 2 && object_state->type != main_state->type) ||
                 object_state->mode == 1 || main_flag || object_flag)) {
                if ((u32)(fn_8020123C(0x3B, main_id, node_id, 2) & 0xFFFFFFFF) == 1) {
                    s32 made = 0;
                    switch (object_state->variant) {
                    case 12:
                        limit *= 2;
                        /* fall through */
                    case 1: case 3: case 4: case 5: case 8: case 10: case 11:
                    case 24:
                    {
                        u32 distance;
                        fn_80201E78(&other_position, node);
                        distance = fn_80178F14((s32)main_position.x,
                            (s32)main_position.y, (s32)main_position.z,
                            (s32)other_position.x, (s32)other_position.y,
                            (s32)other_position.z);
                        if (distance < (u32)best || (!selected && distance < (u32)limit)) {
                            best = distance;
                            selected = node;
                        }
                        if (!create && count && distance < (u32)limit) {
                            (*count)++;
                        }
                        if (create && distance < (u32)limit) {
                            float saved = main_position.z;
                            main_position.z = other_position.z =
                                other_position.z + lbl_8064E5D0;
                            fn_8013F4D0(&volume, &main_position, &other_position);
                            other_position.z -= lbl_8064E5D0;
                            main_position.z = saved;
                            if (!fn_8014317C(&volume, &query_position,
                                            main_object, 0, 3)) {
                                selection_state = 0;
                                {
                                    spawn = fn_80201814(fn_801DA27C(node_id));
                                    did_work = 1;
                                    made = 1;
                                    i = 0;
                                    for (slot = 0; i < amount;) {
                                        s32 values[4] = { 1, 0, 2, 3 };
                                        s32 chosen = 1;
                                        s32 candidate;
                                        s32 blocked = 0;
                                        candidate = values[slot];
                                        if (fn_80066BB8(object, candidate)) chosen = candidate;
                                        {
                                            s32 two = fn_80066D04(head, 2);
                                            s32 three = fn_80066D04(head, 3);
                                            state = fn_8005EE9C(!three, !two, &selection_state);
                                        }
                                        {
                                            RuntimeObject *spawn_state = spawn ? fn_80201B8C(spawn) : 0;
                                            InnerObject *inner = spawn_state ? spawn_state->inner : 0;
                                            if (spawn && inner) {
                                                void *collision_object = fn_801D38E8(inner->object);
                                                s16 timer = 0;
                                                collision = 0;
                                                fn_8002D8C8(collision_object, &kind,
                                                            &timer, &collision);
                                                if (collision == 2) blocked = 1;
                                                else if (collision == 1 && !(i & 1)) blocked = 1;
                                            }
                                        }
                                        if (blocked) {
                                            SVec3 output_first;
                                            Vec3 output_second;
                                            s32 bad;
                                            bad = ++lbl_8064C888;
                                            lbl_8064C888 = bad < 0 || bad >= 5 ? 0 : lbl_8064C888;
                                            fn_8014BEC4(node_id, &main_position,
                                                        &output_first, &output_second, 0);
                                            fn_8005F758(lbl_8030F820 + lbl_8064C888 * 0xC4,
                                                main_state->type, &output_second, main_id,
                                                lbl_80243D24[state].first,
                                                lbl_80243CE4[state].first, 5, 2, 0, 4);
                                        } else {
                                            fn_801D62D0(main_id, lbl_80243D24[state].first,
                                                lbl_80243CE4[state].first, node_id, 0, chosen,
                                                main_state->type, 0, 0, 3, 10, 4, 2,
                                                1, 0, 1, 0x11, 8, 4, 0x20, 0, 0, 0x1E, 0x42040, 0x2030, 4);
                                        }
                                        if (lbl_8064C590++ < 2)
                                            fn_801AAE68(lbl_8064E5BC, 0xBE, 100, 0,
                                                &main_position, 2, 2, 0,
                                                (u16)lbl_8064D18C, 0);
                                        ++i;
                                        slot = slot >= 3 ? 3 : slot + 1;
                                    }
                                }
                            }
                            if (lbl_8064D18C == 0x29) {
                                u32 pair[2];
                                pair[0] = lbl_8064E5C8;
                                pair[1] = lbl_8064E5CC;
                                ++lbl_8064C88C;
                                lbl_8064C88C = !lbl_8064C88C;
                                ((ObjectData *)main_state->object)->timer =
                                    pair[lbl_8064C88C] + 0xB4;
                            } else {
                                ((ObjectData *)main_state->object)->timer = 0xB4;
                            }
                            if (made) {
                                fn_8020104C(0xDF, main_id, main_id, last_node_id,
                                            lbl_8064E5D4);
                            }
                        }
                        break;
                    }
                    }
                }
            }
            node = fn_80201BC0(node);
        }
    }
    if (did_work && create) {
        s32 id = fn_801D39E0(main_state->type);
        main_position.z += lbl_8064E5D8;
        fn_801E2A48(main_state->object, &main_position, &id, 6);
    }
    if (selected) result = fn_80201B54(selected);
    return result;
}
