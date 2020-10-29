#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool isValidKey(string key);
string encrypt(string input, int key);
int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Invalid input no");
        return 1;
    }
    if (!isValidKey(argv[1]))
    {
        printf("Invalid key");
        return 1;
    }
    
    int key = atoi(argv[1]) % 26;
    string userInput = get_string("plaintext: "); 
    string result = encrypt(userInput, key);
    printf("ciphertext: %s\n", result);
    
}

bool isValidKey(string key)
{
    
    int i = 0 ;
    while (key[i] != '\0')
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
        i++;
    }
    return true;
}

string encrypt(string input, int key)
{
    //string result = input;
    int i = 0;
    while (input[i] != '\0')
    {
        if (isalpha(input[i]))
        {
            if (isupper(input[i]))
            {
                input[i] = input[i] - 'A';
                input[i] = ((input[i] + key) % 26) + 'A';
            }
            else
            {
                input[i] = input[i] - 'a';
                input[i] = ((input[i] + key) % 26) + 'a';

            }
            
        }
        else
        {
            input[i] = input[i];
        }
        i++;
    }
    return input;
}