#include "checksum8.h"

CheckSum8::CheckSum8()
{

}

unsigned char CheckSum8::CheckSum_8(char *pBuffer, unsigned int size)
{
    unsigned int iRes = 0x00;
    for(unsigned int i = 0; i < size; i++)
    {
        iRes += static_cast<unsigned int>(pBuffer[i]);
    }
    iRes &= 0xff;
    return static_cast<unsigned char>(iRes);
}
