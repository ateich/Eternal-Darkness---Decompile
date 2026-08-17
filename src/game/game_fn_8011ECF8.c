typedef unsigned char u8;
typedef unsigned short u16;

#pragma use_lmw_stmw on

/*
 * Honest, size-exact reconstruction. The remaining mismatch is a permutation
 * of r25-r31 across count, index, list, slot, and the three stride offsets.
 * Objdiff: 268/268 bytes, 96.04478%; all five relocations agree.
 */

extern unsigned int fn_8012927C(void* object);
extern void fn_80127CE4(void* a, void* b, void* c, float value);
extern void fn_80127B90(void* a, void* b, void* c, float value);
extern float lbl_80650068;

void fn_8011ECF8(register void* object, register void* source)
{
    register int offset76;
    register int offset16;
    register int offset12;
    register u8* slot;
    register void* list;
    register int count;
    register int index;
    register u8* record;
    u8* flags;

    count = *(u16*)(*(u8**)((u8*)object + 60) + 8);
    if ((u16)fn_8012927C(object) != 0xFFFF) {
        count++;
    }

    list = *(void**)(*(u8**)((u8*)source + 184) + 4);
    offset16 = offset76 = 0;
    index = 0;
    offset12 = offset76;

    while (index < count) {
        slot = *(u8**)((u8*)object + 352) + offset76 + 4;
        record = *(u8**)list + offset16;
        flags = *(u8**)((u8*)object + 680);

        flags[index] = 0;
        if (*(u16*)record != 0 && *(void**)(slot + 20) != 0) {
            fn_80127CE4(*(void**)(slot + 20), *(void**)(slot + 24),
                        *(u8**)((u8*)object + 340) + offset12, lbl_80650068);
            (*(u8**)((u8*)object + 680))[index] |= 2;
        }
        if (*(u16*)(record + 8) != 0) {
            fn_80127B90(*(void**)(slot + 48), *(void**)(slot + 52),
                        *(u8**)((u8*)object + 344) + offset16, lbl_80650068);
            (*(u8**)((u8*)object + 680))[index] |= 1;
        }

        offset76 += 76;
        offset16 += 16;
        offset12 += 12;
        index++;
    }
}
