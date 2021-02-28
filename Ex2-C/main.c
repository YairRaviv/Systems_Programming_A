#include <stdio.h>
#include "myBank.h"

int main()
{
    int capacity = 0;
    char i;
    while (i != 'E')
    {
        printf("\nPlease choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
        if (scanf(" %c", &i) == EOF)
        {
            return 0;
        }
        switch (i)
        {
        case 'O':
        {
            if (capacity > 50)
            {
                printf("There is no space for a new account\n");
            }
            else
            {
                double sum;
                printf("Please enter amount for deposit: ");
                if (scanf("%lf", &sum) != 1)
                {
                    printf("Failed to read the amount\n");
                }
                else
                {
                    newAccount(sum);
                }
                capacity++;
            }
            break;
        }
        case 'B':
        {
            int num;
            printf("Please enter account number: ");
            if (scanf("%d", &num) != 1)
            {
                printf("Failed to read the account number\n");
            }
            else if (accountCheck(num))
            {
                printf("This account is closed\n");
            }
            else
            {
                if (!(num > 900 && num < 951))
                {
                    printf("Invalid account number\n");
                }
                else
                {
                    currentSum(num);
                }
            }
            break;
        }

        case 'D':
        {
            int num;
            double amount;
            printf("Please enter account number: ");
            if (scanf("%d", &num) != 1)
            {
                printf("Failed to read the account number\n");
            }
            else if (!(num > 900 && num < 951))
            {
                printf("Invalid account number\n");
            }
            else if (accountCheck(num))
            {
                printf("This account is closed\n");
            }
            else
            {
                printf("Please enter the amount to deposit: ");
                if (scanf("%lf", &amount) != 1)
                {
                    printf("Failed to read the amount\n");
                }
                else if (amount < 0)
                {
                    printf("Cannot deposit a negative amount\n");
                }
                else
                {
                    push(num, amount);
                }
            }
            break;
        }
        case 'W':
        {
            int num;
            double amount;
            printf("Please enter account number: ");
            if (scanf("%d", &num) != 1)
            {
                printf("Failed to read the account number\n");
            }
            else if (!(num > 900 && num < 951))
            {
                printf("Invalid account number\n");
            }
            else if (accountCheck(num))
            {
                printf("This account is closed\n");
            }
            else
            {
                printf("Please enter the amount to withdraw: ");
                if (scanf("%lf", &amount) != 1)
                {
                    printf("Failed to read the amount\n");
                }
                else if (amount < 0)
                {
                    printf("Cannot withdraw a negative amount\n");
                }
                else
                {
                    pull(num, amount);
                }
            }
            break;
        }
        case 'C':
        {
            int num;
            printf("Please enter account number: ");
            if (scanf("%d", &num) != 1)
            {
                printf("Failed to read the account number\n");
            }
            else if (!(num > 900 && num < 951))
            {
                printf("Invalid account number\n");
            }
            else if (accountCheck(num))
            {
                printf("This account is already closed\n");
            }
            else
                close(num);
            capacity--;
            break;
        }
        case 'I':
        {
            int d;
            printf("Please enter interest rate: ");
            if (scanf("%d", &d) != 1)
            {
                printf("Failed to read the interest rate\n");
            }
            else
            {
                rate(d);
            }
            break;
        }
        case 'P':
        {
            print();
            break;
        }
        case 'E':
        {
            break;
        }
        default:
        {
            printf("Invalid transaction type\n");
        }
        }
    }

    Exit();
    return 0;
}