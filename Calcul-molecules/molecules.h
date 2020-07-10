//
// Created by axl on 6/7/20.
//

#ifndef CALCULMOLECULES_MOLECULES_H
#define CALCULMOLECULES_MOLECULES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


const unsigned int C = 12, H = 1, O = 16, N = 14, S = 32;
const char atoms[] = {'C', 'H', 'O', 'N', 'S'};
#define NUM_ATOMS 5

// Error codes
#define SUCCESS 0
#define ERROR_INVALID_ATOM 1
#define ERROR_INVALID_ATOM_NUMBER 2
#define ERROR_EMPTY_MOLECULE 3
#define ERROR_UNKNOWN -1


/**
 * showError give error
 * @param error
 */
void showError(int error);

/**
 * isDigit returns true if the given input it's a number in ASCII
 * @param letter
 * @return
 */
bool isDigit(char letter);

/**
 * stringLength does returns the number of characters from the string
 * @param string
 * @return
 */
unsigned int stringLength(char *string);

/**
 * toUppercase returns given char to upper case if the char is a low case and the same char otherwise
 * @param letter
 * @return
 */
char toUppercase(char letter);

/**
 * toUppercaseString returns an upper case version of a String
 * @param molecule
 * @param numcharacters
 * @return
 */
char *toUppercaseString(char *molecule, unsigned int numcharacters);

/**
 * numberToChar returns the char value in ASCII if the parameter number is a number with only one digit
 * @param character
 * @return
 */
char numberToChar(unsigned int number);

/**
 * charToNumber returns the number represented in a ASCII character representing a number
 * @param character
 * @return
 */
unsigned int charToNumber(char character);

/**
 * isValidAtom returns true if atom is in the list of accepted atoms
 * @param atom
 * @return
 */
bool isAtom(char atom);

/**
 * isAtomsNumberCorrect returns false if there more than 2 digits after characters
 * @param molecule
 * @param numcharmolecule
 * @return
 */
bool isAtomsNumberCorrect(char *molecule, unsigned int numcharmolecule);

/**
 * isStartingAtom returns false if starts with a number
 * @param molecule
 * @return
 */
bool isStartingAtom(char *molecule);

/**
 * getAtomicMass returns the atomic mass of a given atom
 * @param atom
 * @return
 */
unsigned int getAtomicMass(char atom);

/**
 * calculateAtomicMass returns the atomic mass of an atom n times
 * @param atom
 * @param n
 * @return
 */
unsigned int calculateAtomicMass(char atom, unsigned int n);

/**
 * areAtomsValid returns true if all the molecule atoms (characters) are accepted as valid inputs
 * @param molecule
 * @param numcharmolecule
 * @return
 */
bool areAtomsValid(char *molecule, unsigned int numcharmolecule);

/**
 * isMoleculeValid returns true if the molecule is valid for the program following the 3 rules
 * @param molecule
 * @param numcharmolecule
 * @return
 */
bool isMoleculeValid(char *molecule, unsigned int numcharmolecule);

/**
 * calculateMolecularMass returns the molecular mass of the molecule. Does the string's interpretation
 * @param molecule
 * @param numcharmolecule
 * @return
 */
unsigned int calculateMolecularMass(char *molecule, unsigned int numcharmolecule);

/**
 * userInput reads user's keyboard input and returns string of max 100 characters
 * @return
 */
char *userInput();

#endif //CALCULMOLECULES_MOLECULES_H
