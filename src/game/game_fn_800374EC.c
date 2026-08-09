typedef unsigned short u16;
typedef unsigned int u32;

extern char lbl_8064B410[8];

extern void* lbl_8064C720;
extern void* lbl_8064C724;
extern void* lbl_8064C728;
extern void* lbl_8064C72C;
extern void* lbl_8064C730;
extern void* lbl_8064C734;
extern void* lbl_8064C73C;
extern void* lbl_8064C740;
extern void* lbl_8064C744;
extern void* lbl_8064C748;
extern void* lbl_8064C754;
extern void* lbl_8064C758;
extern void* lbl_8064C75C;
extern void* lbl_8064C760;
extern void* lbl_8064C764;
extern void* lbl_8064C768;
extern void* lbl_8064C76C;
extern void* lbl_8064C770;
extern void* lbl_8064C774;
extern void* lbl_8064C778;
extern void* lbl_8064C77C;
extern void* lbl_8064C780;
extern void* lbl_8064C784;
extern void* lbl_8064C788;
extern void* lbl_8064C78C;
extern void* lbl_8064C790;
extern void* lbl_8064C794;
extern void* lbl_8064C798;
extern void* lbl_8064C79C;
extern void* lbl_8064C7A0;
extern void* lbl_8064C7A4;
extern void* lbl_8064C7A8;
extern void* lbl_8064C7AC;
extern void* lbl_8064C7B0;

extern void* fn_801FEA8C(u32, u32, const char*, u32);
extern void* fn_8017CCD8(void*, u32, u32);

#define ALLOCATE(global, size, line) \
    global = fn_8017CCD8(fn_801FEA8C((u16)count * size, 1, lbl_8064B410, line), size, count)

void fn_800374EC(int type, int count)
{
    switch (type) {
    case 2:
        ALLOCATE(lbl_8064C7B0, 0x98, 0xC5F);
        break;
    case 4:
        ALLOCATE(lbl_8064C7AC, 0xC, 0xC65);
        break;
    case 5:
        ALLOCATE(lbl_8064C7A8, 0x8C, 0xC6B);
        break;
    case 44:
        ALLOCATE(lbl_8064C754, 0x38, 0xC72);
        break;
    case 6:
        ALLOCATE(lbl_8064C774, 0x10, 0xC78);
        break;
    case 9:
        ALLOCATE(lbl_8064C76C, 0x24, 0xC7E);
        break;
    case 8:
        ALLOCATE(lbl_8064C7A4, 0x48, 0xC84);
        break;
    case 10:
        ALLOCATE(lbl_8064C7A0, 0x2C, 0xC8C);
        break;
    case 11:
        ALLOCATE(lbl_8064C79C, 0x2C, 0xC94);
        break;
    case 20:
        ALLOCATE(lbl_8064C798, 0x18, 0xC9C);
        break;
    case 22:
        ALLOCATE(lbl_8064C794, 0xF8, 0xCA4);
        break;
    case 23:
        ALLOCATE(lbl_8064C790, 0xF8, 0xCAC);
        break;
    case 24:
        ALLOCATE(lbl_8064C78C, 0xD4, 0xCB4);
        break;
    case 87:
        ALLOCATE(lbl_8064C788, 0x18, 0xCBC);
        break;
    case 25:
        ALLOCATE(lbl_8064C784, 0x30, 0xCC4);
        break;
    case 26:
        ALLOCATE(lbl_8064C780, 0xDC, 0xCCC);
        break;
    case 32:
        ALLOCATE(lbl_8064C77C, 0xC8, 0xCD4);
        break;
    case 78:
        ALLOCATE(lbl_8064C72C, 0x1B8, 0xCDC);
        break;
    case 79:
        ALLOCATE(lbl_8064C728, 0x30, 0xCE4);
        break;
    case 34:
        ALLOCATE(lbl_8064C748, 0xDC, 0xCEC);
        break;
    case 36:
        ALLOCATE(lbl_8064C744, 0x49C, 0xCF4);
        break;
    case 7:
        ALLOCATE(lbl_8064C778, 0x1C8, 0xCFC);
        break;
    case 43:
        ALLOCATE(lbl_8064C770, 0x100, 0xD04);
        break;
    case 42:
        ALLOCATE(lbl_8064C768, 0x108, 0xD0C);
        break;
    case 56:
        ALLOCATE(lbl_8064C764, 0x48, 0xD16);
        break;
    case 58:
        ALLOCATE(lbl_8064C760, 0xAC, 0xD1E);
        break;
    case 39:
        ALLOCATE(lbl_8064C740, 0x194, 0xD26);
        break;
    case 49:
        ALLOCATE(lbl_8064C75C, 0x10, 0xD2E);
        break;
    case 77:
        ALLOCATE(lbl_8064C734, 0x24, 0xD36);
        break;
    case 80:
        ALLOCATE(lbl_8064C730, 8, 0xD3E);
        break;
    case 53:
        ALLOCATE(lbl_8064C758, 0x2A4, 0xD44);
        break;
    case 63:
        ALLOCATE(lbl_8064C73C, 0x1C, 0xD4A);
        break;
    case 83:
        ALLOCATE(lbl_8064C724, 0x128, 0xD52);
        break;
    case 88:
        ALLOCATE(lbl_8064C720, 0x10, 0xD5A);
        break;
    }
}
