#include "src/game/types.h"

extern void* memcpy(void*, const void*, u32);
extern u32 fn_801E7454(const u8* data, u32 size);
extern int fn_800B0954(unsigned char* data);

/* Save-file header: 21 data blocks follow the 0x98-byte header, each with a
 * size and a checksum. */
typedef struct SaveHeader {
    u8 magic;            /* 0x00: must be 'l' */
    u8 pad01[0x17];
    u16 sizes[21];       /* 0x18 */
    u32 checksums[21];   /* 0x44 */
} SaveHeader;

int fn_800B1244(u8* data) {
    SaveHeader header;
    u32 check;
    u32 offset;
    u8* block;

    memcpy(&header, data, sizeof(SaveHeader));
    if (header.magic != 0x6C) {
        return 0;
    }
    check = fn_801E7454(data + 0x98, header.sizes[0]);
    if (check != header.checksums[0]) {
        return 0;
    }
    offset = header.sizes[0] + 0x98;
    check = fn_801E7454(data + offset, header.sizes[1]);
    if (check != header.checksums[1]) {
        return 0;
    }
    offset += header.sizes[1];
    check = fn_801E7454(data + offset, header.sizes[2]);
    if (check != header.checksums[2]) {
        return 0;
    }
    offset += header.sizes[2];
    check = fn_801E7454(data + offset, header.sizes[3]);
    if (check != header.checksums[3]) {
        return 0;
    }
    offset += header.sizes[3];
    check = fn_801E7454(data + offset, header.sizes[4]);
    if (check != header.checksums[4]) {
        return 0;
    }
    offset += header.sizes[4];
    check = fn_801E7454(data + offset, header.sizes[5]);
    if (check != header.checksums[5]) {
        return 0;
    }
    offset += header.sizes[5];
    check = fn_801E7454(data + offset, header.sizes[6]);
    if (check != header.checksums[6]) {
        return 0;
    }
    offset += header.sizes[6];
    check = fn_801E7454(data + offset, header.sizes[7]);
    if (check != header.checksums[7]) {
        return 0;
    }
    offset += header.sizes[7];
    block = data + offset;
    check = fn_801E7454(block, header.sizes[8]);
    if (check != header.checksums[8]) {
        return 0;
    }
    if (fn_800B0954(block) == 0) {
        return 0;
    }
    offset += header.sizes[8];
    check = fn_801E7454(data + offset, header.sizes[9]);
    if (check != header.checksums[9]) {
        return 0;
    }
    offset += header.sizes[9];
    check = fn_801E7454(data + offset, header.sizes[10]);
    if (check != header.checksums[10]) {
        return 0;
    }
    offset += header.sizes[10];
    check = fn_801E7454(data + offset, header.sizes[11]);
    if (check != header.checksums[11]) {
        return 0;
    }
    offset += header.sizes[11];
    check = fn_801E7454(data + offset, header.sizes[12]);
    if (check != header.checksums[12]) {
        return 0;
    }
    offset += header.sizes[12];
    check = fn_801E7454(data + offset, header.sizes[13]);
    if (check != header.checksums[13]) {
        return 0;
    }
    offset += header.sizes[13];
    check = fn_801E7454(data + offset, header.sizes[14]);
    if (check != header.checksums[14]) {
        return 0;
    }
    offset += header.sizes[14];
    check = fn_801E7454(data + offset, header.sizes[15]);
    if (check != header.checksums[15]) {
        return 0;
    }
    offset += header.sizes[15];
    check = fn_801E7454(data + offset, header.sizes[16]);
    if (check != header.checksums[16]) {
        return 0;
    }
    offset += header.sizes[16];
    check = fn_801E7454(data + offset, header.sizes[17]);
    if (check != header.checksums[17]) {
        return 0;
    }
    offset += header.sizes[17];
    check = fn_801E7454(data + offset, header.sizes[18]);
    if (check != header.checksums[18]) {
        return 0;
    }
    offset += header.sizes[18];
    check = fn_801E7454(data + offset, header.sizes[19]);
    if (check != header.checksums[19]) {
        return 0;
    }
    offset += header.sizes[19];
    check = fn_801E7454(data + offset, header.sizes[20]);
    return check == header.checksums[20];
}
