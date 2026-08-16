typedef struct EventState {
    int kind;
    unsigned char pad4[0x30];
    int target;
} EventState;

extern float lbl_8064EF34;
extern void *fn_80201814();
extern int fn_80201B64(void*);
extern int fn_80036E50(void*);
extern void fn_8020104C(int, void*, void*, int, float);
extern unsigned long long fn_8020123C();

void fn_800A831C(void* context, EventState* state)
{
    if (state->kind == 0x810 && state->target != 0) {
        void* target = fn_80201814((void*)state->target);

        if (target != 0 && fn_80201B64(target) != 8 &&
            (fn_80036E50(target) != 6 || fn_80201B64(target) != 6)) {
            fn_8020104C(0xEB, context, (void*)state->target, 0, lbl_8064EF34);
            fn_8020123C(0xFA, context, (void*)state->target, 7);
        }
        state->target = 0;
    }
}
