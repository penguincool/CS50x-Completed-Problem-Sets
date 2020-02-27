#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    // Testing that user entered an argument when running program.
    // If they did not provide 2 arguments, give error message and
    // return 1;
    if (argc != 2)
    {
        printf("Error, you must enter one non-negative number.\n");

        argv[0] = "0";

        return 1;
    }
    // Else, cipher text.
    else
    {
        // Convert argument to an integer.
        int k;
        k = atoi(argv[1]);

        // If k is greater than 26, mod it by 26 to get a number
        // below 26
        if (k > 26)
        {
            k = k % 26;
        }

        // Get plain text value.
        string plain_text;
        plain_text = get_string("plaintext: ");

        // Declare cipher text string.
        string cipher_text;
        cipher_text = plain_text;

        // Run loop for length of plain_text and cipher text
        // based on if its alphabetical, then if it's upper case
        // or lower case.
        for (int i = 0, len = strlen(plain_text); i < len; i++)
        {
            // Test if character is alphabetical.
            if (isalpha(plain_text[i]))
            {
                // Test if character is upper case.
                if (isupper(plain_text[i]))
                {
                    cipher_text[i] = 65 + (plain_text[i] - 65 + k) % 26;
                }
                // Test if character is lower case.
                if (islower(plain_text[i]))
                {
                    cipher_text[i] = 97 + (plain_text[i] - 97 + k) % 26;
                }
            }
        }

        // Output the ciphered text
        printf("ciphertext: %s\n", cipher_text);


        return 0;
    }
}