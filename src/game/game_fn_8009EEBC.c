typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Identifier8009EEBC {
    u32 first;
    u16 second;
} Identifier8009EEBC;

typedef struct Resource8009EEBC {
    u8 pad0000[0x90];
    void (*callback)(void);
    void* handle;
    float field_98;
    float field_9C;
    float field_A0;
    u8 identifier[6];
    u8 active;
    u8 padAB[0x1695];
    u32 result;
} Resource8009EEBC;

typedef struct Owner8009EEBC {
    u8 pad00[0x15C];
    Resource8009EEBC* resource;
} Owner8009EEBC;

typedef struct State8009EEBC {
    u8 pad00[0xC4];
    Owner8009EEBC* owner;
} State8009EEBC;

extern void* fn_8006ED3C(State8009EEBC*, int, int*);
extern void fn_8019DFA0(Resource8009EEBC*);
extern void fn_8019DFF8(void);
extern void fn_80147EC4(Resource8009EEBC*);
extern u32 fn_801809A0(void*);
extern void* memcpy(void*, const void*, unsigned int);
extern u32 lbl_80651A00;
extern u16 lbl_80651A04;
extern const float lbl_8064EDCC;
extern const float lbl_8064EDD0;
extern const float lbl_8064EDD4;

int fn_8009EEBC(register State8009EEBC* state)
{
    int index;
    Identifier8009EEBC identifier;
    Resource8009EEBC* resource;
    int result;

    identifier.first = lbl_80651A00;
    identifier.second = lbl_80651A04;
    fn_8006ED3C(state, 0xE, &index);
    resource = state->owner->resource;
    result = 0;
    resource->handle = 0;
    fn_8019DFA0(resource);
    resource->callback = fn_8019DFF8;
    resource->field_98 = lbl_8064EDCC;
    resource->field_9C = lbl_8064EDD0;
    resource->field_A0 = lbl_8064EDD4;
    memcpy(resource->identifier, &identifier, 6);
    resource->handle = 0;
    resource->active = 1;
    fn_80147EC4(resource);
    if (resource->handle != 0) {
        resource->result = fn_801809A0(resource->handle);
        result = 1;
    }
    return result;
}
