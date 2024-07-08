#include "tarefa.hpp"

void Tarefa::setAcaoTarefa(string acaoTarefa){ acao = acaoTarefa;}
void Tarefa::setUrgencia(int indiceUrgencia ){
    if(indiceUrgencia == 1){ urgencia = "baixa";}
    else if(indiceUrgencia == 2){ urgencia = "media";}
    else if (indiceUrgencia == 3){ urgencia = "alta";}
    else{ urgencia = "-";}
}
void Tarefa::setRecorrencia(int indiceRecorrencia){
    if(indiceRecorrencia == 1){ recorrencia = "diaria";}
    else if(indiceRecorrencia == 2){ recorrencia = "semanal";}
    else if (indiceRecorrencia == 3){ recorrencia = "mensal";}
    else{ recorrencia = "-";}
} 

string Tarefa::getAcao(){return acao;}
string Tarefa::getUrgencia(){return urgencia;}
string Tarefa::getRecorrencia(){return recorrencia;}
int Tarefa::getIndiceUrgencia(string urgencia) {
    if (urgencia == "alta") return 3;
    if (urgencia == "media") return 2;
    if (urgencia == "baixa") return 1;
    return 0; // Caso nenhuma urgência seja correspondida
}
int Tarefa::getIndiceRecorrencia(string recorrencia){
    if(recorrencia == "diaria"){ return 1;}
    else if(recorrencia == "semanal"){ return 2;}
    else if(recorrencia == "mensal"){ return 3;}
    else if(recorrencia != ""){ return 4;}
    return 0; // Caso nenhuma recorrencia seja correspondida
}