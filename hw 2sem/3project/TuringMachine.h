#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<vector>

class rule
{
public:
    char in;     // Входной символ '\0' - последний
    char* cond;     // Состояние. 'S' - начальное. 'Q' - завершение работы

    char out;    // Выходной символ
    char* newCond;  // Новое состояние
    char dir;

    int shift; //оптимизация перехода в новое состояние

};


int endingCond(rule* (&rls), const int& len);
std::string strToNormal(const std::string(&str), const int len);
void shifting(rule* (&rls), const int(&count));

class TuringMachine
{
    rule* rules;
    int countRules = 0;
    int maxLen;
    int endCond;
public:


    TuringMachine()
    {
        countRules = 0;
        rules = new rule[0];
        maxLen = 0;
        //shifting(rules, countRules);
        //endCond = endingCond(rules, countRules);
    }
    TuringMachine(int len, rule* rls, int c)
    {
        countRules = c;
        rules = new rule[c];
        maxLen = len;
        for (int i = 0; i < c; ++i) rules[i] = rls[i];
        shifting(rules, countRules);
        endCond = endingCond(rules, countRules);
    }
    TuringMachine(TuringMachine const& mac)
    {
        countRules = mac.countRules;
        rules = new rule[countRules];
        for (int i = 0; i < countRules; ++i) rules[i] = mac.rules[i];
        maxLen = mac.maxLen;
        shifting(rules, countRules);
        endCond = endingCond(rules, countRules);
    }
    TuringMachine(TuringMachine&& mac): countRules(std::move(mac.countRules)), rules(std::move(mac.rules)), maxLen(std::move(mac.maxLen))
    {
        mac.rules = nullptr;

        shifting(rules, countRules);
        endCond = endingCond(rules, countRules);
    }

    std::string calc(std::string &init, int maxsteps, int &i);
    TuringMachine begining(std::ifstream (&prog), std::ifstream (&input), std::ofstream (&out));
};
