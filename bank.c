#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

typedef struct {
    int account_number;
    char name[50];
    double balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

void display_customers() {
    if (num_customers == 0) {
        printf("\nNo customers available.\n");
        return;
    }
    printf("\n--- Customer Details ---\n");
    for (int i = 0; i < num_customers; i++) {
        printf("Account No: %d\n", customers[i].account_number);
        printf("Name: %s\n", customers[i].name);
        printf("Balance: %.2f\n", customers[i].balance);
        printf("-----------------------------\n");
    }
}

void deposit(int account_number, double amount) {
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            customers[i].balance += amount;
            printf("Deposit successful. New balance = %.2f\n", customers[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw(int account_number, double amount) {
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            if (customers[i].balance >= amount) {
                customers[i].balance -= amount;
                printf("Withdrawal successful. New balance = %.2f\n", customers[i].balance);
            } else {
                printf("Insufficient balance!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void calculate_interest(int account_number, double rate, int time) {
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            double interest = (customers[i].balance * rate * time) / 100.0;
            printf("Interest for %d years at %.2f%% = %.2f\n", time, rate, interest);
            customers[i].balance += interest;
            printf("New balance after interest = %.2f\n", customers[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void add_customer() {
    if (num_customers >= MAX_CUSTOMERS) {
        printf("Cannot add more customers. Limit reached.\n");
        return;
    }
    int account_number;
    char name[50];
    double balance;
    printf("Enter new account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            printf("Account number already exists! Please choose a different number.\n");
            return;
        }
    }
    printf("Enter customer name: ");
    getchar();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Enter opening balance: ");
    scanf("%lf", &balance);
    customers[num_customers].account_number = account_number;
    strcpy(customers[num_customers].name, name);
    customers[num_customers].balance = balance;
    num_customers++;
    printf("Customer added successfully!\n");
}

int main() {
    int choice, acc_no;
    double amount, rate;
    int time;
    while (1) {
        printf("\n--- Banking System Menu ---\n");
        printf("1. Display Customers\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Calculate Interest\n");
        printf("5. Exit\n");
        printf("6. Add Customer\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_customers();
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                deposit(acc_no, amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                withdraw(acc_no, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                printf("Enter annual interest rate (%%): ");
                scanf("%lf", &rate);
                printf("Enter time (years): ");
                scanf("%d", &time);
                calculate_interest(acc_no, rate, time);
                break;
            case 5:
                printf("Exiting... Thank you!\n");
                exit(0);
            case 6:
                add_customer();
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
