// Week 5, Session 2

/* Task 3.1
 * Number Guessing Game
 * A program where the computer selects a random number and the person tries to guess it
 */

#include <stdio.h>
#include <stdlib.h>  // For rand(), srand(), atoi()
#include <time.h>    // For time()
#include <string.h>  // For strcspn()
#include <ctype.h>

int main(void) {
    char input[20];      // Buffer for input
    int guess;           // The person's guess
    int target;          // The random number to guess
    int num_guesses;     // Counter for number of guesses
    int min = 1;         // Minimum value for random number
    int max = 100;       // Maximum value for random number
    int playing = 1;     // Flag to control the main game loop
    
    // Seed the random number generator
    srand(time(NULL));
    
    printf("=== Number Guessing Game ===\n");
    printf("I'm thinking of a number between %d and %d\n", min, max);
    
    while (playing) {
        target = min + rand() % (max - min + 1);

        // Reset number of guesses for a new game
        num_guesses = 0;
        
        while (1) {
            printf("Enter your guess: ");
            
            if (fgets(input, sizeof(input), stdin) == NULL) {
                return 1;
            }
            input[strcspn(input, "\n")] = '\0';

            char *endptr;
            long parsed = strtol(input, &endptr, 10);
            while (*endptr != '\0' && isspace((unsigned char)*endptr)) {
                endptr++;
            }
            if (endptr == input || *endptr != '\0') {
                printf("Please enter a valid whole number.\n");
                continue;
            }

            guess = (int)parsed;
            if (guess < min || guess > max) {
                printf("Guess must be between %d and %d.\n", min, max);
                continue;
            }
            
            num_guesses++;
            
            if (guess == target) {
                printf("Correct! You guessed it in %d attempts.\n", num_guesses);
                break;
            } else if (guess > target) {
                printf("Too high.\n");
            } else {
                printf("Too low.\n");
            }
            
            if (num_guesses == 5) {
                if (target % 2 == 0) {
                    printf("Hint: The number is even.\n");
                } else {
                    printf("Hint: The number is odd.\n");
                }
            }
        }

        printf("Play again? (y/n): ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            return 1;
        }
        if (input[0] != 'y' && input[0] != 'Y') {
            playing = 0;
        } else {
            printf("I'm thinking of a new number between %d and %d\n", min, max);
        }
    }
    
    printf("\nThanks for playing!\n");
    return 0;
}
