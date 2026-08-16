typedef unsigned char u8;

typedef struct RuntimeState {
    u8 pad[0x20];
    void *payload;
} RuntimeState;

extern void *fn_80037AF4(int);
extern void *fn_80201B8C();
extern void fn_800CD384(void *, void *, void *, void *);
extern void fn_802015A4(void *);

void *fn_800CE9A4(void *first, void *second, void *third)
{
    void *object = fn_80037AF4(0x17);

    fn_800CD384(((RuntimeState *)fn_80201B8C(object))->payload, first, second, third);
    fn_802015A4(object);
    return object;
}
