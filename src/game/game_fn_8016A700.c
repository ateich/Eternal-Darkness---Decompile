typedef struct Value {
    int type;
    int pad04;
    void* pointer;
} Value;

extern Value* fn_8016A55C(void*, int);
extern int fn_80168A70(void*, Value*);

void* fn_8016A700(void* context, int index)
{
    Value* value = fn_8016A55C(context, index);
    int invalid = value == 0 ||
                  (value->type != 3 && fn_80168A70(context, value) != 0);
    return invalid ? 0 : (char*)value->pointer + 20;
}
