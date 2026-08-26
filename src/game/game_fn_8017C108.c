typedef unsigned char u8;

typedef struct Request {
    int kind;
    int state;
    int result;
    u8 value;
} Request;

extern int fn_80220234(u8, int*, int*);
extern void* fn_8017AF64(void);
extern void fn_8017B7EC(int);
extern void fn_8017BA64(unsigned int);
extern int fn_802208C8(u8, void*, void (*)(unsigned int), int);
extern int fn_8021EB20(u8, int);
extern int lbl_8064D20C;
extern char lbl_80250FB0[];
extern void fn_8017BA60();
extern void fn_8017AF78(void);

void fn_8017C108(Request* request)
{
    int first;
    int second;
    void* registration;

    request->result = fn_80220234(request->value, &first, &second);
    if (request->result == 0) {
        registration = fn_8017AF64();
        fn_8017B7EC(second);
        request->result = fn_802208C8(request->value, registration,
                                     fn_8017BA64, 0);
        if (request->result >= 0) {
            (&lbl_8064D20C)[request->value] =
                fn_8021EB20(request->value, request->result);
            request->state = 1;
        } else {
            fn_8017BA60(lbl_80250FB0);
            fn_8017AF78();
        }
    }
}
