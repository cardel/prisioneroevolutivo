/*
 * Carlos Andres Delgado
 * Victor Alberto Romero
 * 
 * Esta clase genera un estado aleatoriamente
 * Los estado se manejan como un arreglo de 4 posiciones
 * [EstadoPresente, Salida, PESICooperan, PESITraiciona]
 */
#include "Estado.h"

Estado::Estado(int numeroEstados)
{
    this->numeroEstados = numeroEstados;
    estadoPE = new int(4);
    estadoActual=0;
}
Estado::~Estado()
{
	/*
	 * @Cardel 21 de Marzo 21:15 GMT -05
	 * Inicio modificación del metodo delete
	 */
	 delete estadoPE;
	/*
	 * @Cardel 21 de Marzo 21:15 GMT -05
	 * Fin modificación del metodo delete
	 */
}

/*
 * Este metodo genera los estados entre 1 y numeroDeEstados
 * En orden S1, S2, ..., SNumeroEstados
 */
void Estado::generarEstados()
{
    estadoActual++;

    if(estadoActual>numeroEstados)
    {
        cerr << "Aqui hay un error"<< estadoActual<<"-"<<numeroEstados<<endl;
        estadoActual = 1;
    }

    estadoPE[0] = estadoActual;

	int salida = rand() % 2;
    estadoPE[1] = salida;

    int proximoEstadoSICooperan = (1 + rand() % numeroEstados);
    estadoPE[2] = proximoEstadoSICooperan;

    int proximoEstadoSITraicionan = (1 + rand() % numeroEstados);
    estadoPE[3] = proximoEstadoSITraicionan;
}

int Estado::obtenerEstado(int posicion)
{
    return estadoPE[posicion];
}
