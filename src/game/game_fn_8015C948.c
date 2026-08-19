typedef struct State {
    int duration;
    int value04;
    int value08;
    int value0C;
    int value10;
    int kind;
    int value18;
    int value1C;
    int value20;
    int callback;
    int callback_arg;
} State;

extern State lbl_805B701C;
extern unsigned char lbl_8064D118;
extern void fn_8011E174(unsigned int, int);
extern void fn_8015C8A4(unsigned int, int);
extern void fn_80047494(int);
extern void fn_801D0F70(int);

void fn_8015C948(int value08, int value1C, int value20, int value0C,
                 int value10, int duration, int value04, int kind,
                 int callback, int callback_arg, int value18)
{
    if (duration <= 0)
        duration = 1;

    lbl_8064D118 = 1;
    lbl_805B701C.value08 = value08;
    lbl_805B701C.value1C = value1C;
    lbl_805B701C.duration = duration;
    lbl_805B701C.value04 = value04;
    lbl_805B701C.value0C = value0C;
    lbl_805B701C.value10 = value10;
    lbl_805B701C.kind = kind;
    lbl_805B701C.value20 = value20;
    lbl_805B701C.callback = callback;
    lbl_805B701C.callback_arg = callback_arg;
    lbl_805B701C.value18 = value18;
    fn_8011E174(0x10000, 1);
    fn_8015C8A4(4, 1);
    fn_80047494(duration + 3);
    fn_801D0F70(0);
}
