extern void *fn_80201BC8();
extern void fn_8011F6A4(void*, void*, void*, int, void*, int);

typedef struct Vector3 {
    float x;
    float y;
    float z;
} Vector3;

typedef struct TransformResult {
    unsigned char pad[8];
    Vector3 value;
    unsigned char tail[0x10];
} TransformResult;

void fn_80149CC4(void* object, Vector3* output, void* first, void* second)
{
    TransformResult result;
    void* instance;

    if (object != 0) {
        instance = fn_80201BC8(object);
        if (instance != 0) {
            fn_8011F6A4(instance, first, second, -1, &result, 1);
            *output = result.value;
        }
    }
}
