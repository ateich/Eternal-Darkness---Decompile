extern void* fn_801A717C(void*);
extern void fn_801A74A0(void*, void*);
extern void fn_801A74A8(void*, void*);
extern void fn_801A7470(void*, void*);
extern unsigned long long fn_8020123C();
extern void fn_801A7228(void*);

void fn_80096690(register void* object, register void* value)
{
    register void* record;

    record = fn_801A717C(object);
    fn_801A74A0(record, object);
    fn_801A74A8(record, object);
    fn_801A7470(record, value);
    fn_8020123C(0x35, object, object, record);
    fn_801A7228(record);
}
