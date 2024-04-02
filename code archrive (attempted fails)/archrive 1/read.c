
int read_dimension_from_file(FILE* file, int *row, int *col) {
    /*Define a line array to read a line from file */
    char line[MAX_BUFFER_SIZE];
    /* fgets is used to read the line from file */
    fgets(line, MAX_BUFFER_SIZE, file);
    /* define line_size and counter */
    int line_size = strlen(line), counter =0;
    /* allocate memory for rows and columns strings */
    char *rows = (char*)malloc(line_size*sizeof(char));
    char *columns = (char*)malloc(line_size*sizeof(char));
    /* check if memory allocation was successful */
    assert(rows != NULL && columns != NULL);
    /* Read row from line */
    while(line[counter] != ' ' && counter < line_size) {
	    if(!isdigit(line[counter])) {
            /* free memory before exiting function */
            free(rows);
            free(columns);
            /* if row has non-digit characters then the program displays error message */
            printf("Error: row value contains non-digit characters\n");
            printf(" %c", line[counter]);
            return EXIT_FAILURE;
        }
        rows[counter] = line[counter];
	    counter++;
	}
    /* end rows string with a NUL character */
	rows[counter] = '\0';
    counter++;
    /* A second counter for columns */
    int counter2 = 0;
	while(line[counter] != '\n' && counter < line_size) {
        if(!isdigit(line[counter])) {
            /* free memory before exiting function */
            free(rows);
            free(columns);
            /* if columns has non-digit characters then the program displays error message */
            printf("Error: column value contains non-digit characters\n");
            return EXIT_FAILURE;
        }
        columns[counter2] = line[counter];
	    counter++;
        counter2++;
	}
    /* end row string with a NUL character */
    columns[counter2] = '\0';
    *row = atoi(rows);
    *col = atoi(columns);
    /* free memory before exiting function */
    free(rows);
    free(columns);
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
