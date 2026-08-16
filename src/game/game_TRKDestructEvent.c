typedef unsigned char u8;
typedef struct TRKEvent {
    u8 type;
    u8 pad[3];
    unsigned id;
    int buffer;
} TRKEvent;

extern void fn_800EFCDC(int);

void TRKDestructEvent(TRKEvent *event)
{
    fn_800EFCDC(event->buffer);
}
