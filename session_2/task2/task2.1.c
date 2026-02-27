// Week 5, Session 2

/* Task 2.1
 * Temperature conversion with input validation
 * Converts temperatures between Celsius and Fahrenheit with error checking
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>  // For toupper function

int main(void) {
    char input[50];
    float temperature;
    char scale;
    int valid_input = 0;
    float converted_temp;
    
    printf("=== Temperature Converter ===\n");
    
    while (!valid_input) {
        printf("Enter temperature with scale (e.g., 23.5C or 75F): ");
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            return 1;
        }
        
        input[strcspn(input, "\n")] = 0;
        
        if (sscanf(input, "%f %c", &temperature, &scale) != 2) {
            printf("Invalid format. Example: 23.5C or 75F\n");
            continue;
        }
        
        scale = toupper((unsigned char)scale);
        if (scale != 'C' && scale != 'F') {
            printf("Invalid scale. Use C or F.\n");
            continue;
        }
        
        valid_input = 1;
    }
    
    if (scale == 'C') {
        converted_temp = temperature * 9.0f / 5.0f + 32.0f;
        printf("%.1f°C is equal to %.1f°F\n", temperature, converted_temp);
    } else {
        converted_temp = (temperature - 32.0f) * 5.0f / 9.0f;
        printf("%.1f°F is equal to %.1f°C\n", temperature, converted_temp);
    }
    
    return 0;
}
