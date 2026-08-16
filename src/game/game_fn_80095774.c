typedef unsigned char u8;
typedef unsigned int u32;

typedef struct State80095654 { u8 pad00[0xCC]; u32 value; } State80095654;
typedef struct Event80095654 { u8 pad00[0x14]; int value; } Event80095654;
typedef struct Context80095654 { u8 pad00[0x68]; void* object; } Context80095654;
typedef struct Object80095654 { u8 pad00[0x30]; short value; } Object80095654;

extern void *fn_80201BC8();
extern void fn_80201E78(void*, void*);
extern Event80095654* fn_800935CC(int, void*, u32, int);
extern void *fn_801294DC(void *, int, int, int);
extern void fn_80128C44(void*, void*, int);
extern void fn_80128C28(void*, void*, int);
extern void fn_80204810(void);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

int fn_80095774(register void* object, register int index,
                register State80095654* state,
                register Context80095654* context)
{
    u8 query[0xC];
    register int result;
    register void* owner;
    register Event80095654* event;
    register void* action;

    result = 0;
    owner = fn_80201BC8(object);
    fn_80201E78(query, object);
    event = fn_800935CC(0, 0, state->value, 4);
    if (event == 0) {
        event = fn_800935CC(0, query, 0, 1);
    }
    if (event == 0) {
        state->value = 0;
        fn_80201D2C(object, 1);
        fn_80201D14(object, 1);
        result = 1;
    } else {
        action = fn_801294DC(owner, 0xA3, 0x30, 6);
        if (action != 0) {
            int tag = index << 8;
            fn_80128C44(action, fn_80204810, tag | 7);
            fn_80128C28(action, fn_80204810, tag | 0xDB);
            ((Object80095654*)context->object)->value = event->value;
            fn_80201D2C(object, 0x64);
            fn_80201D14(object, 1);
            result = 1;
        }
    }
    return result;
}
