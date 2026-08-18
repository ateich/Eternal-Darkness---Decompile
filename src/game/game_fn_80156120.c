typedef struct Value {
    char pad0[0x10];
    unsigned int field_10;
    unsigned int field_14;
    char pad18[0x20];
    unsigned int field_38;
    unsigned int field_3c;
    int id;
    unsigned int flags;
} Value;

extern void* memset(void*, int, unsigned long);
extern int fn_80155FD8(void);

void fn_80156120(Value* value)
{
    memset(value, 0, 0x48);
    value->flags |= 1;
    value->id = fn_80155FD8();
    value->field_38 = 0;
    value->field_3c = 0;
    value->field_10 = 0;
    value->field_14 = 0;
}
