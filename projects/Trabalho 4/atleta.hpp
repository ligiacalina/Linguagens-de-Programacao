/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 4
*  Arquivo de cabecalho da classe atleta
*  Aqui sao definidos os atributos e metodos da classe.
*/

#include <iostream>
#include <string>

using namespace std;

//Classe base
class Atleta{
    public:
        Atleta(string nome) : nome(nome) {}
        virtual ~Atleta() {} // Necessário para polimorfismo

        string getNomeAtleta();
        virtual void imprimeDetalhes(string nomeDoAtleta);
        friend ostream& operator<<(ostream& os, Atleta& atleta);

    protected:
        string nome;
};

//Classe derivada
class AtletaFutebol : public Atleta {
    public:
        AtletaFutebol(string nome, string posicao) : Atleta(nome), posicao(posicao) {}

        void imprimeDetalhes(string nomeDoAtleta) override;

    private:
        string posicao;
};

//Classe derivada
class AtletaKarate : public Atleta {
    public:
        AtletaKarate(string nome, string faixa) : Atleta(nome), faixa(faixa) {}

        void imprimeDetalhes(string nomeDoAtleta) override;

    private:
        string faixa;
};

//Classe derivada
class AtletaRobotica : public Atleta {
    public:
        AtletaRobotica(string nome, string categoria, string nomeDoRobo) : Atleta(nome), categoria(categoria), nomeDoRobo(nomeDoRobo) {}

        void imprimeDetalhes(string nomeDoAtleta) override;

    private:
        string categoria;
        string nomeDoRobo;
};

//Classe derivada
class AtletaVolei : public Atleta {
    public:
        AtletaVolei(string nome, string posicao) : Atleta(nome), posicao(posicao) {}

        void imprimeDetalhes(string nomeDoAtleta) override;

    private:
        string posicao;
};

