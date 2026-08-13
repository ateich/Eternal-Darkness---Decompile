typedef struct Owner { void *effect; } Owner;

extern void fn_8007BCD4(void);
extern void fn_8007C17C(Owner *);

void fn_8007C13C(Owner *owner)
{
    if (owner->effect != 0) {
        fn_8007BCD4();
        fn_8007C17C(owner);
    }
}
