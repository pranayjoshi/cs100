#include "ItemToPurchase.h"

typedef struct {
    char customerName[100];
    char currentDate[100];
    ItemToPurchase cartItems[100];
    int cartSize;
} ShoppingCart;

void PrintMenu(ShoppingCart cart);
void PrintTotal(ShoppingCart cart);
void PrintDescriptions(ShoppingCart cart);
void AddItem(ShoppingCart *cart);
void RemoveItem(ShoppingCart *cart);
void ModifyItem(ShoppingCart *cart);
int GetNumItemsInCart(ShoppingCart cart);
int GetCostOfCart(ShoppingCart cart);