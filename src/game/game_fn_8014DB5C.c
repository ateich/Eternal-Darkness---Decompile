typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Coord3 {
    short x, y, z;
} Coord3;

typedef struct QueryResult {
    u8 pad0[8];
    float position[3];
    float rotation[3];
} QueryResult;

extern void* lbl_8064D18C;
extern float lbl_80650514;

extern void *fn_80201814();
extern void *fn_80201BC8();
extern void *fn_80201B8C();
extern int fn_80201EB8();
extern int fn_8012FA54(void*, int);
extern int fn_8011F6A4(void*, int, int, int, QueryResult*, int);
extern void fn_8017F794(void*);
extern void fn_80147EC4(void*);
extern void fn_8017F7D8(void);
extern int fn_800676C8(u8);
extern void fn_80052310(int, Coord3*);
extern void* fn_801809A0(void*);
extern void* fn_80149E04(void);
extern void fn_801489B4(void*, void*);
extern void fn_8014E20C(void*, void*);
extern void fn_80184740(void*);
extern void* fn_8017FDF4(void*);
extern void fn_80149B38(void*);
extern void* fn_80155DB4(void*);
extern void* fn_80148300(void*, void*, void*);
extern void fn_801568B8(void*, void*);
extern void fn_80149EB8(void*);
extern void fn_80149E28(void);

static int valid_mode(void* resource, int mode)
{
    void* owner = fn_80201BC8(resource);

    if (mode == 1)
        return !fn_8012FA54(owner, 1);
    if (mode >= 0 && mode < 4)
        return fn_8012FA54(owner, 1) && !fn_8012FA54(owner, mode);
    return 0;
}

void fn_8014DB5C(void* state)
{
    u8* self = state;
    u16 event = *(u16*)(self + 0x132C);

    switch (event) {
    case 2:
    case 64:
    case 128:
    case 192:
    case 256: {
        void* resource = fn_80201814(*(void**)(self + 0x394));
        void* owner;
        void* info;
        QueryResult result;
        Coord3 sound_position;
        u8* effect = self + 8;
        int sound = 50;

        *(void**)(self + 0x9C) = 0;
        if (resource == 0)
            break;
        owner = fn_80201BC8(resource);
        info = fn_80201B8C(resource);
        if (!valid_mode(resource, *(int*)(self + 0x39C)))
            break;
        if (fn_80201EB8(resource) != (int)lbl_8064D18C || owner == 0)
            break;
        if (fn_8011F6A4(owner, *(int*)(self + 0x3A0),
                        *(int*)(self + 0x39C), -1, &result, 1) == -1)
            break;

        *(float*)(effect + 0x98) = result.position[0];
        *(float*)(effect + 0x9C) = result.position[1];
        *(float*)(effect + 0xA0) = result.position[2];
        *(short*)(effect + 0xA4) = (short)(lbl_80650514 * result.rotation[0]);
        *(short*)(effect + 0xA6) = (short)(lbl_80650514 * result.rotation[1]);
        *(short*)(effect + 0xA8) = (short)(lbl_80650514 * result.rotation[2]);

        fn_8017F794(effect);
        effect[0] = self[0x398];
        effect[1] = 2;
        *(u16*)(effect + 0x14) = self[0x39A];
        *(u32*)(effect + 0x1D) = *(u32*)(self + 0x3A4);
        *(void**)(effect + 0x94) = 0;
        *(void (**)(void))(effect + 0x90) = fn_8017F7D8;
        effect[0xAA] = 4;
        fn_80147EC4(effect);

        sound_position.x = (short)result.position[0];
        sound_position.y = (short)result.position[1];
        sound_position.z = (short)result.position[2];
        if (fn_800676C8(*((u8*)info + 0x9F)))
            sound = 84;
        fn_80052310(sound, &sound_position);
        if (*(void**)(effect + 0x94) != 0)
            *(void**)(self + 0x390) = fn_801809A0(*(void**)(effect + 0x94));
        break;
    }

    case 3:
    case 65:
    case 129:
    case 193:
    case 257: {
        void* resource = fn_80201814(*(void**)(self + 0x394));
        void* owner = 0;
        u8* work = self + 0x2C8;
        u32 value = *(u32*)(self + 0x3A4);

        if (resource != 0 && valid_mode(resource, *(int*)(self + 0x39C)) &&
            fn_80201EB8(resource) == (int)lbl_8064D18C)
            owner = fn_80201BC8(resource);
        ((u8*)&value)[3] = 0xE0;
        if (owner == 0 || *(void**)(self + 0x9C) == 0)
            break;

        owner = fn_801809A0(*(void**)(self + 0x9C));
        if (owner == *(void**)(self + 0x390)) {
            *(void**)(work + 0xC0) = fn_80149E04();
            if (*(void**)(work + 0xC0) != 0) {
                fn_801489B4(work, *(void**)(work + 0xC0));
                *(void (**)(void*, void*))(work + 0x98) = fn_8014E20C;
                *(void**)(work + 0x94) = 0;
                fn_80184740(work);
                *(u16*)(work + 4) = 0xFFFF;
                work[1] = 1;
                work[3] = (u8)-8;
                *(u32*)(work + 0x2C) = value;
                work[0x14] = 0x10;
                *(void**)(work + 0x28) = fn_8017FDF4(*(void**)(self + 0x9C));
                work[0xBC] = 4;
                *(u8*)(*(u8**)(work + 0xC0)) = self[8];
                fn_80149B38(*(void**)(work + 0xC0));
                *(void**)(work + 0xA8) = owner;
                owner = fn_80155DB4(*(void**)(self + 0x9C));
                if (owner != 0 && fn_80148300(owner, work, *(void**)(work + 0xC0)))
                    fn_801568B8(owner, (void*)0x801487AC);
                else {
                    fn_80149EB8(*(void**)(work + 0xC0));
                    *(void**)(work + 0xC0) = 0;
                }
            }
        }
        *(void**)(self + 0x9C) = 0;
        break;
    }

    case 260:
        fn_80149E28();
        break;
    }
}
