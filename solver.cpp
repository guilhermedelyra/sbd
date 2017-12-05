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
	int z;
    do {
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

        scanf ("%d", &z); if (!z) break;

    	ifstream filein(to_string(z));
        string read, read2, read3, read4, op[4], in1, errmultes[6], in3;
        char buf[3], in2[6];

        while(getline(filein, read)){

        	if (read == "ENUNCIADO") {
        		getline(filein, read2);
        		cout << read2 << "\n\n";
        	}

        	if (read == "TIPO DE QUESTAO") {
        		getline(filein, read2);
        		cout << "TIPO DE QUESTÃO = " << read2 << "\n\n";

        		if (read2 == "VouF") {
        			cout << "\n\nResposta (Verdadeiro ou Falso): "; 
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

        		if (read2 == "Multipla-Escolha") {
        			for (int i = 0; i < 4; ++i) {
        				getline(filein, op[i]); cout << op[i] << endl;
        			}    			

        			cout << "\n\nResposta (apenas uma alternativa!): "; cin >> in1;
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

        		if (read2 == "Escolha-Multipla") {
        			for (int i = 0; i < 4; ++i) {
        				getline(filein, op[i]); cout << op[i] << endl;
        			}    			

        			cout << "\n\nResposta (uma ou multiplas alternativas!): \n"; 
        			
        			scanf (" %[^\n]", in2);
        			in3 = in2;
        			getline (filein, read3);
        			if (in3 == read3) {
        				cout << "Parabéns!\n";
        			} else {
        				getline (filein, read4);
        				cout << "\n\n" << read4 << "\n\n";
        			}
        		}

        		if (read2 == "Lacunas") {
        			getline (filein, read3); cout << read3;
        			cout << "\n\nResposta: "; cin >> in1;
        			getline (filein, read3);
        			if (read3 == in1) {
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

        system ("clear");

    } while (true);

    return 0;
}