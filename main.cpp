#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include "imageio.h"
#include "invert.h"

int main(){
//Task A Convert inImage.pgm to the reciprocal version swapping the colors around
  Invert("inImage.pgm");
  //file is outImage.pgm

  //Task B Converts inImage.pgm where only the right half of the image is swapped like in Task A

  //file is outImage2.pgm
  Invert_right("inImage.pgm");

  //Task C Converts inImage.pgm to have a white box in the center of the image

  //file is outImage3.pgm
  box("inImage.pgm");

  //Task D Converts inImage.pgm to have a white box in the center of the image that only takes a 1 pixel frameinstead of a fully shaded in white bpx

  //file is outImage4.pgm
  frame("inImage.pgm");

// Task E doubles the size of inImage.pgm
//file is outImage5.pgm
  doubling("inImage.pgm");

// Task F pixelates the image of inImage.pgm
//file is outImage6.pgm
  pixelate("inImage.pgm");

return 0;
}
