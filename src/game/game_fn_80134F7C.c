typedef struct Object {
    char pad_0[0x120];
    unsigned int required;
} Object;

typedef struct Slot Slot;

extern Slot* fn_80134F08(Object*);
extern Slot* fn_80134EB0(unsigned int);
extern void fn_8013535C(void);
extern void fn_8013530C(void);

Slot* fn_80134F7C(Object* object)
{
    Slot* slot = fn_80134F08(object);

    if (slot == 0)
        slot = fn_80134EB0(object->required);
    if (slot == 0) {
        fn_8013535C();
        fn_8013530C();
    }
    return slot;
}
