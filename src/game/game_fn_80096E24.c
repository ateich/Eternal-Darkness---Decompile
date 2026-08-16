typedef unsigned char u8;
typedef unsigned int u32;

typedef struct State80096E24 {
    u8 pad00[0x9E];
    u8 category;
    u8 kind;
} State80096E24;

extern int lbl_8064D18C;

extern int fn_80201B44();
extern void *fn_80201814();
extern void *fn_80201B9C();
extern void* fn_80201BC0(void*);
extern void *fn_80201B8C();
extern int fn_80201EB8();
extern u32 fn_80036D5C(void*);
extern void fn_80036DA4(void*, u32);
extern void fn_800359A0(void*, void*);

void fn_80096E24(register void* object)
{
    register void* target;
    register void* current;
    register State80096E24* state;
    register u32 flags;

    target = fn_80201814(fn_80201B44(object));
    switch (lbl_8064D18C) {
    case 0xCF:
        current = fn_80201B9C();
        while (current != 0) {
            state = ((State80096E24*)fn_80201B8C(current));
            flags = fn_80036D5C(object);
            if (fn_80201EB8(current) == lbl_8064D18C &&
                current != object && (flags & 0x8000) && state != 0 &&
                (state->kind == 0xA || state->kind == 0xB ||
                 state->kind == 0x26)) {
                fn_80036DA4(current, (flags & ~0x8000) | 0x880);
                fn_800359A0(current, target);
            }
            current = fn_80201BC0(current);
        }
        break;
    }
}
