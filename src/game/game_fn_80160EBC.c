extern int fn_80160E50(void*, void*, void*, void*);
extern void fn_80160D10(void*, int, int);

void fn_80160EBC(void* object, void* text, void* value, void* context)
{
    if (fn_80160E50(object, text, value, context) == 0) {
        fn_80160D10(object, 0, -1);
    }
}
