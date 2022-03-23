#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include "imageio.h"
#include "invert.h"



void Invert(std::string input){
  int image[MAX_H][MAX_W];
  int h, w;
  readImage(input, image, h, w);

  std::ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) {
		std::cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << std::endl;
	// width, height
	ostr << w << ' ';
	ostr << h << std::endl;
	ostr << 255 << std::endl;

	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << 255 - image[row][col] << ' ';
			ostr << std::endl;
		}
	}
	ostr.close();
	return;


}



void Invert_right(std::string input){
  int image[MAX_H][MAX_W];
  int h, w;
  readImage(input, image, h, w);
  std::ofstream ostr;
  ostr.open("outImage2.pgm");
  if (ostr.fail()) {
    std::cout << "Unable to write file\n";
    exit(1);
  };

  // print the header
  ostr << "P2" << std::endl;
  // width, height
  ostr << w << ' ';
  ostr << h << std::endl;
  ostr << 255 << std::endl;

int right_width = w / 2;


  for (int row = 0; row < h; row++) {
    for (int col = 0; col < w; col++) {
      assert(image[row][col] < 256);
      assert(image[row][col] >= 0);
      if (col >= right_width){
      ostr << 255 - image[row][col] << ' ';
      ostr << std::endl;}
      else{
      ostr << image[row][col] << ' ';
      ostr << std::endl;}
  }


    }

  ostr.close();
  return;}










  void box(std::string input){
    int image[MAX_H][MAX_W];
    int h, w;
    readImage(input, image, h, w);
    std::ofstream ostr;
    ostr.open("outImage3.pgm");
    if (ostr.fail()) {
      std::cout << "Unable to write file\n";
      exit(1);
    }

    // print the header
    ostr << "P2" << std::endl;
    // width, height
    ostr << w << ' ';
    ostr << h << std::endl;
    ostr << 255 << std::endl;

  int right = (w / 4) * 3;
  int left = (w / 4);
  int right2 = (h / 4) * 3;
  int left2 = (h / 4);

    for (int row = 0; row < h; row++) {
      for (int col = 0; col < w; col++) {
        assert(image[row][col] < 256);
        assert(image[row][col] >= 0);
        if ((col <= right && col >= left) && (row <= right2 && row >= left2)){
        ostr << 255  << ' ';
        ostr << std::endl;}
        else{
        ostr << image[row][col] << ' ';
        ostr << std::endl;}
    }


      }

    ostr.close();
    return;}


    void frame(std::string input){
      int image[MAX_H][MAX_W];
      int h, w;
      readImage(input, image, h, w);
      std::ofstream ostr;
      ostr.open("outImage4.pgm");
      if (ostr.fail()) {
        std::cout << "Unable to write file\n";
        exit(1);
      }

      // print the header
      ostr << "P2" << std::endl;
      // width, height
      ostr << w << ' ';
      ostr << h << std::endl;
      ostr << 255 << std::endl;

      int right = (w / 4) * 3;
      int left = (w / 4);
      int right2 = (h / 4) * 3;
      int left2 = (h / 4);

      for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
          assert(image[row][col] < 256);
          assert(image[row][col] >= 0);
          if (((col == right || col == left) && (row <= right2 && row >= left2)) || ((row == right2 || row == left2) && (col <= right && col >= left)) ){
          ostr << 255  << ' ';
          ostr << std::endl;}
          else{
          ostr << image[row][col] << ' ';
          ostr << std::endl;}
      }


        }

      ostr.close();
      return;}





















      void doubling(std::string input){
        int image[MAX_H][MAX_W];
        int h, w;
        readImage(input, image, h, w);
        std::ofstream ostr;
        ostr.open("outImage5.pgm");
        if (ostr.fail()) {
          std::cout << "Unable to write file\n";
          exit(1);
        }

        // print the header
        ostr << "P2" << std::endl;
        // width, height
        ostr << w * 2 << ' ';
        ostr << h * 2 << std::endl;
        ostr << 255 << std::endl;


        int arr[w*2] = {};




        for (int row = 0; row < h; row++) {
          for (int x = 0; x < 2; x++){
          for (int col = 0; col < w; col++) {
            assert(image[row][col] < 256);
            assert(image[row][col] >= 0);
            for (int i = 0; i < 2; i++){
            ostr << image[row][col] << ' ' ;}
            ostr << std::endl;



}

        }


          }

        ostr.close();
        return;

    }


























































          void pixelate(std::string input){
            int image[MAX_H][MAX_W];
            int h, w;
            readImage(input, image, h, w);
            std::ofstream ostr;
            ostr.open("outImage6.pgm");
            if (ostr.fail()) {
              std::cout << "Unable to write file\n";
              exit(1);
            }

            // print the header
            ostr << "P2" << std::endl;
            // width, height
            ostr << w << ' ';
            ostr << h << std::endl;
            ostr << 255 << std::endl;



            int x = 0;





            	for (int row = 0; row < h; row++) {
            		for (int col = 0; col < w; col++) {
            			assert(image[row][col] < 256);
            			assert(image[row][col] >= 0);
                  if (col % 2 == 1 || row % 2 == 0){
                  x = image[row][col];
                  x = x + image[row+1][col];
                  x = x + image[row][col+1];
                  x = x + image[row+1][col+1];
                  x = x/4;}



            			ostr << x << ' ';
            			ostr << std::endl;
            		}
            	}





            ostr.close();
            return;

        }
