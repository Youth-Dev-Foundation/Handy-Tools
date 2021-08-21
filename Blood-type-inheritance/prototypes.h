// Create header with function prototypes for Blood-inheritance module

// Define string
typedef char* string;

// Define person node
typedef struct person
{
    struct person *parents[2];   
    char alleles[2];
}
person;

// Include type FILE *
#include <stdio.h>

// Define macro(s)
#define ERROR_MSG "Usage: ./main GENERATION_SIZE\n"
#define FILE_ERR "Couldn't open the selected file\n"

// Function prototypes
person *create_family(int generations);
void writeToRTextFile(person *p, FILE *output, int generation);
FILE *resetTextFile(string path);
char generateRandomAllele(void);
void freeAllocatedMemory(person *p);
