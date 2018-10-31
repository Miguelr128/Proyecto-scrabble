#include <cstdlib>
#include<iostream>
#include <stdlib.h>
#include <fstream>
#include <csetjmp>

#include "tablero.h"
#include "ficha.h"
#include "diccionario.h"
#include "sistema.h"

using namespace std;

string obtenerValor(istream&, char);
int obtenerValorEntero(istream&, char = ('\t' || '/'));

int main() {
    fstream archivo_dic;
    string linea_dic;
    string palabra_dic;
    fstream archivo_fic;
    string linea_fic;
    string letra_fic;
    int valorLetra_fic;
    int i = 0;
    fstream archivo_guardar;
    
    int opcion;
    bool seguirPrograma = true;
    string nombreJug1;
    string nombreJug2;

    archivo_dic.open("diccionario.txt", ios::in);
    archivo_fic.open("fichas.txt", ios::in);
    archivo_guardar.open("datos.txt", ios::out);
    vectorficha* fichasSistema = new vectorficha();
    diccionario* palabrasDiccionario = new diccionario(1551);
    
    while (archivo_fic.good()) {
        getline(archivo_fic, linea_fic);
        stringstream x(linea_fic);
        try {
            letra_fic = obtenerValor(x, '\t');
            fichasSistema->setLetra(i, letra_fic);
            valorLetra_fic = obtenerValorEntero(x, '\t');
            fichasSistema->setValor(i, valorLetra_fic);
            i++;
        } catch (int ex) {
        }
    }
    while (!archivo_dic.eof()) {
        getline(archivo_dic, linea_dic);
        stringstream r(linea_dic);

            getline(r, palabra_dic, '\n');
            palabrasDiccionario->agregar(palabra_dic);
    }
    
//    cout<<palabrasDiccionario->toString();
//    cout<<fichasSistema->toString();
    

    do {
        system("cmd /c color 79");
        system("cmd /c cls");
        cout << "*******************SCRABBLE*******************\n";
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "Digite la opcion que desea:\n";
        cout << endl;
        cout << "[1] Nueva partida.\n";
        cout << "[2] Finalizar programa.\n";
        cout << endl;
        cout<<"opcion: ";
        cin>>opcion;
        switch (opcion) {
            case 1: {
                system("cmd /c cls");
                tablero* tab = new tablero(8, 13);
                cout << "Digite el nombre del primer Jugador" << endl;
                cout<<"Nombre: ";
                cin >> nombreJug1;
                cout << "Digite el nombre del segundo Jugador" << endl;
                cout<<"Nombre: ";
                cin >> nombreJug2;
                cout<<endl;
                jugador* jug2 = new jugador (nombreJug2, fichasSistema, NULL, tab, false);
                jugador* jug1 = new jugador (nombreJug1, fichasSistema, jug2, tab, true);
                sistema* sis = new sistema (jug1, tab, palabrasDiccionario);
                
                string palabra;
                int fila, columna, op, contador, i, lon, contador2 = 1, posicion;
                string fich, palabraFormada;
                bool terminarTurno = false;
                char terminar;
                while(sis->getFinalizar() != true){
                    contador = 0;
                    cout<<tab->toString()<<endl<<endl;
                    cout<<"Turno de: "<<jug1->getNombre()<<endl;
                    while(jug1->getTurno() == true){
                        cout<<"fichas del jugador: "<<endl;
                        cout<<jug1->toString()<<endl<<endl;
                        cout<<"1. Colocar palabra"<<endl;
                        cout<<"2. Pedir fichas"<<endl;
                        cout<<"3. Pasar turno"<<endl;
                        cout<<"Opcion: ";
                        cin>>op;
                        //Turno de jugador 1 inicio

                        switch (op) {
                            
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
                                    int pos,e = 0;
                                    int vecFic[lon];
                                    while(opcion2 != 1){
                                        cout << " Digite la ficha y la posicion en la que se encuentra la ficha respectivamente para formar la palabra (Hacerlo en el orden correcto)" <<endl;
                                        cout<<"Letra: ";
                                        cin>>fich;
                                        cout<<"Posicion: ";
                                        cin>>posicion;
                                        cout<<endl;
                                        if (sis->validarPalabraVFJ(fich, posicion, jug1) == true) {
                                            vecFic[e] = posicion;
                                            palabraFormada = palabraFormada + fich;
                                            e++;
                                        }
                                        else if (sis->validarPalabraVFJ(fich, posicion, jug1) == false){
                                            cout << "La ficha no se encuentra" << endl;
                                        }

                                        cout << "Termino de formar la palabra?" <<endl;
                                        cout << "[1] Sí" << endl;
                                        cout << "[2] No" << endl;
                                        cout<<"Opcion: ";
                                        cin>>opcion2;
                                        cout<<endl;
                                    }
                                    if (palabrasDiccionario->validarPalabra(palabra) == true && sis->palabrasIguales(palabra, palabraFormada) == true) {
                                        for (int i = 0; i < lon; i++) {
                                            pos = vecFic[i];
                                            fit = jug1->getFicha(pos);
                                            cout<<fit->toString()<<endl;
                                            cout << endl;
                                            cout << "Digite la posicion en la que desea colocar las fichas en el orden que foman la palabra" << endl;
                                            cout << "fila: ";
                                            cin>>fila;
                                            cout << endl;
                                            cout << "columna: ";
                                            cin>>columna;
                                            cout << endl;
                                            tab->reservarPosicion(fila, columna, fit);
                                            cout << tab->toString() << endl<<endl;
                                        }
                                        jug1->puntosPorPalabra(fila, columna);
                                        cout<<"Puntos acumulados: "<<jug1->getPuntos()<<endl<<endl;
                                        jug1->pasarTurno();
                                        terminarTurno = true;
                                    } else
                                        cout << "La palabra no existe en el diccionario o las fichas escogidas no forman la palabra" << endl;
                                }
                                break;
                            }

                            case 2:
                                jug1->nuevasFichas();
                                break;

                            case 3:
                                jug1->pasarTurno();
                                break;

                            default:
                                cout<<"La opcion no es valida"<<endl;
                        }
                        jug2->setTurno(true);
                        //Fin del turno del jugador 1          
                    }
                    if(op == 3){
                        contador = contador + 1;
                    }
                    terminarTurno = false;
                    
                    cout << endl << endl;
                    cout<<"Turno de: "<<jug2->getNombre()<<endl;
                    while(jug2->getTurno() == true){
                        cout<<"fichas del jugador: "<<endl;
                        cout<<jug2->toString()<<endl<<endl;
                        cout<<"1. Colocar palabra"<<endl;
                        cout<<"2. Pedir fichas"<<endl;
                        cout<<"3. Pasar turno"<<endl;
                        cout<<"Opcion: ";
                        cin>>op;
                        
                        //Turno jugador 2 inicio
                        switch (op) {
                            
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
                                    int pos,e = 0;
                                    int vecFic[lon];
                                    while(opcion2 != 1){
                                        cout << " Digite la ficha y la posicion en la que se encuentra la ficha respectivamente para formar la palabra" <<endl;
                                        cout<<"Letra: ";
                                        cin>>fich;
                                        cout<<"Posicion: ";
                                        cin>>posicion;
                                        cout<<endl;
                                        if (sis->validarPalabraVFJ(fich, posicion, jug2) == true) {
                                            vecFic[e] = posicion;
                                            palabraFormada = palabraFormada + fich;
                                            e++;
                                        }
                                        else if (sis->validarPalabraVFJ(fich, posicion, jug2) == false){
                                            cout << "La ficha no se encuentra" << endl;
                                        }

                                        cout << "Termino de formar la palabra?" <<endl;
                                        cout << "[1] Sí" << endl;
                                        cout << "[2] No" << endl;
                                        cout<<"Opcion: ";
                                        cin>>opcion2;
                                        cout<<endl;
                                    }
                                    if (palabrasDiccionario->validarPalabra(palabra) == true && sis->palabrasIguales(palabra, palabraFormada) == true) {
                                        for (int i = 0; i < lon; i++) {
                                            pos = vecFic[i];
                                            cout<<pos<<endl;
                                            fit = jug2->getFicha(pos);
                                            cout << endl;
                                            cout << "Digite la posicion en la que desea colocar las fichas en el orden que foman la palabra" << endl;
                                            cout << "fila: ";
                                            cin>>fila;
                                            cout << endl;
                                            cout << "columna: ";
                                            cin>>columna;
                                            cout << endl;
                                            tab->reservarPosicion(fila, columna, fit);
                                            cout << tab->toString() << endl<<endl;
                                        }
                                        jug2->puntosPorPalabra(fila, columna);
                                        cout<<"Puntos acumulados: "<<jug2->getPuntos()<<endl<<endl;
                                        jug2->pasarTurno();
                                        terminarTurno = true;
                                    } else
                                        cout << "La palabra no existe en el diccionario o las fichas escogidas no forman la palabra" << endl;
                                }
                                break;
                            }

                            case 2:
                                jug1->nuevasFichas();
                                break;

                            case 3:
                                jug1->pasarTurno();
                                break;

                            default:
                                cout<<"La opcion no es valida"<<endl;
                        }
    
                        jug1->setTurno(true);
                    }
                    terminarTurno = false;
                    if(op == 3){
                        contador = contador + 1;
                    }
                    if(contador == 2){
                        sis->finalizarJuego();
                        cout<<"El juego ha terminado"<<endl;
                        break;
                    }
                    cout<<endl<<endl;
                    cout<<"Finalizar juego. Si(Y), No(N): ";
                    cin>>terminar;
                    if(terminar == 'Y'){
                        sis->finalizarJuego();
                        cout<<"El juego ha terminado"<<endl;
                    }
                }

            seguirPrograma = false;
            delete tab;
            delete jug1;
            delete jug2;
            delete sis;
            break;
            }
            case 2: {
                system("cmd /c cls");
                system("cmd /c pause");
                seguirPrograma = false;
                break;
            }
        }
    } while (seguirPrograma == true);
    
    archivo_dic.close();
    archivo_fic.close();
    archivo_guardar.close();
    delete fichasSistema;
    delete palabrasDiccionario;
    return 0;
}

string obtenerValor(istream &entrada, char delimitador) {
    string r;
    getline(entrada, r, delimitador);
    if (entrada.fail()) {
        throw -1;
    }
    return r;
}

int obtenerValorEntero(istream &entrada, char delimitador) {
    string s = obtenerValor(entrada, delimitador);
    stringstream r(s);
    int v;
    if (!(r >> v)) {
        throw -1;
    }
    return v;
}