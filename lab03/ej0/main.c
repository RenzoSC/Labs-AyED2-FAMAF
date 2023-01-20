#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000
void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    if (!(argc == 2)) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}
void sort_array(unsigned int indexes[], char letters[], char sorted[], unsigned int length){
    for (unsigned int i = 0; i < length; i++)
    {
        sorted[indexes[i]] = letters[i];
    }
    
}
unsigned int data_from_file(const char *path,
                                unsigned int indexes[],
                                char letters[],
                                unsigned int max_size)
    {
        FILE *mi_archivo = fopen(path, "r");
        int length=0;
        // int index;
        // char letter;
        // fscanf(mi_archivo, "%i '%c'\n", &index, &letter);
        // printf("Primer index: %i\nPrimer caracter: %c\n", index, letter);
        while (!feof(mi_archivo) && (unsigned int)length <= max_size)
        {
            fscanf(mi_archivo, "%u '%c'\n", &indexes[length], &letters[length]);
            length++;
        }
        fclose(mi_archivo);
        return length;
    }
int main(int argc, char *argv[]) {
    char *file = NULL;
    file = parse_filepath(argc, argv);
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    /* -- completar -- */
    length = data_from_file(file, indexes, letters, MAX_SIZE);
    sort_array(indexes,letters,sorted,length);
    dump(sorted, length);
    return EXIT_SUCCESS;
}

