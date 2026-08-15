typedef unsigned char u8;

typedef struct Object800A4724 {
    u8 pad0[0x24c];
    int child;
} Object800A4724;

extern void* fn_80201814();
extern int fn_800A4368(Object800A4724*, int);

int fn_800A4724(Object800A4724* object)
{
    Object800A4724* cursor;
    unsigned int i;
    int result;
    int child;

    result = 0;
    i = 0;
    cursor = object;
    for (; i < 4; i++, cursor = (Object800A4724*)((u8*)cursor + 4)) {
        child = cursor->child;
        if (child != 0 && fn_80201814(child) == 0) {
            result = fn_800A4368(object, child);
        }
    }
    return result;
}
