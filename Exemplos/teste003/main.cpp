/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matemática
 * DMA  - Departamento de Matemática Aplicada
 *
 *   MAE015 - Tópicos em Engenharia de Dados A
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 03  : Introdução a linguagem C/C++
 *   Exemplo 003: Herança, Hierarquia de Classes, Ponteiros e Iteradores
 *
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 13 de setembro de 2022
 *   Data alteração: 13 de setembro de 2022
 *
 *--------------------------------------------------------------
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "+---------------------------------------------------------------------+" << endl;
    cout << "| Exemplo 003: Herança, Hierarquia de Classes, Ponteiros e Iteradores |" << endl;
    cout << "+---------------------------------------------------------------------+" << endl << endl;

    std::vector<char> vect;
    vect.push_back( 'a' ); vect.push_back( 'b' );

    for( auto &it : vect ) {
        std::cout << it << '\n';
    }

    return 0;
}
