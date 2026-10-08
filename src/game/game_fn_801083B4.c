extern int lbl_8064CC7C;
extern int lbl_8064CC80;

extern int fn_80108558(void*, int, int);
extern int fn_801086C4(void*, int, int);

int fn_801083B4(void* buffer, int size)
{
    int written;

    if (lbl_8064CC7C < lbl_8064CC80 + size) {
        lbl_8064CC80 = 0;
    }

    written = fn_801086C4(buffer, size, lbl_8064CC80);
    if (written < 0) {
        return -1;
    }

    if (written != size) {
        if (fn_80108558(buffer == 0 ? 0 : (char*)buffer + written,
                         size - written, lbl_8064CC80 + written) < 0) {
            return -1;
        }
    }

    lbl_8064CC80 += size;
    return size;
}
