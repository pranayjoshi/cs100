#include <stdio.h>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"
#include <string.h>

int main() {
    ShoppingCart cart;
    cart.cartSize = 0;
    printf("Enter Customer's Name:\n");
    fgets(cart.customerName, 100, stdin);
    cart.customerName[strlen(cart.customerName) - 1] = '\0';
    printf("Enter Today's Date:\n");
    fgets(cart.currentDate, 100, stdin);
    cart.currentDate[strlen(cart.currentDate) - 1] = '\0';
    printf("\nCustomer Name: %s\n", cart.customerName);
    printf("Today's Date: %s\n", cart.currentDate);
    PrintMenu(cart);

    return 0;
}