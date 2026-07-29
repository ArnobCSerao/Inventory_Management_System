#include <stdio.h>

#include "inventory.h"
#include "menu.h"

int main(void)
{
    Product inventory[MAX_PRODUCTS];
    int product_count = 0;

    show_title();
    
    load_inventory(inventory, &product_count);

    if (product_count == 0)
    {
        printf("\nNo saved inventory found.\n");
        printf("Initializing with default inventory...\n");

        product_count = initialize_inventory(inventory);
    }

    show_menu(inventory, &product_count);

    return 0;
}











