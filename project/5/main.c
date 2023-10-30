#include <stdio.h>
#include "ItemToPurchase.h"

int main() {
    struct ItemToPurchase item1, item2;
    char c;

    // Item 1
    printf("Item 1\n");
    printf("Enter the item name:\n");
    scanf("%s", item1.itemName);
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter the item price:\n");
    scanf("%d", &item1.itemPrice);

    printf("Enter the item quantity:\n");
    scanf("%d", &item1.itemQuantity);

    while ((c = getchar()) != '\n' && c != EOF);

    printf("\nItem 2\n");
    printf("Enter the item name:\n");
    scanf("%s", item2.itemName);
    while ((c = getchar()) != '\n' && c != EOF);

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
