typedef struct Value {
    int type;
    char payload[12];
} Value;

extern Value* fn_8016A55C(void*, int);

int fn_8016A5F4(void* context, int index)
{
    Value* value = fn_8016A55C(context, index);
    if (value == 0) {
        return -1;
    }
    return value->type;
}
