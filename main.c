#include "monty.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        error_usage();
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    interpret_file(filename);

    return 0;
}
