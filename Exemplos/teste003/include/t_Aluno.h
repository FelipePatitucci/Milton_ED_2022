#ifndef T_ALUNO_H
#define T_ALUNO_H

#include <t_Pessoa.h>
#include <string>

using namespace std;
typedef unsigned long int t_DRE;

class t_Aluno : public t_Pessoa
{
    public:
        t_Aluno();
        virtual ~t_Aluno();
        void Cadastra(t_CPF pCPF, string pNome);
        void Print(void);

    protected:

    private:
        t_DRE   DRE;
        double  CR;
};

#endif // T_ALUNO_H
