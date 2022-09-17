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
#include <cstring>   

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
    double nota;
    unsigned int  num_alunos;

	public:
    void Cadastro(string Codigo, string Nome, t_Aluno* Alunos, double n_nota, unsigned int num_aluno){
    
    Codigo_Curso = Codigo;
    Nome_Curso   = Nome; 
    num_alunos   = num_aluno;
    for (int i = 0; i < num_alunos; i++){
    lista_de_alunos[i] = Alunos[i];
    }
    nota = n_nota;
    }
    void Print(void){
    cout<< "   _____                     "<< endl;
    cout<< "  / ____|                    "<< endl;
    cout<< " | |    _   _ _ __ ___  ___  "<< endl;
    cout<< " | |   | | | | '__/ __|/ _ \\ "<< endl;
    cout<< " | |___| |_| | |  \\__ \\ (_) |"<< endl;
    cout<< "  \\_____\\__,_|_|  |___/\\___/ "<< endl;
    cout<< "                             "<< endl;
    printf("\n");
    cout << "Nome:  "           << Nome_Curso << endl;
    cout << "Código do curso: " << Codigo_Curso << endl;
    cout << "Nota de curso:   " << nota << endl; 
    cout << "Alunos no curso :" << endl;
    for (int i = 0; i < num_alunos; i++ ){ 
	 cout << "- " << lista_de_alunos[i].Nome << endl;
    }
    }
    
    double operator +(t_Curso curso2){
    return nota + curso2.nota;
    }

    
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
    t_Aluno a1, a2 , a3, a4, a5 ;
    t_Curso Matematica_Aplicada, Engenharia_Matematica;

    a1.Cadastro(119313142,"Ruan felipe da silva e sousa",7.8);
    a2.Cadastro(120999109,"Matheus moreira do nascimento",8.9);
    a3.Cadastro(120994515,"Felipe Patitucci", 9.3);
    a4.Cadastro(120999313,"Pedro Wong", 9.6);
    a5.Cadastro(119884322,"Igor Torres", 8.2);

    t_Aluno Alunos1[] = {a1,a2,a5};
    t_Aluno Alunos2[] = {a3,a4};
    Matematica_Aplicada.Cadastro("3101050000", "Matemática Aplicada",Alunos1 , 3.6, 3);
    Engenharia_Matematica.Cadastro("3101080000", "Engenharia Matemática ",Alunos2 , 5.4,2);

    cout << "Calculando Medias" << endl;
    cout << "Media entre os dois cursos  : " << Media(Matematica_Aplicada,Engenharia_Matematica) << endl;
    Matematica_Aplicada.Print();
    printf("\n");
    Engenharia_Matematica.Print();
    return 0;
}
