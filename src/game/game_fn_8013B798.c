extern int fn_8013B8C0(void*, void*);
extern int fn_8013B178(void*, void*, int, int, int);
extern void fn_80047674(void*, void*);
extern void fn_800475E8(void*, void*);

void fn_8013B798(void* item, void* object, int update)
{
    int result;
    int mode;

    mode = fn_8013B8C0(object, item);
    result = fn_8013B178(object, item, mode, update, 1);
    switch (result) {
    case 0:
        break;
    case 2:
        fn_80047674(object, *(void**)((char*)item + 0x2C));
        break;
    case 1:
        fn_800475E8(object, *(void**)((char*)item + 0x2C));
        break;
    case 3:
        break;
    }
}
