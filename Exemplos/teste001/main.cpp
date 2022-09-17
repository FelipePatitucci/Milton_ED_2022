/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matem�tica
 * DMA  - Departamento de Matem�tica Aplicada
 *
 *   MAE015 - T�picos em Engenharia de Dados A
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 01  : Introdu��o a linguagem C/C++
 *   Exemplo 001: Menu de Op��es simples
 *
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data cria��o  : 06 de setembro de 2022
 *   Data altera��o: 06 de setembro de 2022
 *
 *--------------------------------------------------------------
*/
#include <iostream>

using namespace std;

void Apresenta_texto_menu(void)
{
    cout << "+----------------------------------+" << endl;
    cout << "\t1 - Executar a Soma Vetorial" << endl;
    cout << "\t2 - Executar a Multiplicacao por Escalar" << endl;
    cout << "\t3 - Executar a Combinacao Linear" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "+ aperte a tecla 's' para sair" << endl;
    cout << "+----------------------------------+" << endl;
}

void Executa_opcao_1(void)
{
    cout << "*************************" << endl;
    cout << "* executando a Soma Vetorial *" << endl;
    cout << "*************************" << endl;
    int dim_1, dim_2;
    float vetor_1[100] = {};
    float vetor_2[100] = {};
    cout << "Digite o tamanho do primeiro vetor:";
    cin >> dim_1;
    cout << "Digite os elementos do primeiro vetor:";
    Gera_Vetor(vetor_1, dim_1);
    cout << "Digite o tamanho do segundo vetor:";
    cin >> dim_2;
    if (dim_1 != dim_2) {
        Dimensoes_Diferentes(dim_1, dim_2);
    }
    else {
    cout << "Digite os elementos do segundo vetor:";
    Gera_Vetor(vetor_2, dim_2);
    cout << "A soma dos vetores resulta no vetor: (";
    Soma_Vetor(vetor_1, vetor_2, dim_1);
    }
    cout << "Digite 1 para sair";
    int a;
    cin >> a;
}

void Executa_opcao_2(void)
{
    cout << "*************************" << endl;
    cout << "* executando a Multiplicacao por Escalar *" << endl;
    cout << "*************************" << endl;
    int dim_1, escalar;
    float vetor_1[100] = {};
    cout << "Digite o tamanho do vetor:";
    cin >> dim_1;
    cout << "Digite os elementos do primeiro vetor:";
    Gera_Vetor(vetor_1, dim_1);
    cout << "Digite o escalar pelo qual deseja multiplicar o vetor:";
    cin >> escalar;
    cout << "A multiplicacao do vetor pelo escalar resulta no vetor: (";
    Multiplicacao_Escalar(vetor_1, dim_1, escalar);
    cout << "Digite 1 para sair";
    int a;
    cin >> a;
}

void Executa_opcao_3(void)
{
    cout << "*************************" << endl;
    cout << "* executando a Combinacao Linear *" << endl;
    cout << "*************************" << endl;
    int dim_1, dim_2, primeiro, segundo;
    float vetor_1[100] = {};
    float vetor_2[100] = {};
    cout << "Digite o tamanho do primeiro vetor:";
    cin >> dim_1;
    cout << "Digite os elementos do primeiro vetor:";
    Gera_Vetor(vetor_1, dim_1);
    cout << "Digite o tamanho do segundo vetor:";
    cin >> dim_2;
    if (dim_1 != dim_2) {
        Dimensoes_Diferentes(dim_1, dim_2);
    }
    else {
    cout << "Digite os elementos do segundo vetor:";
    Gera_Vetor(vetor_2, dim_2);
    cout << "Digite o valor que multiplica o primeiro vetor: ";
    cin >> primeiro;
    cout << "Digite o valor que multiplica o segundo vetor: ";
    cin >> segundo;
    cout << "A combinacao linear dos vetores usando os coeficientes a e b resulta no vetor: (";
    Combinacao_Linear(vetor_1, vetor_2, dim_1, primeiro, segundo);
    }
    cout << "Digite 1 para sair";
    int l;
    cin >> l;
}

void Menu(void)
{
    char opcao_escolhida;

    do {
        Apresenta_texto_menu();
        cin >> opcao_escolhida;
        switch (opcao_escolhida) {
            case '1' : Executa_opcao_1(); break;
            case '2' : Executa_opcao_2(); break;
            case '3' : Executa_opcao_3(); break;
            case 's' : break;
            default  : cout << "Opcao invalida, tente novamente, ou 's' para sair" << endl;
        }
    } while (opcao_escolhida != 's');
}

void Soma_Vetor(float arr1[100], float arr2[100], int dim) {
    for (int i = 0; i < dim; i++) {
        float soma = 0.0;
        if (i == dim - 1) {
            cout << arr1[i] + arr2[i] << ")"; 
        }
        else {
        cout << arr1[i] + arr2[i] << ", "; 
        }
    }
}

void Gera_Vetor(float arr[100], int dim) {
    for (int i = 0; i < dim; i++) {
        float k;
        cin >> k;
        arr[i] = k;
    }
}

void Dimensoes_Diferentes(int dim1, int dim2) {
    cout << "A operacao de soma vetorial requer que os dois vetores tenham tamanhos iguais" << endl
    << "Tamanhos recebidos:   " << dim1 << "  ;  " << dim2 << endl;
}

void Multiplicacao_Escalar(float arr1[100], int dim, int k) {
    for (int i = 0; i < dim; i++) {
        float produto = 0.0;
        if (i == dim - 1) {
            cout << arr1[i]*k << ")"; 
        }
        else {
        cout << arr1[i]*k << ", "; 
        }
    }
}

void Combinacao_Linear(float arr1[100], float arr2[100], int dim, int a, int b) {
    for (int i = 0; i < dim; i++) {
        float soma = 0.0;
        if (i == dim - 1) {
            cout << a*arr1[i] + b*arr2[i] << ")"; 
        }
        else {
        cout << a*arr1[i] + b*arr2[i] << ", "; 
        }
    }
}

int main()
{
    cout << "Exemplo 001: Menu de Opcoes simples " << endl;
    Menu();

    return 0;
}
