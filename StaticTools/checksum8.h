#ifndef CHECKSUM8_H
#define CHECKSUM8_H


class CheckSum8
{
public:
    CheckSum8();
    static unsigned char CheckSum_8(char *pBuffer, unsigned int size);
};

#endif // CHECKSUM8_H
