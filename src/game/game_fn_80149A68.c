extern void* fn_80201BC8(void*);
extern void fn_8011F6A4(void*, void*, void*, int, void*, int);
extern void fn_80149D58(float*, short*);
extern float lbl_8065048C;

typedef struct TransformResult {
    unsigned char pad[8];
    float values[3];
    unsigned char tail[0x10];
} TransformResult;

void fn_80149A68(void* object, short* output, void* first, void* second, int unused)
{
    TransformResult result;

    if (object != 0) {
        object = fn_80201BC8(object);
        if (object != 0) {
            fn_8011F6A4(object, first, second, -1, &result, 1);
            result.values[2] += lbl_8065048C;
            fn_80149D58(&result.values[0], output);
            fn_80149D58(&result.values[1], output + 1);
            fn_80149D58(&result.values[2], output + 2);
        }
    }
}
