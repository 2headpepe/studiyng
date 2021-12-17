#include <iostream>
#include <fstream>
#include<iomanip>

int file2hex(int argc, const char* argv[]) {
    if (argc < 3)
    {
        std::cout << "Wrong input\n";
        std::cout << "Usage: Files inFile_name, outFile_name\n";
        return 1;
    }
    std::ifstream in(argv[1]);
    if (!in.is_open())
    {
        std::cout << "Input file open error \n";
        return 2;
    }
    else {
        std::cout << "Input file successfully opened\n";
    }


    std::ofstream out(argv[2]);

    if (!out.is_open())
    {
        std::cout << "Output file open error \n";
        return 3;
    }
    else {
        std::cout << "Output file successfully opened\n";
    }



    unsigned char c;
    std::string str_output = "";
    int counter = 0, global_counter = 0;
    while ((c = in.get()) != (unsigned char)EOF)
    {
        if (counter == 0)
            std::cout << std::setfill('0') << std::setw(10) << std::hex << 16 * global_counter << ": ";

        str_output += c;

        std::cout << std::setfill('0') << std::setw(2) << std::hex << (unsigned int)c << " ";
        counter++;

        if (counter == 7)
            std::cout << " |  ";
        else if (counter == 15)
        {
            std::cout << "  " + str_output << std::endl;
            counter = 0;
            str_output = "";
            global_counter++;
        }
    }
    if (counter != 0)
    {
        while (counter < 16)
        {
            std::cout << "   ";
            if (counter == 7)
                std::cout << " |  ";
            counter++;
        }
        std::cout << "  " + str_output << std::endl;
    }
    in.close();
    out.close();
    std::cout << "Files are closed successfully (^_^)\n";
    return 0;
}

int main(int argc, const char* argv[]) {


    return file2hex(argc, argv);
}
