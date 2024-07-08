/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 3
*  Arquivo principal do exercicio 
*  Este e um arquivo que descreve os metodos da classe historico.
*/
#include "historico.hpp"

using namespace std;

vector<Disciplina> Historico::getListaDisciplinas(){ return disciplinas; }
int Historico::getNumMaxDisciplinas(){return maxDisciplinas;}

//Adiciona uma disciplina ao vector de disciplinas
int Historico::adicionarDisciplina(Disciplina disc){
    // Verificar se a disciplina já existe
    auto it = find(disciplinas.begin(), disciplinas.end(), disc);
    if (it != disciplinas.end()) {
        cout << "Disciplina com o mesmo nome ja existe." << endl;
        return -1;
    } else {
        disciplinas.push_back(disc);
        sort(disciplinas.begin(), disciplinas.end());
        cout << "Disciplina adicionada com sucesso." << endl;
        it = find(disciplinas.begin(), disciplinas.end(), disc);
        int indice = distance(disciplinas.begin(), it);
        return indice;
    }
}

//Remove uma disciplina do vector de disciplinas
int Historico::removerDisciplina(Disciplina& disc){
    // Verificar se a disciplina já existe
    int contador = 0;
    int indice = -1;
    for(Disciplina d : disciplinas){
        if(d == disc){
            indice = contador;
            break;
        }
        contador += 1;
        //cout << contador << ": contador. Nome:" << d.nome << ". Nome remover: "<< disc.nome <<endl;
    }
        if(indice == -1){ 
            cout << "Nao foi encontada disciplina com este nome. " << endl;
            return -1;
        }

        disciplinas.erase(disciplinas.begin() + indice);
        cout << "Disciplina removida com sucesso." << std::endl;
        return indice;
    }

//Busca todas as disciplinas que sao concluidas em um determinado periodo e retorna um vector com todas elas
vector<Disciplina> Historico::buscarDisciplinasPeloPeriodo(string periodo){
    vector<Disciplina> resultado; //Vector para guardar as disciplinas daquele periodo
    for(Disciplina disc : disciplinas){
        if(disc.periodoConclusao == periodo){
            resultado.push_back(disc);
        }
    }
    return resultado;
}

//Retorna a nota de uma determinada disciplina a partir do seu nome
double Historico::getNotaPeloNome(string nome){
    for (Disciplina& disc : disciplinas) {
        if (disc.nome == nome) {
            return disc.nota;
        }
    }
    // Se não encontrou a disciplina, retorna um valor inválido
    double notaInvalida = -1.0;
    return notaInvalida;
}

//Sobrecarga do operador << para Historico
ostream& operator<<(ostream& os, Historico hist){
    sort(hist.disciplinas.begin(), hist.disciplinas.end());
    for(Disciplina disc : hist.disciplinas){
        os << disc << endl;
    }
    return os;
}

//Sobrecarga do operador += para adicionar uma unica disciplina
int Historico::operator+=(Disciplina disc){
    return adicionarDisciplina(disc);
}

//Sobrecarga do operador += para adicionar um vector de disciplinas
int Historico::operator+=(vector<Disciplina> novasDisciplinas){

    int ultimoIndice = -1;
    for(Disciplina disc : novasDisciplinas){
        int indiceAtual = adicionarDisciplina(disc);

        if(indiceAtual != -1){
            ultimoIndice = indiceAtual;
        }
    }
    return ultimoIndice;
}

//Sobrecarga do operador -= para Historico
int Historico::operator-=(Disciplina disc){
    return removerDisciplina(disc);
}

//Sobrecarga do operador () para Historico
vector<Disciplina> Historico::operator()(string periodo){
    return buscarDisciplinasPeloPeriodo(periodo);
}

//Sobrecarga do operador [] para Historico
double& Historico::operator[](string& nome){
    for (Disciplina& disc : disciplinas) {
        if (disc.nome == nome) {
            return disc.nota;
        }
    }

    // Se não encontrou a disciplina, retorna -1
    static double notaInvalida = -1.0;
    return notaInvalida;
}

// Sobrecarga do operador >> para calculo do CRA do Historico
double& Historico::operator>>(double& cra){
//cout << "Quantidade disciplinas: " << disciplinas.size();
    if (disciplinas.empty()) {
        cra = 0.0;
    }

    else {
        double somaPonderada = 0.0;
        int totalCreditos = 0;
        for (const Disciplina& disc : disciplinas) {
            somaPonderada += disc.nota * disc.creditos;
            totalCreditos += disc.creditos;
        }
        cra = somaPonderada / totalCreditos;
    }

    cout << fixed << setprecision(2);
    cout << "O CRA e: " << cra << ". " << endl;
    return cra;
}

void Historico::carregarDisciplinas(){
    ifstream file("historico.txt");
    if(file.is_open()){
        string linha;
        while(getline(file, linha)){
            istringstream stream(linha);
            Disciplina disc;
            string nome, periodo, creditos, nota;
            // Lendo cada campo da linha
            getline(stream, nome, ','); // Nome da disciplina
            getline(stream, periodo, ','); // Periodo de conclusao
            getline(stream, creditos, ','); // Numero de creditos
            getline(stream, nota, ';'); // Nota final (terminada com ;)
            
            //Realizando trim para tirar quaisquer caracteres(espacos no final ou no comeco, \n e etc) da palavra
            disc.nome = disc.trim(nome);
            disc.periodoConclusao = disc.trim(periodo);
            creditos = disc.trim(creditos);
            nota = disc.trim(nota);

            // Convertendo strings para os tipos apropriados
            disc.creditos = stoi(creditos);
            disc.nota = stod(nota);

            // Adicionando a disciplina ao vetor
            disciplinas.push_back(disc);
        }
        file.close();
    }
}

void Historico::salvarDisciplinas(){
    ofstream file("historico.txt");
    if(file.is_open()){
        for(Disciplina disc : disciplinas){
            file << disc.nome << ", " << disc.periodoConclusao << ", " << disc.creditos << ", " << disc.nota << ";\n";
        }
        file.close();
    }
}
