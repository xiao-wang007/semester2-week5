//Week 5, Session 2

# include <stdio.h>

int main(void){
/* Task 1.2b
 * Convert the following Python while loop to (1) while loop (2) do...while loop in C.
 * 
 * Python code:
 * while True:
 *     choice = input("Enter 'q' to quit: ")
 *     if choice == 'q':
 *         break
 */
	char input[20];
	char choice = '\0';

	printf("While loop version:\n");
	while(1){
		printf("Enter 'q' to quit: ");
		if(fgets(input, sizeof(input), stdin) == NULL){
			return 1;
		}
		choice = input[0];
		if(choice == 'q'){
			break;
		}
	}

	printf("Do...while version:\n");
	do{
		printf("Enter 'q' to quit: ");
		if(fgets(input, sizeof(input), stdin) == NULL){
			return 1;
		}
		choice = input[0];
	} while(choice != 'q');
	
    return 0;
}
