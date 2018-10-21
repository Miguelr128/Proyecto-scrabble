#ifndef FICHA_H
#define FICHA_H

class ficha {
public:
    ficha(char, int, int);
    virtual ~ficha();
private:
    char letra;
    int valorLetra;
    int cantidadLetra;
    bool letraComodin;
};
#endif /* FICHA_H */