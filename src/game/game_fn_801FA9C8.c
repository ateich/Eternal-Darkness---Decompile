typedef unsigned char u8;

typedef struct MotionObject {
    u8 pad00[0x7C];
    void* resource;
} MotionObject;

typedef struct MotionGlobals {
    void* entry;
    MotionObject* object;
    float scale;
    float time;
    int value;
    int type;
} MotionGlobals;

extern MotionGlobals lbl_8063E9C8;
extern void fn_80144C40(void);
extern unsigned int fn_80144710(unsigned int, int, int);
extern int fn_801F9A38(void*, int);

#define MIN(a, b) ((b) < (a) ? (b) : (a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CLAMP(value, low, high) MIN(MAX((value), (low)), (high))

void fn_801FA9C8(short amount)
{
    float delta;

    fn_80144C40();
    delta = (float)amount / lbl_8063E9C8.scale;
    if (fn_80144710(0x1000000, 1, 0) != 0) {
        delta *= 3.0f;
    }

    lbl_8063E9C8.time += delta;
    lbl_8063E9C8.time = CLAMP(lbl_8063E9C8.time, 0.0f,
                              (float)fn_801F9A38(lbl_8063E9C8.object->resource, 1));
}
