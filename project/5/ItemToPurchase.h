#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

struct ItemToPurchase {
    char itemName[100];
    int itemPrice;
    int itemQuantity;
};

void MakeItemBlank(struct ItemToPurchase* item);
void PrintItemCost(const struct ItemToPurchase* item);

#endif
