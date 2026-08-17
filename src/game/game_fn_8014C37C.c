typedef unsigned char u8;
typedef struct Work {
    void* resource;
    u8 descriptor[0x18];
    u8 placement[0x4C];
    int flags;
} Work;

extern void* fn_801FD63C(void*);
extern void* fn_80156DA0(int, void*);
extern void fn_80156904(void*, int);
extern void fn_8014C470(void);
extern void fn_801568FC(void*, void (*)(void));
extern void fn_801568C0(void*, int);
extern void fn_801568B8(void*, int);
extern void fn_8014C5B0(void);
extern void fn_8015690C(void*, void (*)(void));
extern void fn_80156914(void*, int);
extern void fn_80156918(void*, void*);
extern void fn_80156F80(void*, void*);
extern void fn_801FD534(void*);

void fn_8014C37C(void* callback_data, Work* work)
{
    void* object;

    work->resource = fn_801FD63C(work->descriptor);
    if (work->resource == 0)
        return;
    object = fn_80156DA0(5, work->placement);
    if (object != 0) {
        fn_80156904(object, 0);
        fn_801568FC(object, fn_8014C470);
        fn_801568C0(object, 0);
        fn_801568B8(object, 0);
        fn_8015690C(object, fn_8014C5B0);
        fn_80156914(object, 0);
        fn_80156918(object, work->resource);
        if (callback_data != 0) {
            fn_80156904(object, work->flags);
            fn_80156F80(object, callback_data);
        }
    } else if (work->resource != 0) {
        fn_801FD534(work->resource);
    }
}
