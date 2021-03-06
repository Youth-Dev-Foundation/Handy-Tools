// Include dependencies stored in a header file
#include "dependencies.h"

// Include prototypes header file with dependencies
#include "prototypes.h"

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

    // Define default location PATH
    string PATH = "output/blood-inheritance.txt";

    // Receive newly reset txt file and append to it
    FILE *outputFile = resetTextFile(PATH);
    if (outputFile == NULL)
    {
        printf(FILE_ERR);
        return 1;
    }

    // Write the analogy to a local txt file
    writeToRTextFile(p, outputFile, 0);

    // Free memory to prevent memory leaks
    freeAllocatedMemory(p);

    // Close opened local files
    fclose(outputFile);
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
void writeToRTextFile(person *p, FILE *output, int generation)
{
    // Define a base case
    if (p == NULL)
    {
        return;
    }

    for (int i = 0; i < generation * 5; i++)
    {
        fputc(' ', output);
    }

    // Write to the text file
    fprintf(output, "Generation no. %i type: %c%c\n", generation, p->alleles[0], p->alleles[1]);

    for (int i = 0; i <= 1; i++)
    {
        // Recursively call the function until NULL is reached (for both parents' iters)
        writeToRTextFile(p->parents[i], output, generation + 1);
    }
}
FILE *resetTextFile(string path)
{
    // Reset output txt file
    FILE *f = NULL;
    f = fopen(path, "w");

    // Handle error
    if (f == NULL)
    {
        // Abort the process
        printf(FILE_ERR);
        return f;
    }

    // Create text file for output
    f = fopen(path, "a");

    // Handle error
    if (f == NULL)
    {
        // Abort the process
        printf(FILE_ERR);
        return f;
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
