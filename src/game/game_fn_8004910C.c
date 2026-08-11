extern void* fn_801A7778(void);
extern void* fn_8020499C(void* object);

void* fn_8004910C(void)
{
    void* result = 0;
    void* object = fn_801A7778();

    if (object != 0) {
        result = fn_8020499C(object);
    }
    return result;
}
