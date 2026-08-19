typedef struct ObjectNode {
    struct ObjectNode* next;
    unsigned char unknown04[0x3C];
    void* object;
} ObjectNode;

extern ObjectNode* fn_80155D78(void);

ObjectNode* fn_80156948(void* object)
{
    ObjectNode* node;

    for (node = fn_80155D78(); node != 0; node = node->next) {
        if (node->object == object) {
            return node;
        }
    }
    return 0;
}
