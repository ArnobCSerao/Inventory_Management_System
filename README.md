# Inventory Management System

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

This project is part of my Engineering Portfolio documenting my progress in C programming and Embedded Systems development.