typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Color { u8 r, g, b, a; } Color;
typedef struct FontDescriptor { u8 reserved[4]; s8 height; u8 widths[256]; } FontDescriptor;

extern int lbl_8064D564;
extern void* lbl_8064D570;
extern s16 lbl_8064D574;
extern s16 lbl_8064D578;
extern u32 lbl_8064D57C;
extern int lbl_8064D580;
extern Color lbl_8064D594;
extern FontDescriptor* lbl_8064D59C;
extern void* lbl_806333C8[];
extern void* lbl_806333F0[];
extern float lbl_8064C314;
extern int lbl_8064C320;
extern char lbl_8064C324;
extern float lbl_80651260;
extern float lbl_80651264;
extern u8 lbl_80255898[];
extern u8 lbl_802558E8[];

extern void fn_801E4188(void);
extern void fn_801E418C(u16);
extern void fn_801E4198(s16, s16, s16);
extern void fn_801E39A8(int);
extern void fn_801ED3F4(void*);
extern void fn_801A8EDC(void*);
extern void fn_801A852C(Color*, int, void*, u32);
extern void fn_801ECD74(Color*);
extern void fn_80226AB4(int, int, int);
extern int fn_800FBFD0(char*, char*, ...);
extern void fn_801E7DCC(char*, ...);

/* NonMatching: complete retail-backed control-sequence reconstruction. */
char* fn_801E3B08(char* text)
{
    int command = (s8)*text;
    int value = 0;
    u8* palette = lbl_80255898;
    u8* diagnostics = lbl_80255898 + 0x10000;
    Color glyph_color, restored_color, raw_color;
    Color named_r, named_g, named_b, named_l, named_w, named_y, named_f;
    Color named_c, named_u, named_x, named_m, named_s, named_a, named_d;

    switch (command) {
    case 'h': {
        int digits = 0;
        text++;
        while (*text >= '0' && *text <= '9' && digits < 3) {
            value *= 10;
            value += (s8)*text;
            digits++;
            text++;
            value -= '0';
        }
    }
    case 'r': {
        float glyph_scale;
        int raw_size;
        s16 short_size;
        int glyph;

        if (command == 'r') {
            value = lbl_8064D564 + 26;
            text++;
        }
        if (value >= 0 && value < 32) {
            glyph_scale = lbl_80651260 * lbl_8064C314;
            raw_size = (int)glyph_scale;
            fn_801ED3F4(lbl_8064D570);
            fn_801A8EDC(diagnostics - 0x14a0);
            glyph_color = lbl_8064D594;
            fn_801A852C(&glyph_color, 0, (void*)1, 0x80000000);
            lbl_8064C320 = -1;
            fn_80226AB4(0x80, 5, 4);
            short_size = (s16)glyph_scale;
            fn_801E4198(lbl_8064D574, lbl_8064D578 + short_size, -1);
            glyph = (value & 0x3fff) << 2;
            fn_801E418C((u16)(glyph + 3));
            fn_801E4198(lbl_8064D574, lbl_8064D578, -1);
            fn_801E418C((u16)glyph);
            fn_801E4198(lbl_8064D574 + (s16)raw_size, lbl_8064D578, -1);
            fn_801E418C((u16)(glyph + 1));
            fn_801E4198(lbl_8064D574 + (s16)raw_size, lbl_8064D578 + short_size, -1);
            fn_801E418C((u16)(glyph + 2));
            fn_801E4188();
            fn_801ED3F4(lbl_806333C8[lbl_8064D580]);
            fn_801A8EDC(lbl_802558E8);
            restored_color = lbl_8064D594;
            fn_801A852C(&restored_color, 0, lbl_806333F0[lbl_8064D580], 0x80000000);
            lbl_8064D574 += (s16)(lbl_8064C314 * lbl_8064D59C->widths[value]);
        } else {
            fn_801E7DCC((char*)diagnostics - 0x127c, value);
        }
        break;
    }
    case 'b': {
        lbl_8064D594.r = text[1]; lbl_8064D594.g = text[2];
        lbl_8064D594.b = text[3]; lbl_8064D594.a = text[4];
        text += 5;
        raw_color = lbl_8064D594;
        fn_801ECD74(&raw_color);
        break;
    }
    case '\\': {
        switch (text[1]) {
        case 'r': {
            lbl_8064D594.r = 200; lbl_8064D594.g = 62; lbl_8064D594.b = 57;
            named_r = lbl_8064D594; fn_801ECD74(&named_r);
            break;
        }
        case 'g': {
            lbl_8064D594.r = 0; lbl_8064D594.g = 230; lbl_8064D594.b = 0;
            named_g = lbl_8064D594; fn_801ECD74(&named_g);
            break;
        }
        case 'b': {
            lbl_8064D594.r = 100; lbl_8064D594.g = 100; lbl_8064D594.b = 255;
            named_b = lbl_8064D594; fn_801ECD74(&named_b);
            break;
        }
        case 'l': {
            lbl_8064D594.r = 175; lbl_8064D594.g = 200; lbl_8064D594.b = 255;
            named_l = lbl_8064D594; fn_801ECD74(&named_l);
            break;
        }
        case 'w': {
            lbl_8064D594.r = 230; lbl_8064D594.g = 230; lbl_8064D594.b = 230;
            named_w = lbl_8064D594; fn_801ECD74(&named_w);
            break;
        }
        case 'y': {
            lbl_8064D594.r = 230; lbl_8064D594.g = 230; lbl_8064D594.b = 0;
            named_y = lbl_8064D594; fn_801ECD74(&named_y);
            break;
        }
        case 'f': {
            lbl_8064D594.r = 130; lbl_8064D594.g = 130; lbl_8064D594.b = 130;
            named_f = lbl_8064D594; fn_801ECD74(&named_f);
            break;
        }
        case 'c': {
            lbl_8064D594.r = palette[4]; lbl_8064D594.g = palette[5]; lbl_8064D594.b = palette[6];
            named_c = lbl_8064D594; fn_801ECD74(&named_c);
            break;
        }
        case 'u': {
            lbl_8064D594.r = palette[8]; lbl_8064D594.g = palette[9]; lbl_8064D594.b = palette[10];
            named_u = lbl_8064D594; fn_801ECD74(&named_u);
            break;
        }
        case 'x': {
            lbl_8064D594.r = palette[12]; lbl_8064D594.g = palette[13]; lbl_8064D594.b = palette[14];
            named_x = lbl_8064D594; fn_801ECD74(&named_x);
            break;
        }
        case 'm': {
            lbl_8064D594.r = palette[16]; lbl_8064D594.g = palette[17]; lbl_8064D594.b = palette[18];
            named_m = lbl_8064D594; fn_801ECD74(&named_m);
            break;
        }
        case 's': {
            u8* source = palette + *(u32*)(palette + 0x14 + lbl_8064D564 * 12) * 4;
            lbl_8064D594.r = source[0]; lbl_8064D594.g = source[1]; lbl_8064D594.b = source[2];
            named_s = lbl_8064D594; fn_801ECD74(&named_s);
            break;
        }
        case 'a': {
            u8* source = palette + lbl_8064D564 * 4;
            lbl_8064D594.r = source[0]; lbl_8064D594.g = source[1]; lbl_8064D594.b = source[2];
            named_a = lbl_8064D594; fn_801ECD74(&named_a);
            break;
        }
        case 'd': {
            u8* source = palette + *(u32*)(palette + 0x1c + lbl_8064D564 * 12) * 4;
            lbl_8064D594.r = source[0]; lbl_8064D594.g = source[1]; lbl_8064D594.b = source[2];
            named_d = lbl_8064D594; fn_801ECD74(&named_d);
            break;
        }
        default:
            fn_801E7DCC((char*)diagnostics - 0x1254, (s8)text[1]);
            break;
        }
        text += 2;
        break;
    }
    case 's': {
        float scale;
        int consumed = 0;
        text++;
        if (fn_800FBFD0(text, &lbl_8064C324, &scale, &consumed) > 0) {
            if (scale < lbl_80651264) lbl_8064C314 = scale;
            else fn_801E7DCC((char*)diagnostics - 0x1214, (double)scale);
        }
        text += consumed;
        break;
    }
    case 'e': lbl_8064D57C = 1; break;
    case 'i': fn_801E39A8((s8)text[1] - '0'); text += 2; break;
    case '~': text += 2; break;
    default: fn_801E7DCC((char*)diagnostics - 0x11d8, command); break;
    }
    return text;
}
