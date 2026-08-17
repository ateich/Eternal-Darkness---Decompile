extern void fn_801936FC(void);
extern void fn_8014AE54(void);
extern void* memset(void*, int, unsigned long);

typedef struct Descriptor { unsigned char pad[0x90]; void* callback; unsigned int value94; void* handler; unsigned int value9C; unsigned int valueA0; unsigned int valueA4; unsigned char padA8[0x14]; unsigned char type; } Descriptor;
typedef struct Work { unsigned char active; unsigned char pad[0x87]; unsigned char data[0x40]; } Work;

void fn_8014A2AC(Descriptor* descriptor, Work* work)
{
    descriptor->callback = fn_801936FC;
    descriptor->value94 = 0;
    descriptor->handler = fn_8014AE54;
    descriptor->value9C = 0;
    descriptor->valueA0 = 0;
    descriptor->valueA4 = 0;
    descriptor->type = 4;
    work->active = 1;
    memset(work->data, 0, 0x40);
}
