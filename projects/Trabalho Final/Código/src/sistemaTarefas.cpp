/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Final
*  Implementação das funcionalidades de gerenciamento de tarefas.
*/

#ifndef SISTEMATAREFAS_CPP
#define SISTEMATAREFAS_CPP

#include "sistemaTarefas.hpp"

using namespace std;
namespace py = pybind11;

void SistemaTarefas::carregarTarefas(string arquivo, string tipo){
    ifstream file(arquivo);
    if (!file) {
        cout << "Nao foi possivel abrir o arquivo." << endl;
        return;
    }

    string linha;
    while (getline(file, linha)) {
        stringstream ss(linha);
        string acao;
        int urgencia, recorrencia;
        getline(ss, acao, ',');
        ss >> urgencia;
        ss.ignore(); // Ignorar a vírgula
        ss >> recorrencia;
        ss.ignore(); // Ignorar o ponto e vírgula

        Tarefa tarefa(acao, urgencia, recorrencia);
        if(tipo == "a fazer"){tarefas.push_back(tarefa);
        }else{tarefasConcluidas.push_back(tarefa);}

    }
    file.close();

    sort(tarefas.begin(), tarefas.end(), compareTarefas);
    sort(tarefasConcluidas.begin(), tarefasConcluidas.end(), compareTarefas);
}

void SistemaTarefas::listarTarefas(){
    cout << endl << "------------------Lista de Tarefas------------------" << endl << endl;
    int contador = 1;
    for (Tarefa tarefa : tarefas) {
        cout << contador << ") " << tarefa.getAcao() << ", Urgencia: " << tarefa.getUrgencia() << ", Recorrencia: " << tarefa.getRecorrencia() << endl;
        contador++;
    }
    cout << endl << "----------------------------------------------------" << endl;
}

void SistemaTarefas::adicionarTarefa(){
    string acao;
    int urgencia, recorrencia;

    cout << "Digite a acao da tarefa: ";
    cin >> ws;
    getline(cin, acao);
    // Remover todos os \n e \r da string
    acao.erase(remove_if(acao.begin(), acao.end(), [](char c) { return c == '\r' || c == '\n'; }), acao.end());

    cout << "Digite o indice de urgencia (1: baixa, 2: media, 3: alta, ou qualquer outro numero para sem urgencia): ";
    cin >> urgencia;
    cin.ignore();
    cout << "Digite o indice de recorrencia (1: diaria, 2: semanal, 3: mensal, ou qualquer outro numero para sem recorrencia): ";
    cin >> recorrencia;
    cin.ignore();

    Tarefa novaTarefa(acao, urgencia, recorrencia);
    tarefas.push_back(novaTarefa);
    sort(tarefas.begin(), tarefas.end(), compareTarefas);

    // Salvar a nova tarefa no arquivo
    ofstream file("tarefas.txt", ios::app);
    if (file.is_open()) {
        file << acao << "," << urgencia << "," << recorrencia << ";\n";
        file.close();
        cout << "Tarefa adicionada com sucesso." << endl;
    } else {
        cout << "Nao foi possivel abrir o arquivo para salvar a tarefa." << endl;
    }
}

void SistemaTarefas::removerTarefa(unsigned int indice){
    if (indice < 1 || indice > tarefas.size()) {
        cout << "Indice de tarefa invalido." << endl;
        return;
    }

    // Remover a tarefa da lista
    tarefas.erase(tarefas.begin() + indice - 1);

    // Atualizar o arquivo de tarefas
    ofstream file("tarefas_temp.txt");
    if (file.is_open()) {
        for (Tarefa tarefa : tarefas) {
            file << tarefa.getAcao() << "," << tarefa.getIndiceUrgencia(tarefa.getUrgencia()) << "," << tarefa.getIndiceRecorrencia(tarefa.getRecorrencia()) << ";\n";
        }
        file.close();
        remove("tarefas.txt");
        rename("tarefas_temp.txt", "tarefas.txt");
        cout << "Tarefa removida da lista de afazeres com sucesso." << endl;
    } else {
        cout << "Nao foi possivel abrir o arquivo para atualizar as tarefas." << endl;
    }
}

void SistemaTarefas::concluirTarefa(unsigned int indice){
    if (indice < 1 || indice > tarefas.size()) {
        cout << "Indice de tarefa invalido." << endl;
        return;
    }

    // Mover a tarefa para o vetor de tarefas concluídas
    Tarefa tarefaConcluida = tarefas[indice - 1];
    tarefasConcluidas.push_back(tarefaConcluida);

    // Atualizar o arquivo de tarefas concluídas
    ofstream file("tarefasConcluidas.txt", ios::app);
    if (file.is_open()) {
        file << tarefaConcluida.getAcao() << "," << tarefaConcluida.getIndiceUrgencia(tarefaConcluida.getUrgencia()) << "," << tarefaConcluida.getIndiceRecorrencia(tarefaConcluida.getRecorrencia()) << ";\n";
        file.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo de tarefas concluidas para adicionar a tarefa." << endl;
    }

    // Chamar a função removerTarefa para remover do arquivo tarefas.txt
    removerTarefa(indice);

    cout << "Tarefa concluida e movida para o arquivo de tarefas concluidas." << endl;
}

void SistemaTarefas::listarTarefasConcluidas(){

    cout << endl << "------------------Lista de Tarefas------------------" << endl << endl;
    int contador = 1;
    for (Tarefa tarefa : tarefasConcluidas) {
        cout << contador << ") " << tarefa.getAcao() << ", Urgencia: " << tarefa.getUrgencia() << ", Recorrencia: " << tarefa.getRecorrencia() << endl;
        contador++;
    }
    cout << endl << "----------------------------------------------------" << endl;
}

void SistemaTarefas::analisarTarefa(unsigned int indice){
        vector<string> resultado = chamarScriptPython(indice);

        if (!resultado.empty()) {
            string conteudo = resultado[0];
            int contagemPalavras = stoi(resultado[1]);
            string palavrasChave = resultado[2];

            // Exibir os resultados
            cout << "Descricao da tarefa: " << conteudo << endl;
            cout << "Contagem de palavras: " << contagemPalavras << endl;
            cout << "Palavras-chave: " << palavrasChave << endl;
        }
}

void SistemaTarefas::editarTarefa(unsigned int indice){
    if (indice < 1 || indice > tarefas.size()) {
        cout << "Indice de tarefa invalido." << endl;
        return;
    }

    Tarefa& tarefa = tarefas[indice - 1];

    int indiceEdicao;
    cout << "1) Acao" << endl << "2) Urgencia" << endl << "3) Recorrencia" << endl
        << "Digite o indice referente ao que deseja editar na tarefa: ";
    cin >> indiceEdicao;
    cin.ignore(); // Ignorar o newline do input

    if (indiceEdicao == 1) {
        string novaAcao;
        cout << "Digite a nova acao: ";
        cin >> ws;
        getline(cin, novaAcao);
        // Remover todos os \n e \r da string
        novaAcao.erase(remove_if(novaAcao.begin(), novaAcao.end(), [](char c) { return c == '\r' || c == '\n'; }), novaAcao.end());
    } else if (indiceEdicao == 2) {
        int novaUrgencia;
        cout << "Digite o indice de urgencia (1: baixa, 2: media, 3: alta, ou qualquer outro numero para sem urgencia): ";
        cin >> novaUrgencia;
        tarefa.setUrgencia(novaUrgencia);
    } else if (indiceEdicao == 3) {
        int novaRecorrencia;
        cout << "Digite o indice de recorrencia (1: diaria, 2: semanal, 3: mensal, ou qualquer outro numero para sem recorrencia): ";
        cin >> novaRecorrencia;
        tarefa.setRecorrencia(novaRecorrencia);
    } else {
        cout << "Indice invalido. Nao foi possivel editar tarefa." << endl;
        return;
    }

    sort(tarefas.begin(), tarefas.end(), compareTarefas);

    // Atualizar o arquivo de tarefas
    ofstream file("tarefas_temp.txt");
    if (file.is_open()) {
        for (Tarefa t : tarefas) {
            file << t.getAcao() << "," << t.getIndiceUrgencia(t.getUrgencia()) << "," << t.getIndiceRecorrencia(t.getRecorrencia()) << ";\n";
        }
        file.close();
        remove("tarefas.txt");
        rename("tarefas_temp.txt", "tarefas.txt");
        cout << "Tarefa editada e arquivo atualizado com sucesso." << endl;
    } else {
        cout << "Nao foi possivel abrir o arquivo para atualizar as tarefas." << endl;
    }
}

void SistemaTarefas::listarTarefasUrgentes(){
    cout << endl << "------------------URGENTE------------------" << endl << endl;
    int contador = 1;
    for (Tarefa tarefa : tarefas) {
        if (tarefa.getIndiceUrgencia(tarefa.getUrgencia()) == 3) {
            cout << contador << ") " << tarefa.getAcao() << ", Urgencia: " << tarefa.getUrgencia() << ", Recorrencia: " << tarefa.getRecorrencia() << endl;
        }
        contador++;
    }
    cout << endl << "----------------------------------------------------" << endl;
}

void SistemaTarefas::exibirListaDeCompras(){
    vector<Tarefa> listaDeCompras;
    int indice = 1;
    for (Tarefa tarefa : tarefas) {
        vector<string> resultado = chamarScriptPython(indice);

        if (!resultado.empty()) {
            string palavrasChave = resultado[2];

            // Verificar se há a palavra "comprar" nas palavras-chave
            if (palavrasChave.find("comprar") != string::npos) {
                listaDeCompras.push_back(tarefa);
            }else if(palavrasChave.find("Comprar") != string::npos) {
                listaDeCompras.push_back(tarefa);
            }
            indice++;
        }

    }

    if (listaDeCompras.empty()) {
        cout << "Nao ha itens na lista de compras." << endl;
    } else {
        int contador = 1;
        cout << "-------------------COMPRAS-------------------" << endl;
        for (Tarefa compra : listaDeCompras) {
            cout << contador << ") " << compra.getAcao() << ", Urgencia: " << compra.getUrgencia() << ", Recorrencia: " << compra.getRecorrencia() << endl;
            contador++;
        }
        cout << "---------------------------------------------" << endl;
    }
}

vector<string> SistemaTarefas::chamarScriptPython(unsigned int indice) {
    vector<string> resultado;
    py::initialize_interpreter();
    if (indice < 1 || indice > tarefas.size()) {
        cout << "Indice de tarefa invalido." << endl;
        return resultado;
    }

    string conteudoTarefa = tarefas[indice - 1].getAcao();

    try {
        py::module_ script = py::module_::import("analisarTarefa");
        auto contar_palavras_func = script.attr("contar_palavras");
        auto identificar_palavras_chave_func = script.attr("identificar_palavras_chave");

        int contagemPalavras = contar_palavras_func(conteudoTarefa).cast<int>();
        
        // Usar reinterpret_borrow para garantir que estamos lidando com um objeto Python
        py::list py_palavras_chave = identificar_palavras_chave_func(conteudoTarefa).cast<py::list>();
        vector<string> palavrasChave;
        
        // Converter a lista Python para um vetor de strings C++
        for (unsigned int i = 0; i < py_palavras_chave.size(); ++i) {
            palavrasChave.push_back(py_palavras_chave[i].cast<string>());
        }

        resultado.push_back(conteudoTarefa);
        resultado.push_back(to_string(contagemPalavras));
        resultado.push_back(juntarPalavrasChave(palavrasChave, ' '));
    } catch (const py::cast_error& e) {
        cerr << "Erro de casting ao chamar o script Python: " << e.what() << endl;
    } catch (const py::error_already_set& e) {
        cerr << "Erro ao chamar o script Python: " << e.what() << endl;
    }
    py::finalize_interpreter();
    return resultado;
}

string SistemaTarefas::juntarPalavrasChave(vector<string> vector, char delimitador){
    stringstream ss;
    for (unsigned int i = 0; i < vector.size(); ++i) {
        if (i != 0) ss << delimitador;
        ss << vector[i];
    }
    return ss.str();
}

bool SistemaTarefas::compareTarefas(Tarefa tarefaA, Tarefa tarefaB){
    return tarefaA.getIndiceUrgencia(tarefaA.getUrgencia()) > tarefaB.getIndiceUrgencia(tarefaB.getUrgencia());
}

#endif // SISTEMATAREFAS_CPP