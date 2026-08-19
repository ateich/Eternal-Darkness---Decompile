typedef struct InputStream InputStream;

struct InputStream {
    unsigned int remaining;
    unsigned char* cursor;
    int (*refill)(InputStream*);
};

extern void fn_80167D80(void*, InputStream*);

int fn_80167DC8(void* object, InputStream* input)
{
    int result;

    if (input->remaining-- != 0) {
        result = *input->cursor++;
    } else {
        result = input->refill(input);
    }

    if (result == -1) {
        fn_80167D80(object, input);
    }
    return result;
}
