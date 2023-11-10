typedef struct ItemToPurchase_struct {
    char itemName[100];
    char itemDescription[1000];
    int itemPrice;
    int itemQuantity;
} ItemToPurchase;

void MakeItemBlank(ItemToPurchase* item);
void PrintItemCost(ItemToPurchase* item);
void PrintItemDescription(ItemToPurchase* item);