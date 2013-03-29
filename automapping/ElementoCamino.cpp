#include "ElementoCamino.h"

ElementoCamino::ElementoCamino() {
	tipoElementoCamino = NULO;
}

ElementoCamino::~ElementoCamino() {
	// TODO Auto-generated destructor stub
}

elementoCamino_t ElementoCamino::GetTipo(){
	return tipoElementoCamino;
};

void ElementoCamino::SetTipo(elementoCamino_t tipo){
	tipoElementoCamino = tipo;
}

void ElementoCamino::AdaptateParaConectarEnNuevaDireccion(ladoAdyacencia_t ladoNuevaAdyacencia){

}
