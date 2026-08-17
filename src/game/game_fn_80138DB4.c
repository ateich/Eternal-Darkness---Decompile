typedef struct Object {
    unsigned char pad[0x248];
    int state;
} Object;

extern int fn_80046104(void);
extern int fn_80139464(Object*, int);
extern int fn_80139D10(Object*, int);

int fn_80138DB4(Object* object, int value)
{
    int result = 0;

    switch (object->state) {
    case 1:
        if (fn_80046104() == 0) {
            result = fn_80139464(object, value);
        }
        break;
    case 2:
    case 3:
        if (value == 0 || value == -1) {
            result = 1;
        }
        break;
    case 4:
        result = fn_80139D10(object, value);
        break;
    }
    return result;
}
