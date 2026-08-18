extern void* fn_80156938(void*);
extern void *fn_80201BC8();
extern void fn_8011F6A4(void*, void*, void*, int, void*, int);
extern void fn_801879E8(void*, void*);
extern void fn_80187A3C(void*, int);
extern void fn_80187A44(void*, int);

void fn_80149920(void* object, void* other)
{
    unsigned char work[0x30];
    unsigned char* data;

    if (object != 0 && other != 0) {
        data = fn_80156938(object);
        object = fn_80156938(other);
        if (data != 0 && object != 0) {
            object = fn_80201BC8(object);
            fn_8011F6A4(object, *(void**)(data + 8), *(void**)(data + 0x48),
                        -1, work, 1);
            data = *(unsigned char**)(data + 0x88);
            fn_801879E8(data, work + 8);
            fn_80187A3C(data, 0x100);
            fn_80187A44(data, 0x60);
        }
    }
}
