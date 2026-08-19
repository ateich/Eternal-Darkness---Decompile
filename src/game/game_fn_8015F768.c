typedef struct OuterObject {
    char pad0[0x28];
    void* object;
} OuterObject;

extern void fn_8015F414(void*, void*, int);
extern void fn_8015F448(void*, void*, int);
extern void fn_8015F4D0(OuterObject*, void*, int);

void fn_8015F768(OuterObject* outer, int type, void* command)
{
    void* object = outer->object;

    switch (type) {
    case 12:
        fn_8015F414(object, command, 1);
        break;
    case 13:
        fn_8015F448(object, command, 1);
        break;
    default:
        fn_8015F4D0(outer, command, 1);
        break;
    }
}
