#include "mbed.h"

BusOut display(D6, D7, D9, D10, D11, D5, D4, D8);
DigitalIn mypin(BUTTON1);

char table[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

int main()
{
    mypin.mode(PullNone);
    int i = 0;

    while (1)
    {
        if(mypin) i++;
        if(!mypin) i--;
        if(i >= 10) i = 0;
        if(i < 0) i = 9;
        display = table[i];
        ThisThread::sleep_for(500ms);
    }
}