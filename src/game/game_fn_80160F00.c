typedef struct Object {
    char* current;
    char _pad04[4];
    char* end;
} Object;

typedef struct Value {
    double first;
    double second;
} Value;

extern char lbl_8024F5B0[];
extern Value* fn_80167BF0(void*, char*);
extern void fn_8016057C(Object*, int);
extern void fn_8016A8F8(Object*, void*);
extern void fn_80160B18(Object*, char*, int);

void fn_80160F00(Object* object, void* argument)
{
    char* name = lbl_8024F5B0;
    Value* value = fn_80167BF0(object, name);

    if (*(int*)value == 5) {
        *(Value*)object->current = *value;
        if (object->current == object->end) {
            fn_8016057C(object, 1);
        }
        object->current += sizeof(Value);
        fn_8016A8F8(object, argument);
        fn_80160B18(object, object->current - 32, 0);
    }
}
