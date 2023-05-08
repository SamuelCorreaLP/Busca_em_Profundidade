#include <iostream>
#include "grafo.h"

XGrafo::XGrafo (int numVertices) : m_numVertices(numVertices){
    m_mat = new int*[m_numVertices];
    for(int i = 0; i <= m_numVertices; i++) {
        m_mat[i] = new int[m_numVertices];
        for(int j = 0; j <= m_numVertices; j++) {
            m_mat[i][j] = 0;
        }
    }
    m_pos = new int[m_numVertices];
    for(int i = 0; i <= m_numVertices; i++) {
        m_pos[i] = 0;
    }
}

void XGrafo::insereAresta (int v1, int v2, int peso) {
    m_mat[v1][v2] = peso;
}

bool XGrafo::existeAresta (int v1, int v2) {
    return (m_mat[v1][v2] > 0);
}

Aresta* XGrafo::primeiroListaAdj (int v) {
    m_pos[v] = -1;
    return this->proxAdj(v);
}

Aresta* XGrafo::proxAdj (int v) {
    m_pos[v]++;
    while((m_pos[v] < m_numVertices) && (m_mat[v][m_pos[v]] == 0)){
        m_pos[v] ++;
    }
    if (m_pos[v] == m_numVertices) {
        return NULL;
    } else {
        return new Aresta (v, m_pos[v], m_mat[v][m_pos[v]]);
    }
}

Aresta* XGrafo::retiraAresta (int v1, int v2) {
    if (m_mat[v1][v2] == 0){
        return NULL;
    } else {
        Aresta* aresta = new Aresta (v1, v2, m_mat[v1][v2]);
        m_mat[v1][v2] = 0;
        return aresta;
    }
    return NULL;
}

int XGrafo::tamanho () {
    return m_numVertices;
}

void XGrafo::imprime () {
    std::cout << "     ";
    for (int i = 0; i <= m_numVertices; i++)
        std::cout << i << "    ";
    std::cout <<std::endl <<std::endl;
    for (int i = 0; i <= m_numVertices; i++) {
        std::cout << i << "    ";
        for (int j = 0; j <= m_numVertices; j++)
            std::cout << m_mat[i][j] << "    ";
        std::cout << std::endl;
    }
}
