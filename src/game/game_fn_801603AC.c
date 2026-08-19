typedef struct Entry {
    int type;
} Entry;

extern char* fn_80160280(void*, Entry*, char**);
extern void fn_80163BB4(void*, const char*, ...);
extern void* lbl_8023A878[];
extern char lbl_8024F504[];
extern char lbl_8024F534[];

void fn_801603AC(void* object, Entry* entry, char* text)
{
    char* value;
    char* kind = fn_80160280(object, entry, &value);
    void* descriptor = lbl_8023A878[entry->type];

    if (kind != 0) {
        fn_80163BB4(object, lbl_8024F504, text, kind, value, descriptor);
    } else {
        fn_80163BB4(object, lbl_8024F534, text, descriptor);
    }
}
