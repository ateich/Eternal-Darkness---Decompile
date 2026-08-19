typedef struct Collection {
    char pad00[0x5C];
    unsigned int threshold;
    unsigned int total_size;
} Collection;

extern void fn_80161F3C(Collection*);

void fn_80161FA0(Collection* collection)
{
    if (collection->total_size >= collection->threshold)
        fn_80161F3C(collection);
}
