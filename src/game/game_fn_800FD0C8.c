extern const unsigned char lbl_80239E68[32];

unsigned long fn_800FD0C8(const char* string, const char* accept)
{
    unsigned char map[32];
    const unsigned char* p;
    unsigned char ch;

    *(unsigned long*)(map + 0) = *(const unsigned long*)(lbl_80239E68 + 0);
    *(unsigned long*)(map + 4) = *(const unsigned long*)(lbl_80239E68 + 4);
    *(unsigned long*)(map + 8) = *(const unsigned long*)(lbl_80239E68 + 8);
    *(unsigned long*)(map + 12) = *(const unsigned long*)(lbl_80239E68 + 12);
    *(unsigned long*)(map + 16) = *(const unsigned long*)(lbl_80239E68 + 16);
    *(unsigned long*)(map + 20) = *(const unsigned long*)(lbl_80239E68 + 20);
    *(unsigned long*)(map + 24) = *(const unsigned long*)(lbl_80239E68 + 24);
    *(unsigned long*)(map + 28) = *(const unsigned long*)(lbl_80239E68 + 28);

    p = (const unsigned char*)accept - 1;
    while ((ch = *++p) != 0) {
        map[ch >> 3] |= 1 << (ch & 7);
    }

    p = (const unsigned char*)string - 1;
    while ((ch = *++p) != 0) {
        if ((map[ch >> 3] & (1 << (ch & 7))) == 0) {
            break;
        }
    }
    return p - (const unsigned char*)string;
}
