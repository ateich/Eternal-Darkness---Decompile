typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Envelope {
    u8 mode;
    u8 pad_01[0x1F];
    u32 release;
} Envelope;

extern int fn_801C2D9C(Envelope* envelope, u32 duration);

int fn_801C2EF0(Envelope* envelope)
{
    switch (envelope->mode) {
    case 0:
    case 1:
        return fn_801C2D9C(envelope, envelope->release);
    }
    return 0;
}
