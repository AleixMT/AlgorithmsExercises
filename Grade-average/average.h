//
// Created by axl on 9/7/20.
//

#ifndef ALGORITHMSEXERCISES_AVERAGE_H
#define ALGORITHMSEXERCISES_AVERAGE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_GRADES 282
/**
 * average returns the average of a list of doubles
 * @param grades
 * @param gradeslentgh
 * @return
 */
double average(double *grades, unsigned int gradeslentgh);

/**
 * overtheaverage returns the number of doubles over the average
 * @param grades
 * @param gradeslength
 * @param average
 * @return
 */
unsigned int overtheaverage(double *grades, unsigned int gradeslength, double average);

#endif //ALGORITHMSEXERCISES_AVERAGE_H
