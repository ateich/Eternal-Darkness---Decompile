typedef struct Value {
    int type;
    int pad04;
    double number;
} Value;

extern Value* fn_8016A55C(void*, int);
extern int fn_80168A08(Value*);
extern double lbl_80650688;

double fn_8016A694(void* context, int index)
{
    int invalid;
    Value* value = fn_8016A55C(context, index);
    invalid = value == 0 || (value->type != 2 && fn_80168A08(value) != 0);
    return invalid ? lbl_80650688 : value->number;
}
