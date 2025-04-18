#include <stdio.h>
#include <math.h> // For fabs (absolute value for floats)

// Function Prototype for getGCD (needed by decimalToFraction)
int getGCD(int a, int b);

// Function Prototype for slope (optional, as defined before main)
float slope(float y_2, float y_1, float x_2, float x_1);

// Function Prototype for decimalToFraction (optional, as defined before main)
void decimalToFraction(double decimal);

// --- Function Definitions ---

// Function to calculate the Greatest Common Divisor (GCD) using Euclidean Algorithm
int getGCD(int a, int b) {
    // Ensure inputs are non-negative for the algorithm
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    // If both inputs were 0, GCD is undefined, but here it would return 0.
    // If one input was 0, it correctly returns the other number.
    return a == 0 ? 1 : a; // Return 1 if GCD is 0 to avoid division by zero issues later
                           // although fraction simplification should handle 0 numerator correctly.
}

// Function to convert a decimal (double) to a simplified fraction
void decimalToFraction(double decimal) {
    // Define precision limit (adjust if needed, e.g., 1e9 for more places)
    const long long precision_limit = 1000000LL; // Use long long for larger numbers

    // Handle potential non-finite numbers passed from slope calculation
    if (!isfinite(decimal)) {
        printf("Fraction: Undefined (due to non-finite decimal input)\n");
        return;
    }

    // Scale the decimal to handle precision
    // Use long long to avoid potential integer overflow
    long long numerator = (long long)(decimal * precision_limit);
    long long denominator = precision_limit;

    // Find the greatest common divisor
    int common_divisor = getGCD((int)numerator, (int)denominator); // Cast back to int for GCD if within range,
                                                                    // could implement long long GCD if needed.

    // Simplify the fraction
    numerator /= common_divisor;
    denominator /= common_divisor;

    printf("Slope as Decimal: %.6lf\n", decimal); // Print original decimal for comparison

    // Separate whole part and fractional part
    long long wholePart = numerator / denominator;
    long long remainderNumerator = numerator % denominator;

    // Print the simplified fraction (handle different cases)
    if (remainderNumerator == 0) {
         // It's a whole number
         printf("Slope as Fraction: %lld\n", wholePart);
    } else if (wholePart == 0) {
        // It's purely a fraction
        printf("Slope as Fraction: %lld / %lld\n", remainderNumerator, denominator);
    }
     else {
        // It's a mixed number - ensure fractional part has correct sign
        if ((remainderNumerator < 0 && denominator > 0) || (remainderNumerator > 0 && denominator < 0)) {
             // Print negative sign with the whole part if mixed number is negative overall
             if (wholePart == 0) printf("-"); // Handle case like -0 and 1/2 -> -1/2
        }
        printf("Slope as Mixed Fraction: %lld and %lld/%lld\n", wholePart, (remainderNumerator < 0 ? -remainderNumerator : remainderNumerator), (denominator < 0 ? -denominator : denominator));
    }
}


// Function to calculate the slope of a line given two points
float slope(float y_2, float y_1, float x_2, float x_1)
{
    float x_diff;
    float y_diff;

    y_diff = y_2 - y_1;
    x_diff = x_2 - x_1;

    // Note: Division by zero check is handled in main before calling this
    return y_diff / x_diff;
}


// --- Main Program ---
int main()
{
    float y2_in, y1_in, x2_in, x1_in;
    float result_slope;
    int items_read;

    // Prompt user for input
    printf("Enter the coordinates of the first point (x1 y1): ");
    items_read = scanf("%f %f", &x1_in, &y1_in);
    if (items_read != 2) {
        printf("Error reading first point coordinates.\n");
        return 1; // Exit with an error code
    }

    printf("Enter the coordinates of the second point (x2 y2): ");
    items_read = scanf("%f %f", &x2_in, &y2_in);
     if (items_read != 2) {
        printf("Error reading second point coordinates.\n");
        return 1; // Exit with an error code
    }

    // Check for vertical line (division by zero) using a small tolerance for floats
    if (fabs(x2_in - x1_in) < 1e-9) // Check if difference is very close to zero
    {
        printf("\nThe line is vertical (x1 = x2).\n");
        printf("Slope is Undefined.\n");
    }
    // Check for horizontal line (optional, but good practice)
    else if (fabs(y2_in - y1_in) < 1e-9) // Check if difference is very close to zero
    {
         printf("\nThe line is horizontal (y1 = y2).\n");
         result_slope = 0.0f;
         printf("Slope as Decimal: %.6f\n", result_slope);
         printf("Slope as Fraction: 0\n"); // Directly output 0 as fraction
    }
    else
    {
        // Calculate the slope
        result_slope = slope(y2_in, y1_in, x2_in, x1_in);

        // Output the slope as a decimal and then convert to fraction
        printf("\n--- Results ---\n");
        // decimalToFraction function already prints the decimal value
        decimalToFraction((double)result_slope); // Cast float to double for the function
    }

    return 0; // Indicate successful execution
}