#include <stdio.h>
#include "ItemToPurchase.h"

int main() {
    struct ItemToPurchase item1, item2;
    char c;
    printf("Item 1\n");
    printf("Enter the item name: ");
    scanf("%99[^\n]", item1.itemName);
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter the item price: ");
    scanf("%d", &item1.itemPrice);

    printf("Enter the item quantity: ");
    scanf("%d", &item1.itemQuantity);
    
    while ((c = getchar()) != '\n' && c != EOF);
    printf("\nItem 2\n");
    printf("Enter the item name: ");
    scanf("%99[^\n]", item2.itemName);
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter the item price: ");
    scanf("%d", &item2.itemPrice);

    printf("Enter the item quantity: ");
    scanf("%d", &item2.itemQuantity);

    printf("\nTOTAL COST\n");
    PrintItemCost(&item1);
    PrintItemCost(&item2);

    int totalCost = (item1.itemQuantity * item1.itemPrice) + (item2.itemQuantity * item2.itemPrice);
    printf("\nTotal: $%d\n", totalCost);

    return 0;
}
