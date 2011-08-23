#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <cstring>

using namespace std;

void printaMatriz(vector<string> m){
	int i;
	cout << "-- Matriz --------" << endl;
	for(i = 0; i < m.size(); i++){
		cout << m[i] << endl;
	}
	cout << "------------------" << endl;
}

void geraArg(vector<string> m, char *aux[]){
	int i,j;
	char *aux2[m.size()];
	for(i = 1; i < m.size(); i++){
		aux2[i-1] = new char[m[i].length()];
		strcpy(aux2[i-1],m[i].c_str());
	}
	aux2[i-1] = NULL;
	aux = aux2;
}

int main(int argc, char *argv[]){
	vector<string> matriz;
	string entrada, aux;
	int sair = 0;
	char **args;
	int i,j;

	while(!sair){
		matriz.clear();
		cout << "koopa> ";
		getline(cin,entrada,'\n');
		if(!entrada.compare("exit")){
			sair = 1;	
		}else{
			j = 0;
			for(i = 0; i < entrada.length(); i++){
				if(entrada[i] == ' '){
					matriz.push_back(aux);
					aux.clear();
				}else{
					aux.push_back(entrada[i]);
				}		
			}
			matriz.push_back(aux);
			aux.clear();
			printaMatriz(matriz);
			geraArg(matriz, args);
			if(execvp(matriz[0].c_str(),args))
				cout << "Comando nao encontrado " << endl;
		}
	}
	return 0;
}
