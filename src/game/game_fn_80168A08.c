typedef struct Value {
    int type;
    int unused;
    char* data;
} Value;

extern int fn_80163B14(void*, void*);

int fn_80168A08(Value* value)
{
    if (value->type != 3)
        return 1;
    if (fn_80163B14(value->data + 0x14, &value->data) == 0)
        return 2;
    value->type = 2;
    return 0;
}
