#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int **puntero;
	puntero = new int*;
	*puntero = new int;
	**puntero =  5;
	cout << **puntero;
	return 0;
}

