extern void fn_801936FC(void);
extern void fn_8014AF38(void);
extern void fn_8014B494(void);
extern void* memset(void*, int, unsigned long);

typedef struct Descriptor { unsigned char pad[0x90]; void* callback; unsigned int value94; void* handler; unsigned int value9C; void* secondary; unsigned int valueA4; unsigned char padA8[0x14]; unsigned char type; } Descriptor;
typedef struct Work { unsigned char active; unsigned char pad[0x87]; unsigned char data[0x40]; } Work;

void fn_8014A178(Descriptor* descriptor, Work* work)
{
    descriptor->callback = fn_801936FC;
    descriptor->value94 = 0;
    descriptor->handler = fn_8014AF38;
    descriptor->value9C = 0;
    descriptor->secondary = fn_8014B494;
    descriptor->valueA4 = 0;
    descriptor->type = 1;
    work->active = 1;
    memset(work->data, 0, 0x40);
}
