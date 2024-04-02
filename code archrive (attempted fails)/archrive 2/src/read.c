#include "headers/main.h"


int read_dimension_from_file(FILE* file, int *row, int *col) {
    int read_char, counter = 0;
    char rows[MAX_BUFFER_SIZE];
    char columns[MAX_BUFFER_SIZE];
    while((read_char = fgetc(file)) != ' ') {
        rows[counter++] = read_char;
    }
    rows[counter] = '\0';
    counter = 0;
    while((read_char = fgetc(file)) != '\n') {
        columns[counter++] = read_char;
    }
    columns[counter] = '\0';
    counter = 0;
    *row = atoi(rows);
    *col = atoi(columns);
    return EXIT_SUCCESS;
}

char *  read_image_line(FILE* image_file, int col) {
    /* malloc with col+1 to account for '\n' */
    char *image_line = (char*)malloc((col+1)*sizeof(char));
    /* Ensure that memory has been allocated */
    assert(image_line != NULL);
    fgets(image_line, (col+1), image_file);
    image_line[col] = '\n';
    /* if verification is successful return image_line */
    return image_line;
}

int main(int argc, char **argv) {

    FILE* image_file = fopen(argv[1],"r");
    //int row=-1, col=-1;
    char *img = read_image_line(image_file,4);
    printf("%s",img);
    free(img);
    img = read_image_line(image_file,2);
    printf("%s",img);
    free(img);
    fclose(image_file);
    return 0;
}