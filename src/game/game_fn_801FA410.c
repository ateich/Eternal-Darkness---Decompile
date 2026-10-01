typedef unsigned char u8;

typedef struct MotionState {
    u8 pad00[0x70];
    struct MotionState* source;
    u8 pad74[0x14];
} MotionState;

extern int lbl_8064C3A8;

static MotionState first[12] = {0};
static MotionState second[12] = {0};
static MotionState current_first = {0};
static MotionState current_second = {0};

int fn_801FA410(int index)
{
    int previous = lbl_8064C3A8;

    lbl_8064C3A8 = index;
    current_first.source = &second[index];
    current_second.source = &first[index];
    return previous;
}
