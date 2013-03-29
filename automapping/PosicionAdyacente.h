#ifndef POSICIONADYACENTE_H_
#define POSICIONADYACENTE_H_

#include "Posicion.h"

enum t_ladoAdyacencia{
	derecha,izquierda,arriba,abajo
};

class PosicionAdyacente: public Posicion {
public:
	t_ladoAdyacencia ladoAdyacencia;
	PosicionAdyacente(int fila,int columna,t_ladoAdyacencia ladoAdyacencia);
	virtual ~PosicionAdyacente();

	static t_ladoAdyacencia direccionOpuesta(t_ladoAdyacencia lado);
};

#endif /* POSICIONADYACENTE_H_ */
