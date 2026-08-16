typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Entry { int mode; unsigned char pad[12]; } Entry;
extern Entry lbl_8031D3F8[][2][4];
extern int lbl_8064C560, lbl_8064C564, lbl_8064C578, lbl_8064C56C;
extern int lbl_8064D18C;
extern float lbl_8064EC48;
extern void fn_8011F114();
extern int fn_80036D5C(void*);
extern int fn_80201B54();
extern int fn_80201EB8();
extern void fn_8008F960(void*, void*, void*, void*, void*, void*);
extern void fn_800DD314(void*, int, int, int);
extern void fn_800DD050(void);
extern void fn_8008F5B4(void*, void*, void*, Vec3*, void*, void*, void*, void*, int, void*);
extern void fn_80090004(void*, void*, void*, Vec3*, void*, void*, void*, void*, int);
extern void fn_8008F890(void*, void*, void*);
extern int fn_800DE298(void*);
extern void fn_801261F4(void*);
extern unsigned long long fn_8020123C();
extern void fn_8011F778(void*, float);
extern void fn_8011F788(void*, float);
extern void fn_8011F798(void*, float);

void fn_800902D0(void* object, void* actor, void* arg3, void* arg4,
                 void* arg5, void* arg6, int* arg7)
{
    Vec3 position;
    Vec3 original;
    Vec3 mode2_position;
    Vec3 mode1_position;
    int flags;
    void* owner;
    int associated;

    fn_8011F114(&original, actor);
    position = original;
    flags = fn_80036D5C(object);
    owner = ((void*)fn_80201B54(object));
    associated = fn_80201EB8(object);
    lbl_8064C56C = 0;
    if (flags & 0x100000) {
        fn_8008F960(object, owner, arg7, arg5, arg6, arg3);
    } else if (associated == lbl_8064D18C) {
        fn_800DD314(object, 15, 255, 0);
        fn_800DD050();
        if (lbl_8031D3F8[lbl_8064C578][lbl_8064C560][lbl_8064C564].mode == 2) {
            mode2_position = position;
            fn_8008F5B4(object, actor, owner, &mode2_position, arg7, arg5, arg3,
                        arg6, (int)arg4, (void*)lbl_8064D18C);
        } else if (lbl_8031D3F8[lbl_8064C578][lbl_8064C560][lbl_8064C564].mode == 1) {
            mode1_position = position;
            fn_80090004(object, actor, owner, &mode1_position, arg7, arg5, arg3,
                        arg6, (int)arg4);
        }
    } else {
        fn_8008F890(object, owner, arg3);
    }
    if (associated == lbl_8064D18C) {
        fn_800DD314(object, 15, 255, 0);
    }
    arg7[6] = 0;
    if (fn_800DE298(object) && associated == lbl_8064D18C) {
        fn_801261F4(actor);
        fn_8020123C(27, owner, owner, 1);
    }
    fn_8011F778(actor, lbl_8064EC48);
    fn_8011F788(actor, lbl_8064EC48);
    fn_8011F798(actor, lbl_8064EC48);
}
