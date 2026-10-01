typedef signed int s32;
typedef unsigned short u16;
typedef volatile u16 vu16;

typedef struct DVDCommandBlock {
    unsigned char _00[0xC];
    s32 state;
} DVDCommandBlock;

typedef struct DVDDriveInfo {
    u16 revisionLevel;
    u16 deviceCode;
    unsigned char _04[0x1C];
} DVDDriveInfo;

extern DVDDriveInfo DriveInfo_80640D80;
vu16 __OSDeviceCode : 0x800030E6;

static void InquiryCallback_80209DC8(s32 result, DVDCommandBlock* block)
{
    switch (block->state) {
    case 0:
        __OSDeviceCode = (u16)(0x8000 | DriveInfo_80640D80.deviceCode);
        break;
    default:
        __OSDeviceCode = 1;
        break;
    }
}
