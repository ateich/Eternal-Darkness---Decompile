typedef unsigned int u32;

extern char fn_800462C8[];

struct NpcResources {
    char chat_l[16];
    char uly_l[12];
    char xel_l[12];
    char chat_v[16];
    char uly_v[12];
    char xel_v[12];
    char chat_g[16];
    char uly_g[12];
    char xel_g[12];
    char npc_format[12];
    char character_data[20];
};

#pragma force_active on
struct NpcResources lbl_8023EAE8 = {
    "NPCChatL.gpk",
    "NPCUlyL.gpk",
    "NPCXelL.gpk",
    "NPCChatV.gpk",
    "NPCUlyV.gpk",
    "NPCXelV.gpk",
    "NPCChatG.gpk",
    "NPCUlyG.gpk",
    "NPCXelG.gpk",
    "NPCS%d.NPC",
    "/ai/ed_chrs.dat",
};

u32 lbl_8023EB80[5] = { 0, 2, 3, 1, 15 };

#define CASE_COMMON (u32)(fn_800462C8 + 0x6C)
#define CASE_NEXT (u32)(fn_800462C8 + 0x90)

u32 jumptable_8023EB94[33] = {
    CASE_COMMON, CASE_NEXT,   CASE_NEXT,   CASE_NEXT,   CASE_NEXT,
    CASE_COMMON, CASE_NEXT,   CASE_COMMON, CASE_COMMON,
    (u32)(fn_800462C8 + 0x74),
    CASE_NEXT,   CASE_COMMON, CASE_COMMON, CASE_COMMON, CASE_COMMON,
    CASE_COMMON, CASE_NEXT,   CASE_NEXT,   CASE_COMMON, CASE_COMMON,
    CASE_NEXT,   CASE_COMMON, CASE_COMMON, CASE_NEXT,   CASE_COMMON,
    CASE_COMMON, CASE_COMMON, CASE_NEXT,   CASE_COMMON, CASE_COMMON,
    CASE_COMMON, CASE_COMMON, CASE_COMMON,
};
#pragma force_active reset
