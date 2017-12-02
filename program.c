#include <stdio.h>
#include <stdlib.h>

char* dec_to_bin(int decimal);
void  real_dec_to_bin(int decimal, char* binary);
void  reverse(char* binary);
int   get_length(char* string);

int main(void)
{
	int decimal = 109;
	char* s = dec_to_bin(decimal);
	printf("%s\n", s);
	return 0;
}

char* dec_to_bin(int decimal)
{
	char* binary = malloc(sizeof(char) * 1024);
	real_dec_to_bin(decimal, binary);

	printf("Answer is %s\n", binary);
	reverse(binary);

	printf("Answer si %s\n", binary);

	return binary;
}

void real_dec_to_bin(int decimal, char* binary)
{
	int remainder;

	while(decimal != 0)
	{
		remainder = decimal % 2;
		decimal = decimal / 2;
		*binary = (remainder + 48);
		binary++;
	}
	//binary++;
	*binary = '\0';

}

void reverse(char* binary)
{
	char temporarry;
	int length = get_length(binary);
	
	char* last_index = binary;
	for(int dummy = 0; dummy < (length-1); dummy++)
	{
		last_index++;
	}	

	for(int i = 0; i < (length / 2); i++)
	{
		temporarry = *binary;
		*binary = *last_index;
		*last_index = temporarry;
	
		binary++;
		last_index--;
	}

}

int get_length(char* string)
{
	int length;
	for(length = 0; *string != '\0'; length++)
	{
		string++;
	}
	printf("Length is %d\n", length);
	return length;
}
