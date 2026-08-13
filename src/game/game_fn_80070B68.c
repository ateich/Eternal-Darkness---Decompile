extern int lbl_8064D18C;
extern void *fn_80201B9C();
extern int fn_80201B4C(void *);
extern void *fn_80201BC8();
extern void *fn_80201B8C();
extern int fn_80201EB8();
extern int fn_80201B54();
extern unsigned long long fn_8020123C();
extern void *fn_80201BC0(void *);

typedef struct ObjectData {
    char pad_00[0x98];
    short type;
} ObjectData;

void fn_80070B68(void)
{
    void *object = fn_80201B9C();

    while (object != 0) {
        int active = fn_80201B4C(object);
        fn_80201BC8(object);
        if (active == 1) {
            ObjectData *data = fn_80201B8C(object);
            switch (data->type) {
            case 0x40:
            case 0x41:
            case 0x42:
            case 0x43: {
                int value = fn_80201EB8(object);
                void *owner = (void *)fn_80201B54(object);
                if (value == lbl_8064D18C) {
                    fn_8020123C(8, 0, owner, 0);
                } else {
                    fn_8020123C(0x39, 0, owner, 0);
                }
                break;
            }
            }
        }
        object = fn_80201BC0(object);
    }
}
