#include <stdio.h>
#include "ItemToPurchase.h"
#include <string.h>
#include <stdlib.h>

void SetItemName(ItemToPurchase* item, char* name) {
    // item->itemName = (char*)malloc((strlen(name) + 1) * sizeof(char));
    if (item->itemName != NULL) {
        strcpy(item->itemName, name);
    }
}

int main() {
    ItemToPurchase item1;
    ItemToPurchase item2;

    char c;

    printf("Item 1\nEnter the item name:\n");
    char itemName1[100];
    fgets(itemName1, 100, stdin);
    itemName1[strcspn(itemName1, "\n")] = 0;
    SetItemName(&item1, itemName1);

    printf("Enter the item price:\n");
    scanf("%d", &item1.itemPrice);
    printf("Enter the item quantity:\n");
    scanf("%d", &item1.itemQuantity);

    while ((c = getchar()) != '\n' && c != EOF);

    printf("\nItem 2\nEnter the item name:\n");
    char itemName2[100];
    fgets(itemName2, 100, stdin);
    itemName2[strcspn(itemName2, "\n")] = 0;
    SetItemName(&item2, itemName2);

    printf("Enter the item price:\n");
    scanf("%d", &item2.itemPrice);
    printf("Enter the item quantity:\n");
    scanf("%d", &item2.itemQuantity);

    printf("\nTOTAL COST\n");
    PrintItemCost(&item1);
    PrintItemCost(&item2);

    int totalCost = (item1.itemQuantity * item1.itemPrice) + (item2.itemQuantity * item2.itemPrice);
    printf("\nTotal: $%d\n", totalCost);

    return 0;
}
