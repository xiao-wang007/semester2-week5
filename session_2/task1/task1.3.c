//Week 5, Session 2

# include <stdio.h>

int main(void){
/* Task 1.3
 * You have to decide which type of loop (for, while, do...while) to use.
 * Write a C program to read a series of integers from the user and sum them
 * until a 0 (zero) is entered. Print the sum at the end.
 */
    int number = 0;
    int sum = 0;

    printf("Enter integers (0 to stop):\n");
    while(1){
        printf("Number: ");
        if(scanf("%d", &number) != 1){
            printf("Invalid input.\n");
            return 1;
        }

        if(number == 0){
            break;
        }

        sum += number;
    }

    printf("Sum = %d\n", sum);

    return 0;
}
