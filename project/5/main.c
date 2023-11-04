#include <stdio.h>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"
#include <string.h>

int main() {
    ShoppingCart cart;
    cart.cartSize = 0;
    printf("Enter Customer's Name:\n");
    fgets(cart.customerName, sizeof(cart.customerName), stdin);
    cart.customerName[strlen(cart.customerName) - 1] = '\0';
    printf("Enter Today's Date:\n");
    fgets(cart.currentDate, sizeof(cart.currentDate), stdin);
    cart.currentDate[strlen(cart.customerName) - 1] = '\0';

    printf("Customer Name:\n%s", cart.customerName);
    printf("Today's Date:\n%s", cart.currentDate);

    PrintMenu(cart);

    return 0;
}