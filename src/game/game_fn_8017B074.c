typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;

typedef struct Request {
    int kind;
    int state;
    int result;
    u8 value;
    u8 pad_0D[0x23];
    int unk_30;
    int unk_34;
    u64 time;
    u16 attempts;
    u16 pad_42;
    int unk_44;
} Request;

extern u64 OSGetTime(void);
extern void fn_8017C1C8(Request*);

void fn_8017B074(int value)
{
    Request request;

    request.kind = 2;
    request.state = 0;
    request.value = value;
    request.unk_30 = 0;
    request.time = OSGetTime();
    request.attempts = 0;
    request.unk_44 = 0;
    fn_8017C1C8(&request);
}
