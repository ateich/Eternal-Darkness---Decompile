typedef struct Value {
    int type;
    int pad04;
    void** pointer;
} Value;

extern Value* fn_8016A55C(void*, int);

void* fn_8016A784(void* context, int index)
{
    Value* value = fn_8016A55C(context, index);
    int invalid = value == 0 || value->type != 0;
    return invalid ? 0 : value->pointer[1];
}
