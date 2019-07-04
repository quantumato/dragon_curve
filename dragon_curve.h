#ifndef DRAGON_CURVE_H
#define DRAGON_CURVE_H

/*enum direction {
    NORTH,
    EAST,
    SOUTH,
    WEST 
};*/

#define NORTH (unsigned char)0
#define EAST (unsigned char)1
#define SOUTH (unsigned char)2
#define WEST (unsigned char)3

typedef struct dragon_curve {
    long totalsteps;
    unsigned char* turns;
} dragon;

#endif
