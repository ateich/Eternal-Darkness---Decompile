typedef struct Entry {
    int type;
    char pad4[12];
} Entry;

extern char* lbl_8023A878[];
extern char lbl_8024F554[];
extern char lbl_8024F578[];
extern void fn_80163BB4(void*, const char*, ...);

void fn_80160480(void* object, Entry* entry)
{
    const char* first = lbl_8023A878[entry[-2].type];
    const char* second = lbl_8023A878[entry[-1].type];

    if ((signed char)first[2] == (signed char)second[2])
        fn_80163BB4(object, lbl_8024F554, first);
    else
        fn_80163BB4(object, lbl_8024F578, first, second);
}
