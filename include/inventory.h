#ifndef INVENTORY_H
#define INVENTORY_H

#define MAX_PRODUCTS 100

typedef struct
{
    int id;
    char name[50];
    float price;
    int quantity;

} Product;


// Input functions
int read_integer(int *value);

int read_float(float *value);

int read_string(char *buffer, int size);


// Inventory functions
int initialize_inventory(Product inventory[]);

void display_inventory(Product inventory[], int size);

void display_product(const Product *product);

void add_product(Product inventory[], int *product_count);

void search_product(Product inventory[], int product_count);

void update_product(Product inventory[], int product_count);

void delete_product(Product inventory[], int *product_count);


// File functions
void save_inventory(Product inventory[], int product_count);

void load_inventory(Product inventory[], int *product_count);


#endif