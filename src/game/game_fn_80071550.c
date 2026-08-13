typedef short s16;

typedef struct GlobalState {
    char pad_00[8];
    int level;
} GlobalState;

typedef struct ObjectData {
    char pad_00[0x98];
    s16 type;
} ObjectData;

extern GlobalState lbl_803003C8;
extern void *fn_80201B9C();
extern void *fn_80201B8C();
extern int fn_80201EB8(void *);
extern int fn_80201B54();
extern unsigned long long fn_8020123C();
extern void *fn_80201BC0(void *);

void fn_80071550(int target, int enabled)
{
    void *object;

    if (lbl_803003C8.level == 7 || lbl_803003C8.level == 0) {
        object = fn_80201B9C();
        while (object != 0) {
            ObjectData *data = fn_80201B8C(object);
            if (data != 0 && data->type == 0x5D) {
                int value = fn_80201EB8(object);
                void *owner = (void *)fn_80201B54(object);
                if (value != target) {
                    enabled = 0;
                }
                fn_8020123C(0x58, 0, owner, enabled);
            }
            object = fn_80201BC0(object);
        }
    }
}
