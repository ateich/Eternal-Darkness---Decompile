typedef unsigned short u16;

#pragma use_lmw_stmw on

typedef struct Record {
    unsigned char pad[8];
    u16 id;
} Record;

typedef struct Root {
    void* value;
    unsigned char pad[12];
} Root;

extern void* lbl_8064C528;
extern void* lbl_8064C52C;
extern void* lbl_8064C530;
extern int lbl_8064D18C;
extern void* lbl_8064B71C;
extern Root lbl_803003C8;
extern unsigned char lbl_8023B940[];

extern void* fn_801E86A0(void*, void*);
extern void fn_801E88E4(void*);
extern void* fn_8011EE04();
extern void fn_8011EAF4(void*, void*);
extern void fn_8011EAFC(void*, int);
extern void fn_8011FB54(void*, int);
extern void* fn_8011F950(void*);
extern Record* fn_8013898C(void*);
extern void fn_8011FC38(void*, int, int);
extern int fn_8012A100(void*, int);
extern void *fn_801294DC(void*, int, int, int);
extern void fn_8011EAB4(void*, int);
extern void fn_8011FA8C(void*, int, int);
extern int fn_80138D2C(void*, int);
extern void* fn_80008724(void*);
extern void fn_8011F808(void*, void*);

void* fn_800070E4(void* object, int mode, int value, float x, float y, float z,
                  u16 existing)
{
    void* result;

    if (existing == 0) {
        if (mode == 2 || mode == 1) {
            result = fn_8011EE04(fn_801E86A0(lbl_8064C528, object), x, y, z);
        } else if (mode == 4) {
            fn_801E88E4(lbl_8064C52C);
            result = fn_8011EE04(fn_801E86A0(lbl_8064C52C, object), x, y, z);
        } else {
            result = fn_8011EE04(fn_801E86A0(lbl_8064C528, object), x, y, z);
        }
    } else {
        result = fn_8011EE04(0);
    }

    fn_8011EAF4(result, object);
    fn_8011EAFC(result, mode);
    fn_8011FB54(result, value);

    if (existing == 0) {
        if (mode == 4) {
            void* other = fn_801E86A0(lbl_8064C530, object);

            if (result != 0) {
                fn_8011F950(result);
            }
            if (other != 0) {
                Record* record = fn_8013898C(other);
                if (record != 0) {
                    fn_8011FC38(result, record->id, 1);
                    if (fn_8012A100(result, 15) != 0) {
                        if (value == lbl_8064D18C) {
                            fn_801294DC(result, 15, 1, 1);
                        } else {
                            fn_8011EAB4(result, 15);
                        }
                    }
                }
            } else {
                fn_8011FA8C(result, 0, 0x20000);
            }
        } else if (result != 0 && fn_8011F950(result) != 0) {
            int found = 0;

            if (mode != 1) {
                found = fn_80138D2C(result, 0);
            }
            if (mode == 1 || found != 0) {
                void* target = 0;
                if (mode == 1) {
                    lbl_8064B71C = fn_80008724(lbl_803003C8.value);
                    target = fn_80008724(lbl_803003C8.value);
                }
                fn_8011FC38(result, (int)target, 1);
                if (fn_8012A100(result, 15) != 0) {
                    fn_8011EAB4(result, 15);
                } else if (fn_8012A100(result, 25) != 0) {
                    fn_8011EAB4(result, 25);
                }
            }
        }
    }

    fn_8011F808(result, lbl_8023B940);
    return result;
}
