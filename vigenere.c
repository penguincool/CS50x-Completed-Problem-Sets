#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    // Testing that user entered an argument when running program.
    // If they did not provide 2 arguments, give error message and
    // return 1.
    if (argc != 2)
    {
        printf("Error, you must enter a key word.\n");

        argv[0] = "0";

        return 1;
    }
    // Test if key has non alphabetical characters. If so,
    // give error message and return 1. Else cipher text.
    else
    {
        // Get key
        string k;
        k = argv[1];

        // Get key length
        int k_length;
        k_length = strlen(k);

        // Test for non alphabetical characters. If character is
        // alphabetical, convert to upper case in alphabetical
        // notation. If it is not alphabetical, give error message
        // and return 1.
        for (int j = 0; j < k_length; j++)
        {
            if (isalpha(k[j]))
            {
                k[j] = toupper(k[j]);
            }
            else
            {
                printf("Error, you must enter a key word.\n");

                return 1;
            }
        }

        // Prompt user for plain text
        string p;
        p = get_string("plaintext: ");

        // Declare cipher text string
        string c;
        c = p;

        // Get plain text length
        int p_length;
        p_length = strlen(p);

        // If p and k have equal or greater lengths only use one loop
        if (k_length >= p_length)
        {
            // Cipher plain text
            for (int i = 0; i < p_length; i++)
            {
                // If plain text character is alphabetical, cipher it.
                if (isalpha(p[i]))
                {
                    // Test if character is upper case
                    if (isupper(p[i]))
                    {
                        c[i] = 65 + (p[i] - 130 + k[i]) % 26;
                    }
                    // Test if character is lower case
                    if (islower(p[i]))
                    {
                        c[i] = 97 + (p[i] - 162 + k[i]) % 26;
                    }
                }
            }
        }
        // else include j in loop to count for k and repeat k as needed
        else
        {
            // Cipher plain text
            for (int i = 0, j = 0; i < p_length; i++, j++)
            {
                // Test if j is equal to k_length. If it is, make j=0 to
                // repeat k
                if (j == k_length)
                {
                    j = 0;
                }
                // If plain text character is alphabetical, cipher it.
                if (isalpha(p[i]))
                {
                    // Test if character is upper case
                    if (isupper(p[i]))
                    {
                        c[i] = 65 + (p[i] - 130 + k[j]) % 26;
                    }
                    // Test if character is lower case
                    if (islower(p[i]))
                    {
                        c[i] = 97 + (p[i] - 162 + k[j]) % 26;
                    }
                }
                // subtract j since no characters were ciphered
                else
                {
                    j--;
                }
            }
        }

        // Display cipher text
        printf("ciphertext: %s\n", c);

        return 0;
    }
}