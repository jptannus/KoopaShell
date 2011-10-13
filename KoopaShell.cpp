#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <csignal>
#include <cstdio>


using namespace std;

void handle_signal(int signo){
	cout << "\nkoopa> ";
	fflush(stdout);
}

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
	char **aux2;
	aux2 = (char**)malloc(sizeof(char)*m.size());
	for(i = 1; i < m.size(); i++){
		aux2[i-1] = new char[m[i].length()];
		strcat(aux2[i-1],m[i].c_str());
		strcat(aux2[i-1],'\0');
	}
	aux2[i-1] = NULL;
	aux = aux2;
}

int main(int argc, char **argv, char **envp){
	vector<string> matriz;
	string entrada, aux;
	int sair = 0;
	char **args;
	int i,j;

	signal(SIGINT, SIG_IGN);
	signal(SIGINT, handle_signal);

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
			//if(execvp(matriz[0].c_str(),args))
			execvp(matriz[0].c_str(), args);
				//cout << "Comando nao encontrado " << endl;
		}
	}
	return 0;
}
