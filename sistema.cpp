#include<iostream>
#include "sistema.h"

using namespace std;

sistema::sistema(jugador* j, tablero* t, diccionario* d) : primerJugador(j), ptrTablero(t), dic(d), finalizar(false), ptrArchivo (new archivo()) {
}

string sistema::ganador(){
    stringstream s;
    jugador* jugador2 = primerJugador->getOtroJugador();
    if(primerJugador->getPuntos() == jugador2->getPuntos()){
        s<<"Empate";
    }
    else
        if(primerJugador->getPuntos() > jugador2->getPuntos()){
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

bool sistema::validarPalabraVFJ(string ficha, int posicion, jugador* j) {
    if (j->getPtrVectorFichas()->buscarFicha(posicion)->getLetra() == ficha) {
        return true;
    }
    return false;
}

bool sistema::palabrasIguales(string palabra1, string palabra2){
    char letrasRecibidas [7];
    char letrasPalabra [20];

    strcpy(letrasRecibidas, palabra1.c_str());
    strcpy(letrasPalabra, palabra2.c_str());
    if (strcmp(letrasPalabra, letrasRecibidas) == 0){
        return true;
    }
    return false;
}

void sistema::turno(int p, jugador* j, int ronda) {
    string fich, palabra, palabraFormada;
    bool terminarTurno = false;
    int fila, columna, i, lon, contador = 1, posicion;
    jugador* j1 = j;
    switch (p) {                    
        case 1:
        {
            while (terminarTurno != true) {
                ficha* fit = NULL;
                int opcion2 = 2;
                string palabraFormada;
                cout<<"Digite la palabra que desea formar: ";
                cin>>palabra;
                cout<<endl;
                cout << "Digite la cantidad de letras que posee la palabra que va a formar" << endl;
                cin >> lon;
                int pos,e = 0, d;
                int vecFic[lon];
                while(opcion2 != 1){
                    cout << " Digite la ficha y la posicion en la que se encuentra la ficha respectivamente para formar la palabra (Hacerlo en el orden correcto)" <<endl;
                    cout<<"Letra: ";
                    cin>>fich;
                    cout<<"Posicion: ";
                    cin>>posicion;
                    cout<<endl;
                    if (validarPalabraVFJ(fich, posicion, j) == true) {
                        vecFic[e] = posicion;
                        palabraFormada = palabraFormada + fich;
                        e++;
                    }
                    else if (validarPalabraVFJ(fich, posicion, j) == false){
                        cout << "La ficha no se encuentra" << endl;
                    }

                    cout << "Termino de formar la palabra?" <<endl;
                    cout << "[1] Sí" << endl;
                    cout << "[2] No" << endl;
                    cout<<"Opcion: ";
                    cin>>opcion2;
                    cout<<endl;
                }
                if (dic->validarPalabra(palabra) == true && palabrasIguales(palabra, palabraFormada) == true) {
                    ptrArchivo->guardarPalabras(palabra, j);
                    cout << "Digite 1 si desea formar la palabra de manera horizontal y dos si desea formar la palabra de manera vertical" <<endl;
                    cin >> d;
                    for (int i = 0; i < lon; i++) {
                        pos = vecFic[i];
                        fit = j->getFicha(pos);
                        cout<<"Ficha: "<<fit->toString()<<endl;
                        cout << endl;
                        cout << "Digite la posicion en la que desea colocar las fichas en el orden que foman la palabra" << endl;
                        cout << "fila: ";
                        cin>>fila;
                        cout << endl;
                        cout << "columna: ";
                        cin>>columna;
                        cout << endl;
                        ptrTablero->reservarPosicion(fila, columna, fit);
                        cout << ptrTablero->toString() << endl << endl;
                        j->eliminar(pos);
                    }
                    if (dic->validarPalabraTableroA() == true && dic->validarPalabraTableroI() == true) {
                        if (ronda == 1 && puntosScrabble(palabra) == true) {
                            j->setPuntos(100);
                            cout << "100 puntos extras por usar todas las fichas" << endl << endl;
                        }
                        j->puntosPorPalabra(fila, columna);
                        cout << "Puntos acumulados: " << j->getPuntos() << endl << endl;
                        ptrArchivo->guardarPuntaje(j->getPuntos(), j);
                        j->pasarTurno();
                        terminarTurno = true;
                    } else {
                        cout << "En el tablero se formo una palabra no valida" << endl;
                        ptrTablero->eliminarPalabra(fila, columna, lon, d);
                    }
                } else
                    cout << "La palabra no existe en el diccionario o las fichas escogidas no forman la palabra" << endl;
            }
            break;
        }

        case 2:
            if(j->estaLleno()){
                cout<<"Ya tiene la cantidad de fichas maximas"<<endl;
            }
            else{
            j->nuevasFichas();
            }
            break;
            
        case 3:
            int p;
            cout<<"Digite la posicion de la ficha que desea cambiar: ";
            cin>>p;
            j->cambiarFichas(p);
            j->pasarTurno();
            break;

        case 4:
            j->pasarTurno();
            break;

        default:
            cout<<"La opcion no es valida"<<endl;
    }
}

void sistema::iniciarJuego(){
    int opcion, contador;
    int ronda = 0;
    char terminar;
    jugador* jugador2 = primerJugador->getOtroJugador();
    while(finalizar != true){
        ronda = ronda + 1;
        contador = 0;
        cout<<ptrTablero->toString()<<endl<<endl;
        cout<<"Turno de: "<<primerJugador->getNombre()<<endl;
        while(primerJugador->getTurno() == true){
            cout<<"fichas del jugador: "<<endl;
            cout<<primerJugador->toString()<<endl<<endl;
            cout<<"1. Colocar palabra"<<endl;
            cout<<"2. Pedir fichas"<<endl;
            cout<<"3. Cambiar fichas"<<endl;
            cout<<"4. Pasar turno"<<endl;
            cout<<"Opcion: ";
            cin>>opcion;
            turno(opcion, primerJugador, ronda);
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
            cout<<"3. Cambiar fichas"<<endl;
            cout<<"4. Pasar turno"<<endl;
            cout<<"Opcion: ";
            cin>>opcion;
            turno(opcion, jugador2, ronda);
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
    ganador();
}

sistema::~sistema() {
}
