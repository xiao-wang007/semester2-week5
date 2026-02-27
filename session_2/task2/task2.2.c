// Week 5, Session 2

/* Task 2.2
 * Write a C program that continuosly prompts the user to enter
 * a message and then prints it back to them. The loop should terminate
 * if the user types "quit".
 * - use fgets() + newline removal
 * - use strcmp for string comparison
 */
 
 #include <stdio.h>
 #include <string.h>
 
 int main(void) {
	 char message[200];

	 while(1){
		 printf("Enter a message (type \"quit\" to stop): ");
		 if(fgets(message, sizeof(message), stdin) == NULL){
			 return 1;
		 }

		 message[strcspn(message, "\n")] = '\0';
		 if(strcmp(message, "quit") == 0){
			 break;
		 }

		 printf("You entered: %s\n", message);
	 }

	 printf("Program ended.\n");
	 
	 return 0;
 }
