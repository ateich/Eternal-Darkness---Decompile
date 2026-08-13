typedef struct Vec8008DF64 {
    float x;
    float y;
    float z;
} Vec8008DF64;

extern const volatile Vec8008DF64 lbl_80239648;
extern int lbl_8064D18C;
extern int lbl_8064C578;

extern int fn_80201B54();
extern void* fn_80201B8C();
extern int fn_80201EB8();
extern void* fn_80201814();
extern void fn_80072618(Vec8008DF64*, Vec8008DF64*, int, int);
extern void fn_8012B344(void*);
extern void fn_8011F0E8(void*, Vec8008DF64*);
extern void fn_8011FA8C(void*, int, int);
extern void fn_8011FB54(void*, int);
extern void fn_80201D2C();
extern void fn_80201D14();

typedef struct Nested8008DF64 {
    unsigned char pad0[0x30];
    int* value30;
} Nested8008DF64;

typedef struct Data8008DF64 {
    unsigned char pad0[0x8c];
    struct {
        unsigned char pad0[0x38];
        int value38;
    }* value8C;
} Data8008DF64;

/* NonMatching: behavior-complete, size-exact C; aggregate loads are scheduled
 * into the prologue differently. */
void fn_8008DF64(void* object, void* resource)
{
    Vec8008DF64 position;
    Vec8008DF64 zero;
    Data8008DF64* data;

    zero = lbl_80239648;
    fn_80201B54(object);
    data = fn_80201B8C(object);
    fn_80201EB8(object);
    if (lbl_8064D18C != 236 && lbl_8064D18C != 83 && lbl_8064C578 != 2) {
        void* target = fn_80201814(data->value8C->value38);
        if (target != 0) {
            Nested8008DF64* nested = fn_80201B8C(target);
            nested->value30[1] = lbl_8064D18C;
        }
        fn_80072618(&zero, &position, 0, 1);
        fn_8012B344(resource);
        fn_8011F0E8(resource, &position);
        fn_8011FA8C(resource, 192, 0);
        fn_8011FB54(resource, lbl_8064D18C);
        fn_80201D2C(object, 57);
        fn_80201D14(object, 1);
    }
}
