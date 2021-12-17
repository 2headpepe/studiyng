#include <iostream>
#include<fstream>
#include<algorithm>
#include "BmpStructures.h"
#include "ImgFunctions.h"

void testBmpIo()
{
	printImgInfo("masterpiece.bmp");
	RgbImg img = readRgbImg("masterpiece.bmp");
	for (size_t row = 0; row < 50; ++row)
		for (size_t col = 0; col < 50; ++col)
		{
			img.pixels[row][col].Blue = 255;
			img.pixels[row][col].Green = 128;
			img.pixels[row][col].Red = 0;
			//img.pixels[row][col] = {255, 255, 255}; //same as above
		}
	writeRgbImg("out\\ugly_copy.bmp", img);
	deleteRgbImg(img);
}

//Generate dummy image example
void genImgWithSquare()
{
	RGB background = { 255, 128, 0 };
	RgbImg img = createRgbImg(600, 600, background);
	for (size_t row = 50; row < 200; ++row)
		for (size_t col = 100; col < 400; ++col)
			img.pixels[row][col] = { 128, 255, 0 };

	writeRgbImg("out\\ai_masterpiece.bmp", img);
	deleteRgbImg(img);
}

//Autobalancing example
void testAutolevels()
{
	RgbImg img = readRgbImg("data\\Lenna.bmp");
	RgbImg balanced = autolevels(img);
	writeRgbImg("out\\Lenna_avtolevels.bmp", img);
	deleteRgbImg(img);
}

//Another autobalancing example
void testGrayworld()
{
	RgbImg img = readRgbImg("data\\sinichka.bmp");
	RgbImg balanced = grayworld(img);
	writeRgbImg("out\\grayworld.bmp", balanced);
	deleteRgbImg(img);
}

//Box filter example
void testBoxFilter()
{
	RgbImg img = readRgbImg("xxx.bmp");
	RgbImg filtered = convolution(img, 7);
	writeRgbImg("xxx1.bmp", filtered);
	deleteRgbImg(img);
	deleteRgbImg(filtered);
}

void testKernelFilter()
{
	size_t const kern_sz = 3;
	double** kernel = new double* [kern_sz];
	for (size_t row = 0; row < kern_sz; ++row)
	{
		kernel[row] = new double[kern_sz];
		for (size_t col = 0; col < kern_sz; ++col)
			kernel[row][col] = 1. / 9;
	}
	RgbImg img = readRgbImg("xxx.bmp");
	RgbImg filtered = convolution(img, 3, kernel);
	writeRgbImg("xxx1.bmp", filtered);
	deleteRgbImg(img);
	deleteRgbImg(filtered);
}

void testContours()
{
	RgbImg img = readRgbImg("data\\sinichka.bmp");
	RgbImg contour_img = contours(img);
	writeRgbImg("out\\contours.bmp", contour_img);
	deleteRgbImg(img);
	deleteRgbImg(contour_img);
}
void rotating(const char* in = "anime.bmp", int rotate = 90, const char* out = "Rotated_pic.bmp")//50/50
{
	RgbImg img = readRgbImg(in);
	RgbImg new_img = createRgbImg(img.width, img.height, { 0,0,0 });
	rotate %= 360;
	//while (rotate)
	//{
		//rotate -= 90;
		for (size_t i = 0; i < img.width; ++i)
		{
			for (size_t j = 0; j < img.height; ++j)
			{
				new_img.pixels[i][j].Blue = img.pixels[j][i].Blue;
				new_img.pixels[i][j].Red = img.pixels[j][i].Red;
				new_img.pixels[i][j].Green = img.pixels[j][i].Green;
			}
		}
	//}
	writeRgbImg(out, new_img);
	deleteRgbImg(new_img);
	deleteRgbImg(img);
}
void BLM(const char* name = "NOHOMO.bmp", const char* outname = "HOMO.bmp")//working
{
	RgbImg img = readRgbImg(name);
	RgbImg new_img = createRgbImg(img.height, img.width, { 0,0,0 });
	for (size_t i = 0; i < img.width; ++i)
	{
		for (size_t j = 0; j < img.height; ++j)
		{
			new_img.pixels[j][i].Blue = (img.pixels[j][i].Blue + img.pixels[j][i].Red + img.pixels[j][i].Green) / 3;
			new_img.pixels[j][i].Red = (img.pixels[j][i].Blue + img.pixels[j][i].Red + img.pixels[j][i].Green) / 3;
			new_img.pixels[j][i].Green=( img.pixels[j][i].Blue+img.pixels[j][i].Red + img.pixels[j][i].Green)/3;
		}
	}
	writeRgbImg(outname, new_img);
	deleteRgbImg(img);
	deleteRgbImg(new_img);
}

void rotation(const char* inpic = "NOHOMO.bmp", const char* outpic = "Rotated_pic", int angle = 90)//Sarmat<3
{
	RgbImg iimg = readRgbImg(inpic);
	int h = iimg.height, w = iimg.width;
	if (angle % 90 != 0)
	{
		std::cout << "Wrong angle!\n";
	}
	else {
		while (angle >= 360)
		{
			angle -= 360;
		}
		if (angle == 90)
		{
			RgbImg oimg = createRgbImg(w, h, { 0, 0, 0 });
			for (size_t x = 0; x < w; x++)
			{
				for (size_t y = 0; y < h; y++)
				{
					oimg.pixels[w - 1 - x][y] = iimg.pixels[y][x];
				}
			}
			writeRgbImg(outpic, oimg);
			deleteRgbImg(iimg);
			deleteRgbImg(oimg);
		}
	}
}
void prep_for_conv(const char* name = "xxx1.bmp", const char* out = "yyy.bmp")
{
	testBoxFilter();
	RgbImg img = readRgbImg(name);
	size_t t = 3;
	double** ker = new double* [3];
	for (int i = 0; i < 3; ++i) ker[i] = new double[3];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			std::cout << "[" << i << "," << j << "]";
			std::cin >> ker[i][j];
		}
	writeRgbImg(out, convolution(img, t, ker));
	deleteRgbImg(img);
	delete[] ker;

}
void BubbleSort(int* M, int n) {
	for (int j = 0; j < n - 1; ++j) {
		bool isSorted = true;
		for (int i = n - 1; i > j; --i) {
			if (M[i] < M[i - 1]) {
				std::swap(M[i], M[i - 1]); // T tmp=M[i]; M[i]=M[i-1]; M[i-1]=M[i];
				isSorted = false;
			}
		}
		if (isSorted) break;
	}
}
void Mediana(int n=3,const char* name = "xxx.bmp", const char* out = "yyy.bmp")
{
	RgbImg img = readRgbImg(name);
	int half = n / 2;
	for (size_t row = half; row < img.height-half; ++row)
	{
		for (size_t col = half; col < img.width-half; ++col)
		{

			int* mas_r = new int[n * n];
			int* mas_g = new int[n * n];
			int* mas_b = new int[n * n];
			for (size_t i = 0; i < n; ++i)
				for (size_t j = 0; i < n; ++j)
				{
					size_t i_m = row+i-half,j_m=col-half+j;
					mas_r[i * 3 + j] = img.pixels[i_m][j_m].Red;
					mas_g[i * 3 + j] = img.pixels[i_m][j_m].Green;
					mas_b[i * 3 + j] = img.pixels[i_m][j_m].Blue;
				}
			BubbleSort(mas_r, n * n);
			BubbleSort(mas_g, n * n);	
			BubbleSort(mas_b, n * n);
			
			img.pixels[row][col].Red = mas_r[n * n / 2 + 1];
			img.pixels[row][col].Green = mas_g[n * n / 2 + 1];
			img.pixels[row][col].Blue = mas_b[n * n / 2 + 1];

			delete[] mas_b;
			delete[] mas_r;
			delete[] mas_g;
		}
	}
	writeRgbImg(out, img);
	deleteRgbImg(img);
}
int main(int argc, const char* argv[])
{		
	try {
		//prep_for_conv();
		Mediana();
	}
	catch (std::exception const& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}
