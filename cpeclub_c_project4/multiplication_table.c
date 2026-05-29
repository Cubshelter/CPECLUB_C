#include <stdio.h>

int main() {
	int rows = 5;
	int colums = 5;
	
	int i = rows;
	int j = colums;
	printf("Multiplication Table\n\n");
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= colums; j++) {
			printf("%d\t", i * j);
		}
		printf("\n");
	}
	return 0;
	
	
}