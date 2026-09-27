typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct Entry {
    char pad00[8];
    int active;
    char pad0C[12];
} Entry;
typedef struct Record {
    char pad00[0x2C];
    s16 position[3];
    char pad32[6];
    float angles[3];
    float scale;
    u32 flags;
} Record;
typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;
typedef struct FrameRecord {
    int field00;
    Vec3 position;
    char pad10[8];
    float value18;
    Vec3 direction;
} FrameRecord;
typedef struct FrameTable {
    char pad00[0x58];
    u16 count;
    char pad5A[2];
    void* records;
} FrameTable;



typedef struct RecordTable {
    char pad00[0x34];
    u16 count;
    char pad36[2];
    Record* records;
} RecordTable;
typedef struct Coord3 {
    s16 x;
    s16 y;
    s16 z;
} Coord3;


typedef struct PoolEntry {
    s16 id;
    s16 state;
    void* value04;
    void* value08;
    char pad0C[0xC];
} PoolEntry;
typedef struct RequestState {
    char pad000[0x11C];
    void* queue;
    char pad120[0x10];
    void* value130;
    char pad134[4];
    char data138[0x8000];
    u32 field8138;
    u32 field813C;
    s16 id;
    s8 flag142;
    s8 loaded;
    s8 active;
} RequestState;
typedef struct RequestGlobals {
    int current;
    int playing;
    int pad08;
    RequestState* volatile states[4];
} RequestGlobals;
typedef struct SourceInfo {
    char pad00[4];
    u32 data_offset;
    u32 work_offset;
} SourceInfo;
typedef struct TransitionState {
    char pad00[0x18];
    int pending;
    char pad1C[0x10];
} TransitionState;

Entry lbl_805B6E00[16];
PoolEntry lbl_805B6F80[4];
volatile RequestGlobals lbl_805B6FE0;
char lbl_805B6FFC[0x20];
TransitionState lbl_805B701C;
int lbl_805B7048[8];


extern void* memset(void*, int, unsigned int);


void fn_80158794(void)
{
    memset(lbl_805B6E00, 0, 384);
}




extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);
extern void fn_80217324(void);


Entry* fn_801587C4(void)
{
    u32 interrupts;
    int index = 0;
    Entry* entry;

    interrupts = OSDisableInterrupts();
    for (;;) {
        entry = &lbl_805B6E00[index];
        if (entry->active == 0) {
            entry->active = 1;
            break;
        }
        index++;
        if ((u32)index >= 16) {
            index = 0;
            OSRestoreInterrupts(interrupts);
            fn_80217324();
            interrupts = OSDisableInterrupts();
        }
    }
    OSRestoreInterrupts(interrupts);
    return entry;
}




void fn_80158850(Entry* entry)
{
    entry->active = 0;
}


int fn_8015885C(void)
{
    return 350016;
}


extern int fn_800460FC(void);
extern int fn_8015885C(void);
extern u8* lbl_8064D168;


u8* fn_80158868(u8* address)
{
    int count = fn_800460FC();
    int size = fn_8015885C();
    int i;

    for (i = 0; i < count; i++) {
        (&lbl_8064D168)[i] = address;
        address += size;
    }
    return address;
}




extern void* fn_8015C390(int);


void* fn_80158950(int key, u16* count)
{
    FrameTable* table = fn_8015C390(key);
    void* data = 0;

    if (table != 0) {
        if (count != 0) {
            *count = table->count;
        }
        data = table->records;
    } else {
        *count = 0;
    }
    return data;
}





extern void* fn_80158A44(int index, int key);


int fn_801589AC(int index, int key, Vec3* position, Vec3* direction,
                float* value)
{
    int found = 0;
    FrameRecord* record = fn_80158A44(index, key);

    if (record != 0) {
        found = 1;
        position->x = record->position.x;
        position->y = record->position.y;
        position->z = record->position.z;
        direction->x = record->direction.x;
        direction->y = record->direction.y;
        direction->z = record->direction.z;
        *value = record->value18;
    }
    return found;
}






void* fn_80158A44(int index, int key)
{
    void* result = 0;
    FrameTable* set;
    void* records;

    if (index != -1) {
        set = fn_8015C390(key);
        if (set != 0 && set->count != 0) {
            records = set->records;
            if (index >= 0 && index < set->count) {
                result = (char*)records + index * 0x2C;
            }
        }
    }
    return result;
}



extern Record* fn_80158C0C(int index, int key);
extern float fn_80179FE4(float*, int, float);


void* fn_80158ABC(int index, int key, float* value)
{
    void* result = 0;
    Record* record = fn_80158C0C(index, key);

    if (record != 0) {
        result = record->position;
        if (value != 0) {
            *value = fn_80179FE4(record->angles, 1, record->scale);
        }
    }
    return result;
}








int fn_80158B20(int index, int key, Vec3* position, Vec3* angles, float* scale)
{
    int result = 0;
    Record* record = fn_80158C0C(index, key);

    if (record != 0) {
        position->x = (float)record->position[0];
        position->y = (float)record->position[1];
        position->z = (float)record->position[2];
        if (angles != 0) {
            angles->x = record->angles[0];
            angles->y = record->angles[1];
            angles->z = record->angles[2];
        }
        if (scale != 0) {
            *scale = record->scale;
        }
        result = 1;
    }
    return result;
}








Record* fn_80158C0C(int index, int key)
{
    Record* result = 0;
    RecordTable* set;
    Record* records;
    Record* record;
    int i;

    if (index != -1) {
        set = fn_8015C390(key);
        if (set != 0 && set->count != 0) {
            records = set->records;
            record = records;
            if (index >= 0 && index < set->count) {
                result = &records[index];
            } else if (index == -2) {
                for (i = 0; i < set->count; i++, record++) {
                    if (record->flags & 0x10) {
                        result = record;
                        break;
                    }
                }
                if (result == 0) {
                    result = records;
                }
            }
        }
    }
    return result;
}




extern void* fn_80158ABC(int index, int key, float* value);
extern void fn_80179398(Coord3*, void*, float);


void* fn_80158CC8(int index, int key, void* output)
{
    float angle;
    Coord3 coord;
    void* result = fn_80158ABC(index, key, &angle);

    if (result != 0 && output != 0) {
        coord.x = 0;
        coord.y = -1;
        coord.z = 0;
        fn_80179398(&coord, output, angle);
    }
    return result;
}









extern u32 fn_80178F14(int, int, int, int, int, int);


int fn_80158D38(Vec3* position, int key, u32 mask, Vec3* output)
{
    int result;
    u32 best_distance;
    Record* best;
    RecordTable* set;
    int i;
    Record* record;

    result = 0;
    best = 0;
    set = fn_8015C390(key);

    if (set != 0 && set->count != 0) {
        record = set->records;

        for (i = 0; i < set->count; i++, record++) {
            if (record->flags & mask) {
                u32 distance = fn_80178F14(record->position[0], record->position[1],
                                          record->position[2], (int)position->x,
                                          (int)position->y, (int)position->z);
                if (best == 0 || distance < best_distance) {
                    best_distance = distance;
                    best = record;
                }
            }
        }
    }

    if (best != 0) {
        result = 1;
        output->x = (float)best->position[0];
        output->y = (float)best->position[1];
        output->z = (float)best->position[2];
    }
    return result;
}


void fn_80158E7C(int value)
{
    if (value == 0) {
        return;
    }
}


void fn_80158E84(void)
{
}




extern int lbl_8064D17C;


int fn_80158E88(int id)
{
    int i;

    for (i = 0; i < lbl_8064D17C; i++) {
        if (lbl_805B6F80[i].id == id) {
            return i;
        }
    }
    return -1;
}




extern int fn_80158E88(int id);
extern int fn_80159EEC(void);
extern void fn_80159DD0(int, int);


int fn_80158ECC(int id)
{
    int index = fn_80158E88(id);

    if (index == -1) {
        u32 interrupts;
        index = fn_80159EEC();
        interrupts = OSDisableInterrupts();
        lbl_805B6F80[index].id = id;
        lbl_805B6F80[index].state = 0;
        lbl_805B6F80[index].value08 = 0;
        lbl_805B6F80[index].value04 = 0;
        OSRestoreInterrupts(interrupts);
    }
    if (lbl_805B6F80[index].state == 0) {
        fn_80159DD0(id, index);
    }
    return index;
}






extern void fn_8020D250(void*, u32, int);


void fn_80158F6C(int id, int slot)
{
    u32 interrupts;
    int index;

    interrupts = OSDisableInterrupts();
    if (lbl_805B6FE0.states[slot]->active == 0) {
        index = fn_80158E88(id);
        if (index != -1) {
            u32 message;
            u32 request;

            message = slot ? 0x100000 : 0;
            lbl_805B6FE0.states[slot]->id = id;
            lbl_805B6FE0.states[slot]->flag142 = 0;
            lbl_805B6FE0.states[slot]->loaded = 0;
            lbl_805B6FE0.states[slot]->active = 1;
            OSRestoreInterrupts(interrupts);
            request = id | 0x40000000 | (index << 12);
            fn_8020D250(lbl_805B6FFC,
                        (request | message), 1);
        } else {
            OSRestoreInterrupts(interrupts);
        }
    } else {
        OSRestoreInterrupts(interrupts);
    }
}








extern SourceInfo* lbl_8064D170[2];
extern int lbl_8064D704;
extern void fn_8015DA70(void*, void*, s8*);
extern void fn_801EA7B4(void*, RequestState*);
extern void fn_8015DAB0(void*);
extern u32 fn_8022658C(void);


void fn_80159088(int slot)
{
    RequestState* state = lbl_805B6FE0.states[slot];

    if (lbl_805B6FE0.states[slot]->loaded == 0) {
        SourceInfo* info = lbl_8064D170[slot];
        state->field813C = 0;
        fn_8015DA70(&state->field813C, (char*)lbl_8064D170[slot] + info->work_offset,
                    &lbl_805B6FE0.states[slot]->loaded);
        fn_801EA7B4((char*)lbl_8064D170[slot] + info->data_offset, state);
        lbl_805B6FE0.states[slot]->loaded = 1;
        if (state->queue != 0 && *(u32*)((char*)state->queue + 8) < (u32)state->queue) {
            fn_8015DAB0(state->queue);
        }
        while ((u16)fn_8022658C() == 0xCACE) {
        }
    }
    lbl_8064D704 = 0;
    state->field8138 = 0;
    state->value130 = 0;
}

extern int lbl_8064D15C;


int fn_8015917C(void)
{
    return lbl_8064D15C;
}






extern int lbl_80651C98;
extern int lbl_8064C4F4;
extern int lbl_8064C3C8;
extern int lbl_8064D158;
extern int lbl_8064D180;
extern u32 lbl_8064D184;
extern int lbl_8064D188;
extern float lbl_80650630;

extern void* fn_80201B3C();
extern void fn_801ED57C(int);
extern void fn_801ED3F4(void*);
extern void fn_801EB2FC(int);
extern void fn_8011E174(int, int);
extern void fn_8013F878(void);
extern void fn_801AB154(void*);
extern void fn_801A9DCC(int, int, int);
extern void fn_800BC74C(int);
extern void fn_80046B0C(void*);
extern void fn_8015AC3C(int);
extern int fn_8015E4E8(void);
extern int fn_80201B44();
extern unsigned long long fn_8020123C();
extern void fn_80200EAC(int, int, int, float, int);
extern void fn_800474D8(void);
extern void fn_8015E788(void);
extern void fn_800477F8(int, int);
extern void fn_801F6DE4(void);
extern void fn_8011E1C4(void);
extern void fn_8016B030(int);
extern void* fn_8015AB00(int);
extern void fn_801EB9F0(void);
extern void fn_801EBA58(void*);
extern void fn_801EBDDC(void*);
extern void fn_8015C8A4(int, int);
extern void fn_802020B4(void*, int);
extern void fn_801801D0(void);
extern void fn_801F348C(int*, int);
extern u32 fn_801E7998(int);
extern void fn_801E7974(int, u32);
extern void fn_801F0294(int, float);
extern void fn_8020AFE4(int);


void fn_80159184(u32 flags)
{
    int saved;
    int* savedp = &saved;
    void* state = lbl_805B6FE0.states[lbl_805B6FE0.current];
    void* token;
    *savedp = lbl_80651C98;
    token = fn_80201B3C();

    fn_801ED57C(1);
    fn_801ED3F4(*(void**)((char*)state + 0x813C));
    fn_801EB2FC(0);
    fn_8011E174(0x10000, 0);
    fn_8013F878();
    if (!(flags & 0x20)) {
        fn_801AB154(state);
    }
    fn_801A9DCC(0, 100, 0);
    fn_801A9DCC(1, 100, 0);
    fn_800BC74C(0);
    fn_80046B0C(state);
    if (!(flags & 0x10)) {
        fn_8015AC3C((flags & 0x44) == 0);
    }

    if (lbl_8064C4F4 == 0) {
        int mode = (flags >> 7) & 1;
        lbl_8064D15C = 1;
        if (fn_8015E4E8() == 0) {
            fn_8020123C(61, 0, fn_80201B44(), 0);
        }
        fn_80200EAC(61, 0, 0, lbl_80650630, lbl_8064D180);
        lbl_8064D15C = 0;
        fn_800474D8();
        if (mode != 0) {
            fn_8015E788();
        }
        fn_800477F8(0, mode);
        fn_801F6DE4();
    } else {
        lbl_8064C4F4 = 0;
    }

    if (!(flags & 4)) {
        fn_8011E1C4();
        fn_8016B030(1);
    }
    if (!(flags & 8)) {
        void* object = fn_8015AB00(lbl_805B6FE0.current);
        if (object != 0) {
            fn_801EB9F0();
            fn_801EBA58(object);
            fn_801EBDDC(object);
        }
    }

    lbl_8064D704 = 0;
    fn_8015C8A4(-1, 0);
    fn_802020B4(token, 1);
    fn_801801D0();
    {
        int value = *savedp;
        fn_801F348C(&value, 10);
    }
    if (lbl_8064D188 == 0 && lbl_8064D184 < fn_801E7998(lbl_8064D158)) {
        fn_801E7974(lbl_8064D158, lbl_8064D184);
    }
    fn_801F0294(0, lbl_80650630);
    fn_8020AFE4(lbl_8064C3C8);
}



void fn_801593AC(int value)
{
    lbl_8064D188 = value;
}




void fn_801593B4(u32 value)
{
    if (value < fn_801E7998(lbl_8064D158)) {
        lbl_8064D184 = value;
        fn_801E7974(lbl_8064D158, value);
    }
}


extern void fn_801E79A0(int, u32);


void fn_801593FC(u32 value)
{
    if (value < fn_801E7998(lbl_8064D158)) {
        fn_801E79A0(lbl_8064D158, value);
    }
}


typedef void (*TransitionCallback)(int*, int*);








extern char lbl_8063CD18[];
extern int lbl_8064D18C;
extern signed char lbl_8064D118;
extern TransitionCallback lbl_8064D150;
extern TransitionCallback lbl_8064D154;
extern void (*lbl_8064D198)(void);

extern void fn_80237D2C(int);
extern void fn_8015AD00(int);
extern void fn_801ACC10(void);
extern void fn_801AC350(int, int, int);
extern void fn_800459C0(void);
extern int fn_801358B4(int);
extern void fn_8015BDF0(int, void*);
extern int fn_8020D318(void*, void*, int);
extern void fn_80228D9C(void);
extern void fn_80159184(u32 flags);
extern void fn_801F7034(void*, int);
extern void fn_8015AC94(int, int);
extern void fn_8015BCB0(void);
extern void fn_8015C020(int);


void fn_80159440(int value, u32 flags)
{
    int special;
    int saved;
    int message;

    fn_80237D2C(1);
    if (lbl_8064D118 != 0) {
        lbl_8064D118 = 0;
    } else {
        lbl_805B701C.pending = 1;
    }

    special = flags & 0x40;
    if (special == 0) {
        if (lbl_8064D198 != 0) {
            lbl_8064D198();
        }
        fn_8015AD00(2);
    }

    if (lbl_8064D154 != 0) {
        lbl_8064D154(&lbl_8064D18C, &value);
    }
    if (value != lbl_8064D18C) {
        fn_801ACC10();
        fn_801AC350(10, 1, 0);
        fn_800459C0();
    } else {
        lbl_8064C4F4 = 1;
    }

    saved = fn_801358B4(0);
    while ((u16)fn_8022658C() != 0xBEEF) {
    }
    fn_8015BDF0(value, &lbl_805B7048);
    fn_8020D318(&lbl_805B7048, &message, 1);
    fn_80228D9C();
    fn_80159184(flags);

    {
        volatile RequestGlobals* channels = &lbl_805B6FE0;
        if (channels->playing != -1) {
            channels->states[channels->playing]->id = -1;
            channels->states[channels->playing]->flag142 = 0;
            channels->states[channels->playing]->loaded = 0;
        }
    }

    if (special == 0) {
        fn_801F7034(lbl_8063CD18 + 0x110, 0);
        fn_8015AC94(2, 0);
    }
    fn_8015BCB0();
    fn_8015C020(0);
    fn_801358B4(saved);
    if (lbl_8064D150 != 0) {
        lbl_8064D150(&lbl_8064D18C, &value);
    }
    fn_80237D2C(0);
}
