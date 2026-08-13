typedef struct Owner {
    unsigned char pad_00[4];
    void *value;
} Owner;

void *fn_8006ED98(Owner *owner)
{
    return owner->value;
}
