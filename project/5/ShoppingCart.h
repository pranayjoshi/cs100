#include "ItemToPurchase.h"

typedef struct {
    char customerName[100];
    char currentDate[100];
    ItemToPurchase cartItems[10];
    int cartSize;
} ShoppingCart;

void PrintMenu(ShoppingCart cart);
void OutputShoppingCart(ShoppingCart cart);
void OutputItemDescriptions(ShoppingCart cart);
void AddItemToCart(ShoppingCart *cart);
void RemoveItemFromCart(ShoppingCart *cart);
void ChangeItemQuantity(ShoppingCart *cart);