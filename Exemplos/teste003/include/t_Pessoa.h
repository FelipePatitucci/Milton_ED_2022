#ifndef T_PESSOA_H
#define T_PESSOA_H

#include <string>
using namespace std;

typedef unsigned long int t_CPF;

class t_Pessoa
{
    public:
        t_Pessoa();
        virtual ~t_Pessoa();
        void Cadastra(t_CPF pCPF, string pNome);
        void Print(void);

    protected:

    private:
        t_CPF   CPF;
        string  Nome;
};

#endif // T_PESSOA_H
