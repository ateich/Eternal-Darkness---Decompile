typedef unsigned char u8;
typedef int s32;

typedef struct ResourceGroup {
    s32 field00;
    s32 fields04[4];
    u8 pad14[0xC];
    s32 field20;
    s32 field24;
    s32 field28;
    s32 fields2C[3];
    s32 field38;
    s32 field3C;
    s32 field40;
} ResourceGroup;

typedef struct ObjectInfo {
    void* field00;
    void* field04;
    void* field08;
    void* field0C;
    void* field10;
    void* field14;
    void* field18;
    void* field1C;
    void* field20;
    void* field24;
    void* field28;
    void* field2C;
    void* field30;
    void* field34;
    void* field38;
    void* field3C;
    void* field40;
    void* field44;
    void* field48;
    void* field4C;
    void* field50;
    void* field54;
    void* field58;
    void* field5C;
    void* field60;
    void* field64;
    void* field68;
    void* field6C;
    void* field70;
    void* field74;
    void* field78;
    void* field7C;
    void* field80;
    void** field84;
    void* field88;
    ResourceGroup* field8C;
} ObjectInfo;

extern void* lbl_8064C720;
extern void* lbl_8064C724;
extern void* lbl_8064C728;
extern void* lbl_8064C72C;
extern void* lbl_8064C730;
extern void* lbl_8064C734;
extern void* lbl_8064C738;
extern void* lbl_8064C73C;
extern void* lbl_8064C740;
extern void* lbl_8064C744;
extern void* lbl_8064C748;
extern void* lbl_8064C74C;
extern void* lbl_8064C750;
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

extern void* fn_80201B8C();
extern int fn_80201B54();
extern void* fn_80204B10(void*, void**);
extern void* fn_80201814();
extern void* fn_80158598(int, int);
extern void fn_80158668(void);
extern s32 fn_80204EC8(void*, void*);
extern s32 fn_80204F54(void*);
extern void* fn_80201BC8();
extern void fn_800BD2DC(void*, void*);
extern void fn_80204C94(void*);
extern void fn_8017CE74(void*, void*);
extern void fn_801A7228(void*);
extern void fn_800E9F84(void*);
extern unsigned long long fn_8020123C();
extern void fn_800EA3A0(void*, void*);
extern void fn_80201D4C(void*, s32);

#define RELEASE(field, heap) \
    if (info->field != 0) { \
        fn_8017CE74(heap, info->field); \
        info->field = 0; \
    }

void fn_80036E8C(register void* object)
{
    register ObjectInfo* info;
    register s32 object_id;
    register void* related;
    register void* link;
    register s32 i;
    void* link_slot;

    info = fn_80201B8C(object);
    object_id = fn_80201B54(object);
    if (info == 0) {
        return;
    }

    related = fn_80204B10(object, &link_slot);
    link = fn_80201814(link_slot);
    if (fn_80158598(object_id, 0) != 0) {
        fn_80158668();
    }
    if (related != 0) {
        if ((link != 0 ? fn_80204EC8(link, object) : fn_80204F54(object)) == 0) {
            fn_80201814(link_slot);
            fn_80201814((void*)object_id);
            fn_80201BC8(link);
            fn_80201BC8(object);
            fn_80204B10(object, &link_slot);
        }
    }

    if (info->field8C != 0) {
        fn_800BD2DC(object, info->field8C);
    }
    fn_80204C94(object);

    RELEASE(field00, lbl_8064C7B0);
    RELEASE(field04, lbl_8064C7AC);
    RELEASE(field08, lbl_8064C7A8);
    RELEASE(field68, lbl_8064C754);
    RELEASE(field48, lbl_8064C774);
    RELEASE(field60, lbl_8064C740);
    RELEASE(field50, lbl_8064C76C);
    RELEASE(field44, lbl_8064C778);
    RELEASE(field0C, lbl_8064C7A4);
    RELEASE(field10, lbl_8064C7A0);
    RELEASE(field14, lbl_8064C79C);
    RELEASE(field18, lbl_8064C798);
    RELEASE(field1C, lbl_8064C794);
    RELEASE(field20, lbl_8064C790);
    RELEASE(field7C, lbl_8064C72C);
    RELEASE(field80, lbl_8064C728);
    RELEASE(field24, lbl_8064C78C);
    RELEASE(field28, lbl_8064C788);
    RELEASE(field2C, lbl_8064C784);
    RELEASE(field30, lbl_8064C780);
    RELEASE(field3C, lbl_8064C748);
    RELEASE(field70, lbl_8064C738);
    RELEASE(field40, lbl_8064C744);
    RELEASE(field54, lbl_8064C768);
    RELEASE(field58, lbl_8064C764);
    RELEASE(field5C, lbl_8064C760);
    RELEASE(field64, lbl_8064C758);
    RELEASE(field34, lbl_8064C75C);
    RELEASE(field74, lbl_8064C734);

    if (info->field84 != 0) {
        if (*info->field84 != 0) {
            fn_801A7228(*info->field84);
        }
        fn_8017CE74(lbl_8064C724, info->field84);
        fn_800E9F84(info->field84);
        info->field84 = 0;
    }

    RELEASE(field78, lbl_8064C730);
    RELEASE(field88, lbl_8064C720);

    if (info->field8C != 0) {
        if (info->field8C->field20 != 0) {
            fn_8020123C(0x39, object_id, info->field8C->field20, 0);
        }
        for (i = 0; i < 4; i++) {
            if (info->field8C->fields04[i] != 0) {
                fn_8020123C(0x39, object_id, info->field8C->fields04[i], 0);
            }
        }
        if (info->field8C->field24 != 0) {
            fn_8020123C(0x39, object_id, info->field8C->field24, 0);
        }
        if (info->field8C->field28 != 0) {
            fn_8020123C(0x39, object_id, info->field8C->field28, 0);
        }
        if (info->field8C->field38 != 0) {
            fn_8020123C(0x39, object_id, info->field8C->field38, 0);
        }
        if (info->field8C->field40 != 0) {
            fn_8020123C(0x39, object_id, info->field8C->field40, 0);
        }
        for (i = 0; i < 3; i++) {
            if (info->field8C->fields2C[i] != 0) {
                fn_8020123C(0x39, object_id, info->field8C->fields2C[i], 0);
            }
        }
        if (info->field8C->field3C != 0) {
            fn_8020123C(0x39, object_id, info->field8C->field3C, 0);
        }
        fn_800EA3A0(object, info->field8C);
        fn_8017CE74(lbl_8064C750, info->field8C);
        info->field8C = 0;
    }

    RELEASE(field38, lbl_8064C77C);
    RELEASE(field4C, lbl_8064C770);
    RELEASE(field6C, lbl_8064C73C);
    fn_8017CE74(lbl_8064C74C, info);
    fn_80201D4C(object, 0);
}
