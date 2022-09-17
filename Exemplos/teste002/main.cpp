/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matemática
 * DMA  - Departamento de Matemática Aplicada
 *
 *   MAE015 - Tópicos em Engenharia de Dados A
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 02  : Introdução a linguagem C/C++
 *   Exemplo 002: Estruturas de Dados primitivas
 *
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 08 de setembro de 2022
 *   Data alteração: 08 de setembro de 2022
 *
 *--------------------------------------------------------------
*/
#include <iostream>

using namespace std;

/*--------------------------------------------------------------
 * Area de estruturas de dados declaradas pelo programador
 *--------------------------------------------------------------
*/
typedef unsigned long int t_DRE;

struct t_Aluno
{
    t_DRE   DRE;
    string  Nome;
    double  CR;

    // Area de algoritmos: métodos do objeto
    void Cadastro(t_DRE pDRE, string pNome, double pCR = 0)
    {
        DRE = pDRE;
        Nome = pNome;
        CR = pCR;
    }
    void Print(void)
    {
        cout << "+-------------------+" << endl;
        cout << "| Registro de Aluno |" << endl;
        cout << "+-------------------+" << endl;
        cout << "| DRE : " << DRE << endl;
        cout << "| Nome: " << Nome << endl;
        cout << "| CR  : " << CR << endl;
        cout << "+-------------------+" << endl;
    }
    double operator +(t_Aluno B) // operador polimorfo
    {
        return (CR + B.CR);
    }

};

class t_Curso
{
    string  Codigo_Curso;
    string  Nome_Curso;
    t_Aluno lista_de_alunos[500];
};

/*--------------------------------------------------------------
 * Area de criação de funções polimorfas: templates
 *--------------------------------------------------------------
*/
template <class T>
double Media(T a1, T a2)
{
    return (a1 + a2)/2;
}

//---------------------------------------------------------------
int main()
{
    t_Aluno a1,a2;

    cout << "+-------------------------------------------- +" << endl;
    cout << "| Exemplo 002: Estruturas de Dados primitivas |" << endl;
    cout << "+-------------------------------------------- +" << endl << endl;

    a1.Cadastro(122001765,"Ze das Coves",7.8);
    a2.Cadastro(122002893,"Fulano de Tal",8.9);
    a1.Print();
    a2.Print();

    cout << "Calculando Medias" << endl;
    cout << "Media entre inteiros 3 e 4  : " << Media(3,4) << endl;
    cout << "Media entre floats 3.0 e 4.0: " << Media(3.0,4.0) << endl;
    cout << "Media entre os CRs dos alunos a1 e a2  : " << Media(a1,a2) << endl;

    return 0;
}
