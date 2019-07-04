#ifndef DRAGON_CURVE_H
#define DRAGON_CURVE_H

typedef enum direction_encoding {
    NORTH,
    EAST,
    SOUTH,
    WEST 
} direction;

typedef struct dragon_curve {
    direction * turns;
} dragon;

#endif
