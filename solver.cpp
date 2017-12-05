#include <bits/stdc++.h>
#include <dirent.h>
#define ll long long
#define debug(x) cout << #x << " " << x << endl
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

int main ( ) {
	string z;
    cout << "insira o numero do grupo (0 para sair)"; 
    cout << "\n[lista de arquivos disponíveis: ";
    DIR *dirp;
    struct dirent *directory;
    dirp = opendir("questoes/");
    if (dirp) {
        while ((directory = readdir(dirp)) != NULL) printf("%s ", directory->d_name);
        closedir(dirp);
    }

    cout << "]\n";

    cin >> z;
    if(z[0] - '0' == 0) return 0;

	ifstream filein("questoes/"+z);
    if (!filein) cout << "mano.\n";
    string read, read2, read3, read4, op[4], in1, errmultes[6], in3;
    char buf[3], in2[15];

    while(getline(filein, read)){
    	if (read[0] == 'E' && read[1] == 'N') {
    		getline(filein, read2);
    		cout << read2 << "\n\n";
    	}

    	if (read[0] == 'T' && read[1] == 'I') {
    		getline(filein, read2);
    		cout << "TIPO DE QUESTÃO = " << read2 << "\n\n";

    		if (read2[0] == 'V' && read2[1] == 'o') {
    			cout << "\n\nResposta (Verdadeiro ou Falso):\n"; 
    			cin >> in1;
    			getline (filein, read3);

    			if (tolower(read3[0]) == tolower(in1[0])) {
    				cout << "Parabéns!\n";
    			} else {
    				cout << "\n\n";
    				getline (filein, read3);
    				cout << read3 << endl;
    				cout << '\n';
    			}
    		}

    		if (read2[0] == 'M' && read2[1] == 'u') {
    			for (int i = 0; i < 4; ++i) {
    				getline(filein, op[i]); cout << op[i] << endl;
    			}    			

    			cout << "\n\nResposta (apenas uma alternativa!):\n"; cin >> in1;
    			getline (filein, read3);

    			if (read3 == in1) {
    				cout << "Parabéns!\n";
    			} else {
    				cout << "\n\n";
    				for (int i = 0; i < 6; ++i) {
    					getline(filein, errmultes[i]); cout << errmultes[i] << endl;
    				}
    				cout << "\n\n";
    			}
    		}

    		if (read2[0] == 'E' && read2[1] == 's') {
    			for (int i = 0; i < 4; ++i) {
    				getline(filein, op[i]); cout << op[i] << endl;
    			}    			

    			cout << "\n\nResposta (uma ou multiplas alternativas!):\n"; 
    			
    			scanf (" %[^\n]", in2);
    			in3 = in2;
    			getline (filein, read3);
                memset(in2, 0, sizeof(char));
    			if (in3 == read3) {
    				cout << "Parabéns!\n";
    			} else {
    				getline (filein, read4);
    				cout << "\n\n" << read4 << "\n\n";
    			}
    		}

    		if (read2[0] == 'L' && read2[1] == 'a') {
    			getline (filein, read3); 
                cout << read3 << endl;
    			cout << "\n\nResposta:\n"; 
                scanf (" %[^\n]", in2);
                in3 = in2;
    			getline (filein, read3);
                memset(in2, 0, sizeof(char));
    			if (read3 == in3) {
    				cout << "Parabens!\n";
    			} else {
    				getline (filein, read4);
    				cout << "\n\n" << read4 << "\n\n";
    			}
    		}
    		printf("\n\nPressione qualquer tecla + <ENTER> para continuar...\n\n");
    		scanf("%s", buf);
    		system ("clear");
    	}
    }

    return 0;
}