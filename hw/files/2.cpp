#include <iostream>
#include <fstream>
#include <iomanip>

int file2hex(/*int argc, const char* argv[]*/const char* inp="ex.txt", const char* outp="x.txt") {
    setlocale(LC_ALL, "rus");
    /*if (argc < 3)
    {
        std::cout << "Wrong input\n";
        std::cout << "Usage: Files inFile_name, outFile_name\n";
        return 1;
    }
    */
    std::ifstream in(/*argv[1]*/"ex.txt");
    if (!in.is_open())
    {
        std::cout << "Input file open error \n";
        return 2;
    }
    else {
        std::cout << "Input file successfully opened\n";
    }
    std::ofstream out(/*argv[2]*/outp);
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

        
        if (c >= 32)
        {
            str_output += c;
        }
        else
        {
            str_output += '.';
        }
        std::cout << std::setfill('0') << std::setw(2) << std::hex << (unsigned int)c << " ";
        counter++;

        if (counter == 8)
            std::cout << " |  ";
        else if (counter == 17) {
            std::cout << "  " + str_output << std::endl;
            counter = 0;
            str_output = "";
            global_counter++;
        }
    }
    if (counter != 0) {
        while (counter < 17)
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
    return file2hex(/*argc, argv*/);
}

