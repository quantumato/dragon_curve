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

direction calcDir(direction currDir, int turn) {
    if(turn == 0) turn = -1;
    return (unsigned long)((currDir + turn) & 0x3);
}

dragon * makeDragon(int size) {
    dragon* _dragon = (dragon *)malloc(sizeof(dragon));
    _dragon->turns = (direction *)malloc(sizeof(direction)*size);
    return _dragon;
}

dragon * generateDragon(int iterations) {
    //NOTE: we're going to arbitrarily default the 0th step to NORTH
    ulong step,it;
    ulong totalstep = 0;
    int turndir;
    
    //calculate total steps
    totalstep = pow(2.0, (double)(iterations));

    dragon * curve = makeDragon(totalstep);
    printf("total steps: %d\n", totalstep);

    //start at 1 since we hard code 0 to be a line north
    for(step = 0;step < totalstep;step++) {
        turndir = calcStep(step);


        //curve->turns[step] = calc
    }
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
    direction testDir = NORTH;
    printf("direction NORTH: %d\n", testDir);
    printf("test NORTH turn LEFT: %lu\n", calcDir(testDir, 0));

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
