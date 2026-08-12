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
    s32 *installed;
} ObjectState;

extern u8 lbl_8030FBF8[];
extern void *fn_80201B3C(void);
extern void *fn_80201814(s32 object_id);
extern ObjectState *fn_80201B8C(void *object);
extern void *memset(void *dest, int value, unsigned long size);

void fn_80067764(void)
{
    u8 *slot;
    void *head;
    s32 i;

    head = fn_80201B3C();
    for (i = 0, slot = lbl_8030FBF8; i < 12; i++, slot += sizeof(RuntimeSlot)) {
        void *object = fn_80201814(*(s32 *)(slot + 0xF8));
        ObjectState *state = object != 0 ? fn_80201B8C(object) : 0;

        if (state != 0 && state->installed != 0) {
            *state->installed = 0;
        }
        memset(slot, 0, sizeof(RuntimeSlot));
        slot[0x10A] = 5;
        *(s32 *)(slot + 0xFC) = -1;
        slot[0x10B] = 0;
    }
    if (head != 0) {
        ObjectState *state = fn_80201B8C(head);
        if (state != 0 && state->installed != 0) {
            *state->installed = 0;
        }
    }
}
