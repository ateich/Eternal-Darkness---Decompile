typedef struct Object {
    char pad00[0x08];
    struct Object* next;
    char pad0C[0x0C];
    void (*callback)(struct Object*, void*);
    char pad1C[0x1C];
    void* callback_arg;
    int enabled;
} Object;

typedef struct List {
    char pad00[0x08];
    Object* first;
} List;

extern List* fn_801560CC(int);
extern int lbl_8064D0CC;

void fn_80156C04(void)
{
    int i;

    lbl_8064D0CC++;
    for (i = 0; i < 126; i++) {
        if (i != 6 && (i < 8 || i > 125)) {
            List* list = fn_801560CC(i);
            if (list != 0) {
                Object* object = list->first;
                while (object != 0) {
                    if (object->enabled != 0 && object->callback != 0) {
                        object->callback(object, object->callback_arg);
                    }
                    object = object->next;
                }
            }
        }
    }
    lbl_8064D0CC--;
}
