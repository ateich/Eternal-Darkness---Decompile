typedef struct InputStream InputStream;

struct InputStream {
    unsigned int remaining;
    unsigned char* cursor;
    int (*refill)(InputStream*);
};

#pragma use_lmw_stmw on

extern void* fn_801688B0(void*, InputStream*);
extern int fn_80167D68(InputStream*);
extern void fn_80163BB4(void*, const char*, ...);
extern const char lbl_8024FC84[];

void* fn_801688F8(void* object, InputStream* input)
{
    void* result = 0;
    int byte;

    if (input->remaining-- != 0)
        byte = *input->cursor++;
    else
        byte = input->refill(input);

    if (byte == 0x1B)
        result = fn_801688B0(object, input);

    if (input->remaining-- != 0)
        byte = *input->cursor++;
    else
        byte = input->refill(input);

    if (byte != -1)
        fn_80163BB4(object, lbl_8024FC84, fn_80167D68(input));

    return result;
}
