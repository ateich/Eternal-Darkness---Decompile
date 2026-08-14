typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Source800A2220 {
    u8 pad000[0x20];
    void* value;
} Source800A2220;

typedef struct Object800A2220 {
    u8 pad000[0x68];
    void* pending;
    u8 pad06C[0x1A];
    u16 state;
    u8 pad088[0x1F9];
    s8 countdown;
} Object800A2220;

extern Source800A2220* fn_80200C38(void*);
extern void* fn_80201B54(void*);
extern int fn_801D137C(void*);
extern void fn_800A45B0(Object800A2220*, void*);

void fn_800A2220(Object800A2220* object, void* context, void* source)
{
    void* value = fn_80200C38(source)->value;
    fn_80201B54(context);

    switch (object->state) {
    case 0:
    case 1:
        if (object->pending != 0) {
            if (fn_801D137C(object->pending)) {
                object->pending = 0;
            } else {
                object->countdown--;
                if (object->countdown == 0) {
                    object->pending = 0;
                }
                fn_800A45B0(object, value);
            }
        }
        break;
    }
}
