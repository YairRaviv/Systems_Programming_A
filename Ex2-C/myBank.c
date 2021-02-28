#include <stdio.h>
double bank[2][50] = {
    {0},
    {0},
};
void newAccount(double firstSum)
{
    if (firstSum > 0)
    {
        int i;
        for (i = 0; i < 50; i++)
        {
            if (!bank[1][i])
                break;
        }
        bank[0][i] = firstSum;
        bank[1][i] = 1;
        printf("New account number is: %d \n", (i + 901));
    }
    else
    {
        printf("Invalid Amount\n");
    }
}

void currentSum(int num)
{
    num -= 901;
    printf("The balance of account number %d is: %.2f\n", num + 901, bank[0][num]);
}

void push(int num, double sum)
{
    num -= 901;
    bank[0][num] += sum;
    printf("The new balance is: %.2f\n", bank[0][num]);
}

void pull(int num, double sum)
{
    num -= 901;
    if ((bank[0][num] - sum) >= 0)
    {
        bank[0][num] -= sum;
        printf("The new balance is: %.2f\n", bank[0][num]);
    }
    else
        printf("Cannot withdraw more than the balance\n");
}

void close(int num)
{
    num -= 901;
    bank[0][num] = 0;
    bank[1][num] = 0;
    printf("Closed account number %d\n", num + 901);
}

void rate(int d)
{
    double rate = (d / 100.0);
    for (int i = 0; i < 50; i++)
    {
        if (bank[1][i])
        {
            bank[0][i] += (rate * bank[0][i]);
        }
    }
}

void print()
{
    for (int i = 0; i < 50; i++)
    {
        if (bank[1][i])
        {
            printf("The balance of account number %d is: %.2f\n", (i + 901), bank[0][i]);
        }
    }
}
void Exit()
{
    for (int i = 0; i < 50; i++)
    {
        bank[0][i] = 0;
        bank[1][i] = 0;
    }
}

int accountCheck(int account_num)
{
    int account_real_num = account_num - 901;
    if (bank[1][account_real_num])
    {
        return 0;
    }
    else
    {
        return 1;
    }
}