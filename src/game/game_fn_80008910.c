typedef signed char s8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct EventRecord {
    u32 frame;
    u16 id;
    u16 duration;
} EventRecord;

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

typedef struct Root {
    u32 pad_00[4];
    u32 flags;
} Root;

extern Root lbl_803003C8;
extern EventState lbl_80302040;
extern void* lbl_8064C5CC;
extern void* lbl_8064C5D0;

extern s32 fn_802365C0(s32);
extern s32 fn_802365D4(void);
extern s32 fn_801AD72C(void);
extern s32 fn_801B0B30(s32);
extern void fn_80008CA0(void);
extern void fn_80008C48(void);
extern void* fn_801E6CA0(void*, s32, s32, u32, s32);

void fn_80008910(s32 type)
{
    s32 id = -1;
    s32 end = lbl_80302040.frame + 1;
    void* owner;

    if (fn_802365C0(lbl_80302040.frame) != 0) {
        end = fn_802365D4();
    }

    if (lbl_80302040.records == 0 || lbl_80302040.index == -1) {
        end = lbl_80302040.frame;
    }

    do {
        if (lbl_80302040.active != 0) {
            switch (lbl_80302040.mode) {
            case 2:
                if (lbl_80302040.actor == fn_801AD72C()) {
                    lbl_80302040.active = 0;
                }
                break;
            case 1:
                if (fn_801B0B30(lbl_80302040.actor) != 0) {
                    lbl_80302040.active = 0;
                }
                break;
            }
        }

        if (lbl_80302040.active == 0) {
            s32 count;
            s32 offset;
            s32 i;
            EventRecord* record;

            owner = type == 3 ? lbl_8064C5CC : lbl_8064C5D0;
            count = lbl_80302040.count;
            if (lbl_80302040.records == 0 ||
                lbl_80302040.index == -1) {
                continue;
            }

            if (lbl_80302040.frame >
                ((EventRecord*)lbl_80302040.records)[count - 1].frame +
                    ((EventRecord*)lbl_80302040.records)[count - 1].duration) {
                fn_80008CA0();
                break;
            }

            for (i = 0, offset = 0; i < count; i++, offset += 8) {
                record =
                    (EventRecord*)(lbl_80302040.records + offset);
                if (lbl_80302040.frame == record->frame) {
                    id = record->id;
                    lbl_80302040.remaining = record->duration;
                }
            }

            if (id != -1) {
                fn_80008C48();
                if (owner != 0 &&
                    ((lbl_803003C8.flags & 1) != 0 ||
                     lbl_80302040.enabled != 0)) {
                    lbl_80302040.handle = fn_801E6CA0(
                        owner, lbl_80302040.index, id, 0x10008, 1);
                }
            }

            lbl_80302040.frame++;
            lbl_80302040.remaining--;
            if (lbl_80302040.handle != 0 &&
                lbl_80302040.remaining == 0) {
                fn_80008C48();
            }
        }
    } while (lbl_80302040.frame < end &&
             (lbl_803003C8.flags & 1) != 0 &&
             lbl_80302040.active == 0);
}
