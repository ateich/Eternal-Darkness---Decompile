typedef struct Header {
    int file;
    short value;
    short id;
    char name[12];
} Header;

typedef struct FileData {
    unsigned char pad[0x14];
    int offset;
} FileData;

extern Header lbl_805AE780;
extern unsigned char lbl_8024EF08[];
extern void* lbl_8064A65C;
extern void fn_800F9D4C(char*, const char*, ...);
extern void fn_80155BB0(const char*, const char*, ...);
extern void fn_802136A4(void*);
extern int fn_8021302C(const char*);
extern int fn_80213320(int, Header*);
extern int fn_802137F4(Header*, void*, int, int, int);
extern void fn_8021345C(Header*);

void fn_801399CC(short id)
{
    Header local;
    char* name;

    if (id == 119) {
        id = 85;
    } else if (id == 120) {
        id = 121;
    } else if (id == 122) {
        id = 101;
    }

    if (lbl_805AE780.id != id) {
        lbl_805AE780.id = -1;
        name = lbl_805AE780.name;
        fn_800F9D4C(name, (char*)lbl_8024EF08 + 0x84);
        fn_802136A4((void*)0x8064D068);
        lbl_805AE780.file = fn_8021302C(name);
        fn_802136A4((void*)0x8064D070);
        if (lbl_805AE780.file != -1) {
            if (!fn_80213320(lbl_805AE780.file, &local)) {
                fn_80155BB0((char*)lbl_8024EF08 + 0x94,
                            (char*)lbl_8024EF08 + 0xAC,
                            name, lbl_805AE780.file);
            } else {
                while (fn_802137F4(&local, lbl_8064A65C, 1024, 0, 2) == -1) {
                }
                ((FileData*)lbl_8064A65C)->offset += (int)lbl_8064A65C;
                lbl_805AE780.id = id;
                fn_8021345C(&local);
            }
        }
    }
}
