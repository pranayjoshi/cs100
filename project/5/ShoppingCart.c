#include <stdio.h>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"

void PrintMenu(ShoppingCart cart)
{
    printf("MENU\n");
    printf("a - Add item to cart\n");
    printf("c - Change item quantity\n");
    printf("i - Output items' descriptions\n");
    printf("o - Output shopping cart\n");
    printf("q - Quit\n");
    printf("Choose an option:\n");
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
    printf("Number of Items:\n%d\n\n", cart.cartSize);
    int totalCost = 0;
    for (int i = 0; i < cart.cartSize; ++i)
    {
        printf("%s %d @ $%d = $%d\n", cart.cartItems[i].itemName, cart.cartItems[i].itemQuantity, cart.cartItems[i].itemPrice, cart.cartItems[i].itemQuantity * cart.cartItems[i].itemPrice);
        totalCost += cart.cartItems[i].itemQuantity * cart.cartItems[i].itemPrice;
    }

    printf("\nTotal:\n$%d\n", totalCost);
}

void OutputItemDescriptions(ShoppingCart cart)
{
    printf("OUTPUT ITEMS' DESCRIPTIONS\n");
    printf("%s's Shopping Cart - %s\n\n", cart.customerName, cart.currentDate);
    printf("Item Descriptions\n");
    for (int i = 0; i < cart.cartSize; ++i)
    {
        printf("%s:\n%s\n", cart.cartItems[i].itemName, cart.cartItems[i].itemDescription);
    }
}

void AddItemToCart(ShoppingCart *cart)
{
    printf("ADD ITEM TO CART\n");
    printf("Enter the item name:\n");
    char itemName[100];
    scanf(" %s", itemName);

    printf("Enter the item description:\n");
    char itemDescription[100];
    scanf(" %s", itemDescription);

    printf("Enter the item price:\n");
    int itemPrice;
    scanf(" %d", &itemPrice);

    printf("Enter the item quantity:\n");
    int itemQuantity;
    scanf(" %d", &itemQuantity);

    ItemToPurchase item;
    sprintf(item.itemName, "%s", itemName);
    sprintf(item.itemDescription, "%s", itemDescription);
    item.itemPrice = itemPrice;
    item.itemQuantity = itemQuantity;

    cart->cartItems[cart->cartSize] = item;
    cart->cartSize++;
}

void RemoveItemFromCart(ShoppingCart *cart)
{
    printf("REMOVE ITEM FROM CART\n");
    printf("Enter name of item to remove:\n");
    char itemName[100];
    scanf(" %s", itemName);
    
    int found = 0;
    for (int i = 0; i < cart->cartSize; ++i)
    {
        if (strcmp(cart->cartItems[i].itemName, itemName) == 0)
        {
            found = 1;
            for (int j = i; j < cart->cartSize - 1; ++j)
            {
                cart->cartItems[j] = cart->cartItems[j + 1];
            }
            cart->cartSize--;
            break;
        }
    }
     

}

void ChangeItemQuantity(ShoppingCart *cart)
{
    printf("CHANGE ITEM QUANTITY\n");
    printf("Enter the item name:\n");
    char itemName[100];
    scanf(" %s", itemName);

    printf("Enter the new quantity:\n");
    int itemQuantity;
    scanf(" %d", &itemQuantity);

    for (int i = 0; i < cart->cartSize; ++i)
    {
        if (strcmp(cart->cartItems[i].itemName, itemName) == 0)
        {
            cart->cartItems[i].itemQuantity = itemQuantity;
            break;
        }
    }
}
