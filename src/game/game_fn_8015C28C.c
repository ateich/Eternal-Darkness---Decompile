typedef struct Shared { int primary; int secondary; short requested; unsigned char pad[2]; void* slots[2]; } Shared;
extern volatile Shared lbl_805B6FE0;

void* fn_8015C28C(int selector)
{
    void* result = 0;
    if (selector == 2) {
        result = lbl_805B6FE0.slots[lbl_805B6FE0.primary];
    } else if (selector == 3) {
        if (lbl_805B6FE0.secondary != -1)
            result = lbl_805B6FE0.slots[lbl_805B6FE0.secondary];
    } else {
        result = lbl_805B6FE0.slots[selector];
    }
    return result;
}
