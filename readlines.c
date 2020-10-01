#include <stdio.h>
#include "readlines.h"


int getLine(char *line, int len)
{
	int c, i;

	i = 0;
	while ((i < len-1) && (c=getchar()) != EOF && c !='\n')
		line[i++] = c;

	if (c == '\n')
		line[i++] = c;

	line[i]='\0';

	return i;
}


static char allocbuf[MAXBUF];
static char *allocp = allocbuf;

char *alloc(int len)
{
	if (allocbuf + MAXBUF - allocp >= len) {
		allocp += len;
		return allocp - len;
	}
	else return 0;
}

void Strcpy(char *to, char *from) {
	while (*to++ = *from++)
		;
}

int readlines(char *lineptr[], int maxlines)
{
	int n, nlines;
	char *p;
	char line[MAXLEN];

	nlines = 0;
	while ((n = getLine(line, MAXLEN))> 0)
		if (nlines > maxlines || (p = alloc(n))==NULL)
			return -1;
		else {
			line[n-1] = '\0';
			Strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int n)
{
	while (n-- > 0)
		printf("%s\n", *lineptr++);
}
