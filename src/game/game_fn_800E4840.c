typedef struct EncounterTable {
    unsigned short values[80];
} EncounterTable;

extern const EncounterTable lbl_802399D8;
extern unsigned short lbl_8064B7D4[4];
extern unsigned short *lbl_8064CAE4;
extern unsigned short lbl_8064CAEC;
extern EncounterTable lbl_80325C40;
extern void *memcpy(void *, const void *, unsigned int);

void fn_800E4840(void)
{
    EncounterTable table = lbl_802399D8;
    lbl_8064CAE4 = lbl_8064B7D4;
    lbl_8064CAEC = 30;
    memcpy(&lbl_80325C40, &table, sizeof(table));
}
