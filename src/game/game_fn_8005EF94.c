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

typedef struct Pair {
    s32 first, second;
} Pair;

typedef struct RuntimeObject {
    u8 pad0[8];
    void *object;
    u8 padC[0x80];
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
extern const Pair lbl_80243CE4[];
extern const Pair lbl_80243D24[];
extern u8 lbl_8030F820[];

extern void *fn_80201B9C(void *);
extern s32 fn_80201B54(void *);
extern void *fn_80201BC8(void *);
extern RuntimeObject *fn_80201B8C(void *);
extern void *fn_80201BC0(void *);
extern s32 fn_80201EB8(void *);
extern void fn_80201E78(Vec3 *, void *);
extern void fn_8011F114(Vec3 *, void *);
extern void fn_8012AB2C(void *);
extern unsigned long long fn_8020123C(s32, s32, s32, s32);
extern u32 fn_80178F14(s32, s32, s32, s32, s32, s32);
extern void fn_8013F4D0(void *, Vec3 *, Vec3 *);
extern void *fn_8014317C(void *, Vec3 *, void *, s32, s32);
extern void fn_801DA27C(s32);
extern void *fn_80201814(void);
extern s32 fn_80066BB8(void *, s32);
extern s32 fn_80066D04(void *, s32);
extern s32 fn_8005EE9C(s32, s32, s32 *);
extern void *fn_801D38E8(void *);
extern void fn_8002D8C8(void *, s16 *, s16 *, s32 *);
extern void fn_8014BEC4(s32, Vec3 *, void *, void *, s32);
extern void fn_8005F758(void *, s32, void *, s32, s32, s32, s32, s32, s32,
                       s32, s32, s32);
extern void fn_801D62D0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                       s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                       s32, s32, s32, s32, s32, s32);
extern void fn_801AAE68(float, s32, s32, s32, Vec3 *, s32, s32, s32, u16, s32);
extern s32 fn_801D39E0(s32);
extern void fn_8020104C(s32, s32, s32, s32, float);
extern void fn_801E2A48(void *, Vec3 *, s32 *, s32);

static const s32 choices[4] = { 1, 0, 2, 3 };

s32 fn_8005EF94(void *head, s32 limit, s32 *count, s32 create, s32 amount)
{
    void *node = fn_80201B9C(head);
    void *selected = 0;
    s32 best = limit == -1 ? -1 : limit;
    s32 result = 0;
    s32 made = 0;
    s32 did_work = 0;
    s32 main_id = fn_80201B54(head);
    void *main_object = fn_80201BC8(head);
    RuntimeObject *main_state = fn_80201B8C(head);
    Vec3 main_position;
    Vec3 other_position;
    Vec3 query_position;
    Vec3 volume;
    s32 state = 0;
    s16 timer = 0;
    s16 kind;
    s32 collision = 0;
    s32 last_node_id = 0;
    u32 pair[2];
    s32 values[4];
    s32 outputs[4];

    fn_8011F114(&main_position, main_object);
    fn_8012AB2C(main_object);
    switch (main_state->type) {
    case 1: kind = 9; break;
    case 2: kind = 5; break;
    case 3: kind = 3; break;
    }

    {
        s32 main_flag = main_state && main_state->flags ?
            ((*main_state->flags >> 22) & 1) : 0;
        if (count && !create) {
            *count = 0;
        }

        while (node) {
            s32 owner = fn_80201EB8(node);
            s32 node_id = fn_80201B54(node);
            void *object = fn_80201BC8(node);
            RuntimeObject *object_state = fn_80201B8C(node);
            s32 object_flag = object_state && object_state->flags ?
                ((*object_state->flags >> 22) & 1) : 0;
            last_node_id = node_id;

            if (lbl_8064D18C == owner && object && object_state && head != node &&
                ((object_state->mode != 2 || object_state->type == main_state->type) &&
                 (object_state->mode == 1 || main_flag || object_flag))) {
                if (object_state->variant <= 0x18 &&
                    (u32)fn_8020123C(0x3B, main_id, node_id, 2) == 1) {
                    s32 accept = 0;
                    switch (object_state->variant) {
                    case 1: case 3: case 4: case 5: case 8: case 10: case 11:
                    case 12: case 24:
                        accept = 1;
                        break;
                    }
                    if (accept) {
                        u32 distance;
                        if (object_state->variant == 12) limit *= 2;
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
                            main_position.z -= lbl_8064E5D0;
                            other_position.z = saved;
                            if (!fn_8014317C(&volume, &query_position,
                                            main_object, 0, 3)) {
                                s32 i, slot = 0;
                                fn_801DA27C(node_id);
                                {
                                    void *spawn = fn_80201814();
                                    made = 1;
                                    did_work = 1;
                                    for (i = 0; i < amount; i++) {
                                        s32 chosen;
                                        s32 blocked = 0;
                                        values[0] = choices[0]; values[1] = choices[1];
                                        values[2] = choices[2]; values[3] = choices[3];
                                        chosen = values[slot];
                                        if (fn_80066BB8(object, chosen)) chosen = 1;
                                        state = fn_8005EE9C(!fn_80066D04(head, 3),
                                                           !fn_80066D04(head, 2), &state);
                                        if (spawn) {
                                            RuntimeObject *spawn_state = fn_80201B8C(spawn);
                                            void *inner = spawn_state ? spawn_state->object : 0;
                                            if (spawn && inner) {
                                                fn_8002D8C8(fn_801D38E8(inner), &kind,
                                                            &timer, &collision);
                                                if (collision == 2 ||
                                                    (collision == 1 && !(i & 1))) blocked = 1;
                                            }
                                        }
                                        if (blocked) {
                                            s32 bad = ++lbl_8064C888;
                                            if (bad < 0 || bad >= 5) lbl_8064C888 = 0;
                                            fn_8014BEC4(node_id, &main_position,
                                                        outputs, outputs + 2, 0);
                                            fn_8005F758(lbl_8030F820 + lbl_8064C888 * 0xC4,
                                                main_state->type, &outputs[2], main_id,
                                                lbl_80243D24[state].first, node_id,
                                                lbl_80243CE4[state].first, 5, 2, 0, 4, 0);
                                        } else {
                                            fn_801D62D0(main_id, lbl_80243D24[state].first,
                                                lbl_80243CE4[state].first, node_id, 0, chosen,
                                                0, 0, main_state->type, 8, 0, 0, 3, 10, 4, 2,
                                                1, 0, 1, 0x11, 8, 4, 0, 0x1E, 0x42040, 0x2030);
                                        }
                                        if (lbl_8064C590++ < 2)
                                            fn_801AAE68(lbl_8064E5BC, 0xBE, 100, 0,
                                                &main_position, 2, 2, 0,
                                                (u16)lbl_8064D18C, 0);
                                        slot = slot >= 3 ? 3 : slot + 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            node = fn_80201BC0(node);
        }
    }
    if (did_work && create) {
        pair[0] = lbl_8064E5C8;
        pair[1] = lbl_8064E5CC;
        if (lbl_8064D18C == 0x29) {
            lbl_8064C88C = !++lbl_8064C88C;
            ((ObjectData *)main_state->object)->timer = pair[lbl_8064C88C] + 0xB4;
        } else {
            ((ObjectData *)main_state->object)->timer = 0xB4;
        }
        fn_8020104C(0xDF, main_id, main_id, last_node_id, lbl_8064E5D4);
    }
    if (made && create) {
        s32 id = fn_801D39E0(main_state->type);
        main_position.z += lbl_8064E5D8;
        fn_801E2A48(main_state->object, &main_position, &id, 6);
    }
    if (selected) result = fn_80201B54(selected);
    return result;
}
