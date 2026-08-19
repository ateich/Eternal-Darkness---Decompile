typedef struct WorkerState WorkerState;

extern void* fn_8015D424(int*, void*);
extern WorkerState* fn_8015A1C0(int, int, void*);
extern void fn_8015D304(void*, WorkerState*);
extern void fn_8015D4EC(int*, int, WorkerState*);
extern void fn_8015D5B0(WorkerState*);
extern void fn_8015D44C(void);

int fn_8015D458(void* owner, int* result, void* callback)
{
    int value;
    int size;
    void* buffer;
    WorkerState* state;

    buffer = fn_8015D424(&size, (void*)3);
    state = fn_8015A1C0(2, size, buffer);
    fn_8015D304(owner, state);
    fn_8015D4EC(&value, 4, state);
    fn_8015D4EC(result, value, state);
    fn_8015D5B0(state);
    fn_8015D44C();
    return value;
}
