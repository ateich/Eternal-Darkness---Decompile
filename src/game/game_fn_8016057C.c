typedef struct Object {
    char* current;
    char* allocation;
    char* end;
    int count;
} Object;

extern void fn_80160FEC(Object*, int);
extern void fn_80160FAC(Object*, const char*);
extern char lbl_8024F5A0[];

void fn_8016057C(Object* object, int requested)
{
    if ((object->end - object->current) / 16 <= requested) {
        if ((object->end - object->allocation) / 16 > object->count - 1) {
            fn_80160FEC(object, 5);
        } else {
            object->end += 640;
            fn_80160FAC(object, lbl_8024F5A0);
        }
    }
}
