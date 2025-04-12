#include <stdio.h>
#include <math.h>
/*This program is a model of the distance formula in 
  geometry. It may be a bit resource intensive considering 
 the extent of float declarations is a single function. 
  To all the code inspectors out there just know im trying my best to write safe 
	c code. */

float dist(float x_1, float y_1, float x_2, float y_2)
{
float a = x_2 - x_1; 
float b = y_2 - y_1;

float c = a * a; 
float d = b * b; 

float e = c + d; 

float f =  sqrt(e); 
return f; 
}

int main()
{
// Example of usage. 
float s = dist(9, 4, 5, 6); // You have to a separate stream for storage. 
printf("Distnace from point 1 to point 2 is: %f\n", s); 
return 0; 
}
