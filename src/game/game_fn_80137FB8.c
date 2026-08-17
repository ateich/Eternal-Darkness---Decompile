typedef struct Entry {
    unsigned int flags;
    int id;
    void* owner;
    float position[3];
    float radius;
} Entry;

extern Entry* fn_80137EFC(int id);

float* fn_80137FB8(int id)
{
    Entry* entry;
    float* result;

    result = 0;
    entry = fn_80137EFC(id);
    if (entry != 0) {
        result = entry->position;
    }
    return result;
}
