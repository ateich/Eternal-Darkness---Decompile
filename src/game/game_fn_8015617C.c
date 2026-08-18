typedef struct Value {
    char pad[0x3c];
    int state;
} Value;

unsigned char fn_8015617C(Value* value)
{
    return value->state == 2;
}
