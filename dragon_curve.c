#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "matrix.h"
#include "dragon_curve.h"

typedef unsigned long ulong;

//given step, give direction encoding
int calcStep(ulong step) {
    ulong LowMask = step ^ (step -1);
    ulong AboveMask = LowMask + 1;
    ulong turnBit = step & AboveMask;
    return turnBit > 0;
}

dragon * makeDragon(int size) {
    dragon* _dragon = (dragon *)malloc(sizeof(dragon));
    _dragon->turns = (direction *)malloc(sizeof(direction)*size);
    return _dragon;
}

dragon * generateDragon(int iterations) {
    //NOTE: we're going to arbitrarily default the first line to NORTH
    ulong step,it;
    ulong totalstep = 0;
    
    //calculate total steps
    totalstep = pow(2.0, (double)(iterations));

    dragon * curve = makeDragon(totalstep);
    printf("total steps: %d\n", totalstep);

    //start at 1 for simplicity
    /*for(it = 1; it <= iterations; it++) {
        for(step = 1;step < totalstep;step++) {
        }
    }*/
    return curve;
}


int main(int argc, char** argv) {
    //usage: dragon_curve order output_file [line_size]
    //TODO: implement handling linesize
    int linesize = 4;   //in pixels
    
    if(argc != 3) {
        printf("usage: dragon_curve iterations output_file\n");
        return -1;
    }

    ulong iterations = 1; //default should be 1 because 0 would return an empty file
    iterations = strtol(argv[1], (char**)NULL, 10);
    if(iterations < 1) {
        printf("Need to have more than one iteration");
        //TODO: handle iterations = 0 but output a smartass remark
        return -1;
    }

    //debug
    printf("iterations: %lu\n", iterations);

    dragon * curve = generateDragon(iterations);
    //TODO: really should just do this with an assert
    if(curve == NULL) {
        printf("Failed to allocated dragon.\n");
        return -1;
    }

    char * output_file = argv[2];
    //int draw_success = draw(iterations, output_file);
    //TODO: move draw to image.cpp

	return 0;
}
