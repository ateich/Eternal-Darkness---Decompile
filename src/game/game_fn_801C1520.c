typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct VoiceLink {
    u8 previous;
    u8 next;
    u16 active;
} VoiceLink;

typedef struct GroupLink {
    u16 previous;
    u16 next;
} GroupLink;

typedef struct Voice {
    u8 pad_000[0xF4];
    u32 index;
    u8 pad_0F8[0x14];
    u8 group;
} Voice;

typedef struct VoiceState {
    u8 pad_000[0x8C0];
    VoiceLink links[64];
    u8 heads[256];
    GroupLink groups[64];
} VoiceState;

extern VoiceState lbl_80626DA0;
extern u16 lbl_8064D464;

void fn_801C1520(Voice* voice)
{
    VoiceLink* link;
    VoiceState* state;
    GroupLink* group;
    u16 active;

    state = &lbl_80626DA0;
    link = (VoiceLink*)((u8*)state + (u8)voice->index * 4);
    active = *(u16*)((u8*)link + 0x8C2);
    link = (VoiceLink*)((u8*)link + 0x8C0);
    if (active != 1) {
        return;
    }
    if (link->previous != 0xFF) {
        state->links[link->previous].next = link->next;
    } else {
        state->heads[voice->group] = link->next;
    }

    if (link->next != 0xFF) {
        state->links[link->next].previous = link->previous;
    } else if (link->previous == 0xFF) {
        group = &state->groups[voice->group];
        if (group->next != 0xFFFF) {
            state->groups[group->next].previous = group->previous;
        } else {
            lbl_8064D464 = group->previous;
        }
        if (group->previous != 0xFFFF) {
            state->groups[group->previous].next = group->next;
        }
    }

    link->active = 0;
}
