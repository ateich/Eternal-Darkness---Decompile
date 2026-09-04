typedef int (*Callback)(int, void*);

typedef struct CallbackOwner {
    unsigned char pad00[0x18];
    void* argument;
} CallbackOwner;

extern Callback lbl_8064D4B0;

int fn_801C753C(CallbackOwner* owner, int value)
{
    if (lbl_8064D4B0 == 0) {
        return 0;
    }

    return lbl_8064D4B0(value, owner->argument);
}
