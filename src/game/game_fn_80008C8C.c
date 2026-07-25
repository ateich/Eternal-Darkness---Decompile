typedef signed char s8;
typedef int s32;

typedef struct EventState {
    s32 index;
    unsigned char* records;
    s32 frame;
    s32 remaining;
    s32 count;
    void* handle;
    s8 mode;
    s8 active;
    s8 enabled;
    s8 pad_1B;
    s32 actor;
} EventState;

extern EventState lbl_80302040;

void fn_80008C8C(void)
{
    lbl_80302040.enabled = 1;
}
