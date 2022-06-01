#include"boolexpr.h"
int main()
{
    std::ifstream in("in.txt");
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
    j = 0;
    i = 0;
    bool countX[256]{ 0 };
    int resCount = 0;
    int flag = 0;
    int xNum=0;
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
            res[i++] = new char[j+1];
            j = 0;
        }
    }
    res[i++] = new char[j+1];
    in.clear();
    in.seekg(0);
    for (int _i = 0; _i < i; ++_i)
    {
        j = 0;
        while (((c = in.get()) != '\n')&&(c!=EOF))
        {
            res[_i][j++] = c;
        }
        res[_i][j] = '\0';
    }
    BooleanExpression result(i, res,resCount);
    //result.F->calc();
    result.truthTabel();
    //std::cout<<F.calc();
}

