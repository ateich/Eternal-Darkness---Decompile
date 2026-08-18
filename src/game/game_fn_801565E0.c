typedef struct Link Link;

struct Link {
    char pad0[8];
    Link* previous;
    Link* next;
};

int fn_801565E0(Link* link)
{
    int result = 0;

    if (link != 0 && link->next != 0) {
        link->next->previous = link->previous;
        if (link->previous != 0)
            link->previous->next = link->next;
        link->next = 0;
        link->previous = 0;
        result = 1;
    }
    return result;
}
