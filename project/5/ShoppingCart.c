#include <stdio.h>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"
#include <string.h>

void PrintMenu(ShoppingCart cart)
{

    char choice = ' ';
    while (choice != 'q')
    {
        printf("MENU\n");
        printf("a - Add item to cart\n");
        printf("c - Change item quantity\n");
        printf("i - Output items' descriptions\n");
        printf("o - Output shopping cart\n");
        printf("q - Quit\n\n");
        printf("Choose an option:\n");
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'o':
            printf("OUTPUT SHOPPING CART\n");
            PrintTotal(cart);
            break;
        case 'i':
            printf("OUTPUT ITEMS' DESCRIPTIONS\n");
            PrintDescriptions(cart);
            break;
        case 'a':
            printf("ADD ITEM TO CART\n");
            AddItem(&cart);
            break;
        case 'r':
            printf("REMOVE ITEM FROM CART\n");
            RemoveItem(&cart);
            break;
        case 'c':
            printf("CHANGE ITEM QUANTITY\n");
            ModifyItem(&cart);
            break;
        case 'q':
            break;
        }
    }
}

void PrintTotal(ShoppingCart cart)
{
    if (cart.cartSize == 0)
    {
        printf("SHOPPING CART IS EMPTY\n");
        return;
    }
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

void PrintDescriptions(ShoppingCart cart)
{
    printf("%s's Shopping Cart - %s\n\n", cart.customerName, cart.currentDate);
    printf("Item Descriptions\n");
    for (int i = 0; i < cart.cartSize; ++i)
    {
        printf("%s:\n%s\n", cart.cartItems[i].itemName, cart.cartItems[i].itemDescription);
    }
}

void AddItem(ShoppingCart *cart)
{
    ItemToPurchase item;
    printf("Enter the item name:\n");
    getchar();
    fgets(item.itemName, sizeof(item.itemName), stdin);

    printf("Enter the item description:\n");
    getchar();
    fgets(item.itemDescription, sizeof(item.itemDescription), stdin);

    printf("Enter the item price:\n");
    scanf(" %d", &item.itemPrice);

    printf("Enter the item quantity:\n");
    scanf(" %d", &item.itemQuantity);
    printf("awdadad\n");
    printf("%d\n", cart->cartSize);

    cart->cartItems[cart->cartSize] = item;
    cart->cartSize++;
}

void RemoveItem(ShoppingCart *cart)
{
    printf("Enter name of item to remove:\n");
    char itemName[100];
    fgets(itemName, sizeof(itemName), stdin);

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

    if (!found)
    {
        printf("Item not found in cart. Nothing removed\n");
    }
}

void ModifyItem(ShoppingCart *cart)
{
    printf("Enter the item name:\n");
    char itemName[100];
    fgets(itemName, sizeof(itemName), stdin);

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

int GetNumItemsInCart(ShoppingCart cart)
{
    int totalItems = 0;
    for (int i = 0; i < cart.cartSize; ++i)
    {
        totalItems += cart.cartItems[i].itemQuantity;
    }
    return totalItems;
}

int GetCostOfCart(ShoppingCart cart)
{
    int totalCost = 0;
    for (int i = 0; i < cart.cartSize; ++i)
    {
        totalCost += cart.cartItems[i].itemQuantity * cart.cartItems[i].itemPrice;
    }
    return totalCost;
}