typedef unsigned char u8;
typedef unsigned int u32;

typedef struct VoiceLink {
    struct VoiceLink* next;
    struct VoiceLink* prev;
    u8 unk8;
    u8 bucket;
    u8 padA[2];
} VoiceLink;

typedef struct VoiceBucket {
    VoiceLink* type0;
    VoiceLink* type2;
    VoiceLink* type1;
} VoiceBucket;

extern u8 lbl_8064D3A1;
extern u8 lbl_80619860[];

void fn_801B775C(VoiceLink* voice, int type, u32 priority)
{
    u32 bucket = (lbl_8064D3A1 + (priority >> 8)) & 0x1F;
    VoiceBucket* bucket_info = (VoiceBucket*)(lbl_80619860 + bucket * 12 + 0x240);
    VoiceLink** head;
    VoiceLink* link;

    switch (type) {
    case 0:
        link = voice;
        if (link->bucket != 0xFF) {
            if (link->bucket == bucket) {
                return;
            }
            if (link->next != 0) {
                link->next->prev = link->prev;
            }
            if (link->prev != 0) {
                link->prev->next = link->next;
            } else {
                ((VoiceBucket*)(lbl_80619860 + 0x240))[link->bucket].type0 = link->next;
            }
        }
        head = &bucket_info->type0;
        break;
    case 1:
        link = voice + 1;
        if (link->bucket != 0xFF) {
            if (link->bucket == bucket) {
                return;
            }
            if (link->next != 0) {
                link->next->prev = link->prev;
            }
            if (link->prev != 0) {
                link->prev->next = link->next;
            } else {
                ((VoiceBucket*)(lbl_80619860 + 0x240))[link->bucket].type1 = link->next;
            }
        }
        head = &bucket_info->type1;
        break;
    case 2:
        link = voice + 2;
        if (link->bucket != 0xFF) {
            return;
        }
        head = &bucket_info->type2;
        break;
    }

    link->bucket = bucket;
    {
        VoiceLink* old_head = *head;
        link->next = old_head;
        if (old_head != 0) {
            old_head->prev = link;
        }
    }
    link->prev = 0;
    *head = link;
}
