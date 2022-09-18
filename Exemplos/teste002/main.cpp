/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matem�tica
 * DMA  - Departamento de Matem�tica Aplicada
 *
 *   MAE015 - T�picos em Engenharia de Dados A
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 02  : Introdu��o a linguagem C/C++
 *   Exemplo 002: Estruturas de Dados primitivas
 *
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data cria��o  : 08 de setembro de 2022
 *   Data altera��o: 08 de setembro de 2022
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
	public:

		t_DRE	DRE;
		string	Nome;
		double	CR;

		// Area de algoritmos: m�todos do objeto
		void	Cadastro(t_DRE pDRE, string pNome, double pCR = 0)
		{
			DRE = pDRE;
			Nome = pNome;
			CR = pCR;
		}

		void	Print(void)
		{
			cout << "+-------------------+" << endl;
			cout << "| Registro de Aluno |" << endl;
			cout << "+-------------------+" << endl;
			cout << "| DRE : " << DRE << endl;
			cout << "| Nome: " << Nome << endl;
			cout << "| CR  : " << CR << endl;
			cout << "+-------------------+" << endl;
		}

		// operador polimorfo
		double	operator+(t_Aluno B)
		{
			return (CR + B.CR);
		}

};

class t_Curso
{
	private:

		string			Codigo_Curso;
		string			Nome_Curso;
		double			Nota;
		unsigned int	Num_Alunos;
		t_Aluno			Lista_De_Alunos[500];

	public:

		void	Cadastro(string pCodigo_Curso, string pNome_Curso, double pNota,
							unsigned int pNum_Alunos, t_Aluno* pLista_De_Alunos)
		{
			Codigo_Curso = pCodigo_Curso;
			Nome_Curso   = pNome_Curso;
			Nota = pNota;
			Num_Alunos   = pNum_Alunos;
			for (int i = 0; i < Num_Alunos; i++) {
				Lista_De_Alunos[i] = pLista_De_Alunos[i];
			}
		}

		void	Print(void)
		{
			cout << "   _____                     " << endl;
			cout << "  / ____|                    " << endl;
			cout << " | |    _   _ _ __ ___  ___  " << endl;
			cout << " | |   | | | | '__/ __|/ _ \\ " << endl;
			cout << " | |___| |_| | |  \\__ \\ (_) |" << endl;
			cout << "  \\_____\\__,_|_|  |___/\\___/ " << endl;
			cout << "                             " << endl;
			cout << endl;
			cout << "Nome do Curso:    " << Nome_Curso << endl;
			cout << "Código do curso:  " << Codigo_Curso << endl;
			cout << "Nota de curso:    " << Nota << endl;
			cout << "Alunos no curso:  " << endl;
			for (int i = 0; i < Num_Alunos; i++) {
				cout << "- " << Lista_De_Alunos[i].Nome << endl;
			}
		}

		double	operator+(t_Curso curso2)
		{
			return Nota + curso2.Nota;
		}
};

/*--------------------------------------------------------------
 * Area de cria��o de fun��es polimorfas: templates
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
	t_Aluno	a1, a2 , a3, a4, a5 ;
	t_Curso	Matematica_Aplicada;
	t_Curso	Engenharia_Matematica;

	a1.Cadastro(119313142,"Ruan felipe da silva e sousa",7.8);
	a2.Cadastro(120999109,"Matheus moreira do nascimento",8.9);
	a3.Cadastro(120994515,"Felipe Patitucci", 9.3);
	a4.Cadastro(120999313,"Pedro Wong", 9.6);
	a5.Cadastro(119884322,"Igor Torres", 8.2);

	t_Aluno Alunos1[] = {a1,a2,a5};
	t_Aluno Alunos2[] = {a3,a4};

	Matematica_Aplicada.Cadastro("3101050000", "Matemática Aplicada", 3.6, 3, Alunos1);
	Engenharia_Matematica.Cadastro("3101080000", "Engenharia Matemática ", 5.4, 2, Alunos2);

	cout << "Calculando Medias" << endl;
	cout << "Media entre os dois cursos: ";
	cout << Media(Matematica_Aplicada,Engenharia_Matematica) << endl;
	cout << endl;
	cout << endl;

	Matematica_Aplicada.Print();
	cout << endl;
	Engenharia_Matematica.Print();

	return 0;
}
