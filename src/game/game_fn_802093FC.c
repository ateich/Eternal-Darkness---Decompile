typedef signed int s32;
typedef signed long long s64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct OSContext OSContext;
typedef void (*SICallback)(s32 chan, u32 error, OSContext *context);
typedef void (*SITypeCallback)(s32 chan, u32 type);

typedef struct SIWork {
    u8 packetAndAlarm[0x120];
    s64 typeTime[4];
    s64 xferTime[4];
    SITypeCallback typeCallback[4][4];
    u8 pollingAndInput[0x50];
    u32 cmdFixDevice[4];
} SIWork;

extern SIWork Packet_80640B68;
extern u32 Type_802FCA34[4];
extern u32 lbl_8064D8D8;

extern s64 __OSGetSystemTime(void);
extern u16 fn_8020EE24(s32 chan);
extern void fn_8020EEA8(s32 chan, u16 id);
extern s32 SITransfer(s32 chan, void *output, u32 outputBytes, void *input,
                      u32 inputBytes, SICallback callback, s64 delay);

static inline void CallTypeAndStatusCallback(SIWork *work, s32 chan, u32 type)
{
    SITypeCallback callback;
    s32 i;

    for (i = 0; i < 4; i++) {
        callback = work->typeCallback[chan][i];
        if (callback != 0) {
            work->typeCallback[chan][i] = 0;
            callback(chan, type);
        }
    }
}

void GetTypeCallback_802093FC(s32 chan, u32 error, OSContext *context)
{
    SIWork *work = &Packet_80640B68;
    u32 type;
    u32 chanBit;
    s32 fix;
    u32 id;

    Type_802FCA34[chan] &= ~0x80;
    Type_802FCA34[chan] |= error;
    work->typeTime[chan] = __OSGetSystemTime();

    type = Type_802FCA34[chan];
    chanBit = 0x80000000 >> chan;
    fix = lbl_8064D8D8 & chanBit;
    lbl_8064D8D8 &= ~chanBit;

    if ((error & 0xF) != 0 || (type & 0x18000000) != 0x08000000 ||
        (type & 0x80000000) == 0 || (type & 0x04000000) != 0) {
        fn_8020EEA8(chan, 0);
        CallTypeAndStatusCallback(work, chan, Type_802FCA34[chan]);
    } else {
        id = fn_8020EE24(chan) << 8;

        if (fix != 0 && (id & 0x100000) != 0) {
            work->cmdFixDevice[chan] =
                0x4E000000 | (id & 0xCFFF00) | 0x100000;
            Type_802FCA34[chan] = 0x80;
            SITransfer(chan, &work->cmdFixDevice[chan], 3,
                       &Type_802FCA34[chan], 3, GetTypeCallback_802093FC, 0);
            return;
        }

        if ((type & 0x00100000) != 0) {
            if ((id & 0xCFFF00) != (type & 0xCFFF00)) {
                if ((id & 0x100000) == 0) {
                    id = type & 0xCFFF00;
                    id |= 0x100000;
                    fn_8020EEA8(chan, id >> 8);
                }

                work->cmdFixDevice[chan] = 0x4E000000 | id;
                Type_802FCA34[chan] = 0x80;
                SITransfer(chan, &work->cmdFixDevice[chan], 3,
                           &Type_802FCA34[chan], 3,
                           GetTypeCallback_802093FC, 0);
                return;
            }
        } else {
            if ((type & 0x40000000) != 0) {
                id = type & 0xCFFF00;
                id |= 0x100000;
                fn_8020EEA8(chan, id >> 8);

                work->cmdFixDevice[chan] = 0x4E000000 | id;
                Type_802FCA34[chan] = 0x80;
                SITransfer(chan, &work->cmdFixDevice[chan], 3,
                           &Type_802FCA34[chan], 3,
                           GetTypeCallback_802093FC, 0);
                return;
            }

            fn_8020EEA8(chan, 0);
        }

        CallTypeAndStatusCallback(work, chan, Type_802FCA34[chan]);
    }
}
