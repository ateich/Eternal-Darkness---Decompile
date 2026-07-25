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

void fn_80008C14(unsigned char* records, s32 index, s32 count, s32 actor)
{
    lbl_80302040.index = index;
    lbl_80302040.records = records;
    lbl_80302040.frame = 0;
    lbl_80302040.remaining = 0;
    lbl_80302040.count = count;
    lbl_80302040.active = 1;
    lbl_80302040.actor = actor;
    lbl_80302040.mode = 1;
    lbl_80302040.enabled = 0;
}
