typedef unsigned char u8;

typedef struct Request {
    int kind;
    int state;
    int result;
    u8 value;
} Request;

extern char lbl_80250FF4[];
extern void fn_8017B344(u8, int);
extern int fn_8017B35C(u8);
extern void fn_8017BA54();
extern void fn_8017BA60(char*);
extern void fn_8017AF78(void);

void fn_8017C724(Request* request)
{
    switch (request->result) {
    case -6:
        fn_8017B344(request->value, 2);
        fn_8017BA54(fn_8017B35C(request->value));
        request->state = 2;
        break;
    case -13:
        fn_8017B344(request->value, 3);
        fn_8017BA54(fn_8017B35C(request->value));
        request->state = 2;
        break;
    case 0:
        fn_8017B344(request->value, 1);
        fn_8017BA54(fn_8017B35C(request->value));
        request->state = 2;
        break;
    case -1:
        break;
    default:
        fn_8017BA60(lbl_80250FF4);
        fn_8017AF78();
        fn_8017BA54(0, 0);
        request->state = 2;
        break;
    }
}
