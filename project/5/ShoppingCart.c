#include <stdio.h>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"
#include <string.h>

void PrintMenu(ShoppingCart cart)
{
    char choice = ' ';
    printf("\nMENU\n");
    printf("a - Add item to cart\n");
    printf("r - Remove item from cart\n");
    printf("c - Change item quantity\n");
    printf("i - Output items' descriptions\n");
    printf("o - Output shopping cart\n");
    printf("q - Quit\n\n");
    while (choice != 'q')
    {
        if (choice == 'a' || choice == 'r' || choice == 'c' || choice == 'i' || choice == 'o')
        {
            printf("\nMENU\n");
            printf("a - Add item to cart\n");
            printf("r - Remove item from cart\n");
            printf("c - Change item quantity\n");
            printf("i - Output items' descriptions\n");
            printf("o - Output shopping cart\n");
            printf("q - Quit\n\n");
        }

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
            AddItemCaller(&cart);
            break;
        case 'r':
            printf("REMOVE ITEM FROM CART\n");
            RemoveItemCaller(&cart);
            break;
        case 'c':
            printf("CHANGE ITEM QUANTITY\n");
            ModifyItemCaller(&cart);
            break;
        case 'q':
            break;
        }
    }
}

void PrintTotal(ShoppingCart cart)
{
    printf("%s's Shopping Cart - %s\n", cart.customerName, cart.currentDate);
    printf("Number of Items: %d\n\n", GetNumItemsInCart(cart));
    int totalCost = 0;
    for (int i = 0; i < cart.cartSize; ++i)
    {
        printf("%s %d @ $%d = $%d\n", cart.cartItems[i].itemName, cart.cartItems[i].itemQuantity, cart.cartItems[i].itemPrice, cart.cartItems[i].itemQuantity * cart.cartItems[i].itemPrice);
        totalCost += cart.cartItems[i].itemQuantity * cart.cartItems[i].itemPrice;
    }

    if (cart.cartSize == 0)
    {
        printf("SHOPPING CART IS EMPTY\n");
    }

    printf("\nTotal: $%d\n", totalCost);
}

void PrintDescriptions(ShoppingCart cart)
{
    printf("%s's Shopping Cart - %s\n\n", cart.customerName, cart.currentDate);
    printf("Item Descriptions\n");
    for (int i = 0; i < cart.cartSize; ++i)
    {
        printf("%s: %s\n", cart.cartItems[i].itemName, cart.cartItems[i].itemDescription);
    }
}

ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart) {
    cart.cartItems[cart.cartSize] = item;
    cart.cartSize++;
    return cart;
}

void AddItemCaller(ShoppingCart *cart)
{
    ItemToPurchase item;
    printf("Enter the item name:\n");
    getchar();
    fgets(item.itemName, sizeof(item.itemName), stdin);
    item.itemName[strlen(item.itemName) - 1] = '\0';

    printf("Enter the item description:\n");
    fgets(item.itemDescription, sizeof(item.itemDescription), stdin);
    item.itemDescription[strlen(item.itemDescription) - 1] = '\0';

    printf("Enter the item price:\n");
    scanf(" %d", &item.itemPrice);

    printf("Enter the item quantity:\n");
    scanf(" %d", &item.itemQuantity);

    ShoppingCart newCart = AddItem(item, *cart);
    // cart = &newCart;
    *cart = newCart;
}


void RemoveItemCaller(ShoppingCart *cart)
{
    printf("Enter name of item to remove:\n");
    char itemName[100];
    getchar();
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strlen(itemName) - 1] = '\0';
    ShoppingCart newCart = RemoveItem(itemName, *cart);
    *cart = newCart;
}

ShoppingCart RemoveItem(char itemName[], ShoppingCart cart)
{
    int found = 0;
    for (int i = 0; i < cart.cartSize; ++i)
    {
        if (strcmp(cart.cartItems[i].itemName, itemName) == 0)
        {
            found = 1;
            for (int j = i; j < cart.cartSize - 1; ++j)
            {
                cart.cartItems[j] = cart.cartItems[j + 1];
            }
            cart.cartSize--;
            break;
        }
    }

    if (!found)
    {
        printf("Item not found in cart. Nothing removed.\n");
    }

    return cart;
}


void ModifyItemCaller(ShoppingCart *cart)
{
    printf("Enter the item name:\n");
    char itemName[100];
    getchar();
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strlen(itemName) - 1] = '\0';

    printf("Enter the new quantity:\n");
    int newQuantity;
    scanf(" %d", &newQuantity);

    ItemToPurchase item;
    strcpy(item.itemName, itemName);
    item.itemQuantity = newQuantity;
    ShoppingCart newCart = ModifyItem(item, *cart);
    *cart = newCart;
}

ShoppingCart ModifyItem(ItemToPurchase item, ShoppingCart cart)
{
    int found = 0;
    for (int i = 0; i < cart.cartSize; ++i)
    {
        if (strcmp(cart.cartItems[i].itemName, item.itemName) == 0)
        {
            found = 1;
            cart.cartItems[i].itemQuantity = item.itemQuantity;
            break;
        }
    }

    if (!found)
    {
        printf("Item not found in cart. Nothing modified.\n");
    }
    return cart;
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