typedef unsigned char u8;
typedef unsigned int u32;

typedef struct GlobalState {
    void* buffer;
    u8 pad_04[0x24];
    int states[2];
    u8 pad_30[0x10];
    u8 statuses[2];
} GlobalState;

typedef struct Request {
    int kind;
    int state;
    int result;
    u8 value;
    u8 payload[1];
} Request;

extern GlobalState lbl_8064A580;
extern u32 lbl_8064D20C;
extern int fn_802223DC(u8, void*, int);
extern u32 fn_8021EB20(u8);

void fn_8017C67C(Request* request)
{
    u8 value = request->value;

    if (lbl_8064A580.states[value] == 1) {
        if (lbl_8064A580.statuses[value] == 0) {
            request->result = fn_802223DC(value, request->payload, 0);
            if (request->result >= 0) {
                (&lbl_8064D20C)[request->value] =
                    fn_8021EB20(request->value);
                request->state = 1;
            }
        }
    } else {
        request->state = 2;
        request->result = -3;
    }
}
