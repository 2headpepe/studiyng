//поворотик
void rotation(int rotate = 90,const char* inpic = "NOHOMO.bmp", const char* outpic = "Rotated_pic.bmp")//Sarmat<3
{
	RgbImg img = readRgbImg(inpic);

	if (rotate % 90 != 0)
	{
		std::cout << "Wrong angle!\n";
	}
	else {
		rotate %= 360;
		if (rotate == 90)
		{
			RgbImg new_img = createRgbImg(img.width, img.height, { 0, 0, 0 });
			for (size_t x = 0; x < img.width; x++)
			{
				for (size_t y = 0; y < img.height; y++)
				{
					new_img.pixels[img.width- 1 - x][y] = img.pixels[y][x];
				}
			}
			writeRgbImg(outpic, new_img);
			deleteRgbImg(img);
			deleteRgbImg(new_img);
		}
		else if (rotate == 180) {
            RgbImg new_img = createRgbImg(img.height, img.width, { 0, 0, 0 });
            for (size_t x = 0; x < img.width; x++)
            {
                for (size_t y = 0; y < img.height; y++)
                {
                    new_img.pixels[y][x] = img.pixels[img.height- y - 1][img.width - x - 1];
                }
            }
            writeRgbImg(outpic, new_img);
            deleteRgbImg(img);
            deleteRgbImg(new_img);
        }
        else if (rotate == 270) {
            RgbImg new_img = createRgbImg(img.width, img.height, { 0, 0, 0 });
            for (size_t x = 0; x < img.width; x++)
            {
                for (size_t y = 0; y < img.height; y++)
                {
                    new_img.pixels[x][img.height - 1 - y] = img.pixels[y][x];
                }
            }
            writeRgbImg(outpic, new_img);
            deleteRgbImg(new_img);
            deleteRgbImg(img);
        }
    }
}
int main(int argc, const char* argv[])
{		
	try {
		//prep_for_conv();
		//Mediana();
		rotation();
	}
	catch (std::exception const& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}
