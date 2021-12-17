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
int main(int argc, const char* argv[])
{		
	try {
		BLM();
	}
	catch (std::exception const& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}
