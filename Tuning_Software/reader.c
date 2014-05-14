/* Fill reading Implementation */
#include <reader.h>
#include <stdio.h>
#include <stdlib.h>

char*  readfile(char *filename)
{
	FILE *fp;
	char *mode = "r";
	fp = open(filename,mode);
}