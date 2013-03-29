#ifndef POSICIONADYACENTE_H_
#define POSICIONADYACENTE_H_

#include "Posicion.h"

typedef enum{
	derecha,izquierda,arriba,abajo
}t_ladoAdyacencia;

class PosicionAdyacente: public Posicion {
public:
	t_ladoAdyacencia ladoAdyacencia;
	PosicionAdyacente(int fila,int columna,t_ladoAdyacencia ladoAdyacencia);
	virtual ~PosicionAdyacente();

	int direccionOpuesta(int lado);
};

#endif /* POSICIONADYACENTE_H_ */
