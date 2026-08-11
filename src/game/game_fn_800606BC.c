typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

typedef struct OwnerData {
    u8 pad00[8];
    u8 *state;
} OwnerData;

extern void *fn_801A7498(void *);
extern void *fn_80201814(void *);
extern s32 fn_800607BC(void *, void *);
extern u32 fn_80128EE4(void *);
extern OwnerData *fn_80201B8C(void *);
extern void *fn_801A717C(void);
extern void fn_8012B344(void *);
extern void fn_801A7470(void *, s32);
extern void fn_801A74A0(void *, void *);
extern void fn_801A74A8(void *, void *);
extern void fn_8020123C(s32, void *, void *, void *);
extern void fn_801A7228(void *);

s32 fn_800606BC(void *owner, void *resource)
{
    void *value;
    void *resolved;
    s32 status;
    u32 flags;

    value = fn_801A7498(resource);
    resolved = fn_80201814(value);
    status = fn_800607BC(owner, resource);
    flags = fn_80128EE4(owner);

    if (status & 0xF) {
        OwnerData *data = fn_80201B8C(resolved);
        data->state[0x89] |= 1;
    } else if ((status & 0x40) && (flags & 0x20)) {
        void *event = fn_801A717C();
        fn_8012B344(owner);
        fn_801A7470(event, 13);
        fn_801A74A0(event, value);
        fn_801A74A8(event, value);
        fn_8020123C(53, value, value, event);
        fn_801A7228(event);
    }
    return 1;
}
