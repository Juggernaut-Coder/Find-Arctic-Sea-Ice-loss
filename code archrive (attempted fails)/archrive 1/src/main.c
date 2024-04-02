#include "headers/main.h"

int main(int argc, char **argv) {
	/* Check if files names are passed as argument strings.
   	 * If no arguments are passed the program inform the user
   	 * that the program requires arguments to operate and terminates.
   	 */
	if (argc == 1) {
	    printf("No arguments were passed.\nPlease pass path of files containing "
	           "strings to count the vowels.\n");
	    /* Stop screen from disappearing until any character is pressed */
	    getchar();
	    return EXIT_NO_INPUT;
	}
	/* Ensure that all file path exist and files are readable, otherwise terminates */
	unsigned int verification_result = verify_files_exist_and_readable(argc, argv);
	if (verification_result !=0) {
		printf("You have entered %u invalid argument(s).\nPlease check the above "
    	"error message(s) and re-enter correct argument(s).\n",
    	verification_result);
    	/* Stop screen from disappearing until any character is pressed */
    	getchar();
    	return EXIT_INVALID_INPUT;
	}
	
	for (int i = 1; i < argc; ++i) {
		/* Open and print the name of the vowel counting string file */
		FILE *image_file = fopen(argv[i], "r");
		assert(image_file != NULL);
		printf("#FILE NAME: %s\n", argv[i]);
		/* Initialize required variables */
		int search_column=-1, search_row=-1, arctic_column=-1, arctic_row=-1;
		char **search_image_matrix, **arctic_image_matrix;
		do {
			int read_search_dimension_result = read_dimension_from_file(image_file,&search_column, &search_row);
			if (read_search_dimension_result == EXIT_FAILURE) {
				printf("Error detected in file:%s\n", argv[i]);
				printf("Exiting program. Please make sure all the files have the correct input contents before trying again.\n");
				return EXIT_FAILURE;
			}
			if (search_column == 0 && search_row == 0) {
				break;
			}
			search_image_matrix = read_image_from_file(image_file,search_column,search_row);
			if (search_image_matrix == NULL) {
				printf("Error detected in file:%s\n", argv[i]);
				printf("Exiting program. Please make sure all the files have the correct input contents before trying again.\n");
				return EXIT_FAILURE;
			}
			int read_arctic_dimension_result = read_dimension_from_file(image_file,&arctic_column,&arctic_row);
			if (read_arctic_dimension_result == EXIT_FAILURE) {
				printf("Error detected in file: %s\n", argv[i]);
				printf("Exiting program. Please make sure all the files have the correct input contents before trying again.\n");
				return EXIT_FAILURE;
			}
			if (search_column < arctic_column && search_row < arctic_row) {
				printf("Incompatible dimensions\n");
				printf("Error detected in file:%s\n", argv[i]);
				printf("Exiting program. Please make sure all the files have the correct input contents before trying again.\n");
				return EXIT_FAILURE;
			}
			arctic_image_matrix = read_image_from_file(image_file,arctic_column,arctic_row);
			if (arctic_image_matrix == NULL) {
				printf("Error detected in file:%s\n", argv[i]);
				printf("Exiting program. Please make sure all the files have the correct input contents before trying again.\n");
				return EXIT_FAILURE;
			}
			// search_arctic(search_image_matrix,search_column,search_row,arctic_image_matrix,arctic_column,arctic_row);
			// print result;
			free_image_matrix_memory(search_image_matrix,search_column);
			free_image_matrix_memory(arctic_image_matrix, arctic_column);
		} while(true);

		/* Close the vowel counting string file */
		int fclose_res = fclose(image_file);
    	assert(fclose_res == 0);
	}
	/* Stop screen from disappearing until any character is pressed */
    getchar();
	return EXIT_SUCCESS;
}
