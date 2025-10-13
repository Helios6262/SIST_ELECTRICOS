#include <iostream>
#include<cstring>
using namespace std;

bool palindroma(char* palabra);
char* pideFrase();

int main()
{
	char* frase = pideFrase();
	int inicio = 0;
	for (int i = 0; i < strlen(frase); i++)
	{
		if (frase[i] == ' ' || i == strlen(frase)-1)
		{
			int size_palabra = i - inicio;
			char* buff2 = new char[size_palabra+1];
			int a = 0;
			for (int j = 0; j < i; j++)
			{
				buff2[a] = frase[inicio + j];
				a++;
			}
			inicio = i+1;
			buff2[size_palabra+1] = '\0';

			size_t size_pal = strlen(buff2);
			char* palabra = new char[size_pal + 1];
			strcpy_s(palabra, size_pal + 1, buff2);
			// hasta aca bien 

			if (palindroma(palabra))
			{
				cout << palabra << " es palindroma";
			}
		}
	}
	return 0;
}

char* pideFrase()
{
	char buff[100];
	cout << "Inserte frase: "; cin.getline(buff,100);

	size_t size = strlen(buff);
	char* frase = new char[size + 1];
	strcpy_s(frase, size + 1, buff);

	return frase;
}

bool palindroma(char* palabra)
{
	size_t length = strlen(palabra);
	for (int i = 0; i < length / 2; i++)
	{
		for (int j = length-1; j > length / 2; j--)
		{
			if (palabra[i] != palabra[j])
			{
				return 0;
				break;
			}
			else
			{
				return 1;
			}
		}
	}

}