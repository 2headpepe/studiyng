#include <iostream>
#include <fstream>
#include <iomanip>
std::string fill(int count, char sign)
{
    std::string str = "";
    for (int i = 0; i < count; ++i) str+= sign;
    return str;
}
std::string to_hex(int x)
{
    std::string str;
    while (x)
    {
        if (x % 16 < 10) str = char(x % 16 + '0')+str;
        else str = char(x % 16 + 'A' - 10)+str;
        x /= 16;
    }
    while (str.length() < 2) str = "0" + str;
    return str;
}

int file2hex(/*int argc, const char* argv[]*/const char* inp = "ex.txt", const char* outp = "x.txt") {
    setlocale(LC_ALL, "rus");
    /*if (argc < 3)
    {
        std::cout << "Wrong input\n";
        std::cout << "Usage: Files inFile_name, outFile_name\n";
        return 1;
    }
    */
    int res = 0;
    std::ifstream in(/*argv[1]*/"ex.txt", std::ios_base::binary);
    if (!in.is_open())
    {
        std::cout << "Input file open error \n";
        return 2;
    }
    else {
        std::cout << "Input file successfully opened\n";
    }
    std::ofstream out(/*argv[2]*/outp, std::ios_base::binary);
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
    while ((c = in.get())!=(unsigned char)EOF)
    {
        
        if (counter == 0)
        {
            
            out << fill(10,'0')<<to_hex(global_counter*16) << ": ";
        }

        if (c >= 32)
        {
            str_output += c;
        }
        else
        {
            str_output += '.';
        }
        out << to_hex(c) << " ";
        counter++;
        res++;

        if (counter == 8)
            out << " |  ";
        else if (counter == 17) {
            out << "  " + str_output << std::endl;
            counter = 0;
            str_output = "";
            global_counter++;
        }
    }
    if (counter != 0) {
        while (counter < 17)
        {
            out << "   ";
            if (counter == 7)
                out << " |  ";

            counter++;
            res++;
        }
        out << "  " + str_output << std::endl;
    }
    in.close();
    out.close();
    out << "Files are closed successfully (^_^)\n" << counter << " " << res;
    return 0;
}

int main(int argc, const char* argv[]) {
    return file2hex(/*argc, argv*/);
}

