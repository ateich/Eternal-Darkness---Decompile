extern unsigned int fn_801A74C0(void *);
extern void *fn_8004914C(void *);
extern void *fn_801A7778(void *);
extern void fn_800BFFDC(void *, void *, int);

int fn_800BFF14(void *unused, void *event)
{
    unsigned int flags = fn_801A74C0(event);

    if ((flags & 0x80) == 0) {
        void *object = fn_8004914C(event);
        if (object != 0) {
            void *state = fn_801A7778(event);
            fn_800BFFDC(object, state, 1);
        }
    }
    return 1;
}
