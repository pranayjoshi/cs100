typedef struct {
    char customerName[100];
    char currentDate[100];
    ItemToPurchase cartItems[10];
    int cartSize;
} ShoppingCart;

void PrintMenu(ShoppingCart cart);
void PrintCart(ShoppingCart cart);