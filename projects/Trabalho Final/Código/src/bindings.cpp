#include <pybind11/pybind11.h>
#include "sistemaTarefas.hpp"

namespace py = pybind11;

PYBIND11_MODULE(analisarTarefa_modulo, m) {
    m.def("chamar_script_python", SistemaTarefas::chamarScriptPython);
}
