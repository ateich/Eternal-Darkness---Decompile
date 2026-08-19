typedef struct Collection {
    char pad00[0x5C];
    int threshold;
    int total_size;
} Collection;

extern const volatile unsigned int lbl_8023A868[4];
extern void fn_80161798(Collection*);
extern void fn_80161948(Collection*);
extern void fn_80161ED8(Collection*, int);
extern void fn_80161CF8(Collection*);
extern void fn_80161D58(Collection*, char*);

void fn_80161F3C(Collection* collection)
{
    fn_80161798(collection);
    fn_80161948(collection);
    fn_80161ED8(collection, 0);
    fn_80161CF8(collection);
    collection->threshold = collection->total_size << 1;
    fn_80161D58(collection, (char*)lbl_8023A868);
}
