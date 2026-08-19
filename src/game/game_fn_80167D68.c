typedef struct Input {
    char pad0[0x10];
    signed char* cursor;
} Input;

signed char* fn_80167D68(Input* input)
{
    signed char* cursor = input->cursor;
    if (*cursor == '@') {
        cursor++;
    }
    return cursor;
}
