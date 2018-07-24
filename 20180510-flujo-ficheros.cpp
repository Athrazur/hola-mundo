#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	
	char linea[128];
	
	ofstream lapiz;
	lapiz.open("texto.txt");
	lapiz << "[categoria]a1b2c3d4" << endl;
	lapiz.close();
	
	ifstream lupa;
	lupa.open("texto.txt");
	lupa.getline(linea, sizeof(linea));
	cout << linea << endl;
	lupa.close();
	return 0;
}

