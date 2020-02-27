#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Declare variable for credit card number
    long long cc_number;

    // Prompt and validate user for a credit card number
    do
    {
        cc_number = get_long_long("Enter a credit card number: ");
    }
    while (cc_number < 0);

    // Find length of credit card
    int length = log10(cc_number) + 1;

    // Create array for storing individual digits of credit card
    long long cc_digits[length];
    cc_digits[0] = 0;

    // Store individual digits of credit card into array
    for (int i = length - 1; i >= 0; i--)
    {
        // On first loop, use modulus to get ones place of credit
        // card number
        if (i == length - 1)
        {
            cc_digits[i] = cc_number % 10;
        }
        // Any other value of i, divide credit card number by 10
        // then apply modulus to get next value place
        else
        {
            cc_number /= 10;
            cc_digits[i] = cc_number % 10;
        }
    }

    // Declare variables for Luhn's algorithm, where x is used to store values
    // in the products/sum of a product in first step. y adds each x, adds
    // values in second step, and is used in the final step to determine if it
    // is divisible wholly.
    long long x = 0;
    long long y = 0;

    // Complete first step of Luhn's algorithm
    for (int i = length - 2; i >= 0; i = i - 2)
    {
        x = cc_digits[i] * 2;

        // If there are multiple digits in x, separate and add them together.
        // Otherwise, add x to y.
        if (log10(x) >= 1)
        {
            for (int j = 1; j >= 0; j--)
            {
                if (j == 1)
                {
                    y = y + x % 10;
                }
                else
                {
                    x /= 10;
                    y = y + x;
                }
            }
        }
        else
        {
            y = y + x;
        }
    }

    // Complete second step
    for (int i = length - 1; i >= 0; i = i - 2)
    {
        y = y + cc_digits[i];
    }

    y = y % 10;

    // Complete last step
    if (y == 0)
    {
        // Determine credit card name based on length and first one or two digits
        // depending on credit card name.
        // If none work display invalid
        switch (length)
        {
            case 13:
                if (cc_digits[0] == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 15:
                if (cc_digits[0] == 3)
                {
                    if (cc_digits[1] == 4 || cc_digits[1] == 7)
                    {
                        printf("AMEX\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 16:
                if (cc_digits[0] == 4)
                {
                    printf("VISA\n");
                }
                else if (cc_digits[0] == 5)
                {
                    if (cc_digits[1] >= 1 && cc_digits[1] <= 5)
                    {
                        printf("MASTERCARD\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            default:
                printf("INVALID\n");
        }
    }
    // display the credit card is invalid
    else
    {
        printf("INVALID\n");
    }
}