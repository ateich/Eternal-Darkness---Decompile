extern unsigned int fn_801A74C0(void *);
extern void *fn_8004914C(void *);
extern void *fn_801A7778(void *);
extern void fn_800BFFDC(void *, void *, int);

#pragma opt_propagation off
int fn_800BFF14(void *unused, void *event)
{
    void *saved_event = event;
    unsigned int flags = fn_801A74C0(event);

    if ((flags & 0x80) == 0) {
        void *object = fn_8004914C(saved_event);
        if (object != 0) {
            void *state = fn_801A7778(saved_event);
            fn_800BFFDC(object, state, 1);
        }
    }
    return 1;
}
#pragma opt_propagation reset
