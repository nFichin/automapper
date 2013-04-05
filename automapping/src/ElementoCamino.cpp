#include "ElementoCamino.h"

ElementoCamino::ElementoCamino() {
	tipoElementoCamino = NULO;
}

ElementoCamino::~ElementoCamino() {
}

elementoCamino_t ElementoCamino::GetTipo(){
	return tipoElementoCamino;
};

void ElementoCamino::SetTipo(elementoCamino_t tipo){
	tipoElementoCamino = tipo;
}

void ElementoCamino::SetPos(int fil,int col){
	pos.fila = fil;
	pos.columna = col;
}
void ElementoCamino::AdaptateParaConectarEnNuevaDireccion(ladoAdyacencia_t ladoNuevaAdyacencia){

}
