typedef unsigned char u8;
typedef signed int s32;

typedef struct RuntimeSlot {
    u8 data[0xF8];
    s32 object_id;
    s32 state;
    u8 reserved[10];
    u8 kind;
    u8 active;
    u8 tail[4];
} RuntimeSlot;

typedef struct ObjectState {
    s32 unused;
    RuntimeSlot **installed;
} ObjectState;

extern RuntimeSlot lbl_8030FBF8[12];
extern void *fn_80201814();
extern void *fn_80201B8C();
extern void *memset(void *dest, int value, unsigned long size);

void fn_80067A18(s32 object_id)
{
    ObjectState *state;
    s32 i;
    s32 found;
    void *object;

    object = fn_80201814(object_id);
    found = -1;
    state = fn_80201B8C(object);
    if (state->installed != 0) {
        *state->installed = 0;
        for (i = 0; i < 12; i++) {
            if (lbl_8030FBF8[i].object_id == object_id) {
                found = i;
            }
        }
        if (found != -1) {
            lbl_8030FBF8[found].object_id = 0;
            memset(&lbl_8030FBF8[found], 0, sizeof(RuntimeSlot));
            lbl_8030FBF8[i].kind = 5;
            lbl_8030FBF8[i].state = -1;
            lbl_8030FBF8[i].active = 0;
        }
    }
}
