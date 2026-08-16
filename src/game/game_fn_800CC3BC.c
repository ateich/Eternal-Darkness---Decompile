typedef unsigned char u8;
#pragma use_lmw_stmw on
typedef struct Payload {
    int first;
    void *global;
    int second;
    int third;
    int fourth;
    int fifth;
    int zero;
} Payload;

extern void *lbl_8064D18C;
extern void *fn_80037AF4(int);
extern void fn_802020B4(void *, int);
extern void *fn_80201B8C();
extern void fn_802015A4(void *);
extern void fn_801E8328(int, void *);

void *fn_800CC3BC(int first, int second, int third, int fourth, int fifth,
                  int value)
{
    void *object = fn_80037AF4(36);
    if (object != 0) {
        Payload *payload;
        fn_802020B4(object, value);
        payload = *(Payload **)((u8 *)fn_80201B8C(object) + 0x40);
        payload->first = first;
        payload->global = lbl_8064D18C;
        payload->second = second;
        payload->third = third;
        payload->fourth = fourth;
        payload->fifth = fifth;
        payload->zero = 0;
        fn_802015A4(object);
        fn_801E8328(21, object);
    }
    return object;
}
