#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		/*run as an interpreture*/
	}
	else
	{
		//int keepProcessingArgs = 1;
		int argvI = 1;
		while (argvI < argc)
		{
			switch (argv[argvI])
			{
				case "-o":
					if (++argvI <= argc)
					{
						printf("%s\n", argv[argvI]);
					}
					else
					{
						printf("missing <fileName> in option -o <fileName>");
					}
					break;
			}
			argvI++;
		}
		
	}


	return 0;
}