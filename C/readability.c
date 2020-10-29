#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

float colemanIndex(int lettersCount, int wordsCount, int sentencesCount);
void printGrade(float colemanIndex);

int main(void)
{
    // neede containers
    int lettersCount = 0, wordsCount = 1, sentencesCount = 0;
    
    // getting user input text
    string userText = get_string("Text: ");
    
    // counting user entered text letter
    int indx = 0;
    while (userText[indx] != 0)
    {
        // checking if text element is character
        if (isalpha(userText[indx]))
        {
            // incrasing characters count
            lettersCount++;
        }
        
        // checking if text element is a word treminator 
        else if (userText[indx] == ' ')
        {
            wordsCount++;
        }
        
        // checking if text element is a sentence treminator 
        else if (userText[indx] == '.' || userText[indx] == '!' || userText[indx] == '?')
        {
            sentencesCount++;
        }
        
        // getting next text element index
        indx++;
        
    }
    
    // calculating Coleman Index
    float readabilityIndex = colemanIndex(lettersCount, wordsCount, sentencesCount);
    
    // processing user output result
    printGrade(readabilityIndex);
    
    
}

float colemanIndex(int lettersCount, int wordsCount, int sentencesCount)
{
    // getting text`s words factor to 100 words
    float wordsFactor = 100.0 / wordsCount ;
    
    // getting average letters per 100 word
    float L = wordsFactor * lettersCount ;
    
    // getting average sentences per 100 word
    float S = wordsFactor * sentencesCount ;
    
    //calculating Coleman-Liau index
    return ((0.0588 * L) - (0.296 * S) - 15.8) ;
}

void printGrade(float colemanIndex)
{
    if (colemanIndex < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (colemanIndex > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int)round(colemanIndex));
    }
}

