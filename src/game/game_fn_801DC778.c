typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* NonMatching: honest partial reconstruction. In addition to cleanup and the
 * terminal states, this recovers the complete 40..120 and 141..153 position
 * updates and four repeated particle-construction states. The large 151..153
 * descriptor construction remains incomplete. */

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Payload {
    short position[3];
    short pad06[5];
    void* effects[3];
    u8 pad1C[0x18];
    void* particles[3];
    u8 pad40[0x7C];
} Payload;

typedef struct Object {
    u8 pad00[4];
    u32 type;
    u32 owner;
    u8 pad0C[0x38];
    void* linked;
    u8 pad48[0x74];
    Payload payload;
    u8 pad178[0xE7C];
    u16 state;
} Object;

extern int lbl_8064D18C;
extern short fn_801CEB2C(u32);
extern void fn_80190500(void*, int);
extern void fn_801FE22C(void*);
extern void fn_801A9E40(int);
extern void fn_801D0E78(Object*);
extern void fn_8017E804(Payload*, short*, int);
extern void fn_8017DC88(Payload*, short*, int);
extern void* fn_8017FDA8(void*, int);
extern void fn_801FDEB4(void*, Vec3*);
extern void fn_801FDF74(void*, u32);
extern int fn_801D3A34(u32, int);
extern void fn_801D38E8(u32);
extern void* fn_801D3974(void);
extern void* fn_8014E9B0(void*, Vec3*, u8, int, void*, int, int, int);
extern void* fn_80156938(void*);
extern void fn_801858E0(void*);
extern void fn_801D38BC(u32, void*, void*);
extern void fn_80185AE8(void);
extern void fn_801E8328(int, void*);
extern void fn_80180CE4(void*, int);
extern void fn_80180CC8(void*, void*);
extern void* memcpy(void*, const void*, u32);
extern u8 lbl_802FC5BC[];
extern u32 lbl_80651EF4;
extern u16 lbl_80651EF8;

void fn_801DC778(Object* object)
{
    Payload* payload = &object->payload;
    int count = fn_801CEB2C(object->type);
    int i;

    if (object->owner != lbl_8064D18C) {
        if (object->state <= 0x99) {
            for (i = 0; i < (short)count; i++) {
                if (payload->effects[i] != 0) {
                    fn_80190500(payload->effects[i], 0);
                }
            }
        }
        if (object->linked != 0) {
            fn_801FE22C(object->linked);
        }
        fn_801A9E40(-1);
        fn_801D0E78(object);
        return;
    }

    if (object->state >= 40 && object->state <= 120) {
        Vec3 position;
        fn_8017E804(payload, &payload->pad06[0], 5 - ((object->state - 40) >> 4));
        position.x = payload->position[0];
        position.y = payload->position[1];
        position.z = payload->position[2];
        if (object->linked != 0) {
            fn_801FDEB4(object->linked, &position);
        }
        for (i = 0; i < (short)count; i++) {
            if (payload->effects[i] != 0) {
                short* effect = fn_8017FDA8(payload->effects[i], 0);
                effect[2] = payload->position[2];
            }
        }
    } else if (object->state > 140 && object->state < 154) {
        short next[3];
        next[2] = payload->pad06[3];
        fn_8017DC88(payload, next, 2);
        payload->pad06[3] = next[2];
        {
            Vec3 position;
            position.x = payload->position[0];
            position.y = payload->position[1];
            position.z = payload->position[2];
            if (object->linked != 0) {
                fn_801FDEB4(object->linked, &position);
            }
        }
        for (i = 0; i < (short)count; i++) {
            if (payload->effects[i] != 0) {
                short* effect = fn_8017FDA8(payload->effects[i], 0);
                effect[2] = payload->position[2];
            }
        }
    }

    switch (object->state) {
    case 10:
    {
        Vec3 position;
        position.x = payload->position[0];
        position.y = payload->position[1];
        position.z = payload->position[2];
        fn_8014E9B0(&payload->pad40[0], &position, (u8)count,
                    fn_801D3A34(object->type, 57), lbl_802FC5BC + 12,
                    16, 4, 0);
        break;
    }
    case 25:
    {
        Vec3 position;
        position.x = payload->position[0];
        position.y = payload->position[1];
        position.z = payload->position[2];
        fn_8014E9B0(&payload->pad40[0], &position, (u8)count,
                    fn_801D3A34(object->type, 61), lbl_802FC5BC + 12,
                    16, 4, 1);
        break;
    }
    case 40:
    {
        Vec3 position;
        void* config;
        void* particle;
        fn_801D38E8(object->type);
        config = fn_801D3974();
        position.x = payload->position[0];
        position.y = payload->position[1];
        position.z = payload->position[2];
        particle = fn_8014E9B0(&payload->pad40[0], &position, (u8)count,
                               65, &config, 16, 4, 1);
        payload->particles[0] = particle != 0 ? fn_80156938(particle) : 0;
        break;
    }
    case 55:
    {
        Vec3 position;
        void* particle;
        position.x = payload->position[0];
        position.y = payload->position[1];
        position.z = payload->position[2];
        particle = fn_8014E9B0(&payload->pad40[0], &position, (u8)count,
                               fn_801D3A34(object->type, 57),
                               lbl_802FC5BC + 12, 16, 4, 0);
        payload->particles[1] = particle != 0 ? fn_80156938(particle) : 0;
        break;
    }
    case 70:
    {
        Vec3 position;
        void* particle;
        position.x = payload->position[0];
        position.y = payload->position[1];
        position.z = payload->position[2];
        particle = fn_8014E9B0(&payload->pad40[0], &position, (u8)count,
                               fn_801D3A34(object->type, 57),
                               lbl_802FC5BC + 12, 16, 4, 0);
        payload->particles[2] = particle != 0 ? fn_80156938(particle) : 0;
        break;
    }
    case 121:
        payload->pad06[2] -= 200;
        break;
    case 151:
    case 152:
    {
        u8* descriptor = (u8*)payload + 0xF0;
        struct {
            u32 word;
            u16 half;
        } init;

        init.word = lbl_80651EF4;
        init.half = lbl_80651EF8;
        fn_801858E0(descriptor);
        fn_801D38E8(object->type);
        descriptor[1] = 100;
        *(u16*)(descriptor + 8) = 60;
        *(u16*)(descriptor + 6) = 84;
        descriptor[3] = -10;
        fn_801D38BC(object->type, descriptor + 0x78, descriptor + 4);
        descriptor[0x14] = 50;
        *(u16*)(descriptor + 0x1C) = 250;
        descriptor[0x18] |= 2;
        descriptor[0x19] = 4;
        *(void**)(descriptor + 0x90) = fn_80185AE8;
        *(u32*)(descriptor + 0x98) = *(u32*)((u8*)object + 0x38);
        *(u32*)(descriptor + 0x9C) = *(u32*)((u8*)object + 0x3C);
        *(u32*)(descriptor + 0xA0) = *(u32*)((u8*)object + 0x40);
        memcpy(descriptor + 0xA4, &init, 6);
        *(u32*)(descriptor + 0x94) = 0;
        descriptor[0xAA] = 4;
        fn_801E8328(16, descriptor);
        for (i = 0; i < 3; i++) {
            if (payload->particles[i] != 0) {
                fn_80180CE4(payload->particles[i], 1);
                fn_80180CC8(payload->particles[i], (u8*)object + 0x38);
            }
        }
        break;
    }
    case 173:
        if (object->linked != 0) {
            fn_801FDF74(object->linked, 0x593E0);
        }
        break;
    case 193:
        fn_801A9E40(-1);
        fn_801D0E78(object);
        break;
    }
}
