typedef struct Owner Owner;
typedef int (*Callback)(Owner *owner);

typedef struct Handler {
    unsigned char pad_00[0x1C];
    Callback callback;
} Handler;

struct Owner {
    unsigned char pad_00[4];
    Handler *handler;
};

int fn_8006EC8C(Owner *owner)
{
    int result;

    result = 0;
    if (owner->handler != 0 && owner->handler->callback != 0) {
        result = owner->handler->callback(owner);
    }
    return result;
}
