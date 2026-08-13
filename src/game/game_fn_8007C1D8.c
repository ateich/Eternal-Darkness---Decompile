typedef struct Owner { void *effect; } Owner;

extern int fn_801FE25C(void *);
extern void fn_801FDF74(void *, int);
extern void fn_801FE4FC(void *);

void fn_8007C1D8(Owner *owner)
{
    if (fn_801FE25C(owner->effect) != 0) {
        fn_801FDF74(owner->effect, 0);
        fn_801FE4FC(owner->effect);
    }
    owner->effect = 0;
}
