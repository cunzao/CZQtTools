#include "checkxor.h"

CheckXOR::CheckXOR()
{

}

unsigned char CheckXOR::CheckXor(char *pBuffer, unsigned int size)
{
    unsigned char ucRes = 0x00;
    for(unsigned int i = 0; i < size; i++)
    {
        ucRes ^= static_cast<unsigned char>(pBuffer[i]);
    }
    ucRes &= 0xff;
    return static_cast<unsigned char>(ucRes);
}
