# ATM System Project

A simple and interactive ATM system developed in C++. The ATM allows users to authenticate with a PIN, check their balance, deposit money, and withdraw funds. It includes basic input validation and error handling for a smooth user experience.

---

## Table of Contents

1. [Project Overview](#project-overview)
2. [Features](#features)
3. [Technologies Used](#technologies-used)
4. [Installation](#installation)
5. [Usage](#usage)
6. [File Structure](#file-structure)
7. [Testing](#testing)
8. [Contributing](#contributing)
9. [License](#license)
10. [Acknowledgments](#acknowledgments)

---

## Project Overview

This project simulates an ATM machine using basic C++ functionality. Users can log in using a PIN, view their account balance, deposit funds, or withdraw money. It includes basic input validation and simulates real-world ATM operations.

### Use Cases:
- **Personal Finance Simulation**: Simulate basic financial transactions like deposits, withdrawals, and balance checks.
- **Learning Project**: A great beginner project to understand basic C++ concepts such as input/output, loops, conditional statements, and object-oriented programming.

---

## Features

- **User Authentication**: PIN-based login to access the account.
- **Check Balance**: View the current balance at any time.
- **Deposit Money**: Add funds to your account.
- **Withdraw Money**: Remove funds from your account (checks for sufficient balance).
- **Input Validation**: Handles invalid input (e.g., entering a negative amount for deposits or withdrawals).
- **Interactive Console Interface**: Simple and intuitive console-based menu system.

---

## Technologies Used

- **Language**: C++
- **Libraries**: 
  - `<iostream>` for input/output
  - `<iomanip>` for formatted output
  - `<limits>` for input validation
  - `<unistd.h>` for adding delays (optional)

---

## Installation

To run this ATM system on your local machine, follow these steps:

1. Clone the repository:
   
   git clone https://github.com/Sahiljain0/ATM_MACHINE-C-.git
   cd ATM


<!-- Compile the C++ code: -->

g++ atm_machine.cpp -o atm_machine
./atm_machine

<!-- ************************************************************************** -->
<!-- Usage -->

* Login: Enter your PIN to access the system.
* Main Menu: After login, you’ll be presented with the following options:
* Check balance
* Deposit money
* Withdraw money
* Exit the system
* Exiting: Select the "Exit" option to log out of the ATM.

<!-- ************************************************************************ -->

                ============================================
                =              WELCOME TO ATM              =
                ============================================

                Enter your PIN: 1234

                Login successful! Welcome, John Doe.

                ********************************************
                *                 MAIN MENU                *
                ********************************************
                *  1. Check Balance                        *
                *  2. Deposit Money                        *
                *  3. Withdraw Money                       *
                *  4. Exit                                 *
                ********************************************
                Please choose an option: 1

                ============================================
                =              CURRENT BALANCE             =
                ============================================
                =        Your balance: $ 5000.00           =
                ============================================
<!-- ************************************************************************* -->
* File Structure *
ATM
│
├── atm_machine.cpp       # Main ATM system code
├── README.md             # Project overview and documentation
└── atm_machine.txt       # having text content


<!-- **********************************************************************
 -->
 ## Contributing

Contributions are welcome! If you'd like to contribute to the ATM System, please follow these steps:

# 1. Fork the repository
git clone https://github.com/Sahiljain0/ATM_MACHINE-C-.git
cd atm-system
git remote add upstream https://github.com/originalowner/atm-system.git

# 2. Create a new branch
git checkout -b feature-branch

# 3. Make your changes
# (Edit files, add features, fix bugs, etc.)

# 4. Commit your changes
git add .
git commit -m 'Add some feature'

# 5. Push to the branch
git push origin feature-branch

# 6. Open a pull request
