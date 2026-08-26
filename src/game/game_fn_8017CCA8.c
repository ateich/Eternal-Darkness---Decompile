typedef unsigned short u16;

typedef struct BufferState {
    void* data;
    void* other;
    u16 count;
    u16 size;
} BufferState;

extern BufferState lbl_80606300;
extern BufferState lbl_8060630C;

void fn_8017CCA8(void* data, u16 count, void* other, u16 size)
{
    lbl_80606300.data = data;
    lbl_80606300.count = count;
    lbl_80606300.other = other;
    lbl_80606300.size = size;
    lbl_8060630C.data = data;
    lbl_8060630C.count = 0;
    lbl_8060630C.other = other;
    lbl_8060630C.size = 0;
}
