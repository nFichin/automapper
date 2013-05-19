#ifndef POSICIONADYACENTE_H_
#define POSICIONADYACENTE_H_

#include "Posicion.h"

enum ladoAdyacencia_t{
	DERECHA = 0x01,
	IZQUIERDA = 0x02,
	ARRIBA = 0x03,
	ABAJO = 0x04
};

class PosicionAdyacente: public Posicion {
public:
	ladoAdyacencia_t 			ladoAdyacencia;
								PosicionAdyacente(int fila,int columna,ladoAdyacencia_t ladoAdyacencia);
	virtual 					~PosicionAdyacente();

	static ladoAdyacencia_t 	DireccionOpuesta(ladoAdyacencia_t lado);
};

#endif /* POSICIONADYACENTE_H_ */
