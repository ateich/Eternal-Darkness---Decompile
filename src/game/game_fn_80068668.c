typedef struct RuntimeOwner {
    unsigned char data[0xC0];
    void *value;
} RuntimeOwner;

typedef struct RuntimeHandle {
    RuntimeOwner *owner;
} RuntimeHandle;

void *fn_80068668(RuntimeHandle *handle)
{
    return handle->owner->value;
}
