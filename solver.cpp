#include <bits/stdc++.h>
#define ll long long
#define debug(x) cout << #x << " " << x << endl
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

int main ( ) {
	int z;
	cout << "insira o numero do grupo: "; cin >> z;
	ifstream filein(to_string(z));
    string read, read2, read3, op[4], in1, errmultes[6];
    char buf[3];
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

    			if (read3 == in1) {
    				cout << "Parabéns!\n";
    				printf("\n\nPressione qualquer tecla + <ENTER> para continuar...\n\n");
    				scanf("%s", buf);
    				system ("clear");
    			} else {
    				for (int i = 0; i < 2; ++i) getline (filein, read3);
    				cout << read3 << endl;
    				getline (filein, read);
    				printf("\n\nPressione qualquer tecla + <ENTER> para continuar...\n\n");
    				scanf("%s", buf);
    				system ("clear");
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
    				printf("\n\nPressione qualquer tecla + <ENTER> para continuar...\n\n");
    				scanf("%s", buf);
    				system ("clear");
    			} else {
    				for (int i = 0; i < 6; ++i) {
    					getline(filein, errmultes[i]); cout << errmultes[i] << endl;
    				}
    				printf("\n\nPressione qualquer tecla + <ENTER> para continuar...\n\n");
    				scanf("%s", buf);
    				system ("clear");
    			}
    		}

    		if (read2 == "Escolha-Multipla") {

    		}

    		if (read2 == "Lacunas") {

    		}
    	}
    }
}