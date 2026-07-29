# Inventory Management System v1.0

A console-based Inventory Management System written in C.

This project was developed as part of my Embedded Systems and Software Engineering learning journey to practice structured programming, modular design, pointers, structures, arrays, file handling, and input validation.

---

## Features

- Display all products
- Add new products
- Search products by Product ID
- Update existing products
- Delete products with confirmation
- Save inventory to a text file
- Load inventory from a text file
- Robust input validation
- Modular function-based design

---

## Technologies Used

- C Programming Language
- GCC Compiler
- Visual Studio Code
- Git
- GitHub

---

## Project Structure

```
Inventory_Management_System/
│
├── main.c
├── README.md
├── .gitignore
└── inventory.txt (generated after saving)
```

---

## How to Compile

```bash
gcc main.c -o Inventory_Management_System
```

---

## How to Run

Windows

```bash
.\Inventory_Management_System.exe
```

Linux / macOS

```bash
./Inventory_Management_System
```

---

## Sample Menu

```
========== Inventory Management ==========
1. Display Inventory
2. Add Product
3. Search Product
4. Update Product
5. Delete Product
6. Save Inventory
7. Load Inventory
8. Exit
```

---

## Concepts Demonstrated

- Structures (`struct`)
- Arrays of Structures
- Functions
- Pointers
- Pointer Parameters
- Input Validation
- Dynamic Inventory Management
- File Input/Output
- Modular Programming
- String Handling
- Error Handling

---

## Future Improvements

- Prevent duplicate Product IDs
- Validate positive prices and quantities
- Sort inventory by ID or name
- Separate source into `.c` and `.h` files
- Binary file storage
- CSV import/export
- Product categories
- Inventory statistics

---

## Author

Arnob Claydon Serao

Electrical and Information Engineering Student

---------------------------------------------

# Inventory Management System v2.0

A console-based Inventory Management System written in C.

This project demonstrates:
- C structures
- Header files (.h)
- Multiple source files (.c)
- File handling
- Input validation
- CRUD operations
- Modular programming

---

## Overview

This program allows users to manage a product inventory through a command-line interface.

Features:
- Display products
- Add products
- Search products by ID
- Update product information
- Delete products
- Save inventory data
- Load inventory data automatically

The project was upgraded from a single-file C program into a modular multi-file architecture.

---

## Features

### Product Information
Each product contains:
- Product ID
- Product Name
- Product Price
- Product Quantity

### Data Storage

Inventory data is stored in:

data/inventory.txt

The program loads saved inventory when started.

If no saved inventory exists, a default inventory is created.

### Input Safety

The program uses:
- fgets()
- strtol()
- strtof()

for safer user input handling.

---

## Project Structure

Inventory_Management_System

main.c

include/
- inventory.h
- menu.h

src/
- inventory.c
- menu.c

data/
- inventory.txt

README.md
.gitignore

---

## Compilation

Compile using GCC:

gcc main.c src/inventory.c src/menu.c -Iinclude -o Inventory_Management_System

Run:

Windows:
Inventory_Management_System.exe

Linux/macOS:
./Inventory_Management_System

---

## Default Inventory

Product 1:
ID: 101
Name: Arduino Uno
Price: 25.50
Quantity: 12

Product 2:
ID: 102
Name: Raspberry Pi Pico
Price: 18.75
Quantity: 20

Product 3:
ID: 103
Name: ESP32
Price: 32.90
Quantity: 15

---

## Learning Purpose

This project is part of my journey toward becoming an Embedded Systems Engineer.

Skills practiced:
- C programming
- Software organization
- File handling
- Modular architecture
- Problem solving

Future improvements:
- Dynamic memory allocation
- Linked lists
- Advanced data structures
- Embedded system adaptation

---

## Version History

## v2.0 - Modular Architecture

Changes:
- Split program into multiple .c and .h files
- Improved project organization
- Improved maintainability


## v1.0 - Initial Release

Features:
- Basic inventory management
- CRUD operations
- File saving and loading

---

## Author

Arnob Claydon Serao

Electronic & Information Engineering Student

Aspiring Embedded Systems Engineer

GitHub:
https://github.com/ArnobCSerao