#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int ncorden;	//numero de coorenadas por vector.
	int nvector;	//cantidad de vectores.
	//char sumvtr;	//indica si el vector actual se toma como su negativo o su positivo.
	float **vtr;	//puntero a array de vectores.Es casi seguro que se haga una array biimencional: vtr[][];
	float *rvtr;	//vector resultante.
	float producto;
	char opcion;
	
	do{
		do{
			producto=0.0f;
			
			cout << "\n Numero coordenadas:\t"; cin >> ncorden;
			cout << " Numero de vectores:\t"; cin >> nvector;
			rvtr = new float[ncorden];
			vtr = new float * [nvector];
			
			for(int i=0; i<nvector; i++)
			{
				vtr[i] = new float[ncorden];
				
				for(int j=0; j<ncorden; j++)
				{
					vtr[i][j] = 0.0f;
				}
			}
			
			for(int i=0; i<ncorden; i++)
			{
				rvtr[i] = 0.0f;
			}
			
			for(int i=0; i<nvector; i++)
			{
				cout << "\n Ingrese datos del vector " << i+1 << ":\n";
				
				for(int j=0; j<ncorden; j++)
				{
					cout << "\tcoordenada " << j+1 << ":\t"; cin >> vtr[i][j];
				}
			}
			
			for(int i=0; i<ncorden; i++)
			{
				for(int j=0; j<nvector; j++)
				{
					if(j==0)
						rvtr[i]=vtr[j][i];
					else rvtr[i]*=vtr[j][i];
				}
			}
			
			for(int i=0; i<ncorden; i++){
				producto += rvtr[i];
			}
			
			cout << "\n\tProducto resultante:\t" << producto << endl;
			
			delete rvtr;
			for(int i=0; i<nvector; i++)
			{
				delete vtr[i];
			}
			delete vtr;
			
			cout << "------------------------------------------------------" << endl;
			cout << " Hacer otra multiplicacion(s/n):\t"; cin >> opcion;
			
		} while(opcion=='s');
		
		cout << " Salir(s/n):\t"; cin >> opcion;
	
	} while(opcion!='s');
	
	return 0;
}

