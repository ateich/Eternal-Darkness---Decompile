typedef int (*Reader)(void);

typedef struct Input {
    unsigned int remaining;
    const unsigned char* cursor;
    Reader reader;
    int state;
    void* user;
} Input;

extern int fn_8016A444(void);

Input* fn_8016A44C(Input* input, const unsigned char* data,
                  unsigned int size, void* user)
{
    if (data == 0) {
        return 0;
    }
    input->remaining = size;
    input->cursor = data;
    input->reader = fn_8016A444;
    input->state = 0;
    input->user = user;
    return input;
}
