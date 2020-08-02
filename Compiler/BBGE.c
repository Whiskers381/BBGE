#include <stdio.h>
#include <stdlib.h>
#include <string.h>




enum OutPutType { ConsoleO, FileO };
enum OutPutType _outPutState = FileO;
char* _outputFileName = "Argument.c";

enum SourceType { ConsoleS, FileS, ArgumentS };
enum SourceType _sourceState = ConsoleS;
char* _sourceFileName;
char* _source;

void UpdateSource()
{
	switch (_sourceState)
	{
	case ConsoleS:
		break;
	case FileS:
		break;
	case ArgumentS:
		break;
	}
}

int ParseSource(int* lowerBound, int* upperBound, int* exponentA, int* exponentB)
{
	char intBuffer[10];
	int intBufferI = 0;
	int _sourceI = 0;

	while (_source[_sourceI] != '\0')
	{
		if ('b' == _source[_sourceI++])
		{
			//"b"[lowerBound]
			intBufferI = 0;
			while (_source[_sourceI] != '\0' && _source[_sourceI] != '-')
			{
				intBuffer[intBufferI++] = _source[_sourceI++];
			}
			*lowerBound = atoi(intBuffer);
			memset(&intBuffer[0], 0, sizeof(intBuffer));

			//"b"<lowerBound>"-"
			_sourceI++;

			//"b"<lowerBound>"-"<upperBound>
			intBufferI = 0;
			while (_source[_sourceI] != '\0' && _source[_sourceI] != 'g')
			{
				intBuffer[intBufferI++] = _source[_sourceI++];
			}
			*upperBound = atoi(intBuffer);
			memset(&intBuffer[0], 0, sizeof(intBuffer));

			//"b"<lowerBound>"-"<upperBound>"g"
			_sourceI++;

			//"b"<lowerBound>"-"<upperBound>"g"<exponent>
			intBufferI = 0;
			while (_source[_sourceI] != '\0' && _source[_sourceI] != 'e')
			{
				intBuffer[intBufferI++] = _source[_sourceI++];
			}
			*exponentA = atoi(intBuffer);
			memset(&intBuffer[0], 0, sizeof(intBuffer));

			//"b"<lowerBound>"-"<upperBound>"g"<exponent>"e"
			_sourceI++;

			//"b"<lowerBound>"-"<upperBound>"g"<exponent>
			intBufferI = 0;
			while (_source[_sourceI] != '\0' && _source[_sourceI] != 'e')
			{
				intBuffer[intBufferI++] = _source[_sourceI++];
			}
			*exponentB = atoi(intBuffer);
			memset(&intBuffer[0], 0, sizeof(intBuffer));

			//"b"<lowerBound>"-"<upperBound>"g"<exponent>"e"<exponent>"e"
			_sourceI++;

		}
		else
		{
			printf("Error: Invalid BBGE. Missing base statment 'b'...");
			return 0;
		}
	}
}

int main(int argc, char *argv[])
{
	

#pragma region Argument Routing
	if (argc == 1)
	{
		printf("No opions. Running as interpreture...");
		/*run as an interpreture*/
	}
	else
	{
		//int keepProcessingArgs = 1;
		int argvI = 1;
		while (argvI < argc)
		{
			//switch(argv[argvI])
			if ('-' == argv[argvI][0])
			{
				if ('o' == argv[argvI][1])
				{
					_outPutState = ConsoleO;
					_outputFileName = argv[++argvI];
				}
				else if ('f' == argv[argvI][1])
				{
					_sourceState = FileS;
					_sourceFileName = argv[++argvI];
					printf("Loading source from file not implemented");
					return 0;
				}
				else if ('h' == argv[argvI][1])
				{
					printf("ToDo: add help/ man data...");
					return 0;
				}
				else
				{
					printf("Error: Invalid option. -h for help.");
				}
			}
			else
			{
				_sourceState = ArgumentS;
				_source = argv[argvI];
			}
			argvI++;
		}
	}
#pragma endregion


	int lowerBound = 0;
	int upperBound = 0;
	int exponentA = 0;
	int exponentB = 0;
	printf("0");
	ParseSource(&lowerBound, &upperBound, &exponentA, &exponentB);
	printf("0");
	//fprintf(f, "\n");
	switch (_outPutState)
	{
	case ConsoleO:
		;
		printf(":\n");
		break;
	case FileO:
		;
		FILE *f;
		f = fopen(_outputFileName, "w");

		fprintf(f, "#include<stdio.h>\n");
		fprintf(f, "#define LOWERBOUND %d\n", lowerBound);
		fprintf(f, "#define UPPERBOUND %d\n", upperBound);

		fprintf(f, "void main()\n");
		fprintf(f, "{\n");

		fprintf(f, "int exponentAResults[UPPERBOUND];\n");
		fprintf(f, "for (int i = LOWERBOUND; i < UPPERBOUND; i++)\n");
		fprintf(f, "{\n");

		fprintf(f, "exponentAResults[i] = i");
		for (int i = 1; i < exponentA; i++)
		{
			fprintf(f, " * i");
		}
		fprintf(f, ";\n");
		fprintf(f, "}\n");

		fprintf(f, "int exponentBBase = 0;\n");
		fprintf(f, "int exponentBResult = 0;\n");
		fprintf(f, "for (int exponentAResultsI = LOWERBOUND; exponentAResultsI < UPPERBOUND; exponentAResultsI++)\n");
		fprintf(f, "{\n");
		fprintf(f, "while (exponentBResult < exponentAResults[exponentAResultsI])\n");
		fprintf(f, "{\n");

		fprintf(f, "exponentBResult = exponentBBase");
		for (int i = 1; i < exponentB; i++)
		{
			fprintf(f, " * exponentBBase");
		}
		fprintf(f, ";\n");

		fprintf(f, "exponentBBase++;\n");
		fprintf(f, "}\n");


		fprintf(f, "if (exponentBResult == exponentAResults[exponentAResultsI])\n");
		fprintf(f, "{\n");
		fprintf(f, "printf(\"%%d\\n\", exponentAResultsI);\n");
		fprintf(f, "}\n");
		fprintf(f, "}\n");
		fprintf(f, "}\n");

		fclose(f);
		break;
	}
	




	
	return 0;
}