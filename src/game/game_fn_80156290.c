typedef struct Value Value;

struct Value {
    Value* next;
    char pad4[0x40];
    unsigned int flags;
};

extern Value* fn_80155EF4(void);

void fn_80156290(unsigned int flags)
{
    Value* value = fn_80155EF4();
    unsigned int mask = ~flags;

    while (value != 0) {
        value->flags &= mask;
        value = value->next;
    }
}
