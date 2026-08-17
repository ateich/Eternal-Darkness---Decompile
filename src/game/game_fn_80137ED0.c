extern void* fn_80137EFC(int id);
extern void fn_80137DD4(void* entry);

void fn_80137ED0(int id)
{
    void* entry = fn_80137EFC(id);
    if (entry != 0) {
        fn_80137DD4(entry);
    }
}
