extern void *fn_80201BC8();
extern int fn_8011F6A4(void*, void*, void*, int, void*, int);
extern void fn_80149D58(float*, short*);
extern float lbl_80650488;

typedef struct TransformResult {
    unsigned char pad[8];
    float values[3];
    unsigned char tail[0x10];
} TransformResult;

void fn_801499C4(void* object, short* output, void* first, void* second, int unused)
{
    TransformResult result;

    if (object != 0) {
        object = fn_80201BC8(object);
        if (object != 0) {
            fn_8011F6A4(object, first, second, -1, &result, 1);
            result.values[2] += lbl_80650488;
            fn_80149D58(&result.values[0], output);
            fn_80149D58(&result.values[1], output + 1);
            fn_80149D58(&result.values[2], output + 2);
        }
    }
}
