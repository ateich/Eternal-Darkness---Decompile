typedef struct DebugEntry {
    void* object;
    void* owner;
    unsigned char active;
    unsigned char pad9;
    unsigned short timer;
} DebugEntry;

extern unsigned char lbl_805B1268[];

void fn_801409C0(unsigned char index)
{
    unsigned int offset = index * sizeof(DebugEntry);
    unsigned char* base = lbl_805B1268;
    DebugEntry* entry = (DebugEntry*)(base + offset);
    entry->timer = 0;
    *(void**)(base + offset) = 0;
    entry->owner = 0;
    entry->active = 0;
}
