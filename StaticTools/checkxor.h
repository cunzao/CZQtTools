#ifndef CHECKXOR_H
#define CHECKXOR_H

#include <QObject>

class CheckXOR
{
public:
    CheckXOR();
    static unsigned char CheckXor(char *pBuffer, unsigned int size);
};

#endif // CHECKXOR_H
