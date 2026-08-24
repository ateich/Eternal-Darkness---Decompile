typedef unsigned char u8;
typedef unsigned short u16;

typedef struct ActorState {
    u8 pad_000[0x86];
    u16 mode;
    u8 pad_088[0x21A];
    u8 flag_80 : 1;
    u8 flag_40 : 1;
    u8 flag_20 : 1;
    u8 flag_10 : 1;
    u8 flag_08 : 1;
    u8 flag_04 : 1;
    u8 flag_02 : 1;
    u8 flag_01 : 1;
} ActorState;

extern int fn_80201B54();
extern int fn_800460EC(void);
extern void fn_800CFE30(ActorState *, void *);
extern void fn_800A41CC(ActorState *, int);
extern void fn_800A2E5C(ActorState *, int);
extern int fn_802006D4(int, int, int, int, int);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

void fn_800D3148(ActorState *state, void *object)
{
    int allowed = 1;
    int id = fn_80201B54(object);

    if (state->flag_80 != 0 || fn_800460EC() != 0) {
        allowed = 0;
    }
    if (allowed != 0) {
        fn_800CFE30(state, object);
        switch (state->mode) {
        case 0:
            fn_800A41CC(state, id);
            fn_800A2E5C(state, 0);
            ((u8 *)state)[0x286] = 0;
            break;
        }
        fn_802006D4(id, id, -1, -1, 0);
        fn_80201D2C(object, 1);
        fn_80201D14(object, 1);
    }
}
