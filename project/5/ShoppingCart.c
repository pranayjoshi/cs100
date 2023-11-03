#include <stdio.h>
#include "ShoppingCart.h"

void PrintMenu(ShoppingCart cart)
{
    printf("MENU\n");
    printf("a - Add item to cart\n");
    printf("c - Change item quantity\n");
    printf("i - Output items' descriptions\n");
    printf("o - Output shopping cart\n");
    printf("q - Quit\n");
    printf("Choose an option: ");
    char choice;
    scanf(" %c", &choice);

    switch (choice)
    {
    case 'o':
        PrintCart(cart);
        break;
    case 'o':
        OutputShoppingCart(cart);
        break;
    case 'i':
        OutputItemDescriptions(cart);
        break;
    case 'a':
        AddItemToCart(&cart);
        break;
    case 'r':
        RemoveItemFromCart(&cart);
        break;
    case 'c':
        ChangeItemQuantity(&cart);
        break;
    case 'q':
        printf("Goodbye!\n");
        break;
    default:
        printf("Invalid choice! Please try again.\n");
        break;
    }
}

void OutputShoppingCart(ShoppingCart cart)
{
    printf("OUTPUT SHOPPING CART\n");
    printf("%s's Shopping Cart - %s\n", cart.customerName, cart.currentDate);
    printf("Number of Items: %d\n\n", cart.cartSize);

    // Loop through cart items and print details...
    int totalCost = 0;
    for (int i = 0; i < cart.cartSize; ++i)
    {
        printf("%s %d @ $%d = $%d\n", cart.cartItems[i].itemName, cart.cartItems[i].itemQuantity, cart.cartItems[i].itemPrice, cart.cartItems[i].itemQuantity * cart.cartItems[i].itemPrice);
        totalCost += cart.cartItems[i].itemQuantity * cart.cartItems[i].itemPrice;
    }

    printf("\nTotal: $%d\n", totalCost);
}

void OutputItemDescriptions(ShoppingCart cart)
{
    printf("OUTPUT ITEMS' DESCRIPTIONS\n");
    printf("%s's Shopping Cart - %s\n\n", cart.customerName, cart.currentDate);
    printf("Item Descriptions\n");
    // Loop through cart items and print descriptions...
    for (int i = 0; i < cart.cartSize; ++i)
    {
        printf("%s: %s\n", cart.cartItems[i].itemName, cart.cartItems[i].itemDescription);
    }
}

void AddItemToCart(ShoppingCart *cart)
{
    // Function logic to add an item to cart
    // You'll need to implement this
}

void RemoveItemFromCart(ShoppingCart *cart)
{
    // Function logic to remove an item from cart
    // You'll need to implement this
}

void ChangeItemQuantity(ShoppingCart *cart)
{
    // Function logic to change item quantity
    // You'll need to implement this
}
