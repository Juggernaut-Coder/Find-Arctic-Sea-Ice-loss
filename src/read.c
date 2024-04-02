#include "headers/main.h"

/* A function that reads matrix dimension from the correct file */
int read_dimension_from_file(FILE* file, int *row, int *col) {
    /* ENSURE THE FILE POINTER IS VALID */
    assert(file != NULL);
    /* initialize required variables */
    int read_char, counter = 0;
    char rows[MAX_BUFFER_SIZE];
    char columns[MAX_BUFFER_SIZE];
    /* Read the row */
    while((read_char = fgetc(file)) != ' ') {
        if(!isdigit(read_char)) {
            printf("Error: row value contains non-digit characters\n");
            return EXIT_FAILURE;
        }
        rows[counter++] = read_char;
    }
    /* Put NUL character in the end to ensure that we don't have any extra characters */
    rows[counter] = '\0';
    /* Reset the counter */
    counter = 0;
    /* Read the column */
    while((read_char = fgetc(file)) != '\n') {
        if(!isdigit(read_char)) {
            printf("Error: column value contains non-digit characters\n");
            return EXIT_FAILURE;
        }
        columns[counter++] = read_char;
    }
    /* Put NUL character in the end to ensure that we don't have any extra characters */
    columns[counter] = '\0';
    /* convert from string to integer */
    *row = atoi(rows);
    *col = atoi(columns);
    /* ensure that column and row values are greater than or both equal to zero */ 
    if ( (*col == 0 || *row == 0) && (*col != 0 || *row !=0) ) {
        printf("Error: row value or column value is 0 when the other is not\n");
        return EXIT_FAILURE;
    } else if (*col < 0 || *row < 0) {
        printf("Error: row value or column value is not a positive integer\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
/* A function that reads image matrix from the correct file */
char **read_image_from_file(FILE * file, int row, int col) {
    /* ENSURE ALL ARGUMENTS ARE VALID */
    assert( file != NULL && \
            row   > 0    && \
            col   > 0
    );
    int read_char;
    /* Allocate memory for the image */
    char **image = (char**)malloc(row*sizeof(char*));
    /* Ensure there is enough memory for the image */
    assert(image != NULL);
    for(int i = 0; i < row; i++) {
        /* Allocate memory for the image[i] */
        image[i] = (char*)malloc(col*sizeof(char));
        /* Ensure there is enough memory for the image */
        assert(image[i]!= NULL);
        for(int j = 0; j < col; j++) {
            read_char = fgetc(file);
            /* copy only if the character are valid */
            if(read_char == (int)'#' || read_char == (int)'.') {
                image[i][j] = (char)read_char;
            } else {
                /* If image contains invalid characters free image memory and return NULL */
                printf("Error: image contains invalid characters\n");
                free_image_memory(image,row);
                return NULL;
            }
        }
        /* Read the '\n' and ignore it */
        fgetc(file);
    }
    /* return image */
    return image;
}
/* A function that frees image memory */
void free_image_memory(char **image,int row) {
    for(int i =0;i<row;i++) {
        /* free image[i] */
		free(image[i]);
	}
    /* free image */
	free(image);
}
