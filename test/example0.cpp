#include <stdio.h>      // printf
#include "QRBG.h"

int main(int argc, char* argv[]) {
    QRBG rndService;
    rndService.defineServer("random.irb.hr", 1227);
    rndService.defineUser("username", "password");

    // acquire some of supported types: byte, integer, long integer, float and double
    printf("QRBG service returned byte: %x \n", rndService.getByte());
    printf("QRBG service returned integer: %x \n", rndService.getInt());
    printf("QRBG service returned long integer: %lx \n", rndService.getLongInt());
    printf("QRBG service returned float: %f \n", rndService.getFloat());
    printf("QRBG service returned double: %f \n", rndService.getDouble());

    // acquire arbitrary number of random floats
    const int size = 10;
    float n[size];
    printf("Requesting %d random floats.. ", size);
    rndService.getFloats(n, size);
    printf("Received:\n");
    float min = 1, max = -1, sum = 0, avg;
    for (int i = 0; i < size; i++) {
        if (n[i] < min) min = n[i];
        if (n[i] > max) max = n[i];
        sum += n[i];
        printf("%f\n", n[i]);
    }
    avg = sum / size;
    printf("min = %f, max = %f, sum = %f, avg = %f \n", min, max, sum, avg);
}
