void rotating(const char* in, int rotate, std::string out)
{
	RgbImg img = readRgbImg(in);
	RgbImg new_img = createRgbImg(img.height, img.width, { 0,0,0 });
	rotate %= 360;
	while (rotate)
	{
		rotate -= 90;
		for (size_t i = 0; i < img.width; ++i)
		{
			for (size_t j = 0; j < img.height; ++j)
			{
				new_img.pixels[i][j].Blue = img.pixels[i][j].Blue;
				new_img.pixels[i][j].Red = img.pixels[i][j].Red;
				new_img.pixels[i][j].Green = img.pixels[i][j].Green;
			}
		}
	}
	writeRgbImg("SARMAT<3.bmp", new_img);
}	
int main(int argc, const char* argv[])
{		
	try {
		rotating(argv[1], (int)argv[2], argv[3]);

	}
	catch (std::exception const& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}
