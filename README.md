# Bank Management System in C

This C program implements a simple console-based **banking management system** that allows users to manage customer accounts and perform basic banking operations. It uses structured programming with **functions** and a `struct` to represent customer details.

## Key Features

- **Add Customer**  
  Allows the user to create a new customer account by entering an account number, customer name, and opening balance.  
  ✅ Ensures account numbers are unique  
  ✅ Limits the number of customers to **100**

- **Display Customers**  
  Lists all customers with their account number, name, and current balance.  
  ℹ️ If no customers exist, it notifies the user.

- **Deposit Money**  
  Enables depositing a specified amount into a customer’s account by entering their account number.  
  💰 The balance is updated accordingly.

- **Withdraw Money**  
  Allows withdrawal of a specified amount from a customer’s account.  
  ⚠️ Ensures withdrawals do not exceed the available balance, preventing overdrafts.

- **Calculate Interest**  
  Computes **simple interest** on a customer’s current balance based on a provided annual interest rate and time period (in years).  
  ➕ The calculated interest is added to the customer’s balance.

- **Exit**  
  Cleanly terminates the program when the user chooses to exit.

## Technical Highlights

- Uses a `struct Customer` to store:
  - Account number
  - Name
  - Balance

- Maintains an array of customers:  
  ```c
  Customer customers[MAX_CUSTOMERS];
