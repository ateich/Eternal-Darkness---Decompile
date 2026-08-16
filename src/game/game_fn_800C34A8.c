typedef unsigned char u8;

extern int fn_801A781C(void *);
extern int fn_800C3854(void *, void *);

int fn_800C34A8(void *context, void *object, void *state)
{
    int mask = fn_801A781C(state);
    int result = fn_800C3854(context, object);

    if ((u8)result != 0 && ((u8)mask & (u8)result) == 0) {
        result = 0;
    }
    return result;
}
