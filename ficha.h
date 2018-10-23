#ifndef FICHA_H
#define FICHA_H

#include <sstream>

using namespace std;

class ficha {
public:
    ficha(char, int);
    void setLetra(char);
    void setValorLetra(int);
    void setLetraComodin(bool);
    char getLetra();
    string toString();
    virtual ~ficha();
private:
    char letra;
    int valorLetra;
    bool letraComodin;
};
#endif /* FICHA_H */