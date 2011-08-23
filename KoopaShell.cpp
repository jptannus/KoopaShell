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

char ** geraArg(vector<string> m){
	int i,j;
	char *aux[m.size()];
	char *aux2;
	for(i = 0; i < m.size(); i++){
		aux[i] = new char[m[i].length()];
		strcpy(aux[i],m[i].c_str());
	}
}

int main(int argc, char *argv[]){
	vector<string> matriz;
	string entrada, aux;
	int sair = 0;
	int i,j;
	pid_t PID = fork();	

	if(PID > 0){
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
				execvp("KoopaShell",geraArg(matriz));
			}
		}
	}else if(PID == 0){
		
	}else{
		cout << "Falha no fork." << endl;
		return 1;
	}
	return 0;
}
