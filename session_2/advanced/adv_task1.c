// Week 5, Session 2

/* Advanced task 1
 * Convert the following Python list comprehension to for loop in C. 
 * 
 * Python code:
 * matrix = [[1, 2], [3, 4], [5, 6]]
 * # Flatten the 2D list into 1D
 * flattened = [item for row in matrix for item in row]
 * for i in flattened:
 *    print(i)
 */
 
 # include <stdio.h>

int main(void){
	int matrix[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    int flattened[6];
	int index = 0;
	
	for(int row = 0; row < 3; row++){
		for(int col = 0; col < 2; col++){
			flattened[index] = matrix[row][col];
			index++;
		}
	}

	for(int i = 0; i < 6; i++){
		printf("%d ", flattened[i]);
	}
	printf("\n");
	
	return 0;
}
