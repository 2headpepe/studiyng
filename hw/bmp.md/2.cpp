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
