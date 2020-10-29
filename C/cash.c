#include<stdio.h>
#include<cs50.h>
#include<math.h>

int coins(int owedChange);
int main(void)
{
    // declaring dollars for user input storing
    float dollars = 0;
    // checking user input for negative numbers
    do
    {
        // geting user input (cashier owed change)
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    
    // handling user input
    int cents = round(dollars * 100);
    
    int count = coins(cents);
    
    printf("%d\n", count);
    
}

int coins(int owedChange)
{
    int coinCount = 0;
    
    coinCount = owedChange / 25;
    owedChange %= 25;
    
    coinCount += owedChange / 10;
    owedChange %= 10;

    coinCount += owedChange / 5;
    owedChange %= 5;

    coinCount += owedChange ;
    
    return coinCount;
}