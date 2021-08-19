#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Remap type 'char*' to 'string'
typedef char* string;

// Create a custom data type for each person (with 2 parents and 2 respective alleles)
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

// Define macro(s)
#define ERROR_MSG "Usage: ./main GENERATION_SIZE\n"
#define FILE_ERR "Couldn't open the selected file\n"

// Create func prototypes
person *create_family(int generations);
void writeToRTextFile(person *p, int generation);
FILE *resetTextFile(string path);
char generateRandomAllele(void);
void freeAllocatedMemory(person *p);

int main(int argc, string argv[])
{
    // Accept 2 command line arguments
    if (argc != 2)
    {
        // Prompt with incorrect usage
        printf(ERROR_MSG);
        return 1;
    }

    int generation = atoi(argv[1]);
    printf("Generation size: %i\n", generation);

    // Create the familz tree (recursive base)
    person *p = create_family(generation);

    // Write the analogy to a local txt file
    writeToRTextFile(p, 0);

    // Free memory to prevent memory leaks
    freeAllocatedMemory(p);
    return 0;
}

person *create_family(int generations)
{
    // Allocate memory for a new person
    person *newPerson = malloc(sizeof(person));

    if (generations > 1)
    {
        // Iterate 2 times (2 parents)
        for (int i = 0; i <= 1; i++)
        {
            // Create parents recursively
            newPerson->parents[i] = create_family(generations - 1);

            // Pass alleles recursively to children from parents
            newPerson->alleles[i] = newPerson->parents[i]->alleles[rand() % 2];
        }
    }
    // Base case for the first of the tree, i.e., having parents as NULL
    else
    {
        for (int i = 0; i <= 1; i++)
        {
            // Set parents to NULL
            newPerson->parents[i] = NULL;

            // Generate random alleles
            newPerson->alleles[i] = generateRandomAllele();
        }
    }
    // Return the created type of person
    return newPerson;
}

void freeAllocatedMemory(person *p)
{
    // Check for NULL (base case)
    if (p == NULL)
    {
        return;
    }

    // Free each parents recursively
    for (int i = 0; i <= 1; i++)
    {
        // Recursive call of freeing
        freeAllocatedMemory(p->parents[i]);
    }

    free(p);
}

// Create function to write the progress to a local txt file
void writeToRTextFile(person *p, int generation)
{
    // Define a base case
    if (p == NULL)
    {
        return;
    }

    // Define default location PATH
    string PATH = "output/blood-inheritance.txt";

    // Receive newly reset txt file and append to it
    FILE *outputFile = resetTextFile(PATH);
    if (outputFile == NULL)
    {
        printf(FILE_ERR);
        return 1;
    }

    for (int i = 0; i < generation * 5; i++)
    {
        fputc(' ', outputFile);
    }

    // Write to the text file
    fprintf(outputFile, "Generation no. %i type: %c%c\n", generation, p->alleles[0], p->alleles[1]);

    for (int i = 0; i <= 1; i++)
    {
        // Recursively call the function until NULL is reached (for both parents' iters)
        writeToRTextFile(p->parents[i], generation + 1);
    }
}
FILE *resetTextFile(string path)
{
    // Reset ouput txt file
    FILE *f = NULL;
    f = fopen(path, "w");

    // Handle error
    if (f == NULL)
    {
        // Abort the process
        printf(FILE_ERR);
        return 1;
    }

    // Create text file for output
    f = fopen(path, "a");

    // Handle error
    if (f == NULL)
    {
        // Abort the process
        printf(FILE_ERR);
        return 1;
    }

    return f;
}

char generateRandomAllele(void)
{
    // Generate random int 0 through 2
    int r = rand() % 3;
    char ALLELE;

    // Create a switch for possible blood types
    switch (r)
    {
    case 0:
        ALLELE = 'A';
        break;
    case 1:
        ALLELE = 'B';
        break;

    case 2:
        ALLELE = 'O';
        break;
    }

    // Return the randomly created allele
    return ALLELE;
}
