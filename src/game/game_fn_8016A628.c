extern char lbl_8024FE60[];
extern void* lbl_8023A878[];

void* fn_8016A628(void* context, int index)
{
    if (index == -1) {
        return lbl_8024FE60;
    }
    return lbl_8023A878[index];
}
