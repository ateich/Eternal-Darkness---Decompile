typedef unsigned char u8;

typedef struct ObjectData {
    u8 bytes[0x100];
} ObjectData;

char lbl_8023E674[] = "Stamina Bar GO";

extern char lbl_8064B3A8;
extern char lbl_8064B3CC;
extern char lbl_8064B418;
extern char lbl_8064B420;
extern char lbl_8064B428;
extern char lbl_8064B430;
extern char lbl_8064B438;
extern char lbl_8064B440;
extern char lbl_8064B448;
extern char lbl_8064B450;
extern char lbl_8064B454;
extern char lbl_8064B458;
extern char lbl_8064B45C;
extern char lbl_8064B464;
extern char lbl_8064B468;
extern char lbl_8064B46C;
extern char lbl_8064B470;
extern char lbl_8064B474;
extern char lbl_8064B478;
extern char lbl_8064B47C;

extern void* lbl_8064C720;
extern void* lbl_8064C72C;
extern void* lbl_8064C730;
extern void* lbl_8064C734;
extern void* lbl_8064C740;
extern void* lbl_8064C744;
extern void* lbl_8064C748;
extern void* lbl_8064C74C;
extern void* lbl_8064C75C;
extern void* lbl_8064C770;
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

extern ObjectData* fn_8017CDB4(void*);
extern void fn_8017CE74(void*, void*);
extern void* fn_802016CC(void*);
extern void fn_80201D3C(void*, int);
extern void fn_80201D44(void*, int);
extern void fn_80201D4C(void*, void*);
extern void fn_802020B4(void*, int);
extern void *fn_80201B9C();
extern int fn_80201B5C(void*);
#define fn_80201B5C(a) fn_80201B5C((void*)(a))
extern void *fn_80201B8C();
extern void* fn_80201BC0(void*);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern unsigned long long fn_8020123C();
extern int fn_801E8328();

#define FIELD(data, offset) (*(void**)((data)->bytes + (offset)))

#define CREATE(template, mode, kind, pool, offset) \
    do { \
        ObjectData* data = fn_8017CDB4(lbl_8064C74C); \
        result = fn_802016CC(template); \
        fn_80201D3C(result, mode); \
        fn_80201D44(result, kind); \
        FIELD(data, offset) = fn_8017CDB4(pool); \
        fn_80201D4C(result, data); \
        return result; \
    } while (0)

#define CREATE_LATE(template, mode, kind, pool, offset) \
    do { \
        ObjectData* data = fn_8017CDB4(lbl_8064C74C); \
        result = fn_802016CC(template); \
        fn_80201D3C(result, mode); \
        fn_80201D44(result, kind); \
        FIELD(data, offset) = fn_8017CDB4(pool); \
        fn_80201D4C(result, data); \
        return result; \
    } while (0)

void* fn_80037AF4(int type)
{
    register void* result;

    switch (type) {
    case 10: {
        ObjectData* data = fn_8017CDB4(lbl_8064C74C);
        result = fn_802016CC(&lbl_8064B3A8);
        fn_80201D3C(result, 4);
        fn_80201D44(result, 10);
        FIELD(data, 0x10) = fn_8017CDB4(lbl_8064C7A0);
        fn_80201D4C(result, data);
        return result;
    }
    case 70:
        CREATE(&lbl_8064B418, 4, 70, lbl_8064C79C, 0x14);
    case 78:
        CREATE(&lbl_8064B420, 4, 78, lbl_8064C72C, 0x7C);
    case 11:
        CREATE(&lbl_8064B428, 4, 11, lbl_8064C79C, 0x14);
    case 20:
        CREATE(lbl_8023E674, 4, 20, lbl_8064C798, 0x18);
    case 22:
        CREATE(&lbl_8064B430, 4, 22, lbl_8064C794, 0x1C);
    case 23:
        CREATE(&lbl_8064B438, 4, 23, lbl_8064C790, 0x20);
    case 24: {
        ObjectData* data = fn_8017CDB4(lbl_8064C74C);
        result = fn_802016CC(&lbl_8064B440);
        fn_80201D3C(result, 4);
        fn_80201D44(result, 24);
        FIELD(data, 0x24) = fn_8017CDB4(lbl_8064C78C);
        fn_80201D4C(result, data);
        fn_802020B4(result, 1);
        return result;
    }
    case 87: {
        ObjectData* data = fn_8017CDB4(lbl_8064C74C);
        result = fn_802016CC(&lbl_8064B448);
        if (result != 0) {
            fn_80201D3C(result, 4);
            fn_80201D44(result, 87);
            FIELD(data, 0x28) = fn_8017CDB4(lbl_8064C788);
            fn_80201D4C(result, data);
            fn_802020B4(result, 1);
        }
        return result;
    }
    case 25:
        CREATE(&lbl_8064B450, 4, 25, lbl_8064C784, 0x2C);
    case 26: {
        ObjectData* data = fn_8017CDB4(lbl_8064C74C);
        result = fn_802016CC(&lbl_8064B454);
        fn_80201D3C(result, 4);
        fn_80201D44(result, 26);
        FIELD(data, 0x30) = fn_8017CDB4(lbl_8064C780);
        fn_80201D4C(result, data);
        fn_802020B4(result, 1);
        return result;
    }
    case 32:
        CREATE(&lbl_8064B458, 4, 32, lbl_8064C77C, 0x38);
    case 34: {
        ObjectData* data;
        void* iterator;
        data = fn_8017CDB4(lbl_8064C74C);
        result = fn_802016CC(&lbl_8064B45C);
        fn_80201D3C(result, 4);
        fn_80201D44(result, 34);
        FIELD(data, 0x3C) = fn_8017CDB4(lbl_8064C748);
        if (FIELD(data, 0x3C) == 0) {
            iterator = fn_80201B9C();
            while (iterator != 0) {
                if (fn_80201B5C(iterator) == 34) {
                    ObjectData* other = fn_80201B8C(iterator);
                    if (other != 0 && FIELD(other, 0x3C) != 0) {
                        if (fn_80201814(*(void**)((u8*)FIELD(other, 0x3C) + 0x18)) != 0 &&
                            fn_80201BC8() != 0)
                            fn_8020123C(
                                57, 0,
                                *(void**)((u8*)FIELD(other, 0x3C) + 0x18), 0);
                        fn_8017CE74(lbl_8064C748, FIELD(other, 0x3C));
                        FIELD(other, 0x3C) = 0;
                        fn_80201D44(iterator, 0);
                        fn_801E8328(2, iterator);
                    }
                }
                iterator = fn_80201BC0(iterator);
            }
            FIELD(data, 0x3C) = fn_8017CDB4(lbl_8064C748);
        }
        fn_80201D4C(result, data);
        return result;
    }
    case 36: {
        ObjectData* resource = fn_8017CDB4(lbl_8064C744);
        if (resource != 0) {
            ObjectData* data = fn_8017CDB4(lbl_8064C74C);
            result = fn_802016CC(&lbl_8064B464);
            fn_80201D3C(result, 4);
            fn_80201D44(result, 36);
            FIELD(data, 0x40) = resource;
            fn_80201D4C(result, data);
            return result;
        }
        break;
    }
    case 43:
        CREATE(&lbl_8064B468, 4, 43, lbl_8064C770, 0x4C);
    case 39: {
        ObjectData* resource = fn_8017CDB4(lbl_8064C740);
        if (resource != 0) {
            ObjectData* data = fn_8017CDB4(lbl_8064C74C);
            result = fn_802016CC(&lbl_8064B46C);
            fn_80201D3C(result, 4);
            fn_80201D44(result, 39);
            FIELD(data, 0x60) = resource;
            fn_80201D4C(result, data);
            return result;
        }
        break;
    }
    case 49:
        CREATE_LATE(&lbl_8064B470, 4, 49, lbl_8064C75C, 0x34);
    case 77:
        CREATE_LATE(&lbl_8064B474, 4, 77, lbl_8064C734, 0x74);
    case 80:
        CREATE_LATE(&lbl_8064B3CC, 2, 80, lbl_8064C730, 0x78);
    case 62: {
        result = fn_802016CC(&lbl_8064B478);
        fn_80201D3C(result, 4);
        fn_80201D44(result, 62);
        return result;
    }
    case 88:
        CREATE_LATE(&lbl_8064B47C, 2, 88, lbl_8064C720, 0x88);
    }
    return 0;
}
