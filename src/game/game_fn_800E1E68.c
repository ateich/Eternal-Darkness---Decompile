typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct EventData {
    unsigned char pad[0x5C];
    void *object;
} EventData;

extern int fn_80200C10(void*);
extern int fn_80201B54();
extern void *fn_80201BC8();
extern void* fn_80201B94();
extern void *fn_80201B8C();
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern int fn_801E8328();
extern void fn_80201D34(void *, int);
extern void fn_80201D1C(void *, int);
extern unsigned long long fn_8020123C();
extern int fn_80200C38();
extern void fn_8012C62C(void *, void *, Vec3 *, Vec3 *, Vec3 *, int);
extern void fn_8020104C(float, int, int, int);

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
        return 0;
    }
    if (event == 38) {
        if (state == 1)
            return 1;
        if (state == 16) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        }
        return state == 3;
    }
    if (event == 1) {
        if (state == 1) {
            fn_8020123C(16, id, id, 14);
            return 1;
        }
        if (state == 16) {
            Vec3 a = {0.0f, 0.0f, 0.0f};
            Vec3 b = {0.0f, 0.0f, 0.0f};
            Vec3 c = {0.0f, 0.0f, 0.0f};
            void *resource = (void *)fn_80200C38(data);
            fn_8012C62C(owner, resource, &a, &b, &c, 6);
            if ((int)resource == 8) {
                fn_80201D2C(object, 14);
                fn_80201D14(object, 1);
            } else {
                fn_8020104C(1.0f, id, id, (int)resource - 1);
            }
            return 1;
        }
        if (state == 61) {
            fn_80201D2C(object, 14);
            fn_80201D14(object, 1);
            return 1;
        }
        return 0;
    }
    if (event == 14)
        return state == 1 || state == 3;
    return 0;
}
