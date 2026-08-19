typedef unsigned char u8;

typedef struct Request {
    int type;
    int active;
    int pad8;
    int value;
    void* destination;
    void* reply_queue;
} Request;

typedef struct WorkerState {
    u8 pad0[0x2048];
    int active;
    u8 pad204C[4];
    int pending;
    u8 pad2054[0xC];
    void* input_queue;
    u8 pad2064[8];
    void* reply_queue;
} WorkerState;

extern Request* fn_801587C4(void);
extern void fn_8020D250(void*, void*, int);
extern void fn_8020D318(void*, void**, int);
extern void fn_80158850(void*);

void fn_8015D4EC(void* destination, int value, WorkerState* state)
{
    int message;
    Request* request;

    if (state->active == 1 && state->pending == 0) {
        request = fn_801587C4();
        request->active = 1;
        request->value = value;
        request->destination = destination;
        request->reply_queue = state->reply_queue;
        fn_8020D250(state->input_queue, request, 1);
        fn_8020D318(request->reply_queue, (void**)&message, 1);
        if (message == 0x2A) {
            fn_8020D250(request->reply_queue, (void*)0x2A, 1);
        } else {
            fn_80158850((void*)message);
        }
    }
}
