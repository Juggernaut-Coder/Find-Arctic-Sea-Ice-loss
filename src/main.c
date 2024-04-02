#include "headers/main.h"

int main(int argc, char **argv) {
	/* Check if files names are passed as argument strings.
   	 * If not arguments are passed or if more than required 
	 * arguments are passed the program inform the user
   	 * that the program requires one file name and terminates.
   	 */
	if(argc != CORRECT_NUMBER_OF_FILENAME_INPUT) {
		printf("You have either not passed a file name or you have passed more than one file name\n");
		printf("The program requires only one file name to operate.\n");
		return EXIT_FAILURE;
	}
	/* open the file */
	FILE *image_file = fopen(argv[FIRST_INPUT_FILE_INDEX], "r");
	/* There is no need to check if file exists with a if condition.  
	 * The assert below ensures that the file exists and has been opened. if the file does not exist
	 * then the program will exit because of assert and no error message is printed on the terminal.
	 * asserts also make debugging easier when compared with if statements.
	 */
    assert(image_file != NULL);
	/* initialize required parameters */
    int search_row, search_column, \
		arctic_row, arctic_column, read_dimension_result;
	/* This do block reads dimensions and images from the file and finds matches */
	do {
	/* read search dimensions */
	read_dimension_result = read_dimension_from_file(image_file, &search_row, &search_column);
	/* error handling */
	if (read_dimension_result == EXIT_FAILURE) {
		/* Close the image file */
		int fclose_res = fclose(image_file);
		/* Ensure image file is properly closed */
    	assert(fclose_res == 0);
		printf("Failure to read search dimension from file\nExiting Program");
		/* Stop screen from disappearing until any character is pressed */
		getchar();
		return EXIT_FAILURE;
	}
	/* exit the loop if 0 and 0 is found on file */
	if(search_row == 0 && search_column == 0) {
		break;
	}
	/* read search_image from file */
	char **search_image = read_image_from_file(image_file, search_row, search_column);
	/* error handling */
	if(search_image == NULL) {
		/* Close the image file */
		int fclose_res = fclose(image_file);
		/* Ensure image file is properly closed */
    	assert(fclose_res == 0);
		printf("Failure to read search image from file\nExiting Program");
		/* Stop screen from disappearing until any character is pressed */
		getchar();
		return EXIT_FAILURE;
	}
	/* read arctic dimensions */
	read_dimension_result = read_dimension_from_file(image_file, &arctic_row, &arctic_column);
	/* error handling */
	if (read_dimension_result == EXIT_FAILURE) {
		free_image_memory(search_image,search_row);
		/* Close the image file */
		int fclose_res = fclose(image_file);
		/* Ensure image file is properly closed */
    	assert(fclose_res == 0);
		printf("Failure to read arctic dimension from file\nExiting Program");
		/* Stop screen from disappearing until any character is pressed */
		getchar();
		return EXIT_FAILURE;
	}
	/* read arctic_image from file */
	char **arctic_image = read_image_from_file(image_file, arctic_row, arctic_column);
	/* error handling */
	if(arctic_image == NULL) {
		free_image_memory(search_image,search_row);
		/* Close the image file */
		int fclose_res = fclose(image_file);
    	/* Ensure image file is properly closed */
		assert(fclose_res == 0);
		printf("Failure to read arctic image from file\nExiting Program");
		/* Stop screen from disappearing until any character is pressed */
		getchar();
		return EXIT_FAILURE;
	}
	/* find number of matches */
	int match_count = search_arctic_find_match(search_image, search_row, search_column, arctic_image, arctic_row, arctic_column);
	/* print the number of matches */
	printf("%d\n",match_count);
	/* free the not needed memory for the image */
	free_image_memory(search_image,search_row);
	free_image_memory(arctic_image,arctic_row);
	} while(true);
	/* Close the image file */
    int fclose_res = fclose(image_file);
	/* Ensure image file is properly closed */
    assert(fclose_res == 0);
	/* Stop screen from disappearing until any character is pressed */	
    getchar();
	return EXIT_SUCCESS;
}
