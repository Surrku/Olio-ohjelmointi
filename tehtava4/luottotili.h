#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include "pankkitili.h"

class luottotili : public pankkitili {
public:
    luottotili(string, double);
    bool deposit(double amount) override;
    bool withdraw(double amount) override;

protected:
    double luottoRaja;
};

#endif // LUOTTOTILI_H
