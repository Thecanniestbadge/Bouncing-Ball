// Programmer:		Thecanniestbadge
// Date:			06/14/2023
// Program Name:	Bouncing Ball
// Chapter:			Repetition
// Description:		This program calulates and displays the number of times a ball will bounce before its height is less than one inch
//					This program validates the users inputs and also has functions in it that will handle the outputs if the ball never stops bouncing

#define _CRT_SECURE_NO_WARNINGS // Disable warnings (and errors) when using non-secure versions of printf, scanf, strcpy, etc.
#include <stdio.h> // Needed for working with printf and scanf

int main(void)
{
	// Constant and Variable Declarations
	// These constants contain and sets the values for minimum height of the ball, minimum and maximum coefficient, and the conversion rate for inches to feet
	const double MIN_HEIGHT      = 0.0;
	const double MIN_COEFFICIENT = 0.0;
	const double MAX_COEFFICIENT = 1.0;
	const double INCH_TO_FEET    = 0.0833333;
	// Input variables
	// These variables store the users input 
	double height      = 0.0; 
	double coefficient = 0.0;
	int count          = 0;

	// *** Your program goes here ***
    // *** INPUT ***
    // Prompt user for initial height
    printf("Enter the initial height of the ball (in feet): ");
    scanf("%lf", &height);
    // *** VALIDATION ***
    // Validate height input
    while (height < MIN_HEIGHT) {
        printf("    The initial height of the ball must be greater than or equal to %.1lf.\n", MIN_HEIGHT);
        printf("    Please re-enter the initial height of the ball (in feet): ");
        scanf("%lf", &height);
    }
    // *** INPUT ***
    // Prompt user for coefficient of restitution
    printf("Enter the balls' coefficient of restitution (%.1lf to %.1lf inclusive): ", MIN_COEFFICIENT, MAX_COEFFICIENT);
    scanf("%lf", &coefficient);
    // *** VALIDATION ***
    // Validate coefficient input
    while (coefficient < MIN_COEFFICIENT || coefficient > MAX_COEFFICIENT) {
        printf("    The coefficient of restitution must be between %.1lf and %.1lf inclusive.\n", MIN_COEFFICIENT, MAX_COEFFICIENT);
        printf("    Please re-enter the balls' coefficient of restitution (%.1lf to %.1lf inclusive): ", MIN_COEFFICIENT, MAX_COEFFICIENT);
        scanf("%lf", &coefficient);
    }

    // Check if the ball will bounce forever
    if (coefficient == MAX_COEFFICIENT) {
        printf("\n"); // Blank line
        printf("With a coefficient of restitution equal to %.1lf, the ball will bounce forever!\n", MAX_COEFFICIENT);
        printf("\n"); // Blank line
        return 0;
    }
    // *** CALCULATION ***
    // Calculate number of bounces until height is less than 1 inch
    while (height >= INCH_TO_FEET) {
        height *= coefficient;
        count++;
    }
    // *** OUTPUT ***
    // Display number of bounces
    printf("\n"); // Blank line
    printf("The ball bounced %d time%s.\n", count, count == 1 ? "" : "s");
    printf("\n"); // Blank line
	return 0;
} // end main()
