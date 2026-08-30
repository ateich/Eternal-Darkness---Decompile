typedef struct {
    unsigned char pad[0x68];
    void* object;
} Data;

extern void fn_80157894(void*);

void fn_801A7910(Data* data) { fn_80157894(data->object); }
