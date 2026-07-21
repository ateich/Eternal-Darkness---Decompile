typedef unsigned int u32;
typedef signed short s16;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct PlayerInfo {
    unsigned char pad[0x88];
    s16 value_88;
    s16 value_8A;
} PlayerInfo;

extern int lbl_8064CB4C;
extern void* lbl_8064C4E4;
extern int lbl_8064D18C;
extern int lbl_8064D5E4;
extern const u32 lbl_8064DC98;
extern const u32 lbl_8064DC9C;
extern const u32 lbl_8064DCA0;
extern const u32 lbl_8064DCA4;
extern const u32 lbl_8064DCA8;
extern const u32 lbl_8064DCAC;
extern const u32 lbl_8064DCB0;
extern const float lbl_8064DCB4;
extern const float lbl_8064DCB8;
extern char lbl_8064A9A0;
extern char lbl_8064A9A8;
extern char lbl_8023BAA0[];

extern PlayerInfo* fn_8015C28C(int);
extern void fn_801F68B0(Vec3*);
extern float fn_801F691C(void);
extern void fn_801F3EDC(void);
extern void fn_801A8D38(int);
extern void fn_801A8660(int, int, int, int, int, const u32*);
extern void fn_801E3AA4(int);
extern void fn_801E5430(int, int);
extern void fn_801E3A34(const u32*);
extern void fn_801E56AC(float, const char*, ...);
extern float fn_8012B750(void*);
extern void fn_8011F114(Vec3*, void*);
extern void fn_801A7BA0(int, int, float);

void fn_80006B38(void)
{
    PlayerInfo* player;
    Vec3 position;
    Vec3 player_position;
    Vec3 temporary;
    float value;
    char* strings = lbl_8023BAA0;
    u32 color0;
    u32 color1;
    u32 color2;
    u32 color3;
    u32 color4;
    u32 color5;
    u32 color6;

    if (lbl_8064CB4C == 0) {
        return;
    }

    player = fn_8015C28C(2);
    fn_801F68B0(&temporary);
    position = temporary;
    value = fn_801F691C();
    fn_801F3EDC();
    fn_801A8D38(5);

    color0 = lbl_8064DC98;
    fn_801A8660(0, 0x190, 0x27F, 0x4F, -1, &color0);
    fn_801E3AA4(0);

    fn_801E5430(10, 0x190);
    color1 = lbl_8064DC9C;
    fn_801E3A34(&color1);
    fn_801E56AC(lbl_8064DCB4, &lbl_8064A9A0, lbl_8064D18C);

    fn_801E5430(0x7D, 0x190);
    color2 = lbl_8064DCA0;
    fn_801E3A34(&color2);
    fn_801E56AC(lbl_8064DCB4, strings + 0x160, player->value_88,
                player->value_8A);

    fn_801E5430(0x140, 0x190);
    color3 = lbl_8064DCA4;
    fn_801E3A34(&color3);
    fn_801E56AC(lbl_8064DCB4, &lbl_8064A9A8);
    fn_801E56AC(lbl_8064DCB4, strings + 0x170, position.x, position.y,
                position.z, value);

    if (lbl_8064C4E4 != 0) {
        value = fn_8012B750(lbl_8064C4E4);
        fn_8011F114(&player_position, lbl_8064C4E4);
        fn_801E5430(10, 0x1A4);
        color4 = lbl_8064DCA8;
        fn_801E3A34(&color4);
        fn_801E56AC(lbl_8064DCB4, strings + 0x194, player_position.x,
                    player_position.y, player_position.z, value);
    }

    fn_801E5430(0x1E0, 0x1A4);
    color5 = lbl_8064DCAC;
    fn_801E3A34(&color5);
    fn_801E56AC(lbl_8064DCB4, strings + 0x1C0, lbl_8064D5E4);

    color6 = lbl_8064DCB0;
    fn_801E3A34(&color6);
    fn_801A7BA0(0x3C, 0x3C, lbl_8064DCB8);
}
