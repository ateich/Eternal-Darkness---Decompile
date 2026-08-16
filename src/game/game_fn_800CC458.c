typedef unsigned char u8;

extern void *fn_80037AF4(int);
extern void fn_802020B4(void *, int);
extern void *fn_80201B8C();
extern void fn_800EB20C(void *, void *, int);
extern void fn_802015A4(void *);
extern void fn_801E8328(int, void *);

void *fn_800CC458(void *source, void *unused, int value)
{
    void *object = fn_80037AF4(39);
    if (object != 0) {
        void *payload;
        fn_802020B4(object, value);
        payload = *(void **)((u8 *)fn_80201B8C(object) + 0x60);
        fn_800EB20C(payload, source, value);
        fn_802015A4(object);
        fn_801E8328(21, object);
    }
    return object;
}
