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
#include <cstring>
#include <cmath>

using namespace std;

void Apresenta_texto_menu(void)
{
    cout << "+----------------------------------+" << endl;
    cout << "\t1 - Executar a Soma Vetorial" << endl;
    cout << "\t2 - Executar a Multiplicacao por Escalar" << endl;
    cout << "\t3 - Executar a Combinacao Linear" << endl;
    cout << "\t4 - Executar o Produto_Interno" << endl;
    cout << "\t5 - Executar a Norma 2" << endl;
    cout << "\t6 - Executar o Teste de Dependencia Linear" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "+ aperte a tecla 's' para sair" << endl;
    cout << "+----------------------------------+" << endl;
}

void Dimensoes_Diferentes(int dim1, int dim2, string operacao) {
    cout << "A operacao " << operacao << " requer que os dois vetores tenham tamanhos iguais" << endl << "Tamanhos recebidos:   " << dim1 << "   ;   " << dim2 << endl;
}

void Soma_Vetor(float arr1[100], float arr2[100], int dim) {
    for (int i = 0; i < dim; i++) {
        float soma = 0.0;
        if (i == dim - 1) {
            cout << arr1[i] + arr2[i] << ")" << endl; 
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

void Multiplicacao_Escalar(float arr1[100], int dim, int k) {
    for (int i = 0; i < dim; i++) {
        float produto = 0.0;
        if (i == dim - 1) {
            cout << arr1[i]*k << ")" << endl; 
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
            cout << a*arr1[i] + b*arr2[i] << ")" << endl; 
        }
        else {
        cout << a*arr1[i] + b*arr2[i] << ", "; 
        }
    }
}

void Produto_Interno(float arr1[100], float arr2[100], int dim) {
    float soma = 0.0;
    for (int i = 0; i < dim; i++) {
        soma += arr1[i]*arr2[i];
    }
    cout << soma << endl;
}

void Norma(float arr1[100], int dim) {
    float soma = 0.0;
    for (int i = 0; i < dim; i++) {
        soma += arr1[i]*arr1[i];
    }
    cout << pow(soma, 0.5) << endl;
}

void Depedencia_Linear(float arr1[100], float arr2[100], int dim) {
    float soma = 0.0;
    for (int i = 0; i < dim; i++) {
        soma += arr1[i]*arr2[i];
    }
    // possivelmente só verificar se é menor que uma certa tolerância para
    // evitar problema de ponto flutuante
    if (soma == 0.0) {
        cout << "Os vetores sao Linearmente Independentes" << endl;
    }
    else {
        cout << "Os vetores sao Linearmente Dependentes" << endl;
    }
}

void Executa_Soma_Vetorial(void)
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
        Dimensoes_Diferentes(dim_1, dim_2, "Soma de Vetores");
    }
    else {
    cout << "Digite os elementos do segundo vetor:";
    Gera_Vetor(vetor_2, dim_2);
    cout << "A soma dos vetores resulta no vetor: (";
    Soma_Vetor(vetor_1, vetor_2, dim_1);
    }
    cout << "Digite 1 para voltar para ao menu de opcoes.";
    int a;
    cin >> a;
}

void Executa_Multiplicacao_Escalar(void)
{
    cout << "*************************" << endl;
    cout << "* executando a Multiplicacao por Escalar *" << endl;
    cout << "*************************" << endl;
    int dim_1;
    float escalar;
    float vetor_1[100] = {};
    cout << "Digite o tamanho do vetor:";
    cin >> dim_1;
    cout << "Digite os elementos do primeiro vetor:";
    Gera_Vetor(vetor_1, dim_1);
    cout << "Digite o escalar pelo qual deseja multiplicar o vetor:";
    cin >> escalar;
    cout << "A multiplicacao do vetor pelo escalar resulta no vetor: (";
    Multiplicacao_Escalar(vetor_1, dim_1, escalar);
    cout << "Digite 1 para voltar para ao menu de opcoes.";
    int a;
    cin >> a;
}

void Executa_Combinacao_Linear(void)
{
    cout << "*************************" << endl;
    cout << "* executando a Combinacao Linear *" << endl;
    cout << "*************************" << endl;
    int dim_1, dim_2;
    float primeiro, segundo;
    float vetor_1[100] = {};
    float vetor_2[100] = {};
    cout << "Digite o tamanho do primeiro vetor:";
    cin >> dim_1;
    cout << "Digite os elementos do primeiro vetor:";
    Gera_Vetor(vetor_1, dim_1);
    cout << "Digite o tamanho do segundo vetor:";
    cin >> dim_2;
    if (dim_1 != dim_2) {
        Dimensoes_Diferentes(dim_1, dim_2, "Combinacao Linear");
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
    cout << "Digite 1 para voltar para ao menu de opcoes.";
    int l;
    cin >> l;
}

void Executa_Produto_Interno(void)
{
    cout << "*************************" << endl;
    cout << "* executando o Produto Interno *" << endl;
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
        Dimensoes_Diferentes(dim_1, dim_2, "Produto Interno");
    }
    else {
    cout << "Digite os elementos do segundo vetor:";
    Gera_Vetor(vetor_2, dim_2);
    cout << "O produto interno dos vetores resulta no valor: ";
    Produto_Interno(vetor_1, vetor_2, dim_1);
    }
    cout << "Digite 1 para voltar para ao menu de opcoes.";
    int l;
    cin >> l;
}

void Executa_Norma_2(void)
{
    cout << "*************************" << endl;
    cout << "* executando a Norma 2 do Vetor *" << endl;
    cout << "*************************" << endl;
    int dim_1;
    float vetor_1[100] = {};
    cout << "Digite o tamanho do vetor:";
    cin >> dim_1;
    cout << "Digite os elementos do vetor:";
    Gera_Vetor(vetor_1, dim_1);
    cout << "A norma do vetor resulta no valor: ";
    Norma(vetor_1, dim_1);
    cout << "Digite 1 para voltar para ao menu de opcoes.";
    int l;
    cin >> l;
}

int Executa_Teste_Dependencia_Linear(void)
{
    cout << "*************************" << endl;
    cout << "* executando teste de Dependencia Linear *" << endl;
    cout << "*************************" << endl;
    float dim_1, dim_2;
    float vetor_1[100] = {};
    float vetor_2[100] = {};
    cout << "Digite o tamanho do primeiro vetor:";
    cin >> dim_1;
    cout << "Digite os elementos do primeiro vetor:";
    Gera_Vetor(vetor_1, dim_1);
    cout << "Digite o tamanho do segundo vetor:";
    cin >> dim_2;
    if (dim_1 != dim_2) {
        Dimensoes_Diferentes(dim_1, dim_2, "Produto Interno");
    }
    else {
    cout << "Digite os elementos do segundo vetor:";
    Gera_Vetor(vetor_2, dim_2);
    Depedencia_Linear(vetor_1, vetor_2, dim_1);
    }
    cout << "Digite 1 para voltar para ao menu de opcoes.";
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
            case '1' : Executa_Soma_Vetorial(); break;
            case '2' : Executa_Multiplicacao_Escalar(); break;
            case '3' : Executa_Combinacao_Linear(); break;
            case '4' : Executa_Produto_Interno(); break;
            case '5' : Executa_Norma_2(); break;
            case '6' : Executa_Teste_Dependencia_Linear(); break;
            case 's' : break;
            default  : cout << "Opcao invalida, tente novamente, ou 's' para sair" << endl;
        }
    } while (opcao_escolhida != 's');
}

int main()
{
    cout << "Exemplo 001: Menu de Opcoes simples " << endl;
    Menu();

    return 0;
}
