#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER (1 << 20)
#define fl(i, e) for(i = 0; i < e; i++)

/*
This program is for use without arguments passed in from the command line for
those who prefer UI based command line programs
*/
int getInput(const char* type)
{
	fflush(stdin);
	char* buffer = NULL;
	printf("Enter the value for %s: ", type);
	size_t len = 0;
	ssize_t buffersize = 0;
	buffersize = getline(&buffer, &len, stdin);
	int val = atoi(buffer);
	free(buffer);
	return val;
}
int main()
{
	int lower, upper, count, i;
	char fn[] = "output.txt";
	char* types[] = {"lower", "upper", "count"};
	fl(i, 3)
	{
		switch(i)
		{
			case(0):
			{
				lower = getInput(types[i]);
				break;
			}
			case(1):
			{
				upper = getInput(types[i]);
				break;
			}
			case(2):
			{
				count = getInput(types[i]);
				break;
			}
			default:
			{
				printf("Something went wrong...\nValue of i: %d\n", i);
				fflush(stdout);
				FILE* fp = fopen("error.log", "w");
				fprintf(fp, "%s -- %s\nValue of i: %d\nValue of lower: %d\nValue of upper: %d\nValue of count: %d\n", __DATE__, __TIME__, i, lower, upper, count);
				fclose(fp);
				exit(-1);
				break;
			}
		}
	}
	srand(time(0));
	double start = time(0);
	FILE* fp = fopen(fn, "w");
	fl(i, count)
	{
		char buffer[MAX_BUFFER];
		int val = rand()%(upper-lower)+lower;
		snprintf(buffer, MAX_BUFFER, "%d", val);
		fprintf(fp, "%d\n", val);
	}
	fclose(fp);
	double end = time(0);
	printf("Finished writing %d random values between %d and %d to %s in %f seconds\n", count, lower, upper, fn, difftime(end, start));
	fflush(stdout);
	return 0;
}
