typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern u8 lbl_80607120[];
extern int lbl_8064D738;

extern void fn_80193B94(void*, void*, void*);
extern void fn_80193CB4(void*, void*);
extern void DCFlushRange(void*, unsigned int);
extern int fn_801ED57C(int);
extern void fn_8018D0D0(void*, void*, s16);
extern void fn_801887C4(void*, void*, void*);

void fn_80193AB8(u8* object)
{
    u16 offset;
    unsigned int byte_offset;
    u16 vertex_size;
    u16 color_size;
    u16 index_size;
    u8* vertex_data;
    u8* color_data;
    u8* index_data;
    u8* self;
    int saved;

    self = object;
    offset = *(u16*)(lbl_80607120 + 2);
    index_data = *(u8**)(object + 0x58);
    vertex_size = *(u16*)(lbl_80607120 + 0xA);
    byte_offset = offset * 4;
    color_size = *(u16*)(lbl_80607120 + 0xE);
    index_size = *(u16*)(lbl_80607120 + 0xC);
    vertex_data = *(u8**)(object + 0x50);
    color_data = *(u8**)(object + 0x54);

    fn_80193B94(self, index_data, index_data + byte_offset);
    if (lbl_8064D738 != 0) {
        color_data += byte_offset;
        index_data += byte_offset;
        vertex_data += offset * 6;
    }
    fn_80193CB4(self, vertex_data);
    DCFlushRange(vertex_data, vertex_size);
    DCFlushRange(color_data, color_size);
    DCFlushRange(index_data, index_size);
    saved = fn_801ED57C(0);
    fn_8018D0D0(self, self + 0x5C, *(s16*)(self + 0xE));
    fn_801887C4(vertex_data, color_data, index_data);
    fn_801ED57C(saved);
}
