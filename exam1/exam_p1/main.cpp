#include "mbed.h"
#include <cstdlib>
#include <cmath>
#include <chrono>

BusOut display(D6, D7, D9, D10, D11, D5, D4, D8);
DigitalOut myled(LED1);
DigitalIn mypin(BUTTON1);

char table[8] = {0x01, 0x03, 0x06, 0x0C, 0x08, 0x18, 0x30, 0x21};

int main()
{
    myled = 0;
    mypin.mode(PullNone);
    
    uint64_t now = Kernel::get_ms_count();
    uint64_t score = 0;
    uint64_t ans = 0;
    uint64_t mode = 0;
    uint64_t patt = rand();

    printf("please hit the following pattern in 10 sec \n\r");

    if(patt % 8 == 0){
        printf(" _\n\r");
    }else if(patt % 8 == 1){
        printf(" _\n\r");
        printf("  |\n\r");
    }else if(patt % 8 == 2){
        printf("  |\n\r");
        printf("  |\n\r");
    }else if(patt % 8 == 3){
        printf("  |\n\r");
        printf(" _\n\r");
    }else if(patt % 8 == 4){
        printf("\n\r");
        printf(" _\n\r");
    }else if(patt % 8 == 5){
        printf("|\n\r");
        printf(" _\n\r");
    }else if(patt % 8 == 6){
        printf("|\n\r");
        printf("|\n\r");
    }else if(patt % 8 == 7){
        printf(" _\n\r");
        printf("|\n\r");
    }

    while (1)
    {
        uint64_t type = rand();
        myled = !myled;

        for (int i = 0; i < 8; i = i + 1)
        {
            display = table[i];
            if(mode == 1) type = rand();

            uint64_t later = Kernel::get_ms_count();

            if(type % 4 == 0){
                ThisThread::sleep_for(62ms);
            }else if(type % 4 == 1){
                ThisThread::sleep_for(62ms);
                ThisThread::sleep_for(62ms);
            }else if(type % 4 == 2){
                ThisThread::sleep_for(62ms);            
                ThisThread::sleep_for(62ms);
                ThisThread::sleep_for(62ms);
                ThisThread::sleep_for(62ms);
            }else if(type % 4 == 3){
                ThisThread::sleep_for(62ms);
                ThisThread::sleep_for(62ms);
                ThisThread::sleep_for(62ms);
                ThisThread::sleep_for(62ms);
                ThisThread::sleep_for(62ms);
                ThisThread::sleep_for(62ms);
                ThisThread::sleep_for(62ms);
                ThisThread::sleep_for(62ms);
            }

            if(!mypin && !ans){
                score += 25 - (later - now) / 1000 - type % 4;
                if(i > patt % 4) score -= i - patt % 4;
                if(i < patt % 4) score -= patt % 4 - i;
                i--;
                printf("score: %u\n\r", (uint32_t)score);
                ans = 1;
            }
        }
    }
}