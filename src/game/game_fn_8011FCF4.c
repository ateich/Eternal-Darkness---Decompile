typedef struct Registry {
    char pad[0x54];
    unsigned short count;
    void** entries;
} Registry;

extern Registry* fn_8015C348(int kind);

void* fn_8011FCF4(void* object)
{
    Registry* registry = fn_8015C348(2);
    int i;

    for (i = 0; i < registry->count; i++) {
        void* entry = registry->entries[i];
        if (*(void**)entry == *(void**)((char*)object + 0x3C)) {
            return entry;
        }
    }
    return 0;
}
