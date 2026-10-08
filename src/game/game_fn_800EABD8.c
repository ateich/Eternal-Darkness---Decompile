typedef signed char s8;
typedef unsigned short u16;
typedef struct Entry80201B3C Entry80201B3C;
typedef struct Actor800EABD8 {
    unsigned char pad00[0x5C];
    short value5C;
} Actor800EABD8;

extern Entry80201B3C *fn_80201B3C(void);
extern void *fn_80201B8C(unsigned char *object);
extern void fn_800C7028(u16 *object, u16 value);
extern void fn_800EAA84(void);
extern void fn_8015C948(int value08, int value1C, int value20, int value0C,
                        int value10, int duration, int value04, int kind,
                        int callback, int callback_arg, int value18);
extern void fn_801AC350(s8 value, int detailed, int drain);

void fn_800EABD8(int arg)
{
    Entry80201B3C *entry = fn_80201B3C();
    Actor800EABD8 **slot;
    Actor800EABD8 *actor;

    if (entry) {
        slot = (Actor800EABD8 **)fn_80201B8C((unsigned char *)entry);
        if (slot)
            actor = *slot;
        else
            actor = 0;
        fn_800C7028((u16 *)actor, 0x80);
        fn_8015C948(actor->value5C, 0, 0, 0, 0, 1, 1, 0x11,
                    (int)fn_800EAA84, arg, 1);
        fn_801AC350(0, 1, 0);
    }
}
