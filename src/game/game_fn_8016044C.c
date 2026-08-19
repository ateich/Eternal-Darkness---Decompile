typedef struct Entry {
    int type;
    char pad4[12];
} Entry;

extern void fn_801603AC(void*, Entry*, char*);

void fn_8016044C(void* object, Entry* entry, int type, char* text)
{
    if (entry->type == type)
        entry++;
    fn_801603AC(object, entry, text);
}
