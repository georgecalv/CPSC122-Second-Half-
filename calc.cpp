#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>


//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(char* argvIn)
{
    stk = new Stack();
    int length = strlen(argvIn);
    inFix = new char[length + 1];
    postFix = new char[length + 1];
    strcpy(inFix, argvIn);
    if (CheckTokens() && CheckParens())
    {
        MakeValueTbl();
        Parse();
        InFixToPostFix();
    }
    else 
    {
        cout << "Error: Invalid Input" << endl;
        exit(EXIT_FAILURE);
    }
}

Calc::~Calc()
{
    delete inFix;
    delete []postFix;
    delete valueTbl;
    while(stk->GetLength() > 0)
    {
        stk->Pop();
    }
    delete stk;
}

bool Calc::CheckTokens()
{
    /*
    Here is some sample code to show how cstring functions might be used
    */
    bool check = true;
    char ch;
    char y;
    for(int i = 0; i < strlen(inFix); i++)
    {
        ch = inFix[i];
        if(!isdigit(ch))
        {
            y = ch + 25;
            if(isupper(y))
            {
                if(y == '.' + 25 || y == ',' + 25)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

void Calc::MakeValueTbl()
{
    // makes empty array of 0s
    valueTbl = new int[26];
    for(int i = 0; i < 26; i++)
    {
        valueTbl[i] = 0;
    }
    valueIdx = 0;
}

void Calc::Parse()
{
    // temp holds number found
    string temp = "";
    // result holds new infix
    string result = "";
    int length = strlen(inFix);
    for(int i = 0; i < length; i++)
    {
        // digit is found
        if(isdigit(inFix[i]))
        {
            // adds first character of digit
            temp += inFix[i];
            for(int k = i + 1; k < length; k++)
            {
                // finds if next character is a digit
                if(isdigit(inFix[k]))
                {
                    temp += inFix[k];
                }
                else
                {
                    // adds to valuetable
                    valueTbl[valueIdx] = stoi(temp);
                    result += valueIdx + 65;
                    valueIdx++;
                    // skips ahead in list depending on how long number is
                    if(temp.length() > 1)
                    {
                        i += temp.length() - 1;
                    }
                    temp = "";
                    break;
                }
            }
        }
        else
        {
            result += inFix[i];
        }
    }
    // creates new inFix
    inFix = new char[result.length()];
    for(int j = 0; j < result.length(); j++)
    {
        inFix[j] = result[j];
    }
}

bool Calc::CheckParens()
{
    char ch;
    bool balanced;
    // goes through infix to find parens
    for(int i = 0; i < strlen(inFix); i++)
    {
        ch = inFix[i];
        if(ch == '(')
        {
            stk->Push(inFix[i]);
        }
        if(ch == ')')
        {
            if(!stk->IsEmpty())
            {
                stk->Pop();
            }
            else
            {
                balanced = false;
            }
        }
    }
    // if the parens are balanced and stk is empty
    if(balanced && stk->IsEmpty())
    {
        return true;
    }
    else {
        return false;
    }
    return balanced;
}

void Calc::DisplayInFix()
{
    cout << inFix << endl;
}

void Calc::InFixToPostFix()
{
    string pfix = "";
    for(int i = 0; i < strlen(inFix); i++)
    {
        // is a letter adds to pfix string
        if(isOperand(inFix[i]))
        {
            pfix += inFix[i];
        }
        // paren pushes to stack
        else if(inFix[i] == '(')
        {
            stk->Push(inFix[i]);
        }
        // is a operator pushes to stack
        else if(isOperator(inFix[i]))
        {
            stk->Push(inFix[i]);
        }
        // is other paren 
        // checks puts what ever is in stack in pfix
        else if(inFix[i] == ')')
        {
            while(stk->Peek() != '(')
            {
                pfix += stk->Peek();
                stk->Pop();
            }
            stk->Pop();
        }
    }
    // changes postfix to equal pfix
    for(int k = 0; k < pfix.length(); k++)
    {
        postFix[k] = pfix[k];
    }
}

void Calc::DisplayPostFix()
{
    cout << postFix << endl;
}

int Calc::Evaluate()
{
    int result = 0;
    // goes through postfix
    for(int i = 0; i < strlen(postFix); i++)
    {
        // is letter pushed to stack
        if(isOperand(postFix[i]))
        {
            stk->Push(postFix[i]);
        }
        // is operator 
        else if(isOperator(postFix[i]))
        {
            // sets char to equal operator
            // sets variables to equal respective operands then numbers
            char op = postFix[i];
            char second = stk->Peek();
            stk->Pop();
            char first = stk->Peek();
            stk->Pop();
            // finds numbers corresponding to letters
            int f = valueTbl[int(first - 65)];
            int s = valueTbl[int(second - 65)];
            // evaluates and puts it on the value table
            if(op == '+')
            {
                valueTbl[valueIdx] = f + s;
                stk->Push(valueIdx + 65);
                valueIdx++;
            }
            else if(op == '-')
            {
                valueTbl[valueIdx] = f - s;
                stk->Push(valueIdx + 65);
                valueIdx++;
            }
            else if(op == '*')
            {
                valueTbl[valueIdx] = f * s;
                stk->Push(valueIdx + 65);
                valueIdx++;
            }
            else if(op == '/')
            {
                valueTbl[valueIdx] = f / s;
                stk->Push(valueIdx + 65);
                valueIdx++;
            }
        }
    }
    // final result is the value index -1
    result = valueTbl[valueIdx - 1];

    return result;
}

bool Calc::isOperator(char ch)
{
    // list of operators
    char operand[4] = {'+', '-', '/', '*'};
    // sees what operator ch is equal to and returns true
    for(int i = 0; i < 4; i++)
    {
        if(operand[i] == ch)
        {
            return true;
        }
    }
    return false;
}
bool Calc::isOperand(char ch)
{
    // returns true if a capital letter
    if(ch >= 65 && ch <= 92)
    {
        return true;
    }
    return false;
}
