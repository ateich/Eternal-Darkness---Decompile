typedef struct {
    unsigned char pad[0x68];
    void* object;
} Data;

extern void fn_80157888(void*);

void fn_801A78EC(Data* data) { fn_80157888(data->object); }
