#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
void convert (int *binaryDigits,int *decimal,int length);
int main (int argc,char **argv)
{
		const int length = argc-1;
	int binaryDigits[length];	
	int decimal = 0;
if (argc >9)
{
	printf ("Too many binary digits entered.\n");
	return(0);
}

	if (argc ==1)
	{
		printf ("You must enter up to 8 binary digits.\n");
		return(0);
	}
	
	for (int i = 0; i< argc-1; i++)
	{
		if (isalpha(argv[i+1][0]))
		{
			printf("Only digits 1 and 0 are permitted.\n");
				   return(0);
				   }
		binaryDigits[i] = atoi(argv[(i+1)]);
		if ((binaryDigits[i] <0) || (binaryDigits[i] >1))
		{
			printf ("Only digits 1 and 0 are permitted.\n");
		return(0);
		}
	}

	convert(binaryDigits,&decimal,length);
	
	printf ("%d\n",decimal);
	
	return (0);
}


void convert (int *binaryDigits,int *decimal,int length)
{
int number =0;
int i=0;
int temp =i+1;
int multiplier = length-1;
for (i = 0; i< length; i++)
{

	if (binaryDigits[i] ==1)
	{
		number = pow(2,multiplier);

		*decimal +=number;
		
	}
multiplier--;	
}

}
