/* A quick search on google: "Equilateral Trianlge Area" shows 
 how to calculate and even goes to the extents of calculating it for 
 you. My curious mind thought "Could I make this using my own mind ?". So after some minutes 
 of scribbling I got to it. It took me about 50 minutes to get the body out 
 but in the end it all worked out. */

#include <stdio.h> // Required for input/output functions like printf and scanf
#include <math.h>  // Required for mathematical functions like sqrt and pow

int main() {
    double side; // Declare a variable to store the side length of the triangle
    double area; // Declare a variable to store the calculated area

    // Prompt the user to enter the side length
    printf("Enter the side length of the equilateral triangle: ");

    // Read the side length from the user
    // %lf is used for reading double-precision floating-point numbers
    // &side provides the memory address where the input value should be stored
    if (scanf("%lf", &side) != 1) {
        printf("Invalid input. Please enter a numeric value.\n");
        return 1; // Indicate an error
    }

    // Check if the side length is non-negative
    if (side < 0) {
        printf("Side length cannot be negative. Please enter a positive value.\n");
        return 1; // Indicate an error
    }

    // Calculate the area of the equilateral triangle using the formula:
    // Area = (sqrt(3) / 4) * side^2
    // M_SQRT3 is a constant defined in math.h for sqrt(3)
    // pow(side, 2) calculates side raised to the power of 2 (side * side)
    area = (sqrt(3) / 4) * pow(side, 2);

    // Display the calculated area to the user
    // %.2lf formats the output to two decimal places
    printf("The area of the equilateral triangle with side length %.2lf is: %.2lf\n", side, area);

    return 0; // Indicate successful execution of the program
}
