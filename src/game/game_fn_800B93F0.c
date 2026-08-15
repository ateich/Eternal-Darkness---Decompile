typedef unsigned char u8;

typedef struct GameState {
    u8 pad[0x1914];
    u8 ready;
} GameState;

extern GameState lbl_803003C8;
extern void fn_80025A78(int);
extern void *fn_8004918C(void);
extern void *fn_80201B3C(void);
extern void fn_8004948C(void *, void *, int);
extern void fn_801A7864(void *);

void fn_800B93F0(void)
{
    if (lbl_803003C8.ready != 0) {
        fn_80025A78(10);
    } else {
        void *object = fn_8004918C();
        fn_8004948C(fn_80201B3C(), object, 0);
        fn_801A7864(object);
    }
}
