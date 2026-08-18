typedef struct Value {
    char pad[0x44];
    unsigned int flags;
} Value;

unsigned int fn_801562DC(Value* value)
{
    return (value->flags >> 9) & 1;
}
