#include "ItemToPurchase.h"

typedef struct {
    char customerName[100];
    char currentDate[100];
    ItemToPurchase cartItems[10];
    int cartSize;
} ShoppingCart;

void PrintMenu(ShoppingCart cart);
void PrintTotal(ShoppingCart cart);
void PrintDescriptions(ShoppingCart cart);
void AddItem(ShoppingCart *cart);
void RemoveItem(ShoppingCart *cart);
void ModifyItem(ShoppingCart *cart);
void GetNumItemsInCart(ShoppingCart cart);
void GetCostOfCart(ShoppingCart cart);