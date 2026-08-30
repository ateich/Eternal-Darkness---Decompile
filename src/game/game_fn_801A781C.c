typedef struct {
    unsigned char pad[0x68];
    void* object;
} Data;

extern void fn_80158210(void*);

void fn_801A781C(Data* data) { fn_80158210(data->object); }
