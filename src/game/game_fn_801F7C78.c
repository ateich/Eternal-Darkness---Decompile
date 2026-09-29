typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Vec3Bits {
    unsigned int x;
    unsigned int y;
    unsigned int z;
} Vec3Bits;

typedef void (*Callback)(void*);

typedef struct Obj {
    float value;
    unsigned char pad04[0x44];
    Vec3 vector;
    unsigned char pad54[0x18];
    Callback callback;
    void* target;
    void* link;
    unsigned char pad78[0x10];
} Obj;

typedef struct Globals {
    Obj first[12];
    Obj second[12];
    Obj current_first;
    Obj current_second;
} Globals;

extern Globals lbl_8063C6B8;
extern Vec3Bits lbl_8023B7E4;
extern int lbl_8064C3A0;
extern int lbl_8064C3A4;
extern int lbl_8064D798;
extern int lbl_8064D79C;
extern int lbl_8064D7BC;
extern float lbl_80651464;
extern float lbl_8065148C;
extern float lbl_80651490;
extern float lbl_80651494;
extern float lbl_80651498;
extern float lbl_8065149C;

extern void fn_801F7034(void*, int);
extern void fn_801FA410(int);
extern void fn_801F76D8(int, int, int, float);
extern void fn_801F7804(void*);
extern void fn_801F7AD4(void*);

#define PTR(p, o) (*(void**)((unsigned char*)(p) + (o)))
#define FLT(p, o) (*(float*)((unsigned char*)(p) + (o)))
#define CB(p, o) (*(Callback*)((unsigned char*)(p) + (o)))
#define VEC(p, o) (*(Vec3*)((unsigned char*)(p) + (o)))

#pragma use_lmw_stmw on
#pragma opt_lifetimes off
/* NonMatching: behavior-complete reconstruction. The integer-address call
 * arguments preserve the global base across the two setup calls on 32-bit
 * Gekko. GC/1.3 still differs in callback scheduling and derived-pointer
 * materialization in the target-copy and final initialization blocks. */
void fn_801F7C78(void)
{
    Vec3 initial;
    Globals* globals = &lbl_8063C6B8;
    Obj* first;
    Obj* second;
    float zero;
    int i;

    ((Vec3Bits*)&initial)->x = lbl_8023B7E4.x;
    ((Vec3Bits*)&initial)->y = lbl_8023B7E4.y;
    ((Vec3Bits*)&initial)->z = lbl_8023B7E4.z;
    lbl_8064C3A0 = 2;
    lbl_8064D798 = 0;
    lbl_8064C3A4 = 2;
    lbl_8064D79C = 0;
    fn_801F7034((Obj*)((unsigned int)globals + 0xcc0), 1);
    fn_801F7034((Obj*)((unsigned int)globals + 0xd48), 1);
    globals->current_second.value = lbl_8065148C;
    globals->current_first.link = &globals->current_second;
    fn_801FA410(2);
    fn_801F76D8(0, 0, 0, lbl_80651464);
    globals->current_first.callback = fn_801F7804;
    globals->current_second.callback = fn_801F7804;
    zero = lbl_8065148C;
    lbl_8064D7BC = 0;

    first = globals->second;
    second = globals->first;
    for (i = 0; i < 12; i++) {
        fn_801F7034(first, 1);
        fn_801F7034(second, 1);
        second->value = zero;
        first->link = second;
        ((Vec3Bits*)&second->vector)->x = ((Vec3Bits*)&initial)->x;
        ((Vec3Bits*)&first->vector)->x = ((Vec3Bits*)&initial)->x;
        ((Vec3Bits*)&second->vector)->y = ((Vec3Bits*)&initial)->y;
        ((Vec3Bits*)&first->vector)->y = ((Vec3Bits*)&initial)->y;
        ((Vec3Bits*)&second->vector)->z = ((Vec3Bits*)&initial)->z;
        ((Vec3Bits*)&first->vector)->z = ((Vec3Bits*)&initial)->z;
        first++;
        second++;
    }

    if (globals->current_first.target != 0) {
        globals->current_first.vector = ((Obj*)globals->current_first.target)->vector;
    }

    second = globals->second;
    FLT(second, 0x440) = lbl_80651490;
    FLT(second, 0x444) = lbl_80651494;
    FLT(second, 0x448) = lbl_8065148C;
    CB(second, 0x6C) = fn_801F7AD4;
    CB(second, 0xF4) = fn_801F7804;
    FLT(second, 0x474) = lbl_80651498;
    VEC(globals->first, 0x440) = VEC(second, 0x440);
    FLT(globals->first, 0x440) = lbl_8065149C;
}
#pragma use_lmw_stmw off
#pragma opt_lifetimes reset
