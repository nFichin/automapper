#include "ElementoCamino.h"

ElementoCamino::ElementoCamino() {
	tipoElementoCamino = nulo;
}

ElementoCamino::~ElementoCamino() {
	// TODO Auto-generated destructor stub
}

void ElementoCamino::agregarseAMatriz(ElementoCamino *matriz[10]){


};

t_elementoCamino ElementoCamino::getTipo(){
	return tipoElementoCamino;
};

void ElementoCamino::setTipo(t_elementoCamino tipo){
	tipoElementoCamino = tipo;
}
