typedef unsigned char u8;

typedef struct SavedPosition {
    float value[3];
    u8 padC;
    u8 active;
} SavedPosition;

typedef struct Owner {
    u8 pad[0x14C];
    SavedPosition saved;
} Owner;

typedef struct Work {
    u8 pad[0xC4];
    Owner* owner;
} Work;

extern void fn_8006ED98(Work*);
extern void* memcpy(void*, const void*, unsigned long);

int fn_80088528(Work* work, float* output)
{
    SavedPosition* saved;
    int result;

    fn_8006ED98(work);
    saved = &work->owner->saved;
    result = 0;
    if (saved->active != 0) {
        memcpy(output, saved->value, 12);
        result = 1;
    }
    return result;
}
