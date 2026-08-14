typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Object800A2384 {
    u8 pad000[0x86];
    u16 state;
} Object800A2384;

extern void fn_800A4368(Object800A2384*, void*);
extern int fn_800A30AC(Object800A2384*);
extern int fn_80201B44(void);
extern int fn_801A7498(void*);
extern void fn_800A30B8(Object800A2384*, int);

void fn_800A2384(Object800A2384* object, void* context, void* source)
{
    switch (object->state) {
    case 0:
        fn_800A4368(object, context);
        break;
    case 1:
        if (!fn_800A30AC(object)) {
            int value = fn_80201B44();
            int other = fn_801A7498(source);
            if (other == value) {
                fn_800A30B8(object, 0);
            }
        }
        break;
    }
}
