typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Context8009F8CC {
    u8 pad00[0x18];
    u32 flags;
} Context8009F8CC;

typedef struct Link8009F8CC {
    u8 pad00[0x44];
    void* field_44;
} Link8009F8CC;

extern int fn_80201B44();
extern void *fn_80201814();
extern void *fn_8006ED3C();
extern Link8009F8CC* fn_80036D38(void*);
extern void fn_802020B4(void*, int);
extern void fn_801A5C30(int);
extern int fn_8006EDA0(void*, void*);
extern void fn_801E7974(void*, int);
extern void fn_8001D9FC(int);
extern void fn_8006EA4C(void);
extern void fn_8006BEE4(Context8009F8CC*, void (*)(void));
extern void* lbl_8064C4E0;

int fn_8009F8CC(register void* state)
{
    void* runtime;
    Context8009F8CC* context;
    void* linked;
    int index;

    runtime = fn_80201814(((void*)fn_80201B44()));
    context = fn_8006ED3C(state, 15, &index);
    linked = fn_80201814(fn_80036D38(runtime)->field_44);
    fn_802020B4(linked, 0);
    fn_801A5C30(0);
    context->flags |= 0x401;
    if (fn_8006EDA0(runtime, linked)) {
        fn_801E7974(lbl_8064C4E0, 837);
        fn_8001D9FC(11);
    } else {
        fn_8006BEE4(context, fn_8006EA4C);
    }
    return 1;
}
