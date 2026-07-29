#include <stdio.h>
#include "inventory.h"
#include "menu.h"

void show_title(void)
{
    printf("====================================\n");
    printf("    Inventory Management System     \n");
    printf("====================================\n");
}

void show_menu(Product inventory[], int *product_count)
{
    int choice;

     while (1)
    {
        printf("\n========== Inventory Management ==========\n");
        printf("1. Display Inventory\n");
        printf("2. Add Product\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Save Inventory\n");
        printf("7. Load Inventory\n");
        printf("8. Exit\n");

        printf("\nEnter your choice: ");

        if(!read_integer(&choice))
        {
            printf("\nInvalid input. Please enter an integer.\n");
            continue;
        }

        switch(choice)
        {
            case 1:
                display_inventory(inventory, *product_count);
                break;

            case 2:
                add_product(inventory, product_count);
                break;

            case 3:
                search_product(inventory, *product_count);
                break;

            case 4:
                update_product(inventory, *product_count);
                break;
            
            case 5:
                delete_product(inventory, product_count);
                break;

            case 6:
                save_inventory(inventory, *product_count);
                break;

            case 7:
                load_inventory(inventory, product_count);
                break;

            case 8:
                printf("\nExiting the program. Goodbye!\n");
                return;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
