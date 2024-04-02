#include "headers/main.h"

int search_arctic_find_match(char **search_image,int search_row,int search_col,
			   char **arctic_image,int arctic_row,int arctic_col){
	/* ENSURE ALL ARGUMENTS ARE CORRECT INPUTS 
	 * IT IS ASSUMED THAT NO INVALID ARGUMENTS WILL BE
	 * PASSED BY THE USER.
	 * HENCE ASSERT IS USED INSTEAD OF USING A IF CONDITION
	 * IF SEARCH ROW AND COLUMN MUST BE SMALLER THAN ARCTIC ROW AND COLUMN 
	 * OTHERWISE THE PROGRAM WILL TERMINATE WITHOUT AN ERROR MESSAGE(that is user-friendly).
	 * THERE WILL BE AN ASSERTION ERROR.(for a programmer)
	 */
	assert(
		search_image != NULL      &&       \
		arctic_image != NULL      &&       \
		search_row < arctic_row   &&       \
		search_col < arctic_col            \
	);

	/* A VARIABLE THAT KEEPS COUNT OF NUMBER OF MATCHES */
	int count = 0;

	/* THESE TWO LOOPS TRAVERSES MATCHABLE BLOCKS OF ARCTIC IMAGE */
	for(int i=0;i+search_row-1<arctic_row;i++) {
		for(int j=0;j+search_col-1<arctic_col;j++) {

			/* SEARCH ROW AND COLUMN INDEX ARE USED TO ITERATE SEARCH IMAGE */
			int search_row_idx = 0;
			int search_col_idx = 0;

			/* FLAG THAT DEFAULTS AT MATCHED AND EQUALS NOT_MATCHED WHEN A DISCREPANCY IS FOUND */
			int flag = MATCHED;

			/* VISUALIZE MATCH ITERATION BELOW WITH THE NEXT TWO FOR LOOPS                                            
			 * FROM ROW           			           			i 
			 * FROM  		*(*(arctic_image+i)+j)          	TO 		*(*(arctic_image+i)+j+search_col-1)
			 * ...
			 * FROM     			column	j                	TO     		column  j+search_col -1
			 * ...
			 * FROM 	*(*(arctic_image+i+search_row-1)+j) 	TO 		*(*(arctic_image+i+search_row-1)+j+search_col-1)
			 * TO ROW                    						i+search_row - 1
			 * --------------------------------------------------------------------------------------------------------------- 
			 */
						 
			/* THESE TWO LOOPS CHECKS IF EACH MATCHABLE BLOCKS IS A MATCH OR NOT */
			for(int m = i;m < i+search_row;m++) {
				for(int n=j;n< j+search_col;n++) {

					if(search_image[search_row_idx][search_col_idx]=='#' && arctic_image[m][n]!=search_image[search_row_idx][search_col_idx]) {	
						/* IF THE CONDITION IS SATISFIED THEN SET THE FLAG = NOT_MATCHED */
						flag = NOT_MATCHED;
						/* AT NOT MATCHED BREAK THE LOOP. NO NEED TO CHECK FURTHER */
						break;
					}

					/* INCREMENT SEARCH COLUMN INDEX */	
					search_col_idx++;
				}
				/* RESET SEARCH COLUMN INDEX TO 0 */	
				search_col_idx=0;
				/* INCREMENT SEARCH ROW INDEX */
				search_row_idx++;
			}
			/* RESET SEARCH ROW INDEX TO 0 */
			search_row_idx=0;
			/* IF FLAG UNCHANGED INCREMENT COUNT  */
			if(flag==MATCHED) {
				count++;
			}		
		}	
	}
	/* RETURNS NUMBER OF MATCHES  */		
	return count;	
}
