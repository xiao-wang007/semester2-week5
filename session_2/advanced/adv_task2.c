// Week 5, Session 2

/* Advanced task 2
 * Convert the following Python list comprehension to for loop in C.
 * 
 * Python code:
 * list1 = [1, 2]
 * list2 = [10, 20]
 * # Create pairs where the sum is greater than 20
 * print("Pairs with sum > 20")
 * pairs = [(x, y) for x in list1 for y in list2 if x + y > 20]
 * for i in pairs:
 *     print(i)
 */
 
#include <stdio.h>

int main(void ) {
    int list1[] = {1, 2};
    int list2[] = {10, 20};
	int list1_len = sizeof(list1) / sizeof(list1[0]);
	int list2_len = sizeof(list2) / sizeof(list2[0]);

    printf("Pairs with sum > 20:\n");
	
	for(int i = 0; i < list1_len; i++){
		for(int j = 0; j < list2_len; j++){
			if(list1[i] + list2[j] > 20){
				printf("(%d, %d)\n", list1[i], list2[j]);
			}
		}
	}
	


    return 0;
}
