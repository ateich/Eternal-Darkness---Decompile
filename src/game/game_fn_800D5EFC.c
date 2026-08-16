typedef struct Actor {
    unsigned char pad_000[0x284];
    signed short counter;
    unsigned char pad_286[0x1c];
    unsigned char flag_7 : 1;
    unsigned char flag_6 : 1;
    unsigned char flag_5 : 1;
    unsigned char flag_4 : 1;
    unsigned char flag_3 : 1;
    unsigned char flag_2 : 1;
    unsigned char flag_1 : 1;
    unsigned char flag_0 : 1;
} Actor;

extern void *fn_80201BC8();
extern Actor *fn_800A1D28(void *);
extern void fn_800A4724(Actor *);
extern void fn_800A4D48(Actor *, void *);
extern int fn_800A46F4(Actor *);
extern int fn_800A46C4(Actor *);
extern void fn_800A1D4C(Actor *);

void fn_800D5EFC(void *object)
{
    void *owner = fn_80201BC8(object);
    Actor *actor = fn_800A1D28(object);

    fn_800A4724(actor);
    fn_800A4D48(actor, owner);
    if (actor->counter > 0) {
        actor->counter--;
    }
    if (fn_800A46F4(actor)) {
        actor->flag_4 = 1;
    }
    if (fn_800A46C4(actor)) {
        fn_800A1D4C(actor);
    }
}
