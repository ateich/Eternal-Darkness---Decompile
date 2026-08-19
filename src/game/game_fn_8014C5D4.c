typedef unsigned char u8;
typedef struct Resource { u8 pad[0x29]; u8 flags; } Resource;

extern void *fn_80156938();
extern void *fn_80201BC8();
extern Resource* fn_801FD6F4(void);
extern int fn_801FE494(void*);
extern int fn_801FE4C8(void*);
extern void fn_80149CC4(void*, void*, int, int, int);
extern void fn_801FDEB4(void*, void*);
extern int fn_8011FB4C(void*);
extern void fn_801FD848(void*, short);

void fn_8014C5D4(void* first, void* second)
{
    int value[4];
    void* first_runtime;
    void* second_runtime;
    void* second_owner;
    Resource* resource;

    second_runtime = fn_80156938(second);
    second_owner = fn_80201BC8(second_runtime);
    first_runtime = fn_80156938(first);
    resource = fn_801FD6F4();

    if (resource != 0) {
        int a = fn_801FE494(first_runtime);
        int b = fn_801FE4C8(first_runtime);
        fn_80149CC4(second_runtime, value, a, b, 0);
        fn_801FDEB4(first_runtime, value);
        if (!(resource->flags & 4))
            fn_801FD848(first_runtime, (short)fn_8011FB4C(second_owner));
    }
}
