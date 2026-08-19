typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Request {
    void* owner;
    u32 field4;
    u32 pad8;
    u32 result;
    u32 field10;
    void* reply_queue;
} Request;

typedef struct WorkerState {
    u8 pad0[0x2060];
    void* queue0;
    void* queue1;
    void* input_queue;
    void* reply_queue;
} WorkerState;

#pragma use_lmw_stmw on

extern Request* fn_801587C4(void);
extern int fn_8020D318(void*, void**, int);
extern void fn_8020D250(void*, void*, int);
extern void fn_80158850(void*);

u32 fn_8015D304(void* owner, WorkerState* state)
{
    Request* request;
    void* message;
    u32 result;

    request = fn_801587C4();
    request->owner = owner;
    request->field4 = 0;
    request->result = 0;
    request->field10 = 0;
    request->reply_queue = state->reply_queue;

    while (fn_8020D318(request->reply_queue, &message, 0)) {
        if (message != 0 && (int)message != 0x2A) {
            fn_80158850(message);
        }
    }
    while (fn_8020D318(state->queue0, &message, 0)) {
        if (message != 0 && (int)message != 0x2A) {
            fn_80158850(message);
        }
    }
    while (fn_8020D318(state->queue1, &message, 0)) {
    }

    fn_8020D250(state->input_queue, request, 1);
    fn_8020D318(state->reply_queue, &message, 1);
    result = ((Request*)message)->result;
    fn_80158850(message);
    return result;
}
