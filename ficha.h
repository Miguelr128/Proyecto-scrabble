#ifndef FICHA_H
#define FICHA_H

#include <sstream>

using namespace std;

class ficha {
public:
    ficha(string, int);
    void setLetra(string);
    void setValorLetra(int);
    void setLetraComodin(bool);
    string getLetra();
    string toString();
    virtual ~ficha();
private:
    string letra;
    int valorLetra;
    bool letraComodin;
};
#endif /* FICHA_H */