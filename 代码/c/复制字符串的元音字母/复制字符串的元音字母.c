#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void function_vowel(char string[],int num)
{
	int k;
	int j=0;
	
	for(k=0;k<num;k++)
	{
		if((string[k]=='a')||(string[k]=='e')||(string[k]=='i')||(string[k]=='o')||(string[k]=='u'))
		{
		putchar(string[k]);
		}
	}                                     /*���ܹ������飬����ͨ�������¼Ԫ�ء���Ϊ������ʱ�洢��������ͷš�*/
	
	
}

int main() 
{
	char string[20];
	gets(string);
	
	int length;
	length=strlen(string);
	
	function_vowel(string,length);
	 
	return 0;
}
