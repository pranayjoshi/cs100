#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

typedef struct ItemToPurchase_struct {
    char itemName[100];
    char itemDescription[200];
    int itemPrice;
    int itemQuantity;
} ItemToPurchase;

void MakeItemBlank(ItemToPurchase* item);
void PrintItemCost(ItemToPurchase* item);

#endif