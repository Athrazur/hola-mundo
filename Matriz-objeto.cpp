#include <iostream>
using namespace std;

//Clase de matrices, para almacenar datos y realizar operaciones algebraicas.
class matriz
{
private:
	int **v=NULL;	//Puntero *v apuntando a la memoria de la matriz
	int i=0;	//Variable que guarda numero de filas en la matriz
	int j=0;	//Variable j que guarda numero de columnas en la matriz
public:
	//Constructor de la matriz: iguala i filas y j columnas a 0 casa una.
	matriz()
	{
		i=0;	//Filas igual a 0
		j=0;	//Columnas igual a 0
	}
	//Destructor de la matriz: libera la memoria dinamica
	~matriz()
	{
		if(v!=NULL)	//Si no se asigno memoria no ejecutar al siguiente codigo, de darse lo contrario si ejecutar
		{
			for(int gfilas=0; gfilas<i; gfilas++)	//inicio bucle para borrar punteros
			{
				delete[]v[gfilas];
			}
			delete[]v;	//Borro las filas
		}
	}

	//Asigno memoria para la matriz y defino a la misma
	void create(int filas, int columnas)
	{
		i= filas;
		j= columnas;
		
		v = new int*[filas];	//Creo los punteros de para cada fila
		
		for(int fi=0; fi < filas; fi++)
		{
			v[fi] = new int[columnas];	//Creo los punteros para las "columnas"
		}
		
		//Limpio la matriz usando bucles for().
		for(int g=0; g < filas; g++)
		{
			for(int h=0; h < columnas; h++)
			{
				v[g][h]=0;
			}
		}
	}

	//Almaceno un natural en una coordenada.
	void save(int *i, int *j, int n)
	{
		v[*i][*j] = n;
	}
	//Libero memoria de la matriz intencionalmente
	void dlete()
	{
		if(v!=NULL)	//Si no se asigno memoria no ejecutar al siguiente codigo, de darse lo contrario si ejecutar
		{
			for(int gfilas=0; gfilas<i; gfilas++)	//inicio bucle para borrar punteros
			{
				delete[]v[gfilas];
			}
			delete[]v;	//Borro las filas
		}
	}

	//Limpio la matriz asignando a todos los valores 0.
	int clean()
	{
		if(v!=NULL)
		{
			for(int gfilas=0; gfilas<i; gfilas++)
			{
				for(int hcolumnas=0; hcolumnas<j; hcolumnas++)
				{
					v[gfilas][hcolumnas] = 0;
				}
			}
			return 0;
		}
		else return 1;
	}

	//Convierto la matriz en una matriz identidad
	int identidad()
	{
		if(v!=NULL)
		{
			for(int gfilas=0; gfilas<i; gfilas++)
			{
				for(int hcolumnas=0; hcolumnas<j; hcolumnas++)
				{
					//Si las coordenadas de la matriz coinciden se asigna un 1
					if(i==j)
					{
						v[i][j] = 1;
					}
					//De no ser asi se asigna un 0
					else
					{
						v[i][j] = 0;
					}
				}
			}
		}
	}

};

int main(int argc, char *argv[]) {
	int * vector;
	vector = new int[2];
	vector[0]=1;
	vector[1]=2;
	cout << vector[0] << endl;
	cout << vector[1] << endl;
	return 0;
}

