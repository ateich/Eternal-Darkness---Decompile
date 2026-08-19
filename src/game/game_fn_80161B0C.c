typedef struct Counts {
    int capacity;
    unsigned int used;
} Counts;

extern void fn_80166C14(void*, Counts*, int);

void fn_80161B0C(void* collection, Counts* counts)
{
    int capacity = counts->capacity;
    if (counts->used < capacity / 4 && capacity > 10)
        fn_80166C14(collection, counts, capacity / 2);
}
