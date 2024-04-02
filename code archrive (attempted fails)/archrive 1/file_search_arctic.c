#include "headers/main.h"

unsigned int verify_search_arctic_text_files(int argc, char **argv) {
	unsigned int number_of_invalid_files = 0;
	for (int i = 1; i < argc; ++i) {
		FILE *image_file;
		char *search_column= NULL, *search_row=NULL, *arctic_column=NULL, *arctic_row=NULL;
		bool read_search_dimension_flag = true, read_image_flag= false, read_arctic_dimension_flag = false;
		char line_buffer[MAX_BUFFER_SIZE];
		if (image_file = fopen(argv[i], "r")) {
			while (fgets(line_buffer, MAX_BUFFER_SIZE, image_file) != NULL) {
				if (read_search_dimension_flag) {
					int line_buffer_size = strlen(line_buffer);
					search_column = (char*)malloc(line_buffer_size*sizeof(char));
					int counter = 0;
					while(line_buffer[counter] != ' ' && counter < line_buffer_size) {
						search_column[counter] = line_buffer[counter];
						counter++;
					}
					counter++;
					search_column[counter] = '\0';
					search_row = (char*)malloc(line_buffer_size*sizeof(char));
					while(line_buffer[counter] != '\n' && counter < line_buffer_size) {
						search_row[counter] = line_buffer[counter];
						counter++;
					}
					counter++;
                    search_row[counter] = '\0';
					for(int i = 0; i < strlen(search_column) && !isdigit(search_column[i]); i++) {
						number_of_invalid_files++;
						break;
					}
					for(int i = 0; i < strlen(search_row) && !isdigit(search_row[i]); i++) {
						number_of_invalid_files++;
						break;
					}
					if (arctic_column != NULL && arctic_row != NULL) {
						free(arctic_column);
						free(arctic_row);
					}
				} else if () {

				}
			}
				
			fclose(image_file);
		} else {
			printf("File %s does not exist\n",argv[i]);
			number_of_invalid_files++;	
		}		
	}
	return number_of_invalid_files;
}
