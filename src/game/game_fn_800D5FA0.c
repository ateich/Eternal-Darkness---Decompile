typedef struct Actor {
    unsigned char pad_000[0x86];
    unsigned short field_086;
    unsigned char pad_088[0x21a];
    unsigned char flag_7 : 1;
    unsigned char flag_6 : 1;
    unsigned char flag_5 : 1;
    unsigned char flag_4 : 1;
    unsigned char flag_3 : 1;
    unsigned char flag_2 : 1;
    unsigned char flag_1 : 1;
    unsigned char flag_0 : 1;
} Actor;

extern int fn_80201B54();
extern int fn_800460EC(void);
extern void fn_800D40A8(Actor *, void *);
extern void fn_800A41CC(Actor *, int);
extern void fn_800A2E5C(Actor *, int);
extern void fn_802006D4(int, int, int, int, int);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

void fn_800D5FA0(Actor *actor, void *object)
{
    int allowed = 1;
    int index = fn_80201B54(object);

    if (actor->flag_7 || fn_800460EC()) {
        allowed = 0;
    }
    if (allowed) {
        fn_800D40A8(actor, object);
        switch (actor->field_086) {
        case 0:
            fn_800A41CC(actor, index);
            fn_800A2E5C(actor, 0);
            break;
        }
        fn_802006D4(index, index, -1, -1, 0);
        fn_80201D2C(object, 1);
        fn_80201D14(object, 1);
    }
}
