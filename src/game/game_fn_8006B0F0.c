typedef signed int s32;
typedef unsigned int u32;

#pragma use_lmw_stmw on

typedef struct Kinds {
    s32 values[3];
} Kinds;

extern const Kinds lbl_80239090;
extern void *fn_80036D38(s32 object);
extern s32 fn_80066D04(s32 object, s32 kind);
extern s32 fn_801A7770(s32 value);

s32 fn_8006B0F0(s32 kind, s32 object, s32 unused, s32 value)
{
    Kinds kinds;
    void *state = fn_80036D38(object);
    s32 i;

    kinds = lbl_80239090;

    for (i = 0; i < 3; i++) {
        if (kind == kinds.values[i] && fn_80066D04(object, kinds.values[i]) &&
            (*(u32 *)((char *)state + 0xB8) & (1U << kinds.values[i])) &&
            kinds.values[i] == fn_801A7770(value)) {
            return kinds.values[i];
        }
    }
    return -1;
}
