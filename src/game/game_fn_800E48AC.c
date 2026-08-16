typedef struct EncounterTable {
    unsigned short values[80];
} EncounterTable;

extern const EncounterTable lbl_80239A78;
extern unsigned short lbl_8064B7DC[4];
extern unsigned short *lbl_8064CAE4;
extern unsigned short lbl_8064CAEC;
extern EncounterTable lbl_80325C40;
extern void *memcpy(void *, const void *, unsigned int);

void fn_800E48AC(void)
{
    EncounterTable table = lbl_80239A78;
    lbl_8064CAE4 = lbl_8064B7DC;
    lbl_8064CAEC = 2;
    memcpy(&lbl_80325C40, &table, sizeof(table));
}
