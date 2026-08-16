extern void *fn_80201B54();
extern void fn_802006D4(void *, void *, int, int, int);
extern void fn_8020104C(int, void *, void *, int, float);

void fn_800C59F0(void *object, int value)
{
    void *id;

    if (object != 0) {
        id = fn_80201B54(object);
        fn_802006D4(id, id, 8, 0x11, 0);
        fn_802006D4(id, id, 9, 0x11, 0);
        fn_8020104C(0x11, id, id, 0, (float)value);
    }
}
