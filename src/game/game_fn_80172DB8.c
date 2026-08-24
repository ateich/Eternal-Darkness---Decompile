typedef struct RuntimeObject {
    unsigned char pad_00[0x68];
    unsigned int flags;
} RuntimeObject;

extern int fn_8016A598(void*);
extern RuntimeObject* fn_8016A784(void*, int);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern const char lbl_8024FF00[];

int fn_80172DB8(void* state)
{
    int value = 0;
    RuntimeObject* object;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    object = fn_8016A784(state, 1);
    if ((object->flags & 4) != 0) {
        value = 1;
    } else if ((object->flags & 8) != 0) {
        value = 2;
    }
    fn_8016A830(state, value);
    return 1;
}
