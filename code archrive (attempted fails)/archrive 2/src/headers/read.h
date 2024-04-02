#ifndef READ_H
#define READ_H

/* This function reads the dimensions of search and arctic image from file. 
 * Error messages are displayed if dimension inputs are not digits.
 */
extern int read_dimension_from_file(FILE*,int*,int*);
/* This function reads search and arctic image from file and returns image_matrix 
 * if image_matrix contains invalid characters, it returns NULL.
 */
extern char** read_image_from_file(FILE*, int, int);
/* This function frees search and arctic image from memory */
extern void free_image_matrix_memory(char**,int);

#endif