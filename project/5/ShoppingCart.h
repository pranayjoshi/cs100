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

ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart);
ShoppingCart RemoveItem(char itemName[], ShoppingCart cart);
ShoppingCart ModifyItem(ItemToPurchase item, ShoppingCart cart);


void AICall(ShoppingCart *cart);
void RICall(ShoppingCart *cart);
void MICcall(ShoppingCart *cart);

int GetNumItemsInCart(ShoppingCart cart);
int GetCostOfCart(ShoppingCart cart);