typedef struct Allocation {
    int index;
    int count;
    void* records;
} Allocation;

extern Allocation** lbl_8064CFF0;
extern void* fn_80139CFC(int);

Allocation* fn_80139C74(int index, int count)
{
    Allocation* allocation;

    if (lbl_8064CFF0[index] == 0) {
        allocation = fn_80139CFC(692);
        lbl_8064CFF0[index] = allocation;
        allocation->index = index;
        allocation->count = count;
        allocation->records = fn_80139CFC(count * 12);
    }
    return lbl_8064CFF0[index];
}
