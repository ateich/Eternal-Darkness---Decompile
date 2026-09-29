typedef struct EventData {
    unsigned char pad[0x5C];
    void *object;
} EventData;

extern int fn_80200C10(EventData *);
extern int fn_80201B54(void *);
extern void *fn_80201BC8(void *);
extern void fn_80201B94(void *);
extern void fn_80201B8C(void *);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_801E8328(int, void *);
extern void fn_80201D34(void *, int);
extern void fn_80201D1C(void *, int);
extern void fn_8020123C(int, int, int, int);
extern int fn_80200C38(EventData *);
extern void fn_8012C62C(void *, int, int *, int *, int *, int);
extern void fn_8020104C(int, int, int, int, float);

extern int lbl_8064F630;
extern int lbl_8064F634;
extern int lbl_8064F638;
extern float lbl_8064F63C;

int fn_800E1E68(void *object, int event, EventData *data)
{
    int state = fn_80200C10(data);
    int id = fn_80201B54(object);
    void *owner = fn_80201BC8(object);

    fn_80201B94(object);
    fn_80201B8C(object);
    if (event == 0) {
        if (state == 1) {
            fn_80201D2C(object, 38);
            fn_80201D14(object, 1);
            return 1;
        }
        if (state == 57) {
            fn_801E8328(2, object);
            fn_80201D34(object, 0);
            fn_80201D1C(object, 1);
            return 1;
        }
    } else if (event == 38) {
        if (state == 1)
            return 1;
        if (state == 16) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        }
        if (state == 3)
            return 1;
    } else if (event == 1) {
        if (state == 1) {
            fn_8020123C(16, id, id, 14);
            return 1;
        }
        if (state == 16) {
            /* Volatile preserves retail's pre-call stack staging order. */
            volatile int initial = lbl_8064F630;
            int a;
            int b;
            int c;
            int resource = fn_80200C38(data);
            c = lbl_8064F638;
            b = lbl_8064F634;
            a = initial;
            fn_8012C62C(owner, resource, &a, &b, &c, 6);
            if (resource == 8) {
                fn_80201D2C(object, 14);
                fn_80201D14(object, 1);
            } else {
                fn_8020104C(16, id, id, resource - 1, lbl_8064F63C);
            }
            return 1;
        }
        if (state == 61) {
            fn_80201D2C(object, 14);
            fn_80201D14(object, 1);
            return 1;
        }
    } else {
        if (event == 14) {
            if (state == 1)
                return 1;
            else if (state == 3)
                return 1;
        } else {
            return 0;
        }
    }
    return 0;
}
