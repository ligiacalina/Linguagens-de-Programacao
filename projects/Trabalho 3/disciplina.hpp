/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 3
*  Arquivo principal do exercicio 
*  Este e um arquivo de header para a struct disciplina, o qual possui todas as assinaturas dos metodos da classe, 
*  assim como as variaveis principais.
*/

#include <iostream>
#include <string>

using namespace std;

struct Disciplina{
    string nome;
    string periodoConclusao;
    int creditos;
    double nota;

    string trim(const string &str);

    //Sobrecarga do operador << para Disciplina
    friend ostream& operator<<(ostream& os, Disciplina disc);

    // Sobrecarga do operador >> para Disciplina
    friend istream& operator>>(istream& is, Disciplina& disc);

    //Sobrecarga do operaador == para Disciplina
    bool operator==(const Disciplina& disc)const;

    //Sobrecarga do operador < para Disciplina
    bool operator<(Disciplina disc);

};
