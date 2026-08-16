typedef unsigned char u8;

typedef struct Room8009C28C {
    u8 pad00[0x54];
    void* state;
} Room8009C28C;

typedef struct RoomState8009C28C {
    u8 pad00[0xEC];
    int resource;
} RoomState8009C28C;

extern int lbl_8064D18C;
extern int fn_800CB098(int, int, int, int, int, int);
extern void *fn_80201B8C();

int fn_8009C28C(register void* object)
{
    register int resource;
    register Room8009C28C* room;
    register int current;

    resource = fn_800CB098(2, -1, -1, lbl_8064D18C, 0, 0);
    room = ((Room8009C28C*)fn_80201B8C(object));
    current = ((RoomState8009C28C*)room->state)->resource;
    return current > resource;
}
