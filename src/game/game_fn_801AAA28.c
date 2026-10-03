typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef unsigned char u8;
typedef struct Target Target;
typedef struct Voice Voice;

typedef struct State {
    unsigned char pad[0x90];
    Vec3 first;
    Vec3 second;
    Vec3 third;
    Vec3 fourth;
} State;

extern volatile State lbl_80608020;
extern unsigned char lbl_806080E0[];
extern int lbl_8064D2F4;
extern float lbl_80650E60;
extern float lbl_80650E64;
extern float lbl_80650E68;
extern float lbl_80650E6C;
extern float lbl_80650E70;

extern int fn_801C9914(Voice*, Vec3*, Vec3*, Vec3*, float, float, float, Vec3*,
                       void*, u8, Target*);
extern void* memset(void*, int, unsigned long);
extern void fn_801ACC94(int);

void fn_801AAA28(void)
{
    float value = lbl_80650E60;
    volatile Vec3* first;
    volatile Vec3* second;
    volatile Vec3* third;
    volatile Vec3* fourth;

    first = &lbl_80608020.first;
    first->x = value;
    first->y = value;
    first->z = value;
    second = &lbl_80608020.second;
    second->x = value;
    second->y = value;
    second->z = value;
    third = &lbl_80608020.third;
    third->x = value;
    third->y = value;
    third->z = lbl_80650E64;
    fourth = &lbl_80608020.fourth;
    fourth->x = value;
    fourth->y = lbl_80650E68;
    fourth->z = value;

    fn_801C9914((Voice*)&lbl_80608020, (Vec3*)first, (Vec3*)second,
                (Vec3*)third, lbl_80650E6C, lbl_80650E6C, lbl_80650E70,
                (Vec3*)fourth, (void*)0, 0, (Target*)0);
    memset(lbl_806080E0, 0, 0x2F80);
    lbl_8064D2F4 = 1;
    fn_801ACC94(1);
}
