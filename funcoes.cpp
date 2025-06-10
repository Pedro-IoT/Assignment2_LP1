#include <iostream>
#include <string>
#include "cadastro.h"
using namespace std;

Funcionario::Funcionario(){
    this -> nome = "sem nome";                  // Atribui valores padrões que seram substituídos logo depois
    this -> salarioBase = 0;
    this -> id = 000;
}

void Funcionario::setNome(string name){
    this -> nome = name;
}

string Funcionario::getNome(){
    return this -> nome;
}

void Funcionario::setSalarioBase(float salary){
    this -> salarioBase = salary;
}

float Funcionario::getSalarioBase(){
    return this -> salarioBase;
}

void Funcionario::setId(int id){
    this -> id = id;
}

int Funcionario::getId(){
    return this -> id;
}

void Funcionario::exibirInformacoes(){              // Define o método virtual com as informações da classe base
    cout << "id: " << getId() << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "Salário base: " << getSalarioBase() << endl;
}

Desenvolvedor::Desenvolvedor(int projetos){         // "Constrói" a classe dev já atribuindo a quantidade de projetos 
    this -> quantidadeDeProjetos = projetos;
}

float Desenvolvedor::calcularSalarioFinal(){       // Calcula o salário com base na fórmula do slide
    float salario = this -> salarioBase;           // Assim como, define o método virtual puro vindo da herença
    int projects = this -> quantidadeDeProjetos;
    salario = salario + (500 * projects);
    this -> salarioFinal = salario;               // Atribui ao atributo salario final
    return salario;
}

void Desenvolvedor::exibirInformacoes(){          // sobre-escreve o método virtual com as novas informações específicas da classe
    cout << "id: " << getId() << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "Tipo: Desenvolvedor" << endl;
    cout << "Projetos: " << this -> quantidadeDeProjetos << endl;
    cout << "Salário base: " << getSalarioBase() << endl;
    cout << "Salário final: " << this -> salarioFinal << endl;
}

Gerente::Gerente(float bonus){                  // Na classe gerente tem a mesma lógica da classe dev porém troca a fórmula de cálculo do salário final
    this -> BonusMensal = bonus;
}

float Gerente::calcularSalarioFinal(){
    float salario = this -> salarioBase;
    float bonus = this -> BonusMensal;
    salario += bonus;
    this -> salarioFinal = salario;
    return salario;
}

void Gerente::exibirInformacoes(){
    cout << "id: " << getId() << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "Tipo: Gerente" << endl;
    cout << "Bônus: " << this -> BonusMensal << endl;
    cout << "Salário base: " << getSalarioBase() << endl;
    cout << "Salário final: " << this -> salarioFinal << endl;
}

Estagiario::Estagiario(int horas){                  // Na classe estagiário tem a mesma lógica da classe dev porém troca a fórmula de cálculo do salário final
    this -> horasTrabalhadas = horas;
}

float Estagiario::calcularSalarioFinal(){
    float salario = this -> salarioBase;
    float horas = this -> horasTrabalhadas;
    salario = salario * (horas / 160.0);
    this -> salarioFinal = salario;
    return salario;
}

void Estagiario::exibirInformacoes(){
    cout << "id: " << getId() << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "Tipo: Estagiário" << endl;
    cout << "Horas trabalhadas: " << this -> horasTrabalhadas << endl;
    cout << "Salário base: " << getSalarioBase() << endl;
    cout << "Salário final: " << this -> salarioFinal << endl;
}
