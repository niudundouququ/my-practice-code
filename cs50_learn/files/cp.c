#include <stdio.h>


typedef unsigned char BYTE;


int main(int argc,char *argv[])
{
    FILE *src = fopen(argv[1],"rb");
    FILE *dst = fopen(argv[2],"wb");
    //read and write in binary mode

    BYTE b;

    while (fread(&b,sizeof(b),1,src) != 0)
    {
        fwrite(&b,sizeof(b),1,dst);
    }

    fclose(src);
    fclose(dst);
    
}