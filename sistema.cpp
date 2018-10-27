#include<iostream>
#include "sistema.h"

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

void sistema::turno(int p, jugador* j){
    string palabra;
    bool terminar = false;
    int fila, columna, i, lon, contador = 1;
    ficha* fi;
    switch(p){
        case 1:
            while(terminar != true){
                cout<<" Digite la palabra que desea colocar (todo en minusculas): ";
                cin>>palabra;
                cout<<endl;
                cout<<"Longitud de la palabra: ";
                cin>>lon;
                cout<<endl;
                // Espacio donde se guarda la palabra en un archivo y se busca en el diccionario//
                if(dic->validarPalabra(palabra) == true){
                    cout<<"A continuacion digite coloque las letras en forma ordenada"<<endl;
                    while(contador <= lon){
                        cout<<"Digite la posicion de la letra que desea colocar: ";
                        cin>>i;
                        fi = j->getFicha(i);
                        cout<<endl;
                        cout<<"Ahora digite la posicion en la desea colocar en el tablero"<<endl;
                        cout<<"fila: ";
                        cin>>fila;
                        cout<<endl;
                        cout<<"columna: ";
                        cin>>columna;
                        cout<<endl;
                        ptrTablero->reservarPosicion(fila, columna, fi);
                        cout<<ptrTablero->toString()<<endl;
                    }
                    j->pasarTurno();
                    terminar = true;
                }
                else
                    cout<<"La palabra no es aceptada"<<endl;
            }
            break;
            
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
        }
        if(opcion == 3){
            contador++;
        }
        cout<<endl<<endl;
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
        }
        if(opcion == 3){
            contador++;
        }
        cout<<endl<<endl;
        cout<<"Finalizar juego. Si(Y), No(N): ";
        cin>>terminar;
        if(terminar == 'Y' || contador == 2){
            finalizarJuego();
            cout<<"El juego ha terminado"<<endl;
        }
    }
}

sistema::~sistema() {
}