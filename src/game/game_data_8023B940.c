typedef unsigned int u32;

typedef void (*Callback)(void);

typedef struct Descriptor {
    u32 mask;
    u32 unused;
    Callback callback;
    void* context;
    u32 value;
    u32 padding[3];
} Descriptor;

typedef struct DebugData {
    Descriptor descriptors[11];
    char entity_counts[16];
    char camera_values[36];
    char player_position[44];
    char fps[12];
    u32 constants[18];
    char camera_name[28];
} DebugData;

extern void fn_80006F30(void);
extern void fn_80006D50(void);
extern void fn_801E7F00(void);
extern void fn_80006A50(void);
extern char lbl_803317E0[];
extern char lbl_803317E4[];
extern char lbl_803317E8[];
extern char lbl_803317EC[];
extern char lbl_803317F0[];

#pragma force_active on
u32 lbl_8023B940[3] = {0, 0, 0xBF800000};

char lbl_8023B94C[] = "Alex Roivas";
char lbl_8023B958[] = "Pious Augustus";
char lbl_8023B968[] = "Dr. Maximillian Roivas";
char lbl_8023B980[] = "Dr. Edwin Lindsey";
char lbl_8023B994[] = "Paul Luther";
char lbl_8023B9A0[] = "Roberto Bianchi";
char lbl_8023B9B0[] = "Dr. Edward M. Roivas";
char lbl_8023B9C8[] = "Peter Jacob";
char lbl_8023B9D4[] = "Michael Edwards";

extern char lbl_8064A980[];
extern char lbl_8064A988[];
extern char lbl_8064A990[];

char* lbl_8023B9E4[12] = {
    lbl_8023B94C, lbl_8023B958, lbl_8064A980, lbl_8064A988,
    lbl_8064A990, lbl_8023B968, lbl_8023B980, lbl_8023B994,
    lbl_8023B9A0, lbl_8023B9B0, lbl_8023B9C8, lbl_8023B9D4,
};

u32 lbl_8023BA14[3] = {0xC4898000, 0x44C80000, 0x41200000};
u32 lbl_8023BA20[4] = {0xC80000FF, 0x0000C8FF, 0x00C800FF, 0x5F164BFF};
u32 lbl_8023BA30[13] = {
    0, 0, 0, 0x0000FFFF, 0x00010000, 1, 0x0000FFFF,
    0, 0xFFFF0001, 0, 0, 0, 0,
};
u32 lbl_8023BA64[15] = {
    0, 0, 0, 3, 1, 2, 1, 2, 3, 2, 3, 1, 0, 4, 0,
};

DebugData lbl_8023BAA0 = {
    {
        {0x00000100, 0, fn_80006F30, 0, 0, {0, 0, 0}},
        {0x00000200, 0, fn_80006F30, 0, 2, {0, 0, 0}},
        {0x00000010, 0, fn_80006F30, 0, 1, {0, 0, 0}},
        {0x000F0000, 0, fn_80006F30, (void*)3, 0x1FFF0000, {0, 0, 0}},
        {0x00001000, 0, fn_80006D50, 0, 1, {0, 0, 0}},
        {0x08000000, 0, fn_801E7F00, 0, 1, {0, 0, 0}},
        {0x00000800, 0, fn_80006A50, lbl_803317E0, 1, {0, 0, 0}},
        {0x00000008, 0, fn_80006A50, lbl_803317E4, 1, {0, 0, 0}},
        {0x00000004, 0, fn_80006A50, lbl_803317E8, 1, {0, 0, 0}},
        {0x00000001, 0, fn_80006A50, lbl_803317EC, 1, {0, 0, 0}},
        {0x00000002, 0, fn_80006A50, lbl_803317F0, 1, {0, 0, 0}},
    },
    "ENT: %d EXT: %d",
    " (%0.0f, %0.0f, %0.0f) fov(%0.0f)",
    "PLAYER POS: (%0.0f, %0.0f, %0.0f) ANG (%f)",
    "   FPS %d",
    {
        0x3F800000, 0x3F800000, 0x3F800000,
        0x3DCCCCCD, 0x3DCCCCCD, 0x3DCCCCCD,
        0, 0, 0, 0x3F800000, 0, 0,
        0xC4058000, 0x44218000, 0x42B60000,
        0xC4340000, 0xC3BE8000, 0x42B60000,
    },
    "Camera: Game Normal\n",
};
#pragma force_active reset
