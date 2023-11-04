#include <stdio.h>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"

int main() {
    ShoppingCart cart;
    printf("Enter Customer's Name:\n");
    fgets(cart.customerName, sizeof(cart.customerName), stdin);
    printf("Enter Today's Date:\n");
    fgets(cart.currentDate, sizeof(cart.currentDate), stdin);

    printf("Customer Name:\n%s", cart.customerName);
    printf("Today's Date:\n%s", cart.currentDate);

    PrintMenu(cart);

    return 0;
}