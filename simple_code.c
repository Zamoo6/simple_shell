#include <main.h>
/**
 * sum - Entry point of the program
 *
 * Description: This program calculates the
 * sum of two integers and prints the result.
 *
 * Return: Always 0 (indicating success)
 */
int sum(void)
{
	int x = 10;
	int y = 20;
	int sum = x + y;

	printf("The sum of %d and %d is %d\n", x, y, sum);
	return (0);
}
