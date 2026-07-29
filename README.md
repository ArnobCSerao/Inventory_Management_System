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