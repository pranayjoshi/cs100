#include <stdio.h>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"

int main() {
    ShoppingCart cart;
    printf("Enter Customer's Name:\n");
    fgets(cart.customerName, sizeof(cart.customerName), stdin);
    printf("Enter Today's Dat\n");
    fgets(cart.currentDate, sizeof(cart.currentDate), stdin);

    printf("Customer Nam\n%s", cart.customerName);
    printf("Today's Dat\n%s", cart.currentDate);

    PrintMenu(cart);

    return 0;
}
