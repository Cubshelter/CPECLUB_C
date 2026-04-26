// Online C complier to run C program online
#include <stdio.h>

int main() {
	float a, b, c, d, e, f;
	float D, Dx, Dy, x, y;
	
	printf("Johnpaul nah big dev");
	return 0;
printf("Enter value for a: ");
scanf("%lf", &a);

printf("Enter value for b: ");
scanf("%lf", &b);

printf("Enter value for c: ");
scanf("%lf", &c);

printf("Enter value for d: ");
scanf("%lf", &d);

printf("Enter value for e: ");
scanf("%lf", &e);

printf("Enter value for f: ");
scanf("%lf", &f);

// calculate the main determinant
D = (a * d) - (b * c);
if (D == 0) {
	printf("Error! There's no unique solution for this equation./n");
	
}
else {
	Dx - ((e * d) - (b * f) / D);
	Dy - ((a * f) - (e * c));
	
	// calculate the real value for x and y
	x = Dx / D;
	y = Dy / D;
	
	// The output result
	printf("The value of x is: %.21f", &x);
	printf("The value of y is: %.21f", &y);
	return 0;
}

}