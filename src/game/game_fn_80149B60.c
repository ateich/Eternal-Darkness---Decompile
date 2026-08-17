extern void* fn_80201BC8(void*);
extern int fn_8011F598(void*, void*, void*, int, void*, int);
extern void fn_8011F6A4(void*, void*, int, int, void*, int);
extern void fn_80149D58(float*, short*);

typedef struct TransformResult {
    unsigned char pad[8];
    float values[3];
    unsigned char tail[0x10];
} TransformResult;

void fn_80149B60(void* object, short* output, void* first, void* second, int unused)
{
    TransformResult result;
    void* instance;

    if (object != 0) {
        instance = fn_80201BC8(object);
        if (instance != 0) {
            if (fn_8011F598(instance, first, second, -1, &result, 1) == -1) {
                fn_8011F6A4(instance, first, 0xF, -1, &result, 1);
            }
            fn_80149D58(&result.values[0], output);
            fn_80149D58(&result.values[1], output + 1);
            fn_80149D58(&result.values[2], output + 2);
        }
    }
}
