#include "headers/main.h"



int find_match(char** search_image,int search_row,int search_col,
			   char** arctic_image,int arctic_row,int arctic_col){

	
			  
	
}



int main() {

	int search_row = 2;
	int search_col = 2;
	
	char search_image[2][2] = { 
								{'#','.'},
					   		    {'#','#'}
							  };
	int arctic_row = 3;
	int arctic_col = 5;
	
	char arctic_image[3][5] = { 
								{'#','.','#','.','#'},
								{'#','#','#','#','#'},
						 		{'.','#','#','#','.'}	
							  };
	int count = 0;
	
	for(int i=0;i+search_row-1<arctic_row;i++) {
		for(int j=0;j+search_col-1<arctic_col;j++) {

				int search_row_idx = 0;
				int search_col_idx = 0;
				int flag = 0;
				for(int m = i;m < i+search_row;m++) {
					for(int n=j;n< j+search_col;n++) {
						if(search_image[search_row_idx][search_col_idx]=='#') {	
							if(arctic_image[m][n]!=search_image[search_row_idx][search_col_idx]) {
								flag = 1;
							}
						}
					search_col_idx++;
					}
				search_col_idx=0;
				search_row_idx++;
				}
				search_row_idx=0;
				
				if(flag==0) {
					count++;
				}
				// 
				// *(*(a_img+i)+j) .... *(*(a_img+i)+j+s_col-1)
				     // ...
				// *(*(a_img+i+s_row-1)+j) .... *(*(a_img+i+s_row-1)+j+s_col-1)
		}
		
	}
	printf("%d\n",count);

    getchar();
	return EXIT_SUCCESS;
}
