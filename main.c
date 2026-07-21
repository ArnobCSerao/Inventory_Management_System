#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_PRODUCTS 100

typedef struct 
{
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

void show_title(void);
int read_integer(int *value);
int read_float(float *value);
int read_string(char *buffer, int size);
void show_menu(Product inventory[], int *product_count);
int initialize_inventory(Product inventory[]);
void display_inventory(Product inventory[], int size);
void display_product(const Product *product);
void add_product(Product inventory[], int *product_count);
void search_product(Product inventory[], int product_count);
void update_product(Product inventory[], int product_count);
void delete_product(Product inventory[], int *product_count);
void save_inventory(Product inventory[], int product_count);
void load_inventory(Product inventory[], int *product_count);

int main(void)
{
    Product inventory[MAX_PRODUCTS];
    int product_count;

    show_title();

    product_count = 0;

    load_inventory(inventory, &product_count);

    if (product_count == 0)
    {
        printf("\nNo saved inventory found.\nInitializing with default inventory...\n");

        product_count = initialize_inventory(inventory);
    }

    show_menu(inventory, &product_count);

    return 0;
}

void show_title(void)
{
    printf("====================================\n");
    printf("    Inventory Management System     \n");
    printf("====================================\n");
}

int read_integer(int *value)
{
    char input[100];
    char *endptr;

    if (fgets(input, sizeof(input), stdin) == NULL)
    {
        return 0;
    }

    input[strcspn(input, "\n")] = '\0';

    errno = 0;

    long number = strtol(input, &endptr, 10);

    if (errno == ERANGE || endptr == input || *endptr != '\0')
    {
        return 0;
    }

    *value = (int)number;

    return 1;
}

int read_float(float *value)
{
    char input[100];
    char *endptr;

    if(fgets(input, sizeof(input), stdin) == NULL)
    {
        return 0;
    }

    input[strcspn(input, "\n")] = '\0';

    errno = 0;

    float number = strtof(input, &endptr);

    if (errno == ERANGE || endptr == input || *endptr != '\0')
    {
        return 0;
    }

    *value = number;

    return 1;
}

int read_string(char *buffer, int size)
{
    if (fgets(buffer, size, stdin) == NULL)
    {
        return 0;
    }

    buffer[strcspn(buffer, "\n")] = '\0';
    
    return 1;
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

int initialize_inventory(Product inventory[])
{
    inventory[0].id = 101;
    inventory[0].price = 25.50;
    inventory[0].quantity = 12;
    strcpy(inventory[0].name, "Arduino Uno");

    inventory[1].id = 102;
    inventory[1].price = 18.75;
    inventory[1].quantity = 20;
    strcpy(inventory[1].name, "Raspberry Pi Pico");

    inventory[2].id = 103;
    inventory[2].price = 32.90;
    inventory[2].quantity = 15;
    strcpy(inventory[2].name, "ESP32");

    return 3;
}

void display_product(const Product *product)
{
    printf("\nProduct ID: %d\n", product->id);
    printf("Product Name: %s\n", product->name);
    printf("Price: %.2f\n", product->price);
    printf("Quantity: %d\n", product->quantity);

    float total_value = product->price * product->quantity;
    printf("\nTotal Value: %.2f\n", total_value);
}

void display_inventory(Product inventory[], int size)
{
    if (size == 0)
    {
        printf("\nInventory is empty.\n");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        printf("\nProduct %d:\n", i + 1);
        display_product(&inventory[i]);
    }
}

void add_product(Product inventory[], int *product_count)
{
    if (*product_count >= MAX_PRODUCTS)
    {
        printf("\nInventory is full! Cannot add more products.\n");
        return;
    }

    Product *new_product = &inventory[*product_count];

    printf("\nEnter Product ID: ");

    while (!read_integer(&new_product->id))
    {
        printf("\nInvalid input. Please enter an integer.\n");
        printf("Enter Product ID: ");
    }

    printf("Product ID stored successfully!\n");

    printf("Enter Product Name: ");

    while (!read_string(new_product->name, sizeof(new_product->name)))
    {
        printf("\nInvalid input.\n");
        printf("Enter Product Name: ");
    }

    printf("Product Name stored successfully!\n");

    printf("Enter Product Price: ");

    while (!read_float(&new_product->price))
    {
        printf("\nInvalid input. Please enter a valid number.\n");
        printf("Enter Product Price: ");
    }

    printf("Product Price stored successfully!\n");

    printf("Enter Product Quantity: ");

    while (!read_integer(&new_product->quantity))
    {
        printf("\nInvalid input. Please enter an integer.\n");
        printf("Enter Product Quantity: ");
    }

    printf("Product Quantity stored successfully!\n");

    (*product_count)++;
}

void search_product(Product inventory[], int product_count)
{
    int id;

    printf("\nEnter Product ID to search:");

    while (!read_integer(&id))
    {
        printf("\nInvalid input. Please enter an integer.\n");
        printf("Enter Product ID to search: ");
    }

    for (int i = 0; i < product_count; i++)
    {
        if (inventory[i].id == id)
        {
            printf("\nProduct found:\n");
            printf("--------------------------------\n");
            
            display_product(&inventory[i]);
            
            return;
        }
    }
    printf("\nProduct not found.\n");
}

void update_product(Product inventory[], int product_count)
{
    int id;
    printf("\nEnter Product ID to update: ");

    while (!read_integer(&id))
    {
        printf("\nInvalid input. Please enter an integer.\n");
        printf("Enter Product ID to update: ");
    }

    for (int i = 0; i < product_count; i++)
    {
        if (inventory[i].id == id)
        {
            printf("\nProduct found:\n");
            printf("--------------------------------\n");

            display_product(&inventory[i]);

            printf("\nEnter new Product Name (leave empty to keep current): ");

            char new_name[50];

            read_string(new_name, sizeof(new_name));

            if (strlen(new_name) > 0)
            {
                strcpy(inventory[i].name, new_name);
            }

            printf("Enter new Product Price (enter -1 to keep current): ");

            float new_price;

            while (!read_float(&new_price) || (new_price < 0 && new_price != -1))
            {
                printf("\nInvalid input. Please enter a valid number.\n");
                printf("Enter new Product Price (enter -1 to keep current): ");
            }

            if (new_price != -1)
            {
                inventory[i].price = new_price;
            }

            printf("Enter new Product Quantity (enter -1 to keep current): ");

            int new_quantity;

            while (!read_integer(&new_quantity) || (new_quantity < 0 && new_quantity != -1))
            {
                printf("\nInvalid input. Please enter an integer.\n");
                printf("Enter new Product Quantity (enter -1 to keep current): ");
            }

            if (new_quantity != -1)
            {
                inventory[i].quantity = new_quantity;
            }

            printf("\nProduct updated successfully!\n");
            return;
        }
    }
    printf("\nProduct not found.\n");
}

void delete_product(Product inventory[], int *product_count)
{
    int id;

    printf("\nEnter Product ID to delete: ");

    while (!read_integer(&id))
    {
        printf("\nInvalid input. Please enter an integer.\n");
        printf("Enter Product ID to delete: ");
    }

    for (int i = 0; i < *product_count; i++)
    {
        if (inventory[i].id == id)
        {
            printf("\nProduct found:\n");
            printf("--------------------------------\n");

            display_product(&inventory[i]);

            printf("\nAre you sure you want to delete this product? (y/n): ");

            char confirm_str[10];
            char confirm;

            while (1)
            {
                if (!read_string(confirm_str, sizeof(confirm_str)))
                {
                    printf("\nInvalid input. Please enter 'y' or 'n'.\n");
                    printf("Are you sure you want to delete this product? (y/n): ");
                    continue;
                }

                confirm = confirm_str[0];

                if (confirm == 'y' || confirm == 'Y')
                {
                    break;
                }
                else if (confirm == 'n' || confirm == 'N')
                {
                    printf("\nProduct deletion canceled.\n");
                    return;
                }
                else
                {
                    printf("\nInvalid input. Please enter 'y' or 'n'.\n");
                    printf("Are you sure you want to delete this product? (y/n): ");
                }
            }

            for (int j = i; j < *product_count - 1; j++)
            {
                inventory[j] = inventory[j + 1];
            }
            (*product_count)--;
            printf("\nProduct deleted successfully!\n");
            return;
        }
    }
    printf("\nProduct not found.\n");
}

void save_inventory(Product inventory[], int product_count)
{
    FILE *file = fopen("inventory.txt", "w");

    if (file == NULL)
    {
        printf("\nError opening file for writing.\n");
        return;
    }

    for (int i = 0; i < product_count; i++)
    {
        fprintf(file, "%d,%s,%.2f,%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }

    fclose(file);

    printf("\nInventory saved successfully to 'inventory.txt'.\n");
}

void load_inventory(Product inventory[], int *product_count)
{
    FILE *file = fopen("inventory.txt", "r");

    if (file == NULL)
    {
        printf("\nNo saved inventory found.\n");
        return;
    }

    *product_count = 0;

    while (fscanf(file, "%d,%49[^,],%f,%d\n", &inventory[*product_count].id, inventory[*product_count].name, &inventory[*product_count].price, &inventory[*product_count].quantity) == 4)
    {
        (*product_count)++;

        if (*product_count >= MAX_PRODUCTS)
        {
            printf("\nInventory limit reached. Some products may not be loaded.\n");
            break;
        }
    }

    fclose(file);

    printf("\nInventory loaded successfully from 'inventory.txt'.\n");
}