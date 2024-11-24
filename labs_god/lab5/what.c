#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replaceword(long long position, char* name_input, FILE* change1, FILE* change2, FILE* output)
{
	if (change1 == NULL || change2 == NULL)
	{
		printf("file does not exist!");
		exit(0);
	}

	int ende = 0;
	long long i = 0, cm = 1;
	char inputChar1, inputChar2, inputChar;

	while (!feof(change1) && !feof(change2))
	{
		FILE* input = fopen(name_input, "r");

		while (i < position)
		{
			inputChar = fgetc(input);
			if (!(((inputChar >= 'A') && (inputChar <= 'Z')) || ((inputChar >= 'a') && (inputChar <= 'z'))))
			{
				i++;
			}
		}

		cm = 1;
		i = 0;
		ende = 0;

		while (!ende)
		{
			inputChar1 = fgetc(change1);
			inputChar = fgetc(input);

			if (inputChar1 == '\n' || inputChar1 == EOF)
			{
				if (!(((inputChar >= 'A') && (inputChar <= 'Z')) || ((inputChar >= 'a') && (inputChar <= 'z'))))
				{
					cm = 1;
					ende = 1;
				}
				else
				{
					cm = 0;
					ende = 1;
				}
			}
			if (!(((inputChar >= 'A') && (inputChar <= 'Z')) || ((inputChar >= 'a') && (inputChar <= 'z'))))
			{
				if (inputChar1 == '\n' || inputChar1 == EOF)
				{
					cm = 1;
					ende = 1;
				}
				else
				{
					cm = 0;
					ende = 1;

					while (((inputChar1 = fgetc(change1)) != EOF) && (inputChar1 != '\n'));
				}
			}
			else
			{
				if (inputChar1 != inputChar)
				{
					cm = 0;
					ende = 1;

					while (((inputChar1 = fgetc(change1)) != EOF) && (inputChar1 != '\n'));
				}
			}
		}

		while (((inputChar2 = fgetc(change2)) != EOF) && (inputChar2 != '\n'))
		{
			if (cm)
			{
				fprintf(output, "%c", inputChar2);
			}
		}

		if (cm)
		{
			fclose(input);
			fclose(change1);
			fclose(change2);
			return 0;
		}

		fclose(input);
	}

	fclose(change1);
	fclose(change2);
	return 1;
}

void findwords(char* name_input, char* change1, char* change2, FILE* output)
{
	FILE* input = fopen(name_input, "r");

	if (input == NULL || output == NULL)
	{
		printf("file does not exist!");
		exit(0);
	}

	long long pos = 0;
	char inputChar;

	while ((inputChar = fgetc(input)) != EOF)
	{
		if (((inputChar >= 'A') && (inputChar <= 'Z')) || ((inputChar >= 'a') && (inputChar <= 'z')))
		{
			if (replaceword(pos, name_input, fopen(change1, "r"), fopen(change2, "r"), output))
			{
				while (((inputChar >= 'A') && (inputChar <= 'Z')) || ((inputChar >= 'a') && (inputChar <= 'z')))
				{
					fprintf(output, "%c", inputChar);
					inputChar = fgetc(input);
				}

				if (inputChar != '�')
				{
					pos++;
					fprintf(output, "%c", inputChar);
				}
			}
			else
			{
				while (((inputChar >= 'A') && (inputChar <= 'Z')) || ((inputChar >= 'a') && (inputChar <= 'z')))
				{
					inputChar = fgetc(input);
				}

				if (inputChar != '�')
				{
					pos++;
					fprintf(output, "%c", inputChar);
				}
			}
		}
		else if (inputChar != '�')
		{
			pos++;
			fprintf(output, "%c", inputChar);
		}
	}

	fclose(input);
	fclose(output);
}

int main(int argc, char* argv[])
{
	if (argc < 5)
	{
		printf("invalid count of arguments");
		exit(0);
	}

	findwords(argv[1], argv[2], argv[3], fopen(argv[4], "w"));
	return 0;
}