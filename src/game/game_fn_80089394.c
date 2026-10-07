typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct SVec3 {
    s16 x, y, z;
} SVec3;

typedef struct Color {
    u8 r, g, b, a;
} Color;

typedef struct EventState {
    u8 pad00[0x8];
    s16 count;
} EventState;

typedef struct Memory {
    u8 pad00[0x16];
    u8 kind;
    u8 pad17;
    s16 radius;
    u8 pad1A[0x2];
    Color color1C;
    Color color20;
    u8 pad24[0x90 - 0x24];
    void (*callback)(void);
    void *object;
    Vec3 position;
    SVec3 offset;
    u8 mode;
    u8 padAB[0x1740 - 0xAB];
    u32 identifier;
    u8 pad1744[0x1780 - 0x1744];
    int handle;
} Memory;

typedef struct Runtime {
    u8 pad[0x15C];
    Memory *memory;
} Runtime;

typedef struct Work {
    u8 pad00[0x15];
    u8 id;
    u8 pad16[0x38 - 0x16];
    int object_id;
    u8 pad3C[0xC4 - 0x3C];
    Runtime *runtime;
} Work;

typedef struct Node {
    u8 pad00[0x38];
    Vec3 position;
    u8 pad44[0x4C - 0x44];
} Node;

typedef struct Config {
    u8 pad00[0x34];
    u16 count;
    u8 pad36[0x2];
    Node *nodes;
} Config;

typedef struct Output {
    u8 pad00[0x8];
    Vec3 position;
    u8 pad14[0x24 - 0x14];
} Output;

extern EventState *fn_8006ED3C(Work *, int, int *);
extern void fn_8006BEE4(EventState *, void (*)(void));
extern void fn_8006EA4C(void);
extern int fn_8006D548();
extern void fn_8008799C(u8);
extern int fn_800879E0(u8);
extern void *fn_80201814(int);
extern void *fn_80201BC8();
extern int fn_8011F6A4(void *, int, int, int, Output *, int);
extern Config *fn_8015C390(int);
extern void fn_8019C26C(SVec3 *, SVec3 *, Vec3 *, Vec3 *, Vec3 *);
extern void fn_8017ED64(Memory *);
extern void fn_8017EDB4(void);
extern int fn_801E79FC(void *, int);
extern void fn_80147EC4(Memory *);
extern u32 fn_801809A0(void *);
extern int fn_8012FF34(void *, Vec3 *, int, int);
extern void fn_801302BC(void *, u16);
extern void fn_801E7DCC(const char *, ...);
extern void *memcpy(void *, const void *, unsigned int);

extern Vec3 lbl_80239548;
extern SVec3 lbl_806519B0;
extern Color lbl_8064EB98;
extern Color lbl_8064EB9C;
extern void *lbl_8064C4E0;
extern u8 lbl_802FC5BC[];
extern char lbl_802450F4[];

int fn_80089394(Work *work)
{
    Output output;
    Vec3 hits[3];
    Vec3 position;
    Vec3 out2;
    Vec3 out1;
    SVec3 offset;
    SVec3 source;
    SVec3 target;
    int type;
    int index;
    Color color1C;
    Color color20;
    EventState *state;
    void *scene;
    Memory *memory;
    Config *config;
    int result;

    result = 0;
    offset = lbl_806519B0;
    type = 0;
    color1C = lbl_8064EB98;
    color20 = lbl_8064EB9C;
    position = lbl_80239548;
    state = fn_8006ED3C(work, 1, &index);
    memory = work->runtime->memory;
    memory->object = 0;
    state->count++;
    fn_80201814(work->object_id);
    scene = fn_80201BC8();
    if (state->count > 0x40) {
        fn_8006BEE4(state, fn_8006EA4C);
    }

    if (memory->handle == -1) {
        if (fn_8011F6A4(scene, 0, 1, -1, &output, 1) != -1) {
            position = output.position;
        }
        memory->handle = fn_8006D548(2, 0x100, 4, &position, &type, 0, 0);
    } else {
        memory->handle = fn_8006D548(2, 0x100, 1, &position, &type, 0, memory->handle);
    }

    if (memory->handle != -1) {
        config = fn_8015C390(2);
        if (config != 0 && config->nodes != 0 && config->count != 0 &&
            memory->handle < config->count) {
            Node *node = &config->nodes[memory->handle];
            source.x = position.x;
            source.y = position.y;
            source.z = position.z;
            target.x = node->position.x;
            target.y = node->position.y;
            target.z = node->position.z;
            fn_8019C26C(&source, &target, hits, &out1, &out2);
            offset.z = 0;
            offset.x = hits[0].x - hits[1].x;
            offset.y = hits[0].y - hits[1].y;
        }
        fn_8017ED64(memory);
        memory->callback = fn_8017EDB4;
        memory->position = position;
        memory->kind = 4;
        memory->color1C = color1C;
        memory->color20 = color20;
        if (fn_801E79FC(lbl_8064C4E0, 0x2ED) != 0) {
            memory->color1C = *(Color *)(lbl_802FC5BC + 0x24);
        }
        switch (type) {
        case 0x30:
            memory->radius = 400;
            break;
        case 0x60:
        case 0x90:
            memory->radius = 600;
            break;
        default:
            memory->radius = 400;
            break;
        }
        memcpy(&memory->offset, &offset, 6);
        memory->object = 0;
        memory->mode = 4;
        memory->identifier = 0;
        fn_80147EC4(memory);
        if (memory->object != 0) {
            memory->identifier = fn_801809A0(memory->object);
            fn_8008799C(work->id);
            if (fn_8012FF34(scene, &position, 4, 2) != 0) {
                fn_801302BC(scene, fn_800879E0(work->id));
            }
        } else {
            fn_801E7DCC(lbl_802450F4, 0);
        }
        result = 1;
        memory->handle = -1;
    }
    return result;
}
