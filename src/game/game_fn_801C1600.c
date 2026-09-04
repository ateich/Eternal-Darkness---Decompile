typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct VoiceLink {
    u8 previous;
    u8 next;
    u16 active;
} VoiceLink;

typedef struct GroupLink {
    u16 next;
    u16 previous;
} GroupLink;

typedef struct Voice {
    u8 pad_000[0xF4];
    u32 index;
    u8 pad_0F8[0x14];
    u8 group;
    u8 pad_10D[3];
    u32 flags;
} Voice;

typedef struct VoiceState {
    u8 pad_000[0x8C0];
    VoiceLink links[64];
    u8 heads[256];
    GroupLink groups[64];
} VoiceState;

extern VoiceState lbl_80626DA0;
extern u16 lbl_8064D464;
extern void fn_801C1520(Voice* voice);
extern void fn_801CC704(u8 index, u32 flags, u32 voice);

void fn_801C1600(Voice* voice, u8 group_id)
{
    VoiceLink* link;
    VoiceState* state;
    u16 group;
    u8 index;
    u16 previous;
    u16 next;
    u8* head;
    u16 active;
    u8 next_head;

    state = &lbl_80626DA0;
    index = (u8)voice->index;
    link = (VoiceLink*)((u8*)state + index * 4);
    active = *(u16*)((u8*)link + 0x8C2);
    link = (VoiceLink*)((u8*)link + 0x8C0);

    if (active == 1) {
        if (voice->group == group_id) {
            return;
        }
        fn_801C1520(voice);
    }

    link->active = 1;
    link->previous = 0xFF;
    head = (u8*)state + group_id;
    next_head = *(head += 0x9C0);
    link->next = next_head;
    if (next_head != 0xFF) {
        state->links[*head].previous = index;
    } else {
        group = lbl_8064D464;
        if (group != 0xFFFF) {
            if (group <= group_id) {
                next = group;
                while (next != 0xFFFF) {
                    if (next > group_id) {
                        break;
                    }
                    previous = next;
                    next = state->groups[next].next;
                }

                state->groups[previous].next = group_id;
                state->groups[group_id].previous = previous;
                state->groups[group_id].next = next;
                if (next != 0xFFFF) {
                    state->groups[next].previous = group_id;
                }
            } else {
                state->groups[group_id].next = group;
                state->groups[group_id].previous = 0xFFFF;
                state->groups[group].previous = group_id;
                lbl_8064D464 = group_id;
            }
        } else {
            state->groups[group_id].next = 0xFFFF;
            state->groups[group_id].previous = 0xFFFF;
            lbl_8064D464 = group_id;
        }
    }

    *head = index;
    voice->group = group_id;
    fn_801CC704((u8)voice->index, (voice->flags >> 15) | ((u32)group_id << 24),
                voice->index);
}
