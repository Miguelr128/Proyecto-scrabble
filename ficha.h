#ifndef FICHA_H
#define FICHA_H

class ficha {
public:
    ficha(char, int);
    virtual ~ficha();
private:
    char letra;
    int valorLetra;
    bool letraComodin;
};
#endif /* FICHA_H */