typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Entry { int mode; unsigned char pad[12]; } Entry;
extern Entry lbl_8031D3F8[][2][4];
extern int lbl_8064C560, lbl_8064C564, lbl_8064C578, lbl_8064C56C;
extern int lbl_8064D18C;
extern float lbl_8064EC44, lbl_8064EC4C;
extern void fn_8011F114();
extern int fn_80200C38(void*);
extern void* fn_80201B54();
extern int fn_80201EB8();
extern int fn_80090204(void*);
extern void fn_802006D4(void*, void*, int, int, int);
extern void fn_8020104C(int, void*, void*, int, float);
extern void fn_8008FB9C(void*, void*, void*, Vec3*, void*, void*, void*, void*, int);
extern void fn_80090004(void*, void*, void*, Vec3*, void*, void*, void*, void*, int);

void fn_8009050C(void* object, void* actor, void* arg3, void* arg4,
                 void* arg5, void* arg6, void* arg7)
{
    Vec3 position;
    Vec3 original;
    Vec3 mode2_position;
    Vec3 mode1_position;
    Vec3 direct_position;
    int value;
    void* owner;
    int associated;

    fn_8011F114(&original, actor);
    position = original;
    value = fn_80200C38(arg3);
    owner = fn_80201B54(object);
    associated = fn_80201EB8(object);
    lbl_8064C56C = 0;
    if (value == -1) {
        if (associated != lbl_8064D18C) {
            if (lbl_8031D3F8[lbl_8064C578][lbl_8064C560][lbl_8064C564].mode == 2) {
                if (!fn_80090204(object)) {
                    fn_802006D4(owner, owner, -1, 23, 0);
                    fn_8020104C(23, owner, owner, -1, lbl_8064EC4C);
                } else {
                    mode2_position = position;
                    fn_8008FB9C(object, actor, owner, &mode2_position, arg7, arg5,
                                arg3, arg6, (int)arg4);
                }
            } else if (lbl_8031D3F8[lbl_8064C578][lbl_8064C560][lbl_8064C564].mode == 1) {
                mode1_position = position;
                fn_80090004(object, actor, owner, &mode1_position, arg7, arg5,
                            arg3, arg6, (int)arg4);
            }
        }
    } else if (!fn_80090204(object)) {
        fn_802006D4(owner, owner, -1, 23, 0);
        fn_8020104C(23, owner, owner, value, lbl_8064EC44);
    } else {
        direct_position = position;
        fn_8008FB9C(object, actor, owner, &direct_position, arg7, arg5,
                    arg3, arg6, (int)arg4);
    }
}
