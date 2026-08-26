extern unsigned int fn_8011FA8C(void* object, unsigned int clear, unsigned int set);
extern void fn_80138568(void* object, void* a, void* b, void* c);

void fn_8011FBD0(void* object, int value, int preserve)
{
    *(int*)((char*)object + 0x294) = value;
    if (!preserve) {
        fn_8011FA8C(object, 0, 0x1000);
    }
    if (value != -1) {
        fn_80138568(object,
                    *(void**)((char*)object + 0x284),
                    *(void**)((char*)object + 0x288),
                    *(void**)((char*)object + 0x28C));
    }
}
