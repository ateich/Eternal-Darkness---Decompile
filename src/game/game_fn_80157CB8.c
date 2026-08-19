typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Record {
    unsigned char pad00[0x0c];
    u32 required_flags;
    u16 mask;
    unsigned char pad12[2];
} Record;

typedef struct Primary {
    unsigned char pad00[4];
    Record* records;
} Primary;

typedef struct Secondary {
    u32 flags;
} Secondary;

typedef struct Object {
    Primary* primary;
    Secondary* secondary;
} Object;

Record* fn_80157CB8(Object* object, u16 mask)
{
    int result = -1;
    int index;

    for (index = 0; index < 10; index++) {
        if ((object->primary->records[index].mask & mask) != 0 &&
            (object->secondary->flags &
             object->primary->records[index].required_flags) != 0) {
            result = index;
            break;
        }
    }
    return &object->primary->records[result];
}
