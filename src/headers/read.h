#ifndef READ_H
#define READ_H


/* This function reads the image from file. */
extern char **read_image_from_file(FILE *, int, int);
/* This function frees search and arctic image from memory */
extern void free_image_memory(char**,int);
/* This function reads dimension from file */
extern int read_dimension_from_file(FILE *, int *, int *);


#endif