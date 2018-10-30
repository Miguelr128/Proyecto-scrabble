#include<iostream>
#include "sistema.h"

using namespace std;

sistema::sistema(jugador* j, tablero* t, diccionario* d):primerJugador(j), ptrTablero(t), dic(d), finalizar(false) {
}

string sistema::ganador(){
    stringstream s;
    jugador* jugador2 = primerJugador->getOtroJugador();
    if(primerJugador->getPuntaje() == jugador2->getPuntaje()){
        s<<"Empate";
    }
    else
        if(primerJugador->getPuntaje() > jugador2->getPuntaje()){
            s<<"Primer jugador es el ganador";
        }
        else
            s<<"Segundo jugador es el ganador";
    return s.str();
}

void sistema::finalizarJuego(){
    finalizar = true;
}

bool sistema::getFinalizar(){
    return finalizar;
}

void sistema::sumarPuntos(jugador* j, int f, int c){
    j->puntosPorPalabra(f, c);
}

bool sistema::puntosScrabble(string palabra) {
    if (palabra.length() == 7)
        return true;
    return false;
}

bool sistema::validarPalabraVFJ(string ficha, int posicion) {
    if (primerJugador ->getPtrVectorFichas()->buscarFicha(posicion)->getLetra() == ficha) {
        primerJugador ->getPtrVectorFichas()->eliminar(posicion);
        return true;
    }
    return false;
}

void sistema::turno(int p, jugador* j) {
    string fich, palabra, palabraFormada;
    bool terminar = false;
    int fila, columna, i, lon, contador = 1, posicion;
    jugador* j1 = j;
    switch (p) {
        case 1:
        {
            while (terminar != true) {
                ficha* fit = NULL;
                int opcion = 2;
                cout<<"Digite la palabra que desea formar: ";
                cin>>palabra;
                cout<<endl;
                cout << "Digite la cantidad de letras que posee la palabra que va a formar" << endl;
                cin >> lon;
                int pos,e = 0;
                int vecFic[lon];
                while(opcion != 1){
                    cout << " Digite la ficha y la posicion en la que se encuentra la ficha respectivamente para formar la palabra" <<endl;
                    cin>>fich;
                    cin>>posicion;
                    if (validarPalabraVFJ(fich, posicion) == true) {
                        vecFic[e] = posicion;
                        e++;
                    }
                    else if (validarPalabraVFJ(fich, posicion) == false){
                        cout << "La ficha no se encuentra" << endl;
                    }
                    
                    cout << "Termino de formar la palabra?" <<endl;
                    cout << "[1] Sí" << endl;
                    cout << "[2] No" << endl;
                    cin>>opcion;
                }
                if (dic->validarPalabra(palabra) == true) {
                    for (int i = 0; i < lon; i++) {
                        pos = vecFic[i];
                        cout<<pos<<endl;
                        fit = j1->getFicha(pos);
                        cout<<fit->toString()<<endl;
                        cout << endl;
                        cout << "Digite la posicion en la que desea colocar las fichas en el orden que foman la palabra" << endl;
                        cout << "fila: ";
                        cin>>fila;
                        cout << endl;
                        cout << "columna: ";
                        cin>>columna;
                        cout << endl;
                        ptrTablero->reservarPosicion(fila, columna, fit);
                        cout << ptrTablero->toString() << endl;
                    }
                    j1->pasarTurno();
                    terminar = true;
                } else
                    cout << "La palabra no existe en el diccionario" << endl;
            }
            break;
        }

        case 2:
            j->nuevasFichas();
            break;
            
        case 3:
            j->pasarTurno();
            break;
            
        default:
            cout<<"La opcion no es valida"<<endl;
    }
}

void sistema::iniciarJuego(){
    string palabra;
    int fila, columna, opcion, contador;
    char terminar;
    jugador* jugador2 = primerJugador->getOtroJugador();
    while(finalizar != true){
        contador = 0;
        cout<<ptrTablero->toString()<<endl<<endl;
        cout<<"Turno de: "<<primerJugador->getNombre()<<endl;
        while(primerJugador->getTurno() == true){
            cout<<"fichas del jugador: "<<endl;
            cout<<primerJugador->toString()<<endl<<endl;
            cout<<"1. Colocar palabra"<<endl;
            cout<<"2. Pedir fichas"<<endl;
            cout<<"3. Pasar turno"<<endl;
            cout<<"Opcion: ";
            cin>>opcion;
            turno(opcion, primerJugador);
            jugador2->setTurno(true);
        }
        if(opcion == 3){
            contador = contador + 1;
        }
        cout << endl << endl;
        cout<<"Turno de: "<<jugador2->getNombre()<<endl;
        while(jugador2->getTurno() == true){
            cout<<"fichas del jugador: "<<endl;
            cout<<jugador2->toString()<<endl<<endl;
            cout<<"1. Colocar palabra"<<endl;
            cout<<"2. Pedir fichas"<<endl;
            cout<<"3. Pasar turno"<<endl;
            cout<<"Opcion: ";
            cin>>opcion;
            turno(opcion, jugador2);
            primerJugador->setTurno(true);
        }
        if(opcion == 3){
            contador = contador + 1;
        }
        if(contador == 2){
            finalizarJuego();
            cout<<"El juego ha terminado"<<endl;
            break;
        }
        cout<<endl<<endl;
        cout<<"Finalizar juego. Si(Y), No(N): ";
        cin>>terminar;
        if(terminar == 'Y'){
            finalizarJuego();
            cout<<"El juego ha terminado"<<endl;
        }
    }
}

sistema::~sistema() {
}
