#ifndef CICLO_H
#define CICLO_H

#include <vector>
#include "grafo.h"

class XCiclo {
    public:
    XCiclo (XGrafo* graph);
    bool temCiclo ();
        
    private:
    enum State {
        WHITE = 0,
        GREY = 1,
        BLACK = 2
    };
    XGrafo* m_graph;
    bool m_temCiclo;
    std::vector<State> m_state;
    std::vector<int> m_peso;
    int m_pesoAtual;

    void IniciaBusca ();
    void buscaInterna (int vAtual, int vAnterior);
};

#endif