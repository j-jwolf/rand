#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define MAX_BUFFER (1 << 20)
#define fl(i, e) for(i = 0; i < e; i++)

int main(int argc, char** argv)
{
	int lower, upper, count, valid = 0;
	char fn[] = "output.txt";
	if(argc == 2)
	{
		lower = INT_MIN;
		upper = INT_MAX;
		count = atoi(argv[1]);
	}
	else if(argc == 3)
	{
		lower = INT_MIN;
		upper = atoi(argv[1]);
		count = atoi(argv[2]);
	}
	else if(argc == 4)
	{
		lower = atoi(argv[1]);
		upper = atoi(argv[2]);
		count = atoi(argv[3]);
	}
	else
	{
		puts("Invalid arguments");
		exit(-1);
	}
	int i;
	srand(time(0));
	double start = time(0);
	FILE* fp = fopen(fn, "w");
	fl(i, count)
	{
		char buffer[MAX_BUFFER];
		int val = rand()%(upper-lower)+lower;
		snprintf(buffer, MAX_BUFFER, "%d", val);
		fputs(buffer, fp);
		fputs("\n", fp);
	}
	fclose(fp);
	double end = time(0);
	printf("Finished writing %d random numbers between %d and %d to %s in %f seconds\n", count, lower, upper, fn, difftime(end, start));
	fflush(stdout);
	return 0;
}
