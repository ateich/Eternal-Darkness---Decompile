typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Object {
    u8 pad0[0x10];
    u8 position[6];
    u8 pad16[0xC];
    u16 state;
    u8 pad24[0x28];
    u8* elements;
    u8 pad50[0xF8];
    void (*callback)(void);
    void (*callback2)(void);
} Object;

extern void* lbl_8064D238;
extern char lbl_80606334[];
extern void fn_8018ABD4(void);
extern void fn_80192318(void);

extern Object* fn_8018038C(void*, const char*);
extern void fn_8019197C(Object*, void*, void*, u8*);
extern void fn_80191C8C(Object*, u8*);
extern void* memcpy(void*, const void*, unsigned long);

Object* fn_80190EEC(void* arg0, void* arg1, u8* config)
{
    Object* object = *(Object**)(config + 0xC);

    if (object == 0) {
        object = fn_8018038C(lbl_8064D238, lbl_80606334);
        fn_8019197C(object, arg0, arg1, config);
    } else {
        int count;
        u8* element;
        int i;

        memcpy(object->position, arg0, 6);
        count = config[0];
        element = object->elements;
        for (i = 0; i < count; i++) {
            element[0x2B] = 0xFF;
            element += 0x38;
        }
    }

    if (object != 0) {
        fn_80191C8C(object, config);
        object->callback2 = fn_80192318;
        object->callback = fn_8018ABD4;
        object->state = 4;
    }
    return object;
}
