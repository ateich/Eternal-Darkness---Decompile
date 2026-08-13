typedef int s32;
typedef unsigned int u32;

#pragma use_lmw_stmw on

typedef struct State {
    u32 words[4];
} State;

extern void* fn_80156938();
extern void* fn_80156930(void*);
extern void *fn_80201BC8();
extern void fn_8011F114();
extern State* fn_8011FE34(void*);
extern u32 fn_8011FAEC(void*);
extern s32 fn_80128EAC(void*);
extern s32 fn_8012A100(void*, s32);
extern void *fn_801294DC(void *, int, int, int);
extern void fn_8011F0E8(void*, State*);

void fn_8002A754(void* callback, void* source_callback)
{
    void* source = fn_80201BC8(fn_80156938(source_callback));
    State state;
    State* source_state;
    void* object;
    State* object_state;
    u32 flags;

    fn_8011F114(&state, source);
    source_state = fn_8011FE34(source);
    object = fn_80201BC8(fn_80156938(callback));
    object_state = fn_8011FE34(object);
    flags = fn_8011FAEC(object);

    if (fn_80128EAC(object) == -1 && fn_80128EAC(source) != -1 &&
        fn_8012A100(object, 15) != 0) {
        fn_801294DC(object, 15, 0, 1);
    }

    if (fn_80156930(callback) != 0 || (flags & 0x8000) != 0) {
        fn_8011F0E8(object, &state);
        *object_state = *source_state;
    }
}
