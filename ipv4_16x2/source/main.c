/* main.c */
/* 0 copyright/licensing */
//made by githubuser addei
//GPL 2.0

/* 1 includes */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
 
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>


#include <wiringPi.h>
#include <lcd.h>


/* 2 defines */

//NETWORK INTERFACE CONFIGURATION
#define interface "eth0"

//LCD CONFIGURATION
#define columns 16
#define rows 2
#define bits 4

#define lcd_rs 25 //grey -> PIN 37
#define lcd_en 24 //green -> PIN 35
#define lcd_db4 23 //orange -> PIN 33
#define lcd_db5 22 //yellow -> PIN 31
#define lcd_db6 21 //blue -> PIN 29
#define lcd_db7 29 //brown -> PIN 40

/* 3 external declarations */
/* 4 typedefs */
/* 5 global variable declarations */


/* 6 function prototypes */

int getIPv4addr(unsigned char *ip_address);
int WiringPi_LCD_init(int *handle);

int main(int argc, char *argv[]) {
/* 7 command-line parsing */

    // WIRING Pi + LCD INITIALIZATION
    int lcd;
    
    if ((WiringPi_LCD_init(&lcd)) != 0) {
        printf("ERROR! LCD initialization failed!\n");
        return -1;
    }

    else {
        lcdHome(lcd);
        lcdClear (lcd);
        sleep(0.5);
        lcdPosition(lcd, 0, 0);
        lcdPrintf(lcd, "IP Address: ");
        unsigned char ipv4_address[15];
        getIPv4addr(ipv4_address);
        lcdPosition(lcd, 0, 1);
        lcdPrintf(lcd, ipv4_address);
    }
    return 0;
}

/* 8 function declarations */

int getIPv4addr(unsigned char *ip_address) {

    int fd;
    struct ifreq ifr;

    /*AF_INET - to define network interface IPv4*/
    /*Creating soket for it.*/
    fd = socket(AF_INET, SOCK_DGRAM, 0);

    /*AF_INET - to define IPv4 Address type.*/
    ifr.ifr_addr.sa_family = AF_INET;

    /*interface - define the ifr_name - port name
    where network attached.*/
    memcpy(ifr.ifr_name, interface, IFNAMSIZ-1);

    /*Accessing network interface information by
    passing address using ioctl.*/
    ioctl(fd, SIOCGIFADDR, &ifr);
    /*closing fd*/
    close(fd);

    /*Extract IP Address*/
    strcpy(ip_address,inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));

    return 0;

}

int WiringPi_LCD_init(int *handle) {

    wiringPiSetup ();
    *handle = lcdInit (rows, columns, bits, lcd_rs, lcd_en, lcd_db4, lcd_db5, lcd_db6, lcd_db7, 0, 0, 0, 0);
    if(handle < 0) {
        return -1;
    }
    return 0;

}
