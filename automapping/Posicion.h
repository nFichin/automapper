#ifndef POSICION_H_
#define POSICION_H_

class Posicion {
public:
	int 		fila;
	int 		columna;
				Posicion(int fila, int columna);
				Posicion();
	virtual 	~Posicion();
};

#endif /* POSICION_H_ */
