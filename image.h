#ifndef IMAGE_HPP
#define IMAGE_HPP
#include "matrix.hpp"
#include<string>

/* RGB
 * Holds the RGB data for each pixel
 */
struct RGB {
	unsigned char R, G, B;
};

/* image 
 * Holds the data for a PPM file
 */
class image {
	public:
		image();
		image(int w, int h);
	
	private:
		matrix<RGB> m;
		char magic[];	//defaults to P6
};
#endif
