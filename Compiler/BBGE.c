#include <stdio.h>
#include <stdlib.h>




enum OutPutType { ConsoleO, FileO };
enum OutPutType _outPutState = ConsoleO;
char* _outputFileName = "Argument.c";

enum SourceType { ConsoleS, FileS, ArgumentS };
enum SourceType sourceState = ConsoleS;
char* _sourceFileName;
char* _source;

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
					sourceState = FileS;
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
				sourceState = ArgumentS;
				_source = argv[argvI];
			}
			argvI++;
		}

	}
#pragma endregion


	/*unsigned int uIntMax = 2;
	int numberOfBitsInAnUnSignedInt = sizeof(unsigned int) * 8;
	for (int i = 0; i <  numberOfBitsInAnUnSignedInt; i++)
	{
		uIntMax = uIntMax * uIntMax;
	}
	printf("\n%d\n", uIntMax);*/
	char intBuffer[10];
	int intBufferI = 0;
	//printf("0");
	if (sourceState == ArgumentS)
	{
		int _sourceI;
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
				unsigned int lowerBound = atoi(intBuffer);

				//"b"<lowerBound>"-"
				_sourceI++;

				//"b"<lowerBound>"-"<upperBound>
				intBufferI = 0;
				while (_source[_sourceI] != '\0' && _source[_sourceI] != 'g')
				{
					intBuffer[intBufferI++] = _source[_sourceI++];
				}
				unsigned int upperBound = atoi(intBuffer);


			}
			else
			{
				printf("Error: Invalid BBGE. Missing base statment 'b'...");
				return 0;
			}
		}
		/*FILE *f;
		f = fopen(_outputFileName, "w");
		fprintf(f, "#include<stdio.h>\n");
		fclose(f);*/
	}
	else
	{
		printf("Error: non Argument source is not implemented");
	}

	return 0;
}
//
//void GetSource(char* source)
//{
//	switch (sourceState)
//	{
//	case ConsoleS:
//		fgets(source,200,stdin)
//		break;
//	case FileS:
//		printf("Error: Loading Source from file currently unsupported");
//		break;
//	case ArgumentS:
//		break;
//	default:
//		printf("Error: Invalid SourceState");
//		return 0;
//	}
//}