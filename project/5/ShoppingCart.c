#include <stdio.h>
#include "ShoppingCart.h"

void PrintMenu(ShoppingCart cart) {
    printf("MENU\n");
    printf("a - Add item to cart\n");
    printf("o - Output shopping cart\n");
    printf("q - Quit\n");
    printf("Choose an option: ");
    char choice;
    scanf(" %c", &choice);

    switch(choice) {
        case 'a':
            // Call function to add item
            break;
        case 'o':
            PrintCart(cart);
            break;
        case 'q':
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
}

void PrintCart(ShoppingCart cart) {
    printf("OUTPUT SHOPPING CART\n");
    printf("%s's Shopping Cart - %s\n", cart.customerName, cart.currentDate);
    printf("Number of Items: %d\n", cart.cartSize);

    // Loop through cart items and print details...
}
