//
// Created by axl on 6/7/20.
//

#include "molecules.h"


void showError(int error)
{
    if (error == ERROR_INVALID_ATOM)
    {
        printf("\nInvalid atoms\n");
        exit(ERROR_INVALID_ATOM);
    }
    else if (error == ERROR_INVALID_ATOM_NUMBER)
    {
        printf("\nInvalid number of atoms\n");
        exit(ERROR_INVALID_ATOM_NUMBER);
    }
    else if (error == ERROR_EMPTY_MOLECULE)
    {
        printf("\nEmpty molecule\n");
        exit(ERROR_EMPTY_MOLECULE);
    }
    else
    {
        printf("\nUnknown error\n");
        exit(ERROR_UNKNOWN);
    }
}

bool isDigit(char letter)
{
    return (letter >= '0') && (letter <= '9');
}

char toUppercase(char letter)
{
    if (letter >= 'a' && letter <= 'z')
    {
        return letter - 'a' + 'A';
    }
    return letter;
}

char *toUppercaseString(char *molecule, unsigned int numcharacters)
{
    for (unsigned int i = 0; i < numcharacters; i++)
    {
        molecule[i] = toUppercase(molecule[i]);
    }
    return molecule;
}

char numberToChar(unsigned int num)
{
    if (num >= 0 && num <= 9)
    {
        return num + '0';
    }
    return num;
}

unsigned int charToNumber(char numtext)
{
    if (numtext <= '9' && numtext >= '0')
    {
        return numtext - '0';
    }
    return numtext;
}

bool isAtom(char atom)
{
    for (unsigned int i = 0; i < NUM_ATOMS ; i++)
    {
        if (atoms[i] == atom)
        {
            return true;
        }
    }
    return false;
}

bool isAtomsNumberCorrect(char *molecule, unsigned int numcharmolecule)
{
    unsigned int i = 0, digitcounter = 0;
    while (i < numcharmolecule)
    {
        if (isAtom(molecule[i]))
        {
            digitcounter = 0;
        }
        else
        {
            digitcounter++;
            if (digitcounter == 3)
            {
                return false;
            }
        }
        i++;
    }
    return true;
}

bool isStartingAtom(char *molecule)
{
    return !isDigit(molecule[0]);
}

bool areAtomsValid(char *molecule, unsigned int numcharmolecule)
{
    for (unsigned int i = 0; i < numcharmolecule; i++)
    {
        if (!isDigit(molecule[i]))
        {
            if (!isAtom(molecule[i]))
            {
                return false;
            }
        }
    }
    return true;
}

unsigned int getAtomicMass(char atom)
{
    if (atom == 'C')
    {
        return C;
    }
    else if (atom == 'H')
    {
        return H;
    }
    else if (atom == 'O')
    {
        return O;
    }
    else if (atom == 'N')
    {
        return N;
    }
    else if (atom == 'S')
    {
        return S;
    }
    else
    {
        return 0;
    }
}

unsigned int calculateAtomicMass(char atom, unsigned int numatoms)
{
    //printf("\nGet atomic mass of the atom (%u) and multiply by the num of atoms %u", getAtomicMass(atom), numatoms);
    return getAtomicMass(atom) * numatoms;
}

unsigned int stringLength(char *string)
{
    unsigned int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}

bool isMoleculeValid(char *molecule, unsigned int numcharmolecule)
{
    return (isAtomsNumberCorrect(molecule, numcharmolecule)) && (isStartingAtom(molecule)) && (areAtomsValid(molecule, numcharmolecule));
}
char *userInput()
{
    char *molecule = malloc(sizeof(char) * 100);
    /*char molecule2[100];*/
    printf("\nIntroduce molecule: ");
    if (fgets(molecule, 100, stdin) == NULL)
    {
        printf("\n\nERROR: MEMORY FULL");
    }
    /* Here we have the molecule stored in buffer*/

    // Remove trailing newline, if there.
    if ((stringLength(molecule) > 0) && (molecule[stringLength(molecule) - 1] == '\n'))
    {
        molecule[stringLength(molecule) - 1] = '\0';
    }
    return molecule;
}

unsigned int calculateMolecularMass(char *molecule, unsigned int numcharmolecule)
{
    char currentatom = -1;
    unsigned int acum = 0, state = 2, digit1 = 0, digit2 = 0;

    for (unsigned int i = 0; i < numcharmolecule; i++)
    {
        if (state == 0)
        {
            if (isDigit(molecule[i]))
            {
                digit1 = charToNumber(molecule[i]);
                state = 1;
            }
            else
            {
                acum += calculateAtomicMass(currentatom, 1);
                currentatom = molecule[i];
                //implicit statement: state = 0;
            }
        }
        else if (state == 1)
        {
            if (isDigit(molecule[i]))
            {
                digit2 = charToNumber(molecule[i]);
                state = 2;
            }
            else
            {
                acum += calculateAtomicMass(currentatom, digit1);
                currentatom = molecule[i];
                state = 0;
            }
        }
        else if (state == 2)
        {
            acum += calculateAtomicMass(currentatom, digit1 * 10 + digit2);
            currentatom = molecule[i];
            state = 0;
        }
        printf("\n acum is: %u", acum);
    }
    if (state == 0)
    {
       acum += calculateAtomicMass(currentatom, 1);
    }
    else if (state == 1)
    {
       acum += calculateAtomicMass(currentatom, digit1);
    }
    else if (state == 2)
    {
        acum += calculateAtomicMass(currentatom, digit1 * 10 + digit2);
    }
    return acum;
}

int main()
{
    //char string[100] = "N2OH45S23";

    char *molecule = userInput();
    unsigned int stringlength = stringLength(molecule);
    if (isMoleculeValid(toUppercaseString(molecule, stringlength), stringlength))
    {
        unsigned int molecularweight = calculateMolecularMass(molecule, stringlength);
        printf("\nThe weight of the molecule is: %u", molecularweight);
    }
    else
    {
        printf("\nMOLECULE IS NOT VALID\n");
        exit(1);
    }
    free(molecule);
    printf("\n");
}
