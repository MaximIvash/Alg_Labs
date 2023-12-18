// Alg_lab_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include "brackets.h"
using namespace std;

bool contains(char elem, vector<char>& line)
{
    for (int i = 0; i < line.size(); ++i)
    {
        if (line[i] == elem)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "ru");
    string line;
    cout << "Введите выражение: ";
    cin >> line;
    string allOperands = "*/+-=()";

    try
    {
        bracketsFine(line);
    }
    catch (const char* error)
    {
        cerr << error;
    }

    vector<char> operands(0);
    vector<string> rPolishNotation(0);

    string tempNum;

    bool flagEquals = false;
    for (int i = 0; i < line.length(); i++)
    {
        if ((line[i] >= '0' && line[i] <= '9') || (line[i] == '-' && (i == 0 || line[i - 1] == '(')))
        {
            tempNum += line[i];
        }
        else
        {
            try
            {
                if (allOperands.find(line[i]) == string::npos)
                {
                    throw "wrong expression";
                }
                if (tempNum.length() == 0 && line[i] != '(' && i == 0 && line[i] != '-')
                {
                    throw "wrong operands";
                }
                if (tempNum.size() > 0 && (line[i] == '('))
                {
                    throw "missed *";
                }
            }
            catch (const char* error)
            {
                cerr << error << endl;
                exit(4);
            }
            if (tempNum.size() > 0)
            {
                rPolishNotation.push_back(tempNum);
                tempNum.clear();
            }
            int n = operands.size() - 1;
            if (line[i] == '*' || line[i] == '/')
            {
                if (operands.size() == 0 || operands[n] == '(' || operands[n] == '+' || operands[n] == '-') operands.push_back(line[i]);
                else
                {
                    while (operands[n] == '*' || operands[n] == '/')
                    {
                        string last = "";
                        last += operands[n];
                        rPolishNotation.push_back(last);
                        operands.pop_back();
                        n = operands.size() - 1;
                        if (operands.size() == 0)
                        {
                            break;
                        }
                    }
                    operands.push_back(line[i]);
                }
            }
            else if (line[i] == '+' || line[i] == '-')
            {
                if (operands.size() == 0) operands.push_back(line[i]);
                else
                {
                    while (operands[n] == '+' || operands[n] == '-' || operands[n] == '*' || operands[n] == '/')
                    {
                        string last = "";
                        last += operands[n];
                        rPolishNotation.push_back(last);
                        operands.pop_back();
                        n = operands.size() - 1;
                        if (operands.size() == 0)
                        {
                            break;
                        }
                    }
                    operands.push_back(line[i]);
                }
            }
            else if (line[i] == '(')
            {
                operands.push_back(line[i]);
            }
            else if (line[i] == ')')
            {
                while (operands[n] != '(')
                {
                    string last = "";
                    last += operands[n];
                    rPolishNotation.push_back(last);
                    operands.pop_back();
                    n = operands.size() - 1;
                    if (operands.size() == 0)
                    {
                        break;
                    }
                }
                operands.pop_back();
            }
            else if (line[i] == '=')
            {
                flagEquals = true;
                while (operands.size() != 0)
                {
                    string last = "";
                    last += operands[n];
                    rPolishNotation.push_back(last);
                    operands.pop_back();
                    n = operands.size() - 1;
                    if (operands.size() == 0)
                    {
                        break;
                    }
                }
            }
        }
    }
    vector<float> stackNumbers(0);
    if (flagEquals)
    {
        for (int i = 0; i < rPolishNotation.size(); ++i)
        {
            if ((rPolishNotation[i][0] >= '0' && rPolishNotation[i][0] <= '9') || rPolishNotation[i][0] == '-')
            {
                stackNumbers.push_back(stof(rPolishNotation[i]));
            }
            else
            {
                float a = stackNumbers[stackNumbers.size() - 1];
                float b = stackNumbers[stackNumbers.size() - 2];
                float res = 0;
                switch (rPolishNotation[i][0])
                {

                case '*':
                    res = a * b;
                    break;
                case '/':
                    if (a == 0)
                    {
                        cout << "division by 0";
                        exit(5);
                    }
                    else
                    {
                        res = b / a;
                        break;
                    }
                case '+':
                    res = a + b;
                    break;
                case '-':
                    res = b - a;
                    break;
                }
                stackNumbers.pop_back();
                stackNumbers.pop_back();
                stackNumbers.push_back(res);
            }
        }
        cout << stackNumbers[0];
    }
    else
    {
        cout << "no equals sign";
    }
    return 0;
}