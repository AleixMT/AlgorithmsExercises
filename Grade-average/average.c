//
// Created by axl on 9/7/20.
//

#include "average.h"
double average(double *grades, unsigned int gradeslength)
{
    double sum = 0;
    for (unsigned int i = 0; i < gradeslength; i++)
    {
        sum += grades[i];
    }

    return sum / gradeslength;
}

unsigned int overtheaverage(double *grades, unsigned int gradeslength, double average)
{
    unsigned int overcount = 0;
    for (unsigned int i = 0; i < gradeslength; i++)
    {
        if (grades[i] > average)
        {
            overcount++;
        }
    }
    return overcount;
}
double *userInput(unsigned int *numofgrades)
{
    *numofgrades = 0;
    double *grades = malloc(sizeof(double) * MAX_GRADES);
    if (grades == NULL)
    {
        printf("\n\nERROR: MEMORY FULL");
    }
    /* Here we have the grades stored in buffer*/
    //scanf("%d", &(grades[i]));
    for (unsigned int i = 0; i < MAX_GRADES; i++)
    {
        printf("\nIntroduce grade: ");
        unsigned int read = scanf("%lf", &grades[i]);
        if (read != 1)
        {
            exit(1);
        }
        else if (grades[i] == -1)
        {
            break;
        }
        (*numofgrades)++;
    }

    // Remove trailing newline, if there.
    return grades;
}

int main()
{
    unsigned int numofgrades;
    double *grades = userInput(&numofgrades);
    double median;
    printf("\nAverage: %.2lf", median = average(grades, numofgrades));
    printf("\nOver the Average: %u", overtheaverage(grades, numofgrades, median));
    //unsigned int gradeslentgh = 0;
    printf("\n");
}