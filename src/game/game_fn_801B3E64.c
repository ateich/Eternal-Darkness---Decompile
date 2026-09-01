typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Node Node;
struct Node {
    Node* next;
    Node* prev;
    u8 state;
    u8 type;
    u8 pad0A[2];
    u32 key;
};

typedef struct Request {
    u32 handle;
    u16 type;
    u8 pad06[2];
    u32 target;
    u16 value0C;
    u8 pad0E[2];
    u32 value10;
    u16 value14;
    u16 value16;
    u8 value18;
    u8 value19;
    u8 pad1A[2];
    u32 value1C;
    u32 value20;
    u16 value24;
    u8 flags;
} Request;

typedef struct CreateInfo {
    u32 flags;
    u32 value4;
    u32 value8;
    u16 valueC;
    u16 valueE;
    u8 value10;
    u8 pad11[7];
    u8 value18;
} CreateInfo;

extern u8 lbl_8060C020[];
extern Node* lbl_8064D398;
extern Node* lbl_8064D39C;
extern void fn_801B3CC8(int, int, u32, int);
extern void fn_801B3B08(u32);
extern int fn_801B2914(u32);
extern void fn_801B8D00(int, int, u32, int);
extern void fn_801B8C70(u32);
extern void fn_801B8CA8(u32, u32, u32);
extern void fn_801B8C28(u32, u16);
extern int fn_801C3F6C(u16, u16, u32, CreateInfo*, int, u8);
extern int fn_801C40AC(u16, u16, u32, CreateInfo*, u8);

static inline int resolve_handle(u32 value)
{
    u32 key = value & 0x7FFFFFFF;
    Node* node = lbl_8064D39C;
    while (node != 0) {
        if (node->key == key)
            return node->type | (value & 0x80000000U);
        node = node->next;
    }
    node = lbl_8064D398;
    while (node != 0) {
        if (node->key == key)
            return node->type | (value & 0x80000000U);
        node = node->next;
    }
    return -1;
}

void fn_801B3E64(Request* request, u32* output, u8 alternate)
{
    u8* base = lbl_8060C020;
    u32 original = request->handle;
    int id = resolve_handle(original);

    if (request->flags & 4) {
        u8* entry = base + id * 0x1868;
        u32* src = (u32*)request;
        u32* dst = (u32*)(entry + 0x22B4);
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
        dst[4] = src[4];
        dst[5] = src[5];
        dst[6] = src[6];
        dst[7] = src[7];
        dst[8] = src[8];
        dst[9] = src[9];
        entry[0x22E0] = 1;
        *(u32*)(entry + 0x22DC) = (u32)output;
        entry[0x22DA] &= ~4;
        *output = request->handle | 0x80000000U;
        return;
    }

    if (alternate) {
        if (request->type >= 5)
            request->type = 5;
        if (request->flags & 1)
            fn_801B3CC8(0, request->type, original, 2);
        else if (request->flags & 0x40)
            fn_801B3CC8(0, request->type, original, 3);
        else
            fn_801B3CC8(0, request->type, original, 1);
    } else {
        if (request->flags & 1)
            fn_801B8D00(0, request->type, original, 2);
        else if (request->flags & 0x40)
            fn_801B8D00(0, request->type, original, 3);
        else
            fn_801B8D00(0, request->type, original, 1);
    }

    if (output == 0)
        return;

    if (request->flags & 2) {
        int target_id = resolve_handle(request->target);
        if (target_id == -1) {
            *output = -1;
            return;
        }
        if (alternate) {
            int index;
            fn_801B3B08(request->target);
            fn_801B3CC8(request->value18, request->value0C, request->target, 0);
            if (request->flags & 0x10) {
                index = fn_801B2914(request->target);
                if (index != -1) {
                    if ((index & 0x80000000U) == 0) {
                        u8* entry = base + index * 0x1868;
                        *(u32*)(entry + 0x151C) = request->value1C;
                        *(u32*)(entry + 0x1520) = request->value20;
                    } else {
                        u8* entry = base + (index & 0x7FFFFFFF) * 0x1868;
                        entry[0x22DA] |= 0x10;
                        *(u32*)(entry + 0x22D0) = request->value1C;
                        *(u32*)(entry + 0x22D4) = request->value20;
                    }
                }
            }
            if (request->flags & 0x20) {
                u16 value = request->value24;
                index = fn_801B2914(request->target);
                if ((index & 0x80000000U) == 0) {
                    u8* entry = base + index * 0x1868;
                    int i;
                    for (i = 0; i < 16; i++)
                        *(u16*)(entry + 0x291A + i * 0x38) = value;
                } else {
                    u8* entry = base + (index & 0x7FFFFFFF) * 0x1868;
                    entry[0x22DA] |= 0x20;
                    *(u16*)(entry + 0x22D8) = value;
                }
            }
        } else {
            fn_801B8C70(request->target);
            fn_801B8D00(request->value18, request->value0C, request->target, 0);
            if (request->flags & 0x10)
                fn_801B8CA8(request->target, request->value1C, request->value20);
            if (request->flags & 0x20)
                fn_801B8C28(request->target, request->value24);
        }
        *output = request->target;
        return;
    }

    {
        CreateInfo info;
        info.flags = 4;
        if (request->flags & 8)
            info.flags |= 0x10;
        if (request->flags & 0x20) {
            info.flags |= 2;
            info.valueC = request->value24;
        }
        if (request->flags & 0x10) {
            info.flags |= 1;
            info.value4 = request->value1C;
            info.value8 = request->value20;
        }
        info.valueE = request->value0C;
        info.value10 = request->value18;
        info.value18 = 0;
        if (alternate) {
            int created = fn_801C3F6C(request->value14, request->value16,
                                      request->value10, &info, 1,
                                      request->value19);
            *output = created;
            if (created != -1 && (request->flags & 0x80)) {
                int index = fn_801B2914(created);
                if (index != -1) {
                    if ((index & 0x80000000U) == 0) {
                        u8* entry = base + index * 0x1868;
                        *(u32*)(entry + 0x151C) = 0;
                        *(u32*)(entry + 0x1520) = 0;
                    } else {
                        u8* entry = base + (index & 0x7FFFFFFF) * 0x1868;
                        entry[0x22DA] |= 0x10;
                        *(u32*)(entry + 0x22D0) = 0;
                        *(u32*)(entry + 0x22D4) = 0;
                    }
                }
            }
        } else {
            int created = fn_801C40AC(request->value14, request->value16,
                                      request->value10, &info,
                                      request->value19);
            *output = created;
            if (created != -1 && (request->flags & 0x80))
                fn_801B8CA8(created, 0, 0);
        }
    }
}
