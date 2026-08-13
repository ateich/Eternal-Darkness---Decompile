typedef unsigned int u32;

extern u32 fn_801A74C0(void*);
extern u32 fn_80038C28(void*, void*, void*);
extern void *fn_80201B9C();
extern void* fn_80201BC0(void*);

u32 fn_80038DAC(register void* source, register void* target,
                register void* effect)
{
    register u32 result = 0;
    register u32 flags = fn_801A74C0(effect);
    register void* iterator;

    if (target != 0 && target != source) {
        result = fn_80038C28(source, target, effect);
    }

    if (flags & 1) {
        iterator = fn_80201B9C();
        while (iterator != 0) {
            if (iterator != target && iterator != source) {
                fn_80038C28(source, iterator, effect);
            }
            iterator = fn_80201BC0(iterator);
        }
    }

    return result;
}
