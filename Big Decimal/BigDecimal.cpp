#include "BigDecimal.h"
#include <iostream>

using namespace std;

BigDecimalInt::BigDecimalInt()
{
    num1=" ";
}
BigDecimalInt::BigDecimalInt(string num1)
{
    this->num1=num1;
}
BigDecimalInt BigDecimalInt:: operator+(BigDecimalInt &num2)
{
    if(num1.size()>num2.num1.size())
    {
        short z=num1.size()-num2.num1.size();
        for(int i=0; i<z; i++)
        {
            num2.num1='0'+num2.num1;
        }
    }
    else if(num2.num1.size()>num1.size())
    {
        short z=num2.num1.size()-num1.size();
        for(int i=0; i<z; i++)
        {
            num1='0'+num1;
        }
    }

    for(int i=num1.size()-1; i>=0; --i)
    {
        num1[i]= (int)num1[i]-48;
        num2.num1[i]=int(num2.num1[i])-48;
        if(num1[i]+num2.num1[i]>=10)
        {
            if(i==0)
            {
                num2.num1[i]=char(num1[i]+num2.num1[i]+48)-10;
                cout << num2.num1[i]+'1'   <<endl ;
                num2.num1='1'+num2.num1;
            }
            else
            {
                num2.num1[i]=char(num1[i]+num2.num1[i]+48)-10;
                cout <<'8'+'1'   <<endl ;
                num1[i-1]+=1;
            }
        }
        else
            num2.num1[i]=char(num1[i]+num2.num1[i])+48;
    }
    return num2;
}
BigDecimalInt BigDecimalInt:: operator-(BigDecimalInt &num2)
{
    for(int i=num2.num1.size()-1; i>=0; --i)
    {
        num2.num1[i]=int(num2.num1[i]-48);
        num2.num1[i]=9-num2.num1[i];
    }
    short counter=1;
    num2.num1[num2.num1.size()-1]+=1;
    while(true)
    {
        if(num2.num1[num2.num1.size()-counter]>=10)
        {
            num2.num1[num2.num1.size()-counter]-=10;
            num2.num1[num2.num1.size()-counter-1]+=1;
        }
        else
            break;
        counter++;
    }
    for(int i=num2.num1.size()-1; i>=0; --i)
    {
        num2.num1[i]=char(num2.num1[i]+48);
    }
    num2=operator+(num2);
    if(num2.num1[0]=='1')
    {
        for(int i=0; i<num2.num1.size(); ++i)
        {
            num2.num1[i]=num2.num1[i+1];
        }
    }
    else
    {
        for(int i=num2.num1.size()-1; i>0; --i)
        {
            num2.num1[i]=int(num2.num1[i]);
            num2.num1[i]=9-num2.num1[i];
        }
        counter=1;
        num2.num1[num2.num1.size()-1]+=1;
        while(true)
        {
            if(num2.num1[num2.num1.size()-counter]>=10)
            {
                num2.num1[num2.num1.size()-counter]-=10;
                num2.num1[num2.num1.size()-counter-1]+=1;
            }
            else
                break;
            counter++;
        }
        for(int i=num2.num1.size()-1; i>=0; --i)
        {
            num2.num1[i]=char(num2.num1[i]+48);
        }
        num2.num1='-'+num2.num1;
    }
    return num2;
}
ostream &operator<<(ostream&out,const BigDecimalInt&num)
{
    for(int i=0; i<num.num1.size(); ++i)
    {
        out<<num.num1[i];
    }
    return out;
}
