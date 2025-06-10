#ifndef CADASTRO_H
#define CADASTRO_H

#include <string>
using namespace std;
    
class Funcionario {
    protected:
        string nome;
        float salarioBase;
    
    private:
        int id;

    public:
        Funcionario();
        void setNome(string name);
        string getNome();
        void setSalarioBase(float salary);
        float getSalarioBase();
        void setId(int id);
        int getId();
        virtual void exibirInformacoes();
        virtual float calcularSalarioFinal() = 0;
};

class Desenvolvedor : public Funcionario {
    private:
        int quantidadeDeProjetos;
        float salarioFinal;
    
    public:
        Desenvolvedor(int projetos);
        float calcularSalarioFinal();
        void exibirInformacoes();
};

class Gerente : public Funcionario {
    private:
        float BonusMensal;
        float salarioFinal;

    public:
        Gerente(float bonus);
        float calcularSalarioFinal();
        void exibirInformacoes();
};

class Estagiario : public Funcionario {
    private:
        int horasTrabalhadas;
        float salarioFinal;

    public:
        Estagiario(int horas);
        float calcularSalarioFinal();
        void exibirInformacoes();
};

#endif
