typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3_8009C300 { float x, y, z; } Vec3_8009C300;

typedef struct Effect8009C300 {
    u32 field00;
    u32 timer;
    u8 pad08[0xC];
    u32 arg2;
    u32 arg3;
    Vec3_8009C300 position;
    u32 handle;
    u16 field2C;
    u16 field2E;
    u8 pad30[4];
    u16 owner_id;
    u8 pad36;
    u8 field37;
    u8 field38;
    u8 pad39[0xF];
    void* callback;
    u8 pad4C[0x18];
    u32 actor_id;
    void* update;
    u32 type;
} Effect8009C300;

extern Effect8009C300 lbl_8031D650;
extern void* lbl_8064C5A8;
extern void fn_8014CBC0(Effect8009C300*);
extern void fn_80149CC4(void*, Vec3_8009C300*, u32, u32, int);
extern void* fn_801D39E0(void*);
extern void fn_801FDA18(void);
extern void fn_8014C9F4(void);
extern int fn_80201B54(void*);
extern int fn_80201EB8(void*);
extern void fn_801E8328(int);

void fn_8009C300(register void* object, register u32 arg2, register u32 arg3)
{
    Vec3_8009C300 position;

    fn_8014CBC0(&lbl_8031D650);
    fn_80149CC4(object, &position, arg2, arg3, 0);
    lbl_8031D650.type = 0xCD;
    lbl_8031D650.field00 = 0;
    lbl_8031D650.position = position;
    lbl_8031D650.handle = (u32)fn_801D39E0(*(void**)lbl_8064C5A8);
    lbl_8031D650.timer = 2500;
    lbl_8031D650.callback = fn_801FDA18;
    lbl_8031D650.field2C = 0;
    lbl_8031D650.arg2 = arg2;
    lbl_8031D650.arg3 = arg3;
    lbl_8031D650.actor_id = fn_80201B54(object);
    lbl_8031D650.update = fn_8014C9F4;
    lbl_8031D650.field37 = 0;
    lbl_8031D650.field38 = 2;
    lbl_8031D650.field2E = 4;
    lbl_8031D650.owner_id = fn_80201EB8(object);
    fn_801E8328(20);
}
