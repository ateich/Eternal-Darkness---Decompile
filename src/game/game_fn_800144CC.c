typedef int s32;
typedef signed short s16;

typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

extern const char lbl_8023BEF8[];
extern const double lbl_8064DCE8;
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void* fn_8016A784(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801D5898(Vec3f*, Vec3f*, s32, s32, s32, s32, s32, s32, s32,
                       s32, s32, s32, s32, s32, s32, s32, s32);
extern void *fn_80156938();
extern void fn_8017FF14(s32, s32);

s32 fn_800144CC(void* script)
{
    s16* first;
    s16* second;
    s32 third;
    s32 fourth;
    s32 fifth;
    s32 sixth;
    s32 seventh;
    s32 eighth;
    s32 ninth;
    s32 tenth;
    s32 eleventh;
    s32 twelfth;
    s32 thirteenth;
    s32 fourteenth;
    Vec3f first_position;
    Vec3f second_position;

    if (fn_8016A598(script) != 14) {
        fn_80163BB4(script, lbl_8023BEF8, 14, fn_8016A598(script));
        return 0;
    }

    first = fn_8016A784(script, 1);
    second = fn_8016A784(script, 2);
    third = (s32)fn_8016A694(script, 3);
    fourth = (s32)fn_8016A694(script, 4);
    fifth = (s32)fn_8016A694(script, 5);
    sixth = (s32)fn_8016A694(script, 6);
    seventh = (s32)fn_8016A694(script, 7);
    eighth = (s32)fn_8016A694(script, 8);
    ninth = (s32)fn_8016A694(script, 9);
    tenth = (s32)fn_8016A694(script, 10);
    eleventh = (s32)fn_8016A694(script, 11);
    twelfth = (s32)fn_8016A694(script, 12);
    thirteenth = (s32)fn_8016A694(script, 13);
    fourteenth = (s32)fn_8016A694(script, 14);
    first_position.x = first[0];
    first_position.y = first[1];
    first_position.z = first[2];
    second_position.x = second[0];
    second_position.y = second[1];
    second_position.z = second[2];
    fn_801D5898(&first_position, &second_position, third, fourth, fifth, sixth,
                seventh, eighth, ninth, tenth, 1, eleventh, twelfth, thirteenth,
                4, 0x2000, 0x100);
    fn_8017FF14((s32)fn_80156938(), fourteenth);
    return 0;
}
