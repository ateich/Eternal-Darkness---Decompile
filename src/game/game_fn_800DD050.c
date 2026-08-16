typedef unsigned int u32;
typedef unsigned short u16;

typedef struct ConfigEntry {
    u32 kind;
    u32 value;
    u16 first;
    u16 second;
    u16 third;
    u16 duration;
} ConfigEntry;

extern ConfigEntry lbl_8031D3F8[24];
extern int lbl_8064C564;
extern int lbl_8064C560;
extern void *memset(void *, int, unsigned long);

void fn_800DD050(void)
{
    ConfigEntry *entry = lbl_8031D3F8;

    memset(entry, 0, sizeof(ConfigEntry) * 24);
    lbl_8064C564 = 0;
    lbl_8064C560 = 0;

    entry[0].kind = 2; entry[0].value = 245; entry[0].first = 53; entry[0].second = 85; entry[0].third = 0; entry[0].duration = 2100;
    entry[1].kind = 2; entry[1].value = 243; entry[1].first = 10; entry[1].second = 14; entry[1].third = 0; entry[1].duration = 1500;
    entry[2].kind = 1; entry[2].value = 247; entry[2].first = 5; entry[2].second = 5; entry[2].third = 5; entry[2].duration = 2400;
    entry[3].kind = 0;
    entry[4].kind = 2; entry[4].value = 247; entry[4].first = 0; entry[4].second = 3; entry[4].third = 3; entry[4].duration = 300;
    entry[5].kind = 2; entry[5].value = 243; entry[5].first = 13; entry[5].second = 10; entry[5].third = 0; entry[5].duration = 900;
    entry[6].kind = 2; entry[6].value = 245; entry[6].first = 85; entry[6].second = 9; entry[6].third = 0; entry[6].duration = 1200;
    entry[7].kind = 1; entry[7].value = 246; entry[7].first = 3; entry[7].second = 23; entry[7].third = 23; entry[7].duration = 2100;
    entry[8].kind = 2; entry[8].value = 245; entry[8].first = 46; entry[8].second = 85; entry[8].third = 0; entry[8].duration = 1200;
    entry[9].kind = 2; entry[9].value = 243; entry[9].first = 10; entry[9].second = 23; entry[9].third = 0; entry[9].duration = 900;
    entry[10].kind = 1; entry[10].value = 241; entry[10].first = 4; entry[10].second = 4; entry[10].third = 4; entry[10].duration = 1800;
    entry[11].kind = 0;
    entry[12].kind = 2; entry[12].value = 241; entry[12].first = 0; entry[12].second = 0; entry[12].third = 0; entry[12].duration = 300;
    entry[13].kind = 2; entry[13].value = 243; entry[13].first = 23; entry[13].second = 10; entry[13].third = 0; entry[13].duration = 900;
    entry[14].kind = 2; entry[14].value = 245; entry[14].first = 85; entry[14].second = 15; entry[14].third = 0; entry[14].duration = 1200;
    entry[15].kind = 1; entry[15].value = 244; entry[15].first = 9; entry[15].second = 9; entry[15].third = 9; entry[15].duration = 1980;
    entry[16].kind = 1; entry[16].value = 245; entry[16].first = 45; entry[16].second = 99; entry[16].third = 99; entry[16].duration = 1800;
}
