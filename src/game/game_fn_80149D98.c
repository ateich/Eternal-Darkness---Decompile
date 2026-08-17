extern void* lbl_8064D09C;
extern void* lbl_8064D18C;
extern void* fn_8017CDB4(void*);
extern unsigned int fn_80149FCC(void);

typedef struct Instance {
    unsigned char pad[0x1320];
    void* owner;
    void* value;
    unsigned char active;
    unsigned char pad1329[3];
    unsigned short state;
    unsigned char pad132E[2];
    unsigned int serial;
    unsigned int id;
} Instance;

Instance* fn_80149D98(void* owner)
{
    Instance* instance = fn_8017CDB4(lbl_8064D09C);

    if (instance != 0) {
        instance->owner = owner;
        instance->state = 0;
        instance->serial = 0;
        instance->id = fn_80149FCC();
        instance->active = 1;
        instance->value = lbl_8064D18C;
    }
    return instance;
}
