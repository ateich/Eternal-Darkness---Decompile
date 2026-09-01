typedef struct Source {
    unsigned char pad0[4];
    int value;
    unsigned char pad8[6];
    unsigned short type;
    int data;
    int size;
} Source;

extern void fn_80139E04(void*, int, int, int, int);
extern void fn_8012B408(int, int);
void fn_80139D88(unsigned char* object, Source* source)
{
    int resource;
    int data;

    fn_80139E04(object, source->value, source->size, source->data, source->type);
    data = *(volatile int*)(object + 0x28C);
    resource = *(volatile int*)(object + 0x284);
    fn_8012B408(resource, data);
}
