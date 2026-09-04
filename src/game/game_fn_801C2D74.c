typedef unsigned char u8;

typedef struct Envelope {
    u8 mode;
    u8 state;
} Envelope;

extern int fn_801C2B00(Envelope* envelope);

int fn_801C2D74(Envelope* envelope)
{
    envelope->state = 0;
    return fn_801C2B00(envelope);
}
