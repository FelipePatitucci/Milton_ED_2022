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
#include <cmath>

using namespace std;

//___________________________________Utils______________________________________
int	Gera_Vetor(float vec[100])
{
	string	str;
	int		index;
	int		elementos = 0;

	getline(cin, str);
	index = 0;
	while (str[index]) {
		if (str[index] != '.' && str[index] != '-'
			&& str[index] != ' ' && !isdigit(str[index])) {
			cout << "\nCaracteres invalidos inseridos\n";
			cout << "      Operação abortada!\n" << endl;
			return (-1);
		}
		index++;
	}
	index = 0;
	while (str[index]) {
		if (str[index] != ' ') {
			if (elementos == 100) {
				cout << "\nNumero de elementos maior que a capacidade máxima\n";
				cout << "               Operação abortada!\n" << endl;
				return (-1);
			}
			elementos++;
			vec[0] = atof(str.substr(index).c_str());
			vec++;
			while (str[index] && str[index] != ' ')
				index++;
		} else {
			index++;
		}
	}
	return (elementos);
}

int	Coletar_Vetores(float vetor_1[100], float vetor_2[100])
{
	int dim_1;
	int dim_2;

	cout << "Digite os elementos do primeiro vetor: ";
	dim_1 = Gera_Vetor(vetor_1);
	if (dim_1 < 0)
		return (-1);

	cout << "Digite os elementos do segundo vetor: ";
	dim_2 = Gera_Vetor(vetor_2);
	if (dim_2 < 0)
		return (-1);

	if (dim_1 != dim_2) {
		cout << "\nA dimensão dos vetores são diferentes\n";
		cout << "   Primeiro: " << dim_1 << " | Segundo: " << dim_2 << "\n";
		cout << "         Operação abortada!\n" << endl;
		return (-1);
	}

	return (dim_1);
}
//___________________________________Utils______________________________________

void	Executa_Teste_Dependencia_Linear(void)
{
	float	vetor_1[100];
	float	vetor_2[100];
	float	escala;
	int		index;
	int		dim;

	cout << "\n******************************************" << endl;
	cout << "* executando teste de Dependencia Linear *" << endl;
	cout << "******************************************" << endl;

	dim = Coletar_Vetores(vetor_1, vetor_2);
	if (dim < 0)
		return ;

	cout << "Resultado: ";

	//Se os 2 vetores são nulos
	for (int i = 0; i < dim; i++) {
		escala += abs(vetor_2[i]) + abs(vetor_1[i]);
	}
	if (escala == 0) {
		cout << "São LD\n" << endl;
		return ;
	}

	//Caso em que somente o vetor 2 é nulo
	index = 0;
	while (index < dim && vetor_2[index] == 0) {
		index++;
	}
	if (index == dim) {
		cout << "São LI\n" << endl;
		return ;
	}

	//Caso em que vetor_1[index] = 0
	escala = vetor_1[index] / vetor_2[index];
	if (escala == 0) {
		cout << "São LI\n" << endl;
		return ;
	}

	//Verificação de fato
	for (int i = 0; i < dim; i++) {
		if (abs(escala * vetor_2[i] - vetor_1[i]) > 1e-6) {
			cout << "São LI\n" << endl;
			return ;
		}
	}
	cout << "São LD\n" << endl;
}

void	Executa_Norma_2(void)
{
	float vetor_1[100];
	float soma = 0;
	int dim_1;

	cout << "\n*********************************" << endl;
	cout << "* executando a Norma 2 do Vetor *" << endl;
	cout << "*********************************" << endl;

	cout << "Digite os elementos do primeiro vetor: ";
	dim_1 = Gera_Vetor(vetor_1);
	if (dim_1 < 0)
		return ;

	cout << "Resultado: ";
	for (int i = 0; i < dim_1; i++) {
		soma += vetor_1[i] * vetor_1[i];
	}
	cout << sqrt(soma) << "\n" << endl;
}

void	Executa_Produto_Interno(void)
{
	float	vetor_1[100];
	float	vetor_2[100];
	float	soma = 0;
	int		dim;

	cout << "\n********************************" << endl;
	cout << "* executando o Produto Interno *" << endl;
	cout << "********************************" << endl;

	dim = Coletar_Vetores(vetor_1, vetor_2);
	if (dim < 0)
		return ;

	cout << "Resultado: ";
	for (int i = 0; i < dim; i++) {
		soma += vetor_1[i] * vetor_2[i];
	}
	cout << soma << "\n" << endl;
}

void	Executa_Combinacao_Linear(void)
{
	string	str;
	float	vetor_1[100];
	float	vetor_2[100];
	float	primeiro;
	float	segundo;
	int		dim;

	cout << "\n**********************************" << endl;
	cout << "* executando a Combinacao Linear *" << endl;
	cout << "**********************************" << endl;

	dim = Coletar_Vetores(vetor_1, vetor_2);
	if (dim < 0)
		return ;

	cout << "Digite o valor que multiplica o primeiro vetor: ";
	getline(cin, str);
	primeiro = atof(str.c_str());

	cout << "Digite o valor que multiplica o segundo vetor: ";
	getline(cin, str);
	segundo = atof(str.c_str());

	cout << "Resultado: (";
	for (int i = 0; i < dim; i++) {
		cout << primeiro * vetor_1[i] + segundo * vetor_2[i] ;
		cout << (i == dim - 1 ? ")\n" : ", ");
	}
	cout << endl;
}

void	Executa_Multiplicacao_Escalar(void)
{
	string	str;
	float	vetor_1[100];
	float	escalar;
	int		dim_1;

	cout << "\n******************************************" << endl;
	cout << "* executando a Multiplicacao por Escalar *" << endl;
	cout << "******************************************" << endl;

	cout << "Digite os elementos do primeiro vetor: ";
	dim_1 = Gera_Vetor(vetor_1);
	if (dim_1 < 0)
		return ;

	cout << "Digite o escalar pelo qual deseja multiplicar o vetor: ";
	getline(cin, str);
	escalar = atof(str.c_str());

	cout << "Resultado: (";
	for (int i = 0; i < dim_1; i++) {
		cout << vetor_1[i] * escalar;
		cout << (i == dim_1 - 1 ? ")\n" : ", ");
	}
	cout << endl;
}

void	Executa_Soma_Vetorial(void)
{
	float	vetor_1[100];
	float	vetor_2[100];
	int		dim;

	cout << "\n******************************" << endl;
	cout << "* executando a Soma Vetorial *" << endl;
	cout << "******************************" << endl;

	dim = Coletar_Vetores(vetor_1, vetor_2);
	if (dim < 0)
		return ;

	cout << "Resultado: (";
	for (int i = 0; i < dim; i++) {
		cout << vetor_1[i] + vetor_2[i];
		cout << (i == dim - 1 ? ")\n" : ", ");
	}
	cout << endl;
}

void	Apresenta_texto_menu(void)
{
	cout << "+----------------------------------+" << endl;
	cout << "\t1 - Executar a Soma Vetorial" << endl;
	cout << "\t2 - Executar a Multiplicacao por Escalar" << endl;
	cout << "\t3 - Executar a Combinacao Linear" << endl;
	cout << "\t4 - Executar o Produto Interno" << endl;
	cout << "\t5 - Executar a Norma 2" << endl;
	cout << "\t6 - Executar o Teste de Dependencia Linear" << endl;
	cout << "+----------------------------------+" << endl;
	cout << "+ aperte a tecla 's' para sair" << endl;
	cout << "+----------------------------------+" << endl;
}

void	Menu(void)
{
	string opcao_escolhida;

	do {
		Apresenta_texto_menu();
		getline(cin, opcao_escolhida);
		switch (opcao_escolhida[0]) {
			case '1' : Executa_Soma_Vetorial(); break;
			case '2' : Executa_Multiplicacao_Escalar(); break;
			case '3' : Executa_Combinacao_Linear(); break;
			case '4' : Executa_Produto_Interno(); break;
			case '5' : Executa_Norma_2(); break;
			case '6' : Executa_Teste_Dependencia_Linear(); break;
			case 's' : break;
			default  : cout << "Opcao invalida, tente novamente, ou 's' para sair" << endl;
		}
	} while (opcao_escolhida[0] != 's');
}

int	main()
{
	cout << "Exemplo 001: Menu de Opcoes simples " << endl;
	Menu();

	return 0;
}
