#include "headers/main.h"

int read_dimension_from_file(FILE* file, int *col, int *row) {
    /*Define a line array to read a line from file */
    char line[MAX_BUFFER_SIZE];
    /* fgets is used to read the line from file */
    fgets(line, MAX_BUFFER_SIZE, file);
    /* define line_size and counter */
    int line_size = strlen(line), counter =0;
    /* allocate memory for columns and rows strings */
    char *columns = (char*)malloc(line_size*sizeof(char));
    char *rows = (char*)malloc(line_size*sizeof(char));
    /* check if memory allocation was successful */
    assert(columns != NULL && rows != NULL);
    /* Read column from line */
    while(line[counter] != ' ' && counter < line_size) {
	    if(!isdigit(line[counter])) {
            /* free memory before exiting function */
            free(columns);
            free(rows);
            /* if column has non-digit characters then the program displays error message */
            printf("Error: column value contains non-digit characters\n");
            return EXIT_FAILURE;
        }
        
        columns[counter] = line[counter];
	    counter++;
	}
    /* end column string with a NUL character */
	columns[counter] = '\0';
    counter++;
    int counter2 = 0;
	while(line[counter] != '\n' && counter < line_size) {
        if(!isdigit(line[counter])) {
            /* free memory before exiting function */
            free(columns);
            free(rows);
            /* if column has non-digit characters then the program displays error message */
            printf("Error: row value contains non-digit characters\n");
            return EXIT_FAILURE;
        }
        rows[counter2] = line[counter];
	    counter++;
        counter2++;
	}
    /* end row string with a NUL character */
    rows[counter2] = '\0';
    *col = atoi(columns);
    *row = atoi(rows);
    /* free memory before exiting function */
    free(columns);
    free(rows);
    /* ensure that column and row values are greater or equal to than zero */ 
    if ( (*col == 0 || *row == 0) && (*col != 0 || *row !=0) ) {
        printf("Error: row value or column value is 0 when the other is not\n");
        return EXIT_FAILURE;
    } else if (*col < 0 || *row < 0) {
        printf("Error: row value or column value is not a positive integer\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

char** read_image_from_file(FILE* file, int col, int row) {
    /* Allocate memory for char array */
    printf("COL:ROW:%d:%d\n", col, row);
    /* Increment row by 1 to account for '/n' in the file lines */
    row += 1;
    col += 1;
    char** image_matrix = (char**)malloc(col*sizeof(char*));
    /* check if memory allocation was successful */
    assert(image_matrix != NULL);
    for(int i = 0; i < col; i++) {
        /* Allocate memory for row number of chars in the array */
        image_matrix[i] = (char*)malloc(row*sizeof(char));
        /* check if memory allocation was successful */
        assert(image_matrix[i]!= NULL);
        char * line = fgets(image_matrix[i], row, file);
        /* Verify image chars */
        printf("%d:%s\n",i,line);
        if(line==NULL) {
            printf("Yes\n");
        }
        for(int j = 0; j < row; j++) {
            // if(image_matrix[i][j] != '#' || image_matrix[i][j] != '.') {
            //     printf("Error: image contains invalid characters\n");
            //     /* Free image matrix */
            //     free_image_matrix_memory(image_matrix, col);
            //     /* returns NULL if verification fails */
            //     return NULL;
            // }
            
        }
    }
    /* returns image matrix */
    return image_matrix;
 }

void free_image_matrix_memory(char** image_matrix, int col) {
    /* Function to free image matrix */
    for(int i = 0; i < col; i++) {
        free(image_matrix[i]);
    }
    free(image_matrix);
}
