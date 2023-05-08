/*
AED2 Prof. Thiago de Souza Rodrigues
Aluno: Samuel Correa Lucas Pereira
Implementação da classe grafo e pesquisa em profundidade para identificar ciclo
*/

#include <iostream>
#include "grafo.h"
#include "ciclo.h"

int main (int argc, char* argv[]) {

    //primeiro grafo
    std::cout <<"Primeiro grafo" <<std::endl;
    XGrafo* grafo = new XGrafo(7);
    grafo->insereAresta(0, 1, 1); grafo->insereAresta(0, 3, 1); grafo->insereAresta(0, 4, 1);
    grafo->insereAresta(1, 0, 1); grafo->insereAresta(1, 2, 1); grafo->insereAresta(1, 5, 1);
    grafo->insereAresta(2, 1, 1); grafo->insereAresta(2, 3, 1); grafo->insereAresta(2, 6, 1);
    grafo->insereAresta(3, 0, 1); grafo->insereAresta(3, 2, 1); grafo->insereAresta(3, 7, 1);
    grafo->insereAresta(4, 0, 1); grafo->insereAresta(4, 5, 1); grafo->insereAresta(4, 7, 1);
    grafo->insereAresta(5, 1, 1); grafo->insereAresta(5, 4, 1); grafo->insereAresta(5, 6, 1);
    grafo->insereAresta(6, 2, 1); grafo->insereAresta(6, 5, 1); grafo->insereAresta(6, 7, 1);
    grafo->insereAresta(7, 3, 1); grafo->insereAresta(7, 4, 1); grafo->insereAresta(7, 6, 1);

    grafo->imprime();

    
    XCiclo ciclo(grafo);
    
    if(ciclo.temCiclo())
        std::cout << "Tem ciclo" <<std::endl;
    else
        std::cout << "Não tem ciclo" <<std::endl;
    std::cout <<std::endl <<std::endl;

    //segundo grafo
    std::cout <<"Segundo grafo" <<std::endl;
    XGrafo* grafo2 = new XGrafo(9);
    grafo2->insereAresta(0,1,1); grafo2->insereAresta(0,2,1); grafo2->insereAresta(0,3,1);
    grafo2->insereAresta(1,2,1);
    grafo2->insereAresta(2,4,1); grafo2->insereAresta(2,3,1);
    grafo2->insereAresta(4,6,1);
    grafo2->insereAresta(5,4,1); grafo2->insereAresta(5,6,1);
    grafo2->insereAresta(6,7,1); grafo2->insereAresta(6,8,1);
    grafo2->insereAresta(7,8,1);
    grafo2->insereAresta(9,6,1);

    grafo2->imprime();
    
    XCiclo ciclo2(grafo2);
    
    if(ciclo2.temCiclo())
        std::cout << "Tem ciclo" <<std::endl;
    else
        std::cout << "Não tem ciclo" <<std::endl;
}
