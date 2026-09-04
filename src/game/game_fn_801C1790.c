typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct VoiceLink { u8 previous, next; u16 active; } VoiceLink;
typedef struct GroupLink { u16 next, previous; } GroupLink;
typedef struct VoiceState {
    u8 pad_000[0x8C0];
    VoiceLink links[64];
    u8 heads[256];
    GroupLink groups[64];
    VoiceLink free_links[64];
} VoiceState;
typedef struct Voice {
    u8 pad_000[0x100];
    u16 kind;
    u8 pad_102[0xA];
    u8 priority;
    u8 pad_10D[3];
    u32 age;
    u32 flags_a;
    u32 flags_b;
    u8 busy;
    u8 special;
} Voice;
typedef struct Limits { u8 pad[0x210]; u8 total, normal, special; } Limits;

extern VoiceState lbl_80626DA0;
extern Limits lbl_80619C20;
extern Voice* lbl_8064D3D0;
extern u8 lbl_8064D3D8;
extern u16 lbl_8064D464;
extern u8 lbl_8064D466, lbl_8064D467, lbl_8064D468, lbl_8064D469;

s32 fn_801C1790(u8 priority, u8 limit, u16 kind, u8 special)
{
    VoiceState* state = &lbl_80626DA0;
    Voice* voices;
    u16 group;
    u8 voice_index;
    s32 candidate = -1;
    s32 count = 0;
    int constrained;

    if (lbl_8064D3D8 != 0) return -1;
    if (special) {
        constrained = lbl_8064D467 >= lbl_80619C20.special && lbl_80619C20.total > lbl_80619C20.special;
        if (lbl_80619C20.special <= limit) goto fallback;
    } else {
        constrained = lbl_8064D466 >= lbl_80619C20.normal && lbl_80619C20.total > lbl_80619C20.normal;
        if (lbl_80619C20.normal <= limit) goto fallback;
    }

    voices = lbl_8064D3D0;
    group = lbl_8064D464;
    while (group != 0xFFFF && priority >= group && candidate == -1) {
        voice_index = state->heads[group];
        while (voice_index != 0xFF) {
            Voice* voice = (Voice*)((u8*)voices + voice_index * 0x404);
            if (voice->kind == kind) {
                count++;
                if (!voice->busy && (!constrained || voice->special == special) &&
                    !(voice->flags_a & 0) && !(voice->flags_b & 2) &&
                    (candidate == -1 || voice->age < ((Voice*)((u8*)voices + candidate * 0x404))->age)) {
                    candidate = voice_index;
                }
            }
            voice_index = state->links[voice_index].next;
        }
        group = state->groups[group].next;
    }
    if (count < limit) return candidate;

fallback:
    candidate = -1;
    if (lbl_8064D469 != 0xFF && !constrained) candidate = lbl_8064D469;
    if (candidate == -1) {
        group = lbl_8064D464;
        if (priority < group) return -1;
        voices = lbl_8064D3D0;
        while (group != 0xFFFF && priority >= group && candidate == -1) {
            voice_index = state->heads[group];
            while (voice_index != 0xFF) {
                Voice* voice = (Voice*)((u8*)voices + voice_index * 0x404);
                if (!voice->busy && (!constrained || voice->special == special) &&
                    !(voice->flags_a & 0) && !(voice->flags_b & 2) &&
                    (candidate == -1 || voice->age > ((Voice*)((u8*)voices + candidate * 0x404))->age)) {
                    candidate = voice_index;
                }
                voice_index = state->links[voice_index].next;
            }
            group = state->groups[group].next;
        }
    }
    if (candidate == -1) return -1;
    if (((Voice*)((u8*)lbl_8064D3D0 + candidate * 0x404))->priority > priority) return -1;

    if (state->free_links[candidate].active == 1) {
        VoiceLink* link = &state->free_links[candidate];
        if (link->previous != 0xFF) state->free_links[link->previous].next = link->next;
        else lbl_8064D469 = link->next;
        if (link->next != 0xFF) state->free_links[link->next].previous = link->previous;
        if (lbl_8064D468 == candidate) lbl_8064D468 = link->previous;
        link->active = 0;
    } else if (((Voice*)((u8*)lbl_8064D3D0 + candidate * 0x404))->special) {
        lbl_8064D467--;
    } else {
        lbl_8064D466--;
    }
    if (special) lbl_8064D467++; else lbl_8064D466++;
    return candidate;
}
