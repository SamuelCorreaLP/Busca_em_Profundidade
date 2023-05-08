#include "ciclo.h"
#include "aresta.h"

XCiclo::XCiclo (XGrafo* graph) : m_graph(graph) {
    for(int i = 0; i <= m_graph->tamanho(); i++) {
        m_state.push_back(XCiclo::WHITE);
        m_peso.push_back(0);
    }
    m_pesoAtual = 0;
    m_temCiclo = false;
    this->IniciaBusca();
}

bool XCiclo::temCiclo () {
    return m_temCiclo;
}

void XCiclo::IniciaBusca () {
    Aresta* aux;
    for(int i = 0; i <= m_graph->tamanho(); i++){ //percorre todos os pontos do grafo
        if(m_state[i] == XCiclo::WHITE){ //avança para o proximo ponto somente se o ponto analisado não foi acessado antes
            m_state[i] = XCiclo::GREY;
            aux = m_graph->primeiroListaAdj(i); // pega primeiro elemento da lista de adjacencia
            while (aux != NULL) { //permanece no for enquanto existir proximo elemento na lista de adjacencia
                m_graph->retiraAresta(aux->getV1(), aux->getV2());
                m_peso[i] = m_pesoAtual + aux->getPeso();
                m_pesoAtual = m_peso[i];
                this->buscaInterna(aux->getV1(), aux->getV2());
                m_peso[i] = m_pesoAtual + aux->getPeso();
                m_pesoAtual = m_peso[i];
                aux = m_graph->proxAdj(i);
            }
            m_state[i] = XCiclo::BLACK; // todos os pontos foram percoridos e o ponto se torna preto
        }
    }
}

void XCiclo::buscaInterna (int vAnterior, int vAtual) {
    Aresta* aux = m_graph->primeiroListaAdj(vAtual);
    m_state[vAtual] = XCiclo::GREY;
    while (aux != NULL) { //permanece no for enquanto existir proximo elemento na lista de adjacencia
        switch (m_state[aux->getV2()]) {
            case XCiclo::WHITE: //caso nunca foi acessado, avança recursivamente para proximo valor
                m_graph->retiraAresta(aux->getV1(), aux->getV2());
                m_peso[vAtual] = m_pesoAtual + aux->getPeso(); //adiciona o contador do peso ao vetor de pesos de cada ponto
                m_pesoAtual = m_peso[vAtual];
                this->buscaInterna(aux->getV1(), aux->getV2());
                m_peso[vAtual] = m_pesoAtual + aux->getPeso(); //ao terminar a recursividade, atualiza o peso do ponto
                m_pesoAtual = m_peso[vAtual];
            break;
            case XCiclo::GREY: // caso já tenha sido acessado no mesmo galho tem ciclo na arvore
                m_graph->retiraAresta(aux->getV1(), aux->getV2());
                m_temCiclo = true;
            break;
            case XCiclo::BLACK: // se o ponto for preto tem que comparar os pesos para saber se é um galho de avanço ou de cruzamento
                if(m_peso[vAtual] > m_peso[aux->getV2()]) { //cruzamento
                    m_graph->retiraAresta(aux->getV1(), aux->getV2());
                } else { //avanço
                    m_graph->retiraAresta(aux->getV1(), aux->getV2());
                }
            break;
        }
        aux = m_graph->proxAdj(vAtual);
    }
    m_state[vAtual] = XCiclo::BLACK; // nesse ponto todos os vertices desse ponto foi percorrido
}
