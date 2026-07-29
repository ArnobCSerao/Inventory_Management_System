#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "inventory.h"

#define INVENTORY_FILE "data/inventory.txt"

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
    FILE *file = fopen(INVENTORY_FILE, "w");

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
    FILE *file = fopen(INVENTORY_FILE, "r");

    if (file == NULL)
    {
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