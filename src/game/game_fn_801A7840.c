typedef struct {
    unsigned char pad[0x68];
    void* object;
} Data;

extern void fn_801578AC(void*);

void fn_801A7840(Data* data) { fn_801578AC(data->object); }
