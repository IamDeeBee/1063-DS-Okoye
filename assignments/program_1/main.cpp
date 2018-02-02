/**
* @ProgramName: Program-1
* @Author: Nodebechukwu Okoye
* @Description:
*     This program reads in images stored as rgb values in a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2018
* @Date: 30 01 2018
*/
#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

/**
Structure to hold an rgb value
*/
struct rgb {
	int r;
	int g;
	int b;

	rgb() {
		r = 0;
		g = 0;
		b = 0;
	}
};
/**
* @FunctionName: writeFile
* @Description:
*     Outputs  the RGB values of the 2D array to a file
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void writeFile(rgb** image, int width, int height) {
	ofstream ofile;
	ofile.open("bot2.txt");
	ofile << width << " " << height << endl;
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			ofile << image[i][j].r << " " << image[i][j].g << " " << image[i][j].b << " ";
		}
		ofile << endl;
	}
	cout << "Image edited\n";
}
/**
* @FunctionName: flipVert
* @Description:
*    flips every RGB value in  the 2d array vertically
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void flipVert(rgb** image, int width, int height) {
	rgb temp;
	for (int i = 0; i < height/2; i++){
		for (int j = 0; j < width; j++) {
			temp = image[i][j];
			image[i][j] = image[height - 1 - i][j];

			image[height - 1 - i][j] = temp;
		}
	}

	writeFile(image, width, height);
}
/*
* @FunctionName: flipHorz
* @Description:
*    flips every RGB value in  the 2d array horizontally
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void flipHorz(rgb** image, int width, int height) {
	rgb temp;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width / 2; j++) {
			temp = image[i][j];
			image[i][j] = image[i][height - 1 - j];

			image[i][height - 1 - j] = temp;

		}
	}
	writeFile(image, width, height);
}
/**
* @FunctionName: grayScale
* @Description:
*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void grayScale(rgb** image, int width, int height) {
	int r, g, b, gray;
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			r = image[i][j].r;
			g = image[i][j].g;
			b = image[i][j].b;

			gray = (r + g + b) / 3;

			image[i][j].r = gray;
			image[i][j].g = gray;
			image[i][j].b = gray;
		}
	}
	writeFile(image, width, height);
}


int main() {
	int uInput = 0;
	ifstream ifile;          //Input / output files
	ifile.open("input.txt");
	

	int width;               //width of image
	int height;              //height of image

	rgb **imgArray;         //Pointer var for our 2D array because we         
							//don't know how big the image will be!

	ifile >> width >> height;   //Read in width and height from top of input file
								//We need this so we can make the array the right 
								//size. After we get these two values, we can
								//now allocate memory for our 2D array.


	imgArray = new rgb*[height];    //This array points to every row

	for (int i = 0; i<height; i++) {
		imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
	}

	//Read the color data in from our txt file
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			ifile >> imgArray[i][j].r >> imgArray[i][j].g >> imgArray[i][j].b;
		}
	}
	cout << "What would you like to do with this image\n";
	cout << "1\tFlip Vertical\n";
	cout << "2\tFlip Horizontal\n";
	cout << "3\tGray Scale\n";

	cout << "Input number ";
	cin >> uInput;

	//We could make any changes we want to the color image here
	if (uInput == 1) {
		cout << "Flipping Image Vertically\n";
		flipVert(imgArray, width, height);
	}else if(uInput == 2) {
		cout << "Flipping Image Horizontally\n";
		flipHorz(imgArray, width, height);
	}else if (uInput ==3) {
		cout << "Gray Scaling Image\n";
		grayScale(imgArray, width, height);
	}
	else {
		//Write out our color data to a new file
		writeFile(imgArray, width, height);
	}

	
	system("pause");
	return 0;
}
