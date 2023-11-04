#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct customer {
    int account_number;
    char name[50];
    float balance;
};

void create_account(struct customer *c) {
    printf("Enter account number: ");
    scanf("%d", &c->account_number);
    printf("Enter name: ");
    scanf("%s", c->name);
    printf("Enter initial balance: ");
    scanf("%f", &c->balance);
    printf("Account created successfully!\n");
}

void deposit(struct customer *c) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    c->balance = c->balance + amount;
    printf("Deposit successful! Current balance: %.2f\n", c->balance);
}

void withdraw(struct customer *c) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if(c->balance < amount) {
        printf("Insufficient balance!\n");
    } else {
        c->balance = c->balance - amount;
        printf("Withdrawal successful! Current balance: %.2f\n", c->balance);
    }
}

void display(struct customer c) {
    printf("Account Number: %d\n", c.account_number);
    printf("Name: %s\n", c.name);
    printf("Balance: %.2f\n", c.balance);
}

int main() {
    struct customer bank[10];
    int choice, acc_no, i;
    
    while(1) {
        printf("1. Create Account\n2. Deposit\n3. Withdraw\n4. Display Account\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // create account
                for(i = 0; i < 10; i++) {
                    if(bank[i].account_number == 0) {
                       create_account(&bank[i]);
                       break;
                    }
                }
                if(i == 10) {
                    printf("Bank limit reached. Cannot create account!\n");
                }
                break;
                
            case 2: // deposit
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                for(i = 0; i < 10; i++) {
                    if(bank[i].account_number == acc_no) {
                       deposit(&bank[i]);
                       break;
                    }
                }
                if(i == 10) {
                    printf("Invalid account number!\n");
                }
                break;
                
            case 3: // withdraw
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                for(i = 0; i < 10; i++) {
                    if(bank[i].account_number == acc_no) {
                       withdraw(&bank[i]);
                       break;
                    }
                }
                if(i == 10) {
                    printf("Invalid account number!\n");
                }
                break;
                
            case 4: // display
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                for(i = 0; i < 10; i++) {
                    if(bank[i].account_number == acc_no) {
                        display(bank[i]);
                        break;
                    }
                }
                if(i == 10) {
                    printf("Invalid account number!\n");
                }
                break;
                
            case 5: // exit
                exit(0);
        }
    }
}