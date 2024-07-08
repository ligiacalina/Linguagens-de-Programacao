/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 2
*  Arquivo auxiliar
*  Este e um arquivo auxiliar, no qual implemento as funcoes definidas no arquivo de cabecalho da classe grafo.
*/
#include "grafo.hpp"

vector<string> Grafo::getCidades(){return cidades;}
//Retorna o indice da cidade passada por argumento
int Grafo::getIndiceCidade(string cidade){
    int contador = 0;
    for(string c : cidades){
        if(c == cidade){
            return contador;
        }
    contador++;
    }
    return 0;
}

void Grafo::lerArquivo() {
    ifstream arquivo(arquivoTxt);
    if (!arquivo.is_open()) {
        cout << "Não foi possível abrir o arquivo. Tente novamente." << endl;
        return;
    }

    string linha;
    while (getline(arquivo, linha, ';')) {
        Aresta estrada = criarAresta(linha);
        estradas.push_back(estrada);
    }

    arquivo.close();
}

void Grafo::imprimirGrafo() {
    for (Aresta &aresta : estradas) {
        cout << aresta.getOrigem().getNomeDaCidade() << " -> "
            << aresta.getDestino().getNomeDaCidade() << ": "
            << aresta.getDistancia() << "km" << endl;
    }
}

int Grafo::imprimirDensidade() {
    int numCidades = cidades.size();
    int numEstradas = estradas.size();
    int numEstradasMaximas = (numCidades * (numCidades - 1)) / 2;
    if (numEstradasMaximas == 0){
        cout << "Nao foi possivel calcular a densidade do grafo dado." << endl;
        return 1;
    }
    double densidade = static_cast<double>(numEstradas) / numEstradasMaximas;

    cout << "Densidade do grafo: " << fixed << setprecision(2) << densidade << endl;
    return 0;
}

void Grafo::imprimirCidades(){
    int contador = 0;
    for(string cidade: cidades){
        cout << contador << " - " << cidade << endl;
        contador++;
    }
}

string Grafo::existeCidade(string& cidade) {
    for(string c : cidades){
        if(c == cidade){
            return "existe";
        }
    }
    return "nao existe";
}   

RetornosMultiplos Grafo::verticeMaiorCentralidade() {
    string verticeMax;
    double maxCentralidade = 0.0;

    for (string cidade : cidades) {
        double centralidade = 0.0;

        // Calcular a soma dos graus do vértice
        for (Aresta& estrada : estradas) {
            if (estrada.getOrigem().getNomeDaCidade() == cidade) {
                centralidade += estrada.getDistancia();
            }
            if (estrada.getDestino().getNomeDaCidade() == cidade) {
                centralidade += estrada.getDistancia();
            }
        }

        // Atualizar o vértice com a maior centralidade
        if (centralidade > maxCentralidade) {
            maxCentralidade = centralidade;
            verticeMax = cidade;
        }
    }
    RetornosMultiplos retorno;

    retorno.cidade = verticeMax;
    retorno.distancia = maxCentralidade;
    

    return retorno;
}

vector<double> Grafo::calcularDistanciaDestinoDijkstra(string origem, vector<double>& distancia, vector<string>& cidadesVizinhas, vector<bool>& cidadesVisitadas) {
    
    //calcula a distancia do algoritmo de dijstra
    int indiceOrigem = getIndiceCidade(origem);
    for (Aresta estrada : estradas) {
        if (origem == estrada.getOrigem().getNomeDaCidade()) {
            int indiceTemporario = getIndiceCidade(estrada.getDestino().getNomeDaCidade());
            if (!cidadesVisitadas[indiceTemporario]) {
                double novaDistancia = distancia[indiceOrigem] + estrada.getDistancia();
                if (novaDistancia < distancia[indiceTemporario]) {
                    distancia[indiceTemporario] = novaDistancia;
                    cidadesVizinhas[indiceTemporario] = origem;
                }
            }
        }
    }
    cidadesVisitadas[indiceOrigem] = true;
    return distancia;
}

void Grafo::imprimeMenorPercursoDuasCidades(int indiceOrigem, int indiceDestino) {
    string origem = cidades[indiceOrigem];
    string destino = cidades[indiceDestino];

    //garantindo que as listas estejam sem nenhuma informacao anterior
    vector<double> distancia(cidades.size(), INFINITO);
    vector<string> cidadesVizinhas(cidades.size());
    vector<bool> cidadesVisitadas(cidades.size(), false);

    distancia[indiceOrigem] = 0;

    //fila de prioridade para que as cidades que nao foram visitadas
    priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> fila;
    fila.push({ 0, origem });

    while (!fila.empty()) {
        string cidadeAtual = fila.top().second;//Pega a primeira cidade da fila de prioridade
        fila.pop();//e a retira logo em seguida, garantindo que so tenha cidades nao visitadas

        calcularDistanciaDestinoDijkstra(cidadeAtual, distancia, cidadesVizinhas, cidadesVisitadas);

        //iteracao para o algoritmo de dijkstra
        for (Aresta estrada : estradas) {
            if (cidadeAtual == estrada.getOrigem().getNomeDaCidade()) {
                string vizinho = estrada.getDestino().getNomeDaCidade();
                int indiceVizinho = getIndiceCidade(vizinho);
                if (!cidadesVisitadas[indiceVizinho]) {
                    fila.push({ distancia[indiceVizinho], vizinho });
                }
            }
        }
    }

    // Exibir a menor distância ou caminho
    if (distancia[indiceDestino] != INFINITO) {
        cout << "A menor distancia entre " << origem << " e " << destino << " e: " << distancia[indiceDestino] << " km" << endl;
        vector<string> caminho = reconstruirCaminho(indiceDestino, cidadesVizinhas);
        cout << "Caminho percorrido: ";

        //somente para que a seta nao seja exibida na cidade final
        unsigned int contador = 1;
        for (string cidade : caminho) {
            cout << cidade;
            if (contador < caminho.size()) {
                cout << " -> ";
            }
            contador++;
        }
        cout << endl;
    } else {
        cout << "Nao foi possível encontrar um caminho entre " << origem << " e " << destino << "." << endl;
    }
}

//funcao feita para printar o caminho feito ate o destino setado pelo usuario
vector<string> Grafo::reconstruirCaminho(int indiceDestino, vector<string>& cidadesVizinhas) {
    vector<string> caminho;
    for (string at = cidades[indiceDestino]; !at.empty(); at = cidadesVizinhas[getIndiceCidade(at)]) {
        caminho.push_back(at);
    }
    reverse(caminho.begin(), caminho.end());
    return caminho;
}

//algoritmo de dijkstra usado para o item 5 do trabalho
vector<double> Grafo::dijkstraParaTodasCidades(int indiceOrigem) {
    string origem = cidades[indiceOrigem];
    vector<double> distanciaLocal(cidades.size(), INFINITO);
    vector<bool> cidadesVisitadas(cidades.size(), false);
    distanciaLocal[indiceOrigem] = 0; // A cidade de origem tem distância zero até ela mesma

    //fila de prioridade para que as cidades que nao foram visitadas
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> fila;
    fila.push({0, indiceOrigem});

    while (!fila.empty()) {
        int cidadeAtual = fila.top().second;//Pega a primeira cidade da fila de prioridade
        fila.pop();//e a retira logo em seguida, garantindo que so tenha cidades nao visitadas

        if (cidadesVisitadas[cidadeAtual]) continue;
        cidadesVisitadas[cidadeAtual] = true;

        //realiza-se o algoritmo dijkstra
        for (Aresta& estrada : estradas) {
            int indiceVizinho;
            double novaDistancia;

            if (cidades[cidadeAtual] == estrada.getOrigem().getNomeDaCidade()) {
                indiceVizinho = getIndiceCidade(estrada.getDestino().getNomeDaCidade());
                novaDistancia = distanciaLocal[cidadeAtual] + estrada.getDistancia();
            } else if (cidades[cidadeAtual] == estrada.getDestino().getNomeDaCidade()) {
                indiceVizinho = getIndiceCidade(estrada.getOrigem().getNomeDaCidade());
                novaDistancia = distanciaLocal[cidadeAtual] + estrada.getDistancia();
            } else {
                continue;
            }

            if (novaDistancia < distanciaLocal[indiceVizinho]) {
                distanciaLocal[indiceVizinho] = novaDistancia;
                fila.push({novaDistancia, indiceVizinho});
            }
        }
    }

    return distanciaLocal;
}

void Grafo::imprimirMaiorCentralidadeProximidade() {
    double maxCentralidade = -DBL_MAX;
    string verticeMax;

    for (unsigned i = 0; i < cidades.size(); ++i) {

        //cria-se uma lista de distancia local para que nao de problema com a lista de distancias utilizada para o item 4
        vector<double> distanciaLocal = dijkstraParaTodasCidades(i);
        double somaDistancias = 0.0;
        //este e o numero de cidades que e possivel alcancar dadi um no especifico como origem
        int numCidadesAlcancaveis = 0;

        //soma das distancias do no de origem
        //Aqui, itera-se a variavel de cidades alcancaveis tambem, pois, se a distancia nao e infinito, foi possivel ter ela como destino
        for (double d : distanciaLocal) {
            if (d != INFINITO) {
                somaDistancias += d;
                numCidadesAlcancaveis++;
            }
        }

        if (numCidadesAlcancaveis > 1) {  // exclui o proprio no
            double centralidade = (numCidadesAlcancaveis - 1) / somaDistancias; 
            if (centralidade > maxCentralidade) {
                maxCentralidade = centralidade;
                verticeMax = cidades[i];
            }
        }
    }

    cout << "O vertice com a maior centralidade de proximidade e: " << verticeMax << endl;
    cout << "Sua centralidade de proximidade e: " << maxCentralidade << endl;
}

string Grafo::trim(const string &str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == string::npos) return "";

    // Retorna uma substring da string original, começando pelo primeiro caractere não 
    // branco e indo até o último caractere não branco.
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}

Aresta Grafo::criarAresta(const string& linha) {
    Aresta estrada;
    istringstream ss(linha);
    string origem, destino, distanciaStr;

    getline(ss, origem, ',');
    getline(ss, destino, ',');
    getline(ss, distanciaStr);

    //Realiza o trim para garantir que cidades com o mesmo nomes sejam tidas como iguais
    origem = trim(origem);
    destino = trim(destino);

    estrada.setOrigem(origem);
    estrada.setDestino(destino);
    estrada.setDistancia(stod(distanciaStr));
    
    // Adicionando vértices ao vetor vertices
    if (existeCidade(origem) == "nao existe") {
        cidades.push_back(origem);
    }
    if (existeCidade(destino) == "nao existe") {
        cidades.push_back(destino);
    }

    return estrada;
}
