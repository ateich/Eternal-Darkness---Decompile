typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef int s32;

typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Callback { char pad[0x3C]; void* inner; } Callback;
typedef struct State {
    s32 unk00;
    s32 activated;
    s32 unk08;
    s32 alternate;
    s32 type;
    s32 linked_id;
    s32 spawned_id;
    s32 spawn_arg;
    s32 unk20;
    float timer;
    u8 effect[0xAB];
} State;

extern const float lbl_8064E064, lbl_8064E068, lbl_8064E070;
extern const float lbl_8064E10C, lbl_8064E110, lbl_8064E114, lbl_8064E118;
extern const float lbl_8064E11C, lbl_8064E120, lbl_8064E124;
extern const double lbl_8064E038;
extern const u32 lbl_8064E0C4, lbl_8064E0C8, lbl_8064E0CC;
extern const u32 lbl_8064E0D0, lbl_8064E0D4, lbl_8064E0D8;
extern const u32 lbl_8064E0DC, lbl_8064E0E0, lbl_8064E0E4;
extern const u32 lbl_8064E0E8, lbl_8064E0EC, lbl_8064E0F0;
extern const u32 lbl_8064E0F4, lbl_8064E0F8, lbl_8065190C;
extern const u32 lbl_8064E0FC, lbl_80651910, lbl_8064E104, lbl_8064E108;
extern const u16 lbl_8064E100;
extern s32 lbl_8064D18C;

extern s32 fn_80200C10(void*);
extern void *fn_80201B8C();
extern int fn_80201B54();
extern void fn_802020B4(void*, int);
extern void fn_80201D2C(void *, s32);
extern void fn_80201D14(void *, s32);
extern void fn_80201D34(void *, s32);
extern void fn_80201D1C(void *, s32);
extern int fn_801E8328();
extern unsigned long long fn_8020123C();
extern s32 fn_802006D4(s32, s32, s32, s32, s32);
extern s32 fn_80200614(s32, s32, s32);
extern void fn_8020104C(int, void *, void *, int, float);
#define fn_8020104C(a, b, c, d, e) fn_8020104C((a), (void *)(b), (void *)(c), (int)(d), (e))
extern void fn_80200460(s32, s32, s32, s32, float);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern void fn_8020216C(void*);
extern int fn_80201AE4(void);
extern int fn_80201EB8(void *);
extern s32 fn_801D38E8(s32);
extern void fn_801D3BE4(s32, s32*, s32*);
extern s32 fn_801CEB2C(s32);
extern int fn_801D3974(s32);
extern int fn_80038308(void *, int, short *);
extern int fn_80038464(void*, int, s16*);
extern int fn_800389E0(void*, int, s32, int);
extern s32 fn_80047178(void);
extern s32 fn_8012F674(void*, s32, s32);
extern s32 fn_8012FA54(void*, s32);
extern void fn_8012C62C(void*, s32, void*, void*, void*, s32);
extern void fn_8012F58C(void*, s32, s32, s32, s32, s32);
extern s32 fn_80128258(void);
extern s32 fn_80128130(void);
extern void fn_801499C4(void*, s16*, s32, s32, s32);
extern s32 fn_800453AC(s32, s32, s32, float, s32, s32, s32, s32, s32, Vec3*, s32, s32);
extern s32 fn_8006749C(s32);
extern void fn_80120AD0(void*, s32, s32, u16, float, float);
extern void fn_8019917C(void*);
extern void fn_8011F114(void *, void *);
extern void* memcpy(void*, const void*, u32);
extern void fn_8019901C(void);

s32 fn_8002EA68(void* callback, s32 phase, void* event)
{
    s16 count, other_count;
    s32 x, y;
    s16 pos[4];
    Vec3 vector, point;
    void* callback_object = callback;
    s32 event_id = fn_80200C10(event);
    State* state = (State*)((Callback*)fn_80201B8C(callback_object))->inner;
    s32 object_id = fn_80201B54(callback_object);

    if (phase == 0) {
        if (event_id == 1) {
            fn_802020B4(callback_object, 1);
            fn_8020123C(0x60, object_id, object_id, 0);
            fn_80201D2C(callback_object, 1);
            fn_80201D14(callback_object, 1);
            return 1;
        }
        if (event_id == 0x39) {
            fn_802006D4(object_id, object_id, -1, 0x5E, 0);
            fn_802006D4(object_id, object_id, -1, 0x60, 0);
            fn_801E8328(2, callback_object);
            fn_80201D34(callback_object, 0);
            fn_80201D1C(callback_object, 1);
            return 1;
        }
        if (event_id == 0x60) {
            void* linked = fn_80201814(state->linked_id);
            Callback* linked_callback;
            if (linked && (linked_callback = fn_80201B8C(linked)) && *(void**)((char*)linked_callback + 0x8C)) {
                s32 type;
                fn_8020216C(linked);
                type = fn_801D38E8(state->type);
                if (type == 1 || type == 4) {
                    fn_80038308(linked, 0, &other_count);
                    fn_800389E0(linked, 0, (s16)(other_count + 1), 1);
                    if (fn_80038464(linked, 3, &count))
                        fn_800389E0(linked, 3, count, 0);
                }
                if (type == 2 || type == 4) {
                    fn_80038308(linked, 2, &other_count);
                    fn_800389E0(linked, 2, (s16)(other_count + 1), 1);
                }
                if (type == 3 || type == 4) {
                    fn_80038308(linked, 1, &other_count);
                    fn_800389E0(linked, 1, (s16)(other_count + 1), 1);
                }
            }
            fn_8020104C(0x60, object_id, object_id, 0, lbl_8064E070);
            return 1;
        }
        if (event_id == 0x61) {
            void* linked = fn_80201814(state->linked_id);
            if (linked) {
                if (fn_80047178()) {
                    void* actor = fn_80201BC8(linked);
                    if (actor && !(fn_8012F674(actor, 0xF, 0) & 8)) {
                        switch (state->type & 0xF) {
                        case 1: { u32 a,b,c; c=lbl_8064E0CC; b=lbl_8064E0C8; a=lbl_8064E0C4; fn_8012C62C(actor,15,&a,&b,&c,2); break; }
                        case 2: { u32 a,b,c; c=lbl_8064E0D8; b=lbl_8064E0D4; a=lbl_8064E0D0; fn_8012C62C(actor,15,&a,&b,&c,2); break; }
                        case 4: { u32 a,b,c; c=lbl_8064E0E4; b=lbl_8064E0E0; a=lbl_8064E0DC; fn_8012C62C(actor,15,&a,&b,&c,2); break; }
                        case 8: { u32 a,b,c; c=lbl_8064E0F0; b=lbl_8064E0EC; a=lbl_8064E0E8; fn_8012C62C(actor,15,&a,&b,&c,2); break; }
                        }
                        fn_8012F58C(actor, 15, 0, 0, 0, 4);
                        state->timer = lbl_8064E10C;
                    }
                }
                fn_8020104C(0x61, object_id, object_id, 0, lbl_8064E110);
            }
            return 1;
        }
        if (event_id == 0x3E) {
            if (fn_80200614(object_id, -1, 0x5D)) {
                fn_802006D4(object_id, object_id, -1, 0x5D, 0);
                fn_8020123C(0x5D, object_id, object_id, 0);
                fn_80200460(object_id, object_id, 0x61, 1, lbl_8064E114);
            }
            return 1;
        }
    } else if (phase == 1) {
        if (event_id == 1) {
            float delay = lbl_8064E068;
            if (state->alternate) delay = lbl_8064E118;
            fn_8020104C(0x5D, object_id, object_id, 0, delay);
            fn_8020104C(0x61, object_id, object_id, 0, lbl_8064E114 + delay);
            return 1;
        }
        if (event_id == 0x5D) {
            void* linked = fn_80201814(state->linked_id);
            if (linked && (fn_80128258() || fn_80128130())) {
                s32 type = fn_801D38E8(state->type);
                fn_801D3BE4(type, &x, &y);
                fn_801499C4(linked, pos, 0, 0, 0);
                vector.x = pos[0]; vector.y = pos[1]; vector.z = pos[2];
                state->spawned_id = fn_800453AC(y, x, state->spawn_arg, lbl_8064E068,
                                                -1, -1, -1, -1, 0x3E, &vector, 1, 0);
                linked = fn_80201814(state->spawned_id);
                if (linked) {
                    void* actor = fn_80201BC8(linked);
                    if (actor) {
                        u32 a,b,c;
                        s32 mask;
                        u16 flags;
                        c=lbl_8064E0F8; b=lbl_8064E0F4; a=lbl_8065190C;
                        fn_8012C62C(actor,15,&a,&b,&c,4);
                        mask=fn_8006749C(type);
                        flags=(u16)(mask|0x202);
                        fn_80120AD0(actor,0,50,flags,lbl_8064E064,lbl_8064E11C);
                    }
                } else {
                    fn_8020104C(0x5D, object_id, object_id, 0, lbl_8064E064);
                    state->spawned_id = 0;
                }
            } else {
                fn_8020104C(0x5D, object_id, object_id, 0, lbl_8064E064);
                state->spawned_id = 0;
            }
            if (!fn_80200614(object_id, -1, 0x5E))
                fn_8020104C(0x5E, object_id, object_id, 0, lbl_8064E120);
            return 1;
        }
        if (event_id == 0x5E) {
            void* linked = fn_80201814(state->linked_id);
            void* spawned = fn_80201814(state->spawned_id);
            if (linked && spawned) {
                void* actor = fn_80201BC8(linked);
                if (actor) {
                    if (state->linked_id != fn_80201AE4() || (fn_80047178() && fn_8012FA54(actor,15))) {
                        if (fn_80201EB8(linked) == lbl_8064D18C) {
                            u8 init[6];
                            s32 type;
                            u8 transformed;
                            u8* fx;
                            *(u32*)init=lbl_8064E0FC; *(u16*)(init+4)=lbl_8064E100;
                            type = fn_801D38E8(state->type);
                            transformed = fn_801CEB2C(state->type);
                            fx = state->effect;
                            fn_8019917C(fx);
                            fx[0]=(u8)(transformed*2); fx[1]=6; *(u16*)(fx+4)=0x41;
                            *(s32*)(fx+0x10)=fn_801D3974(type);
                            *(signed char*)(fx+3)=-5;
                            fx[0x14]=0; fx[0x15]=fx[0]; fx[0x16]=0; fx[0x17]=180; fx[0x18]=120;
                            *(void**)(fx+0x90)=fn_8019901C;
                            actor=fn_80201BC8(spawned);
                            if (actor) { fn_8011F114(&point,actor); *(Vec3*)(fx+0x98)=point; *(float*)(fx+0xA0)+=lbl_8064E114; }
                            memcpy(fx+0xA4,init,6); *(s32*)(fx+0x94)=0; fx[0xAA]=20;
                            fn_801E8328(0x10,fx);
                        }
                    }
                }
                fn_8020104C(0x5E, object_id, object_id, 0, lbl_8064E118);
            }
            return 1;
        }
        if (event_id == 0x5F) {
            if (!state->activated) {
                void* spawned=fn_80201814(state->spawned_id);
                if (spawned) {
                    void* actor=fn_80201BC8(spawned);
                    if (actor) {
                        u32 a,b,c;
                        c=lbl_80651910; b=lbl_8064E108; a=lbl_8064E104;
                        fn_8012C62C(actor,15,&a,&b,&c,4);
                        fn_8020104C(0x39,object_id,object_id,0,lbl_8064E124);
                        fn_8020104C(0x39,object_id,state->spawned_id,0,lbl_8064E124);
                        state->activated=1;
                    } else fn_8020123C(0x39,object_id,object_id,0);
                } else fn_8020123C(0x39,object_id,object_id,0);
            }
            fn_802006D4(object_id,object_id,-1,0x5D,0);
            return 1;
        }
        if (event_id == 0xE8) {
            if (fn_80201814(state->spawned_id)) {
                fn_8020123C(0x39,object_id,object_id,0);
                fn_8020123C(0x39,object_id,state->spawned_id,0);
            }
            fn_802006D4(object_id,object_id,-1,0x5D,0);
            return 1;
        }
        if (event_id == 3) return 1;
    } else return 0;
    return 0;
}
