#include<stdio.h>

#define LOWERBOUND 1
#define UPPERBOUND 10000

void main()
{
	int exponentAResults[UPPERBOUND];
	for (int i = LOWERBOUND; i < UPPERBOUND; i++)
	{
		exponentAResults[i] = i * i;//varable with exponentA value from BBGE
	}

	int exponentBBase = 0;
	int exponentBResult = 0;

	for (int exponentAResultsI = LOWERBOUND; exponentAResultsI < UPPERBOUND; exponentAResultsI++)
	{
		while (exponentBResult < exponentAResults[exponentAResultsI])
		{
			exponentBResult = exponentBBase * exponentBBase * exponentBBase;//varable with exponentB value from BBGE
			exponentBBase++;
		}

		if (exponentBResult == exponentAResults[exponentAResultsI])
		{
			printf("%d\n", exponentAResultsI);
		}
	}
}