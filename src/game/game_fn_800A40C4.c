typedef struct Vec800A40C4 {
    float x;
    float y;
    float z;
} Vec800A40C4;

typedef struct Context800A40C4 {
    unsigned char pad0[0x19c];
    unsigned char field19C;
} Context800A40C4;

extern float lbl_8064EED0;

extern void fn_801A7744(Vec800A40C4*, void*);
extern int fn_801A7770(void*);
extern int fn_8011F6A4(void*, int, int, int, void*, int);
extern void* fn_801A7778(void*);
extern void fn_8003B0BC(void*, Vec800A40C4*, Vec800A40C4*, void*, int, int);
extern void fn_80211A6C();
extern void fn_80211A90(Vec800A40C4*, Vec800A40C4*, float);
extern void fn_800A1C50(Vec800A40C4*, Vec800A40C4*, void*, void*);

void fn_800A40C4(void* object, Context800A40C4* context, void* value,
                 void* runtime)
{
    Vec800A40C4 initial;
    Vec800A40C4 position;
    Vec800A40C4 direction;
    Vec800A40C4 scaled;
    Vec800A40C4 result;
    unsigned char work[0x24];

    fn_801A7744(&initial, runtime);
    position = initial;

    if (fn_8011F6A4(object, 0, fn_801A7770(runtime), -1, work, 1) != -1) {
        fn_8003B0BC(fn_801A7778(runtime), &direction, &scaled, runtime, 0, 0);
        fn_80211A6C(&result, &direction, &initial);
        fn_80211A90(&initial, &initial, lbl_8064EED0);
        fn_80211A6C(&result, &initial, &scaled);
        fn_800A1C50(&position, &scaled, value, &context->field19C);
    }
}
