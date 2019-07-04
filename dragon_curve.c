#include<cstdio>
#include<cstdlib>

long calcDirection(long step) {
}

void draw(long iterations, char * outputfile) {
    
}

int main(int argc, char** argv) {
    //usage: dragon_curve order output_file
    if(argc != 3) {
        printf("usage: dragon_curve iterations output_file\n");
        return -1;
    }

    long iterations = 1; //default should be 1 because 0 would return an empty file
    iterations = strtol(argv[1], (char**)NULL, 10);
    if(iterations < 1) {
        printf("Need to have more than one iteration");
        //TODO: handle iterations = 0 but output a smartass remark
        return -1;
    }

    //debug
    printf("iterations: %d\n", iterations);

    char * output_file = argv[2];
    int draw_success = draw(iterations, output_file);
    //TODO: probably should check that value

	return 0;
}
