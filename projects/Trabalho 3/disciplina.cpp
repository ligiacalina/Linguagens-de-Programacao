/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 3
*  Arquivo principal do exercicio 
*  Este e um arquivo que descreve os metodos da struct disciplina.
*/
#include "disciplina.hpp"

    string Disciplina::trim(const string &str) {
        size_t first = str.find_first_not_of(" \t\n\r");
        if (first == string::npos) return "";

        // Retorna uma substring da string original, começando pelo primeiro caractere não 
        // branco e indo até o último caractere não branco.
        size_t last = str.find_last_not_of(" \t\n\r");
        return str.substr(first, last - first + 1);
    }

    //Sobrecarga do operador << para Disciplina
    ostream& operator<<(ostream& os, Disciplina disc){
        os << "Nome: " << disc.nome
           << ", Periodo: " << disc.periodoConclusao
           << ", Creditos: " << disc.creditos
           << ", Nota Final: " << disc.nota << ".";
        return os;
    }

    // Sobrecarga do operador >> para Disciplina
    istream& operator>>(istream& is, Disciplina& disc) {
        cout << "Digite o nome da disciplina: ";
        is >> ws;
        getline(is, disc.nome);
        disc.nome = disc.trim(disc.nome);

        cout << "Digite o periodo de conclusao (ex.: 2024.2): ";
        is >> disc.periodoConclusao;
        disc.periodoConclusao = disc.trim(disc.periodoConclusao);

        cout << "Digite o numero de creditos: ";
        is >> disc.creditos;

        cout << "Digite a nota final: ";
        is >> disc.nota;

        return is;
    }

    //Sobrecarga do operador == para Disciplina
    bool Disciplina::operator==(const Disciplina& disc)const{
        return nome == disc.nome;
    }
    
    //Sobrecarga do operador < para Disciplina
    bool Disciplina::operator<(Disciplina disc){
        if(periodoConclusao != disc.periodoConclusao){
            return (periodoConclusao < disc.periodoConclusao);
        }
        return nome < disc.nome;
    }

