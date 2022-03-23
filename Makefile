main: main.o imageio.o invert.o
	g++ -o main main.o imageio.o invert.o

main.o: main.cpp imageio.h invert.h

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h

invert.o: invert.cpp invert.h

clean:
	rm -f a.out main main.o sample sample.o imageio.o invert.o outImage.pgm outImage2.pgm outImage3.pgm outImage4.pgm outImage5.pgm outImage6.pgm
