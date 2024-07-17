#include <reg51.h>
#include<stdio.h>
#include<math.h>

#define PI 3.14159265
sbit w = P0^7;
float dfreq = 0.02; // frequency factor

// Define keypad rows and columns
sbit ROW1 = P0^3;
sbit ROW2 = P0^2;
sbit ROW3 = P0^1;
sbit ROW4 = P0^0;
sbit COL1 = P0^6;
sbit COL2 = P0^5;
sbit COL3 = P0^4;

int offset = 128;

int signal_num = -1;
int frequency_num = 0;
int T;
int amplitude_num = 0;
int amp;
int DAC_num = -1;

int WaveValues0[30] = {36, 42, 48, 53, 56, 59, 60, 60, 57, 54, 50, 44, 38, 32, 25, 19, 13, 8, 4, 1, 0, 0, 1, 4, 8, 13, 19, 25, 32};

// Square Wave Generation
void square() {
    int i = 0;
    w = 0;
    P1 = 0x00;
    while (i < T) {
        P1 = 0x00;
        i++;
    }
    while (i > 0) {
        P1 = amp;
        i--;
    }
}

// Triangle Wave Generation
void generateTriangle() {
    int a = 0;
    int t = 0;
    P1 = 0x00;
    w = 0;
    while (t < T) {
        a = a + (amp / T);
        t++;
        P1 = a;
    }
    while (t > 0) {
        a = a - (amp / T);
        t--;
        P1 = a;
    }
}

// Sawtooth Wave Generation
void generateSaw() {
    int a = 0;
    int n = 0;
    w = 0;
    P1 = 0x00;
    while (n < T) {
        a = a + (amp / T);
        P1 = a;
        n++;
    }
    P1 = 0x00;
}

// Sine Wave Generation
void generateSine() {
    int i;
    int a = T / 2;
    w = 0;
    if (amplitude_num == 0) {
        for (i = 0; i < 29; i = i + a) {
            P1 = WaveValues0[i];
        }
    }
    if (amplitude_num == 1) {
        for (i = 0; i < 29; i = i + a) {
            P1 = 2 * WaveValues0[i];
        }
    }
    if (amplitude_num == 2) {
        for (i = 0; i < 29; i = i + a) {
            P1 = 4 * WaveValues0[i];
        }
    }
}

// Keypad Scanning
unsigned char scan_keypad() {
    ROW1 = 0; ROW2 = 1; ROW3 = 1; ROW4 = 1;
    if (COL1 == 0) { signal_num++; return keypad[0][0]; }
    if (COL2 == 0) { amplitude_num++; return keypad[0][1]; }
    if (COL3 == 0) { frequency_num++; return keypad[0][2]; }

    ROW1 = 1; ROW2 = 0; ROW3 = 1;
    if (COL2 == 0) { DAC_num++; return keypad[1][1]; }

    return 0;
}

// Signal Plotting
void signal_plot() {
    if (signal_num > 4) {
        signal_num = 0;
    }
    if (frequency_num > 3) {
        frequency_num = 0;
    }
    if (amplitude_num > 3) {
        amplitude_num = 0;
    }

    if (amplitude_num == 0) {
        amp = 63;
    }
    if (amplitude_num == 1) {
        amp = 127;
    }
    if (amplitude_num == 2) {
        amp = 255;
    }

    if (frequency_num == 0) {
        T = 2;
    }
    if (frequency_num == 1) {
        T = 4;
    }
    if (frequency_num == 2) {
        T = 8;
    }

    if (signal_num == 0) {
        generateSine();
    }
    if (signal_num == 1) {
        square();
    }
    if (signal_num == 2) {
        generateTriangle();
    }
    if (signal_num == 3) {
        generateSaw();
    }
}

// Resolution Setting
void resolution() {
    int n;
    int T = 750;
    if (DAC_num == 0) {
        offset = 3;
        n = 7;
    }
    if (DAC_num == 1) {
        offset = 16;
        n = 32;
    }
}

// Main Function
void main() {
    unsigned char key;
    while (1) {
        key = scan_keypad();
        if (DAC_num < 2) {
            resolution();
        }
        offset = 128;
        signal_plot();
    }
}
