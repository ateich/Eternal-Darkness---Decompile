extern void fn_80161C30(void*, int);
extern void fn_80161E20(void*);
extern void fn_80161B58(void*, int);
extern void fn_80161AA0(void*);
extern void fn_801619BC(void*);
extern void fn_80161A34(void*);

void fn_80161ED8(void* collection, int preserve)
{
    fn_80161C30(collection, preserve);
    fn_80161E20(collection);
    fn_80161B58(collection, preserve);
    fn_80161AA0(collection);
    fn_801619BC(collection);
    fn_80161A34(collection);
}
