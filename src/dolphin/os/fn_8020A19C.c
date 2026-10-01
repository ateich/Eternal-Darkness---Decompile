typedef unsigned char u8;
typedef unsigned int u32;

typedef void (*OSExceptionHandler)(u8, void*);

extern u32 BI2DebugFlag_8064D8F4;
extern u32 OSExceptionTable_8064D900;
extern u8 lbl_802FCBBE[];

extern u32 __OSEVSetNumber[];
extern u32 __OSDBINTSTART[];
extern u32 __OSDBINTEND[];
extern u32 __OSDBJUMPEND[];
extern u32 __DBVECTOR[];
extern u32 __OSEVStart[];
extern u32 __OSEVEnd[];
extern void OSDefaultExceptionHandler(void);

extern int __DBIsExceptionMarked(u32);
extern void DBPrintf(const char*, ...);
extern void* memcpy(void*, const void*, u32);
extern void DCFlushRangeNoSync(void*, u32);
extern void ICInvalidateRange(void*, u32);
extern void __sync(void);
extern OSExceptionHandler __OSSetExceptionHandler(u8, OSExceptionHandler);

static void OSExceptionInit_8020A19C(void)
{
    u32 i;
    u32 size;
    u32* p;
    u32* vector;
    u32 savedInstruction = *__OSEVSetNumber;
    u32* exceptionLocations = (u32*)(lbl_802FCBBE + 0xCA);

    if (*(u32*)0x80000060 == 0) {
        DBPrintf((char*)lbl_802FCBBE + 0x106);
        size = (u8*)__OSDBINTEND - (u8*)__OSDBINTSTART;
        memcpy((void*)0x80000060, __OSDBINTSTART, size);
        DCFlushRangeNoSync((void*)0x80000060, size);
        __sync();
        ICInvalidateRange((void*)0x80000060, size);
    }

    for (i = 0; i < 15; i++) {
        if (BI2DebugFlag_8064D8F4 != 0 &&
            *(u32*)BI2DebugFlag_8064D8F4 >= 2 &&
            __DBIsExceptionMarked(i)) {
            DBPrintf((char*)lbl_802FCBBE + 0x122, (u8)i);
            continue;
        }

        *__OSEVSetNumber = savedInstruction | (u8)i;
        if (__DBIsExceptionMarked(i)) {
            DBPrintf((char*)lbl_802FCBBE + 0x152, (u8)i);
            memcpy(__DBVECTOR, __OSDBINTEND, (u8*)__OSDBJUMPEND - (u8*)__OSDBINTEND);
        } else {
            size = (u8*)__OSDBJUMPEND - (u8*)__OSDBINTEND;
            p = __DBVECTOR;
            while (size != 0) {
                *p++ = 0x60000000;
                size -= 4;
            }
        }

        vector = (u32*)(0x80000000 | exceptionLocations[i]);
        size = (u8*)__OSEVEnd - (u8*)__OSEVStart;
        memcpy(vector, __OSEVStart, size);
        DCFlushRangeNoSync(vector, size);
        __sync();
        ICInvalidateRange(vector, size);
    }

    OSExceptionTable_8064D900 = 0x80003000;
    for (i = 0; i < 15; i++) {
        __OSSetExceptionHandler((u8)i, (OSExceptionHandler)OSDefaultExceptionHandler);
    }
    *__OSEVSetNumber = savedInstruction;
    DBPrintf((char*)lbl_802FCBBE + 0x182);
}
