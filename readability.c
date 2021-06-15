#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main(void)
{
    //User input

    string text = get_string("Text: ");

    float length = strlen(text); //Length of string

    float letters = 0; //letters

    float sentences = 0; //sentences

    float words = 1; //words

    for (int i = 0; i < length; i++) //counts previous three variables
    {
        if (text[i] > 64 && text[i] < 91) //counts uppercase letters
        {
            letters++;
        }
        else if (text[i] > 96 && text[i] < 123) //counts lowercase letters
        {
            letters++;
        }
        else if (text[i] == 46 || text[i] == 63 || text[i] == 33) //counts sentence ending characters
        {
            if (text[i] == text[i + 1])
            {
            }
            else
            {
                sentences++;
            }
        }
        else if (text[i] == 32) //counts spaces (for number of words)
        {
            words++;
        }
    }

    //Coleman-Liau equation

    float l = 0;

    l = 100 / words;
    l = letters * l;

    float s = 0;

    s = 100 / words;
    s = sentences * s;

    float index = 0.0588 * l - 0.296 * s - 15.8;

    if (index < 1) //sorts whether its before grade 1 or after 16
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }
}