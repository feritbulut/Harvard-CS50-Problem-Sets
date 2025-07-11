#include <cs50.h>
#include <stdio.h>

int calculate_change(int cents, int value);

int main(void)
{

    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    int quarters = calculate_change(cents, 25);
    cents -= quarters * 25;

    int dimes = calculate_change(cents, 10);
    cents -= dimes * 10;

    int nickels = calculate_change(cents, 5);
    cents -= nickels * 5;

    int pennies = calculate_change(cents, 1);
    cents -= pennies * 1;

    int sum = quarters + dimes + nickels + pennies;

    printf("%i \n", sum);
}

int calculate_change(int cents, int coin_value)
{
    int coin = 0;

    while (cents >= coin_value)
    {
        coin++;
        cents -= coin_value;
    }
    return coin;
}
