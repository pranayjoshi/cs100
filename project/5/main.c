#include <stdio.h>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"

int main() {
    ShoppingCart cart;
    printf("Enter Customer's Name: ");
    fgets(cart.customerName, sizeof(cart.customerName), stdin);
    printf("Enter Today's Date: ");
    fgets(cart.currentDate, sizeof(cart.currentDate), stdin);

    printf("Customer Name: %s", cart.customerName);
    printf("Today's Date: %s", cart.currentDate);

    PrintMenu(cart);

    return 0;
}
