typedef struct ShortVector {
    short x;
    short y;
    short z;
} ShortVector;

typedef struct FloatVector {
    float x;
    float y;
    float z;
} FloatVector;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_8016A970(void*, void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern ShortVector* fn_8016BA38(int);
extern void *fn_80201814();
extern void fn_80201E78(FloatVector*, void*);
extern const char lbl_8024FF00[];

int fn_80172FF0(void* state)
{
    int index;
    int handle;
    ShortVector* vector;
    void* object;
    FloatVector position;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    index = fn_8016A694(state, 1);
    handle = fn_8016A694(state, 2);
    vector = fn_8016BA38(index);
    object = fn_80201814(handle);
    if (object != 0) {
        fn_80201E78(&position, object);
        vector->x = position.x;
        vector->y = position.y;
        vector->z = position.z;
    }
    fn_8016A970(state, vector, 0);
    return 1;
}
