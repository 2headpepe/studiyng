void rotating(const char* in = "bird.bmp", int rotate = 90, std::string out = "Rotated_pic.bmp")
{
	RgbImg img = readRgbImg(in);
	RgbImg new_img = createRgbImg(img.width, img.height, { 0,0,0 });
	rotate %= 360;
	while (rotate)
	{
		rotate -= 90;
		for (size_t i = 0; i < img.width; ++i)
		{
			for (size_t j = 0; j < img.height; ++j)
			{
				new_img.pixels[j][i].Blue = img.pixels[i][j].Blue;
				new_img.pixels[j][i].Red = img.pixels[i][j].Red;
				new_img.pixels[j][i].Green = img.pixels[i][j].Green;
			}
		}
	}
	writeRgbImg("SARMATlove.bmp", new_img);
	deleteRgbImg(new_img);
	deleteRgbImg(img);
}	
int main(int argc, const char* argv[])
{		
	try {
		rotating();

	}
	catch (std::exception const& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}
