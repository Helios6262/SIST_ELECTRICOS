#include <iostream>
using namespace std;
#include <stdlib.h>
#include <iomanip>

int Menu();
void Jugar(char adivina[6], int intentos, char*Numero);
void Ver(char num[4], int intentos);
char* Genera(int &intentos);

void main()
{
	char Adivina[] = { 0,0,0,0,0 }; //este se marca 0 o 1
	int intentos = 0;
	char* Numero = Genera(intentos);

	while (true)
	{
		int ret = Menu();
		switch (ret)
		{
			case 1: Jugar(Numero, intentos, Numero); break;
			case 2: Ver(Adivina, intentos); break;
			case 3: Numero = Genera(intentos); break;
			case 4: return;
		}
	}

}

int Menu()
{
	int opcion;
	cout << "******* MENU ********" << endl;
	cout << "1. Jugar" << endl;
	cout << "2. Ver digitos adivinados e intentos " << endl;
	cout << "3. Generar otro numero " << endl;
	cout << "4. Salir " << endl;
	cout << "		Opcion?: "; cin >> opcion;

	return opcion;
}

char* Genera(int& intentos)
{
	int rand_num = rand() % (99999 - 10000); //defino rango de 5 digitos
	char rand_char[4];
	_itoa_s(rand_num, rand_char, 4, 10);
	intentos++;
	return rand_char;
}

void Ver(char num[6], int intentos)
{
	cout << "El numero de intentos es: " << intentos << endl;
	for (int i = 0; i < 6; i++)
	{
		if (num[i] == 0)
		{
			cout << " X ";
		}
		else
		{
			cout << " " << num[i] << " ";
		}
	}
	cout << endl;
}

void Jugar(char adivina[6], int intentos, char Numero[4])
{
	int num_try;
	cout << "Inserta un numero de 5 digitos. " << endl;
	cin >> num_try;
	char num_try_char[6];
	_itoa_s(num_try, num_try_char, 6, 10);

	
	cout << "Digitos adivinados: ";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (num_try_char[i] == Numero[j])
			{
				cout << num_try_char[i] << " ";
			}
		}
	}

	cout << endl;
	cout << "Digitos en posicion correcta: ";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (num_try_char[i] == Numero[j])
			{
				if (i == j)
				{
					cout << num_try_char[i];
				}
			}
		}
	}


}