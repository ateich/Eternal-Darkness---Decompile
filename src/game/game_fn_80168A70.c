typedef struct Value {
    int type;
    int unused;
    union {
        double number;
        char* string;
    } data;
} Value;

extern char lbl_8064BBE0;
extern int fn_800F9D4C(char*, const char*, ...);
extern char* fn_801670A8(void*, const char*);

int fn_80168A70(void* state, Value* value)
{
    char buffer[24];

    if (value->type != 2)
        return 1;
    fn_800F9D4C(buffer, &lbl_8064BBE0, value->data.number);
    value->data.string = fn_801670A8(state, buffer);
    value->type = 3;
    return 0;
}
