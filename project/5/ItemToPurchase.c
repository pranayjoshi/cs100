#include <stdio.h>
#include "ItemToPurchase.h"
#include <string.h>
#include <stdlib.h>


void MakeItemBlank(ItemToPurchase* item) {
    sprintf(item->itemName, "none");
    sprintf(item->itemDescription, "none");
    item->itemPrice = 0;
    item->itemQuantity = 0;
}

void PrintItemCost(ItemToPurchase* item) {
    printf("%s %d @ $%d = $%d\n", item->itemName, item->itemQuantity, item->itemPrice, (item->itemQuantity * item->itemPrice));
}

void PrintItemDescription(ItemToPurchase* item) {
    printf("%s: %s\n", item->itemName, item->itemDescription);
}