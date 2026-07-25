typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

#pragma use_lmw_stmw on

typedef struct Player {
    unsigned char pad0[0xB0];
    u16 count;
    unsigned char padB2[2];
    unsigned char* entries;
} Player;

typedef struct Object {
    unsigned char pad0[0x94];
    s32 value;
    unsigned char pad98[6];
    s8 type;
    s8 subtype;
} Object;

extern const char lbl_8023BEF8[];
extern s32 lbl_8064D18C;

extern u32 fn_800F5C54(double);
extern Player* fn_8015C28C(s32);
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern void fn_8016A830(void*, double);
extern void* fn_80201B9C(void);
extern Object* fn_80201B8C(void*);
extern void* fn_80201BC8(void*);
extern void fn_80201B54(void*);
extern void* fn_80201BC0(void*);
extern s32 fn_8011FB4C(void*);
extern s32 fn_8013B8C0(void*, void*);

s32 fn_800094C0(void* script)
{
    Player* player;
    u32 object_id;
    s32 entry_offset;
    s32 value;
    s32 type;
    s32 subtype;
    s32 i;
    s32 count;

    player = fn_8015C28C(2);
    count = 0;
    if (fn_8016A598(script) != 4) {
        fn_80163BB4(script, lbl_8023BEF8, 4, fn_8016A598(script));
        return 0;
    }

    object_id = fn_800F5C54(fn_8016A694(script, 1));
    type = (s32)fn_8016A694(script, 2);
    subtype = (s32)fn_8016A694(script, 3);
    value = (s32)fn_8016A694(script, 4);

    i = 0;
    entry_offset = 0;
    for (; i < player->count; entry_offset += 0x74, i++) {
        void* iterator;

        if (*(u32*)(player->entries + entry_offset + 0x2C) != object_id) {
            continue;
        }

        iterator = fn_80201B9C();
        while (iterator != 0) {
            Object* object;
            void* context;
            s32 matches;
            s32 eligible;

            object = fn_80201B8C(iterator);
            context = fn_80201BC8(iterator);
            if (object != 0 && context != 0) {
                fn_80201B54(iterator);
                eligible = 1;
                if ((s8)type != -1) {
                    matches = 0;
                    if ((s8)type == object->type
                        && ((s8)subtype == -1 || (s8)subtype == object->subtype)
                        && (value == -1 || value == object->value)) {
                        matches = 1;
                    }
                    if (!matches) {
                        eligible = 0;
                    }
                }

                if (context != 0 && eligible != 0
                    && lbl_8064D18C == fn_8011FB4C(context)
                    && fn_8013B8C0(context, player->entries + entry_offset) != 0) {
                    count++;
                }
            }
            iterator = fn_80201BC0(iterator);
        }
    }

    fn_8016A830(script, (double)count);
    return 1;
}
