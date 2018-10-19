#ifndef FICHA_H
#define FICHA_H

class ficha {
public:
    ficha(char, int);
    virtual ~ficha();
private:
    char letra;
    int valorLetra;
    char letraComodin;
};
#endif /* FICHA_H */