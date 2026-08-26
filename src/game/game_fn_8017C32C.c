typedef unsigned char u8;
typedef unsigned int u32;

typedef struct GlobalState {
    u8 pad_00[0x28];
    int states[2];
} GlobalState;

typedef struct Request {
    int kind;
    int state;
    int result;
    u8 value;
} Request;

extern GlobalState lbl_8064A580;
extern u32 lbl_8064D20C;
extern int fn_80221394(u8, int);
extern u32 fn_8021EB20(u8);

void fn_8017C32C(Request* request)
{
    if (lbl_8064A580.states[request->value] != 0) {
        request->result = fn_80221394(request->value, 0);
        if (request->result >= 0) {
            (&lbl_8064D20C)[request->value] = fn_8021EB20(request->value);
            request->state = 1;
        }
    } else {
        request->state = 2;
        request->result = -3;
    }
}
