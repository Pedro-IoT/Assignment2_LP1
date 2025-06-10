#include <iostream>
#include <string>
#include "cadastro.h"
using namespace std;

int main(){
    const int MAX = 10;
    Funcionario* funcionarios[MAX] = {0};       //Inicializa o vetor de funcionários como vazio
    int qtd = 0;                                // Conta quantos funcionários foram cadastrados
    do{
        cout << "Cadastro de funcionario (" << qtd+1 << " de " << MAX << "):\n";
        cout << "1 - Desenvolvedor\n";
        cout << "2 - Gerente\n";                       // "Menu" para o cadastro 
        cout << "3 - Estagiário\n";
        cout << "Escolha o tipo de funcionario: ";
        int opcao;
        cin >> opcao;

        string nome;
        int id;
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);                        // Pega todas as informações que são comuns aos funcionários
        cout << "ID: ";
        cin >> id;
        float salario;
        cout << "Salario base: ";
        cin >> salario;
        
        switch (opcao){                        // Switch para fazer a diferenciação de cada funcionário
            case 1: {
                int projetos;
                cout << "Quantidade de projetos: ";
                cin >> projetos;
                funcionarios[qtd] = new Desenvolvedor(projetos);    // Adiciona um dev no vetor de funcionários
                funcionarios[qtd]->setId(id);
                funcionarios[qtd]->setNome(nome);
                funcionarios[qtd]->setSalarioBase(salario);        // Logo depois atribui todas as informações necessárias ao dev
                funcionarios[qtd]->calcularSalarioFinal();
                break;
            }
            case 2: {
                int bonus;
                cout << "Bônus mensal: ";
                cin >> bonus;
                funcionarios[qtd] = new Gerente(bonus);             // Adiciona um gerente no vetor de funcionários
                funcionarios[qtd]->setId(id);
                funcionarios[qtd]->setNome(nome);
                funcionarios[qtd]->setSalarioBase(salario);         // Logo depois atribui todas as informações necessarias ao gerente
                funcionarios[qtd]->calcularSalarioFinal();
                break;
            }
            case 3: {
                int horas;
                cout << "Horas trabalhadas: ";
                cin >> horas;
                funcionarios[qtd] = new Estagiario(horas);             // Adiciona um estagiário no vetor de funcionários
                funcionarios[qtd]->setId(id);
                funcionarios[qtd]->setNome(nome);
                funcionarios[qtd]->setSalarioBase(salario);          // Logo depois atribui todas as informações necessarias ao estagiário
                funcionarios[qtd]->calcularSalarioFinal();
                break;
            }
            default:
                cout << "Opcao invalida. Tente novamente.\n";       // Caso o "menu" não seja usado corretamente
                continue;
        }

        qtd++;

        if (qtd < MAX) {
            char resp;
            cout << "Deseja cadastrar outro funcionario? (s/n): ";  // Verifica se há o desejo de cadastrar um novo funcionário
            cin >> resp;
            if (resp == 'n' || resp == 'N') {
                break;
            }
        }
    } while (qtd < MAX);                                        // Para o cadastro se o vetor estiver cheio

    cout << "\n---- Relatorio de funcionarios ----\n";
    for (int i = 0; i < qtd; ++i) {
        funcionarios[i]->exibirInformacoes();                   // Após o cadastro imprime as informações 
        cout << endl;
    }

    return 0;
}
