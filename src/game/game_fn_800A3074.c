extern void* fn_80201814(int);
extern int fn_80201B5C(void*);

int fn_800A3074(int handle)
{
    void* object = fn_80201814(handle);
    int result = 0;

    if (object != 0) {
        result = fn_80201B5C(object);
    }
    return result;
}
