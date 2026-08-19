typedef struct Object {
    void* current;
    char* allocation;
    char* end;
    int count;
    void* start;
    char pad14[0x4c];
    char* limit;
} Object;

extern char lbl_8064BA58;
extern void* fn_8016B5CC(void*, int, unsigned int, const char*, int);

void fn_801604F8(Object* object, int count)
{
    object->allocation = fn_8016B5CC(object, 0, (count + 40) << 4,
                                    &lbl_8064BA58, 35);
    object->limit += count << 4;
    object->end = object->allocation + ((count - 1) << 4);
    object->count = count;
    object->start = object->current = object->allocation;
}
