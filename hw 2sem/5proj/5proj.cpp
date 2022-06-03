    #include"boolexpr.h"
    #include"formulaNode.h"
    BooleanExpression begin(std::ifstream& in)
    {
        char c;
        int i = 1;
        int j = 0;
        while ((c = in.get()) != EOF)
        {
            if (c == '\n')
                ++i;
        }
        in.clear();
        in.seekg(0);


        char** res = new char* [i];
        int resCount = 0;

        j = 0;
        i = 0;

        bool countX[10]{ 0 };
        int flag = 0;
        int xNum = 0;
        while ((c = in.get()) != EOF)
        {
            if (c == 'x') flag = 1;
            else if ((flag) && ((c > '9') || (c < '0')))
            {
                flag = 0;
                if (!countX[xNum]) ++resCount;
                countX[xNum] = 1;
                xNum = 0;
            }
            else if (flag)
            {
                xNum *= 10;
                xNum += c - '0';
            }

            ++j;
            if (c == '\n')
            {
                res[i++] = new char[j + 1];
                j = 0;
            }
        }
        if ((!countX[xNum]) && (flag)) ++resCount;
        res[i++] = new char[j + 1];
        in.clear();
        in.seekg(0);
        for (int _i = 0; _i < i; ++_i)
        {
            j = 0;
            while (((c = in.get()) != '\n') && (c != EOF))
            {
                res[_i][j++] = c;
            }
            res[_i][j] = '\0';
        }

        BooleanExpression result(i, res, resCount);
        return result;
    }
    int main(int argc, char* argv[])
    {   
        
        std::ifstream in("in.txt");
        if (!in.is_open()) return -2;
        BooleanExpression x{ begin(in) };
        std::ofstream out("out.txt");
        if (!out.is_open()) return -2;
        x.isFull(out);
        in.close();
        out.close();

       /*if ((argc == 3) && (argv[1][0] == '-') && (argv[1][1] == 't') && (argv[1][2] == 'a') && (argv[1][3] == 'b') && (argv[1][4] == 'l') 
            && (argv[1][5] == 'e'))
        {
            std::ifstream in(argv[2]);
            if (!in.is_open()) return -2;
            BooleanExpression x{ begin(in) };
            x.truthTabel();

            in.close();
        }
        if (argc == 2)
        {
            if (((argv[1][0] == '-') && (argv[1][1] == 'h')) || (argv[1][0] = '?'))
            {
                std::cout << "____________________"<<std::endl;
                std::cout << "boolcalc - calc input output" << std::endl;
                std::cout << "boolcalc -cnf input output" << std::endl;
                std::cout << "boolcalc -dnf input output" << std::endl;
                std::cout << "boolcalc -zh input output" << std::endl;
                std::cout << "boolcalc -table input" << std::endl;
                std::cout << "boolcalc -isfull input output" << std::endl;
                std::cout << "____________________"<<std::endl;
            }
        }
        if (argc == 4)
        {
            if ((argv[1][0] == '-') && (argv[1][1] == 'c') && (argv[1][2] == 'a') && (argv[1][3] == 'l') && (argv[1][4] == 'c'))
            {
                std::ifstream in(argv[2]);
                if (!in.is_open()) return -2;
                BooleanExpression x{ begin(in) };
                std::ofstream out(argv[3]);
                if (!out.is_open()) return -2;
                for (int i = 0; i < x.count; ++i) out<<x.F[i]._calc()<<std::endl;
                in.close();
                out.close();
            }
            if ((argv[1][0] == '-') && (argv[1][1] == 'c') && (argv[1][2] == 'n') && (argv[1][3] == 'f'))
            {
                std::ifstream in(argv[2]);
                if (!in.is_open()) return -2;
                BooleanExpression x{ begin(in) };
                std::ofstream out(argv[3]);
                if (!out.is_open()) return -2;
                x.cnf(out);
                in.close();
                out.close();
            }
            if ((argv[1][0] == '-') && (argv[1][1] == 'd') && (argv[1][2] == 'n') && (argv[1][3] == 'f'))
            {
                std::ifstream in(argv[2]);
                if (!in.is_open()) return -2;
                BooleanExpression x{ begin(in) };
                std::ofstream out(argv[3]);
                if (!out.is_open()) return -2;
                x.dnf(out);
                in.close();
                out.close();
            }
            if ((argv[1][0] == '-') && (argv[1][1] == 'z') && (argv[1][2] == 'h'))
            {
                std::ifstream in(argv[2]);
                if (!in.is_open()) return -2;
                BooleanExpression x{ begin(in) };
                std::ofstream out(argv[3]);
                if (!out.is_open()) return -2;
                x.zheg(out);
                in.close();
                out.close();
            }
            if ((argv[1][0] == '-') && (argv[1][1] == 'i') && (argv[1][2] == 's') && (argv[1][3] == 'f') && (argv[1][4] == 'u') && (argv[1][5] == 'l')
                && (argv[1][6] == 'l'))
            {
                std::ifstream in(argv[2]);
                if (!in.is_open()) return -2;
                BooleanExpression x{ begin(in) };
                std::ofstream out(argv[3]);
                if (!out.is_open()) return -2;
                x.isFull(out);
                in.close();
                out.close();
            }


        }*/



       /*
        result.truthTabel();
        result.cnf();
        result.dnf();
        result.zheg();
        std::cout <<( (result.isFull()) ? "yes" : "no");*/
    }

