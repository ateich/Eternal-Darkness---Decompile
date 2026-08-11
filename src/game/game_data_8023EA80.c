struct MenuResources {
    char menu[12];
    char inventory[16];
    char package[16];
    char credits[20];
};

#pragma force_active on
struct MenuResources lbl_8023EA80 = {
    "EMnMenu.cmp",
    "EBookInv.tpl",
    "EBookPak.bin",
    "credits/cr%04d.cmp",
};
#pragma force_active reset
