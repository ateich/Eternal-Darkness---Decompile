typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct NOTE NOTE;
struct NOTE {
    NOTE* next;
    NOTE* prev;
    u32 id;
    s32 endTime;
    u8 section;
    u8 pad11[3];
};

typedef struct SEQ_INSTANCE SEQ_INSTANCE;
struct SEQ_INSTANCE {
    SEQ_INSTANCE* next;
    SEQ_INSTANCE* prev;
    u8 state;
    u8 index;
    u8 pad0A[2];
    u32 publicId;
    u8 pad010[0xE64 - 0x10];
    NOTE* noteUsed[2];
    NOTE* noteKeyOff;
    u8 padE70[0xEDA - 0xE70];
    u8 syncCrossFlags;
    u8 padEDB;
    u32* syncSeqIdPtr;
    u8 padEE0[0x1868 - 0xEE0];
};

extern SEQ_INSTANCE* lbl_8064D39C;
extern SEQ_INSTANCE* lbl_8064D398;
extern SEQ_INSTANCE* lbl_8064D394;
extern void fn_801C21E8(u32);
extern void fn_801B244C(SEQ_INSTANCE*);

#define seqActiveRoot lbl_8064D39C
#define seqPausedRoot lbl_8064D398
#define seqFreeRoot lbl_8064D394
#define voiceKillSound fn_801C21E8
#define ResetNotes fn_801B244C

static NOTE seqNote[256];
static SEQ_INSTANCE seqInstance[8];

static inline u32 seqGetPrivateId(u32 seqId)
{
    SEQ_INSTANCE* si;
    for (si = seqActiveRoot; si != 0; si = si->next) {
        if (si->publicId == (seqId & ~0x80000000)) {
            return si->index | seqId & 0x80000000;
        }
    }
    for (si = seqPausedRoot; si != 0; si = si->next) {
        if (si->publicId == (seqId & ~0x80000000)) {
            return si->index | seqId & 0x80000000;
        }
    }
    return 0xffffffff;
}

static inline void KillNotes(SEQ_INSTANCE* seq)
{
    NOTE* n;
    u32 i;

    for (i = 0; i < 2; i++) {
        for (n = seq->noteUsed[i]; n != 0; n = n->next) {
            voiceKillSound(n->id);
        }
    }

    for (n = seq->noteKeyOff; n != 0; n = n->next) {
        voiceKillSound(n->id);
    }
}

void fn_801B3770(int seqId)
{
    SEQ_INSTANCE* si;

    if ((seqId = seqGetPrivateId(seqId)) == 0xffffffff) {
        return;
    }

    if ((seqId & 0x80000000) == 0) {
        si = &seqInstance[seqId];
        switch (si->state) {
        case 1:
            if (si->prev != 0) {
                si->prev->next = si->next;
            } else {
                seqActiveRoot = si->next;
            }

            KillNotes(&seqInstance[seqId]);
            ResetNotes(&seqInstance[seqId]);
            break;
        case 2:
            if (si->prev != 0) {
                si->prev->next = si->next;
            } else {
                seqPausedRoot = si->next;
            }
            break;
        }

        if (si->next != 0) {
            si->next->prev = si->prev;
        }
        si->state = 0;
        if (seqFreeRoot != 0) {
            seqFreeRoot->prev = si;
        }
        si->next = seqFreeRoot;
        si->prev = 0;
        seqFreeRoot = si;
    } else {
        si = &seqInstance[seqId & ~0x80000000];
        if (si->state != 0) {
            si->syncSeqIdPtr = 0;
        }
    }
}
