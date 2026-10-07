typedef struct Object80201EB8 Object80201EB8;
typedef struct Object80201D14 Object80201D14;
typedef struct Object80201D2C Object80201D2C;
typedef void (*ObjectCallback)(int);

extern int lbl_8064D18C;
extern float lbl_8064F7EC;
extern float lbl_8064F800;
extern int fn_80201B54(int *);
extern int fn_80201EB8(Object80201EB8 *);
extern int fn_802006D4(int, int, int, int, ObjectCallback);
extern void fn_80201138(int, void *, int, int, int, float);
extern void *fn_80201BC8(void *);
extern void fn_800E8524(void *, int);
extern void fn_8020104C(int, int, int, int, float);
extern void fn_80201D2C(Object80201D2C *, int);
extern void fn_80201D14(Object80201D14 *, unsigned char);

int fn_800E8634(void *callback, void *context)
{
    Object80201D14 *object = context;
    int handle = fn_80201B54((int *)object);

    if (lbl_8064D18C != fn_80201EB8((Object80201EB8 *)object)) {
        fn_802006D4(handle, handle, 1, 18, 0);
        fn_80201138(18, object, 1, 57, 0, lbl_8064F7EC);
    } else {
        fn_800E8524(object, callback != fn_80201BC8(object));
        fn_8020104C(201, handle, handle, 0, lbl_8064F800);
        fn_80201D2C((Object80201D2C *)object, 6);
        fn_80201D14(object, 1);
    }
    return 0;
}
