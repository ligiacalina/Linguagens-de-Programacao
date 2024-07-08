/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 1
*  Arquivo contendo as definições de bindings para interagir com Python usando Pybind11.
*/

#include <pybind11/pybind11.h>
#include "sistemaTarefas.hpp"

namespace py = pybind11;

PYBIND11_MODULE(analisarTarefa_modulo, m) {
    m.def("chamar_script_python", SistemaTarefas::chamarScriptPython);
}
