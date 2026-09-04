typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Link {
    struct Link* next;
    struct Link* prev;
    u32 key;
    u32 value;
} Link;

typedef struct Voice {
    u8 pad_000[0xEC];
    u32 previous_id;
    u32 next_id;
    u32 state;
    Link* first;
    Link* last;
    u8 pad_100[0x304];
} Voice;

extern Voice* lbl_8064D3D0;
extern Link* lbl_8064D45C;
extern Link* lbl_8064D460;
extern void fn_801C2754(Voice* voice);

static inline void release_link(Link* link)
{
    if (link->prev != 0) {
        link->prev->next = link->next;
    } else {
        lbl_8064D45C = link->next;
    }
    if (link->next != 0) {
        link->next->prev = link->prev;
    }
    link->next = lbl_8064D460;
    if (lbl_8064D460 != 0) {
        lbl_8064D460->prev = link;
    }
    link->prev = 0;
    lbl_8064D460 = link;
}

void fn_801C106C(Voice* voice)
{
    if (voice->state != (u32)-1) {
        fn_801C2754(voice);
        if (voice->next_id != (u32)-1) {
            lbl_8064D3D0[(u8)voice->next_id].previous_id = voice->previous_id;
            if (voice->previous_id != (u32)-1) {
                lbl_8064D3D0[(u8)voice->previous_id].next_id = voice->next_id;
            }
            release_link(voice->first);
            voice->first = 0;
        } else if (voice->previous_id != (u32)-1) {
            voice->first->value = voice->previous_id;
            lbl_8064D3D0[(u8)voice->previous_id].next_id = (u32)-1;
            lbl_8064D3D0[(u8)voice->previous_id].last = voice->last;
            if (voice->first != voice->last) {
                release_link(voice->first);
            }
            voice->first = 0;
            voice->last = 0;
        } else if (voice->first != voice->last) {
            release_link(voice->first);
            voice->first = 0;
            release_link(voice->last);
            voice->last = 0;
        } else {
            release_link(voice->first);
            voice->first = 0;
            voice->last = 0;
        }
    }
}
