//
// Created by axl on 9/7/20.
//

#include "average.h"

double *userInput()
{
    double *grades = malloc(sizeof(char) * 282);
    printf("\nIntroduce grade: ");
    if (fgets(*grades, 282, stdin) == NULL)
    {
        printf("\n\nERROR: MEMORY FULL");
    }
    /* Here we have the grades stored in buffer*/
    //scanf("%d", &(grades[i]));
    for (unsigned int i = 0; i < 283; i++)
    {
        scanf("%lf", &grades[i]);
    }

    // Remove trailing newline, if there.
    return *grades;
}

int main()
{
    double *grades = userInput();
    printf("test");
    //unsigned int gradeslentgh = 0;
}