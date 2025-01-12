#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{

    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    double letters = count_letters(text);
    double words = count_words(text);
    double sentences = count_sentences(text);
    // Compute the Coleman-Liau index

    // printf("%f\n%f\n%f\n",letters,words,sentences);

    double l = letters / words * 100;
    double s = sentences / words * 100;
    // printf("%f\n%f\n",l,s);
    //Coleman-Liau index calculation
    double index = 0.0588 * l - 0.296 * s - 15.8;

    index = round(index);
    // type casting

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
        printf("Grade %i\n", (int) index);
}

int count_letters(string text)
{
    int lcount = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]) != 0)
            count += 1;
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (isblank(text[i]) != 0)
            count += 1;
    }
    return count + 1;
}

int count_sentences(string text)
{
    int count = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if ((text[i]) == '.' || (text[i]) == '?' || (text[i]) == '!')
            // if(ispunct(text[i])!=0)
            count += 1;
    }
    return count;
}
