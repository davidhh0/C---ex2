#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 50
int numOfAccounts = 0;
double accounts[MAX][2];
/*
Accounts is a matrix (double array) that has accounts from 0 to 50 ; we will add to each account
900 in order to have a range 901-950.
accounts[x][0] = 1 if the account is active ; 
accounts[x][0] = 0 if the account is not active;
numOfAccounts will store the number of accounts that was inserted.
accounts[x][1] -> stores the money
*/

int main()
{
   
    char whatFunction = '1';
    // printf("Enter a function:");
    //whatFunction = getchar();
    int *p_numOfAccounts;
    

    double (*p_accounts)[MAX][2] = &accounts;

    p_numOfAccounts = &numOfAccounts;

    while (whatFunction != 'E' && whatFunction != EOF)
    {
        whatFunction='1';    
        printf("Enter a function: ");
       scanf(" %c", &whatFunction);
       // whatFunction = getchar();
        switch (whatFunction)
        {
        case 'O':
            O(p_accounts,p_numOfAccounts);
            break;
        case 'B':
            B(p_accounts);
            break;
        case 'D':
            D(p_accounts);
            break;
        case 'W':
            W(p_accounts);
            break;
        case 'C':
            C(p_accounts,p_numOfAccounts);
            break;
        case 'I':
            I(p_accounts);
            break;
        case 'E':
            break;
        case 'P':
            P(p_accounts,p_numOfAccounts);
            break;

        default:
            printf("Please enter function: O , B ,D , W , C , I , P , E \n");
            break;
        }

    }

    printf("\nREST IN PEACE");
    return 0;
}
void O(double (*_accounts)[50][2] , int *_numOfAccounts)
{
    
    if (*_numOfAccounts < 50)
    {
        int whereTo = 0;
        for (int i = 0; i < 50; i++)
        {
            if ((*_accounts)[i][0] == 0)
            {
                whereTo = i;
                break;
            }
        }

        printf("Initial deposit?: ");
        double toDeposit;
        //scanf("%lf", &toDeposit);
        scanf(" %lf", &toDeposit);
        if  (toDeposit < 0)
        {
            printf("Failed to read the amount \n");
            memset(&toDeposit ,'\0',sizeof(float));
                        
        }
        else{
            (*_accounts)[whereTo][0] = 1;
            (*_accounts)[whereTo][1] = toDeposit;
            printf("New account to the bank: %d \n", (whereTo + 901));
            ++*_numOfAccounts;
        }

    }
    else
    {
        printf("The bank is full");
    }
}

void B(double (*_accounts)[50][2])
{
    printf("Enter the account number: ");
    int accountNumber;
    scanf(" %d", &accountNumber);
    if ((*_accounts)[accountNumber - 901][0]==1)
    {// the account is active
    double balance = (*_accounts)[accountNumber-901][1];

    printf("Account number: %d, Balance: %.2lf \n", accountNumber, balance);

    }
    else
    {
        printf("There is not an account: %d \n", accountNumber);
    }
}

void D(double (*_accounts)[50][2])
{
    printf("Enter the account number: ");
    int accountNumber;
    double amountToDeposit;
    scanf(" %d", &accountNumber);

    if ((*_accounts)[accountNumber - 901][0]==1)
        {
        printf("Enter amount to deposit: ");
        scanf(" %lf", &amountToDeposit);
        if (amountToDeposit < 0)
        {
            printf("You can't deposit negative value! \n");
            return;
        }
        double balance = (*_accounts)[accountNumber-901][1];
        (*_accounts)[accountNumber-901][1] = balance + amountToDeposit;
        printf("New balance: %.2lf \n", (balance + amountToDeposit));
    }
    else
    {
        printf("There is not an account: %d \n", accountNumber);
    }
}

void W(double (*_accounts)[50][2])
{
    printf("Enter the account number: ");
    int accountNumber;
    double amountToWithdrawal;
    scanf(" %d", &accountNumber);
    if ((*_accounts)[accountNumber - 901][0]==1)
    {
        printf("Enter amount to withdrawal: ");
        scanf(" %lf", &amountToWithdrawal);
        if (amountToWithdrawal < 0)
        {
            printf("You can't withdrawal negative value! \n");
            return;
        }
        if ((*_accounts)[accountNumber - 901][1] < amountToWithdrawal)
        {
            printf("There is not enought money in the account \n");
        }
        else
        {
            double balance = (*_accounts)[accountNumber-901][1];
            (*_accounts)[accountNumber-901][1] = balance - amountToWithdrawal;
            printf("New balance: %.2lf \n", (balance - amountToWithdrawal));
        }
    }
    else
    {
        printf("There is not an account: %d \n", accountNumber);
    }
}

void C(double (*_accounts)[50][2], int *_numOfAccounts)
{
    printf("Enter the account number: ");
    int accountNumber;
    scanf(" %d", &accountNumber);
    if ((*_accounts)[accountNumber - 901][0]==0)
    {
        printf("There is not an account: %d \n", accountNumber);
    }
    else
    {
        (*_accounts)[accountNumber - 901][0] = 0;
        printf("Account: %d closed.\n", accountNumber);
        --*_numOfAccounts;
    }
}

void I(double (*_accounts)[50][2])
{
    printf("Enter interest rate in percentage: ");
    double percent;
    scanf(" %lf", &percent);
    if(percent<=0){
        printf("Not acceptable interest rate!!");
        return;
    }
    
    for (int i=0; i<50;i++)
    {
        double balance = (*_accounts)[i][1];
        (*_accounts)[i][1] = balance + (percent / 100) * balance;
        
    }
    printf("DONE - interest rate \n");
}

void P(double (*_accounts)[50][2], int *_numOfAccounts)
{
    int i = 0;
    if (*_numOfAccounts == 0)
    {
        printf("No accounts in the bank \n");
    }
    else
    {
        for (i = 0; i < 50; i++)
        {
            if ((*_accounts)[i][0] == 1)
            {
                double balance = (*_accounts)[i][1];
                printf("Account number: %d , balance: %.2lf \n", (i + 901), balance);
            }
        }
    }
}
