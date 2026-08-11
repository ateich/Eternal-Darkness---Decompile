typedef int s32;

typedef struct AlignmentRecord {
    s32 value;
    s32 unknown_04;
    s32 alternate;
} AlignmentRecord;

#pragma force_active on
AlignmentRecord lbl_8023E118[5] = {
    {0, 0, 0},
    {3, 1, 2},
    {1, 2, 3},
    {2, 3, 1},
    {0, 4, 0},
};
#pragma force_active reset
