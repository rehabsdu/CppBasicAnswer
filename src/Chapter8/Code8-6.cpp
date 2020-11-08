// Code 8-6

#include <iostream>
using namespace std;

class calculate
{
public:
	float add(float x,float y);
	float subtraction(float x,float y);
	float multiply(float x,float y);
	float divide(float x,float y,float z);
};

float calculate::add(float x,float y)
{
    float sum=0;
    sum=x+y;
    return sum;
} 


float calculate::subtraction(float x,float y)
{
    float sum=0;
    sum=x-y;
    return sum;
}


float calculate::multiply(float x,float y)
{
    float sum=0;
    sum=x*y;
    return sum; 
}


float calculate::divide(float x,float y,float z)
{
    float sum=0;
    sum=(x*y)/(y*y+z*z);
    return sum;
}


int main()
{
    float x,y,g,h;
    calculate c;

    cout<<"please input the real part of the first complex number"<<endl;
    cin>>x;
    cout<<"please input the imaginary part of the first complex number"<<endl;
    cin>>y;

    cout<<"please input the real part of the second complex number"<<endl;
    cin>>g;
    cout<<"please input the imaginary part of the second complex number"<<endl;
    cin>>h;

    if(c.add(y,h)>0)
        cout<<"z1+z2="<<c.add(x,g)<<"+"<<c.add(y,h)<<"i"<<endl;
    else if(c.add(y,h)==0)
        cout<<"z1+z2="<<c.add(x,g)<<endl;
    else
        cout<<"z1+z2="<<c.add(x,g)<<c.add(y,h)<<"i"<<endl;

    if(c.subtraction(y,h)>0)
        cout<<"z1-z2="<<c.subtraction(x,g)<<"+"<<c.subtraction(y,h)<<"i"<<endl; 
    else if(c.subtraction(y,h)==0)
        cout<<"z1-z2="<<c.subtraction(x,g)<<endl;
    else 
        cout<<"z1-z2="<<c.subtraction(x,g)<<c.subtraction(y,h)<<"i"<<endl;

    if((c.multiply(x,h)+c.multiply(y,g))>0)
        cout<<"z1*z2="<<c.multiply(x,g)-c.multiply(y,h)<<"+"<<c.multiply(x,h)+c.multiply(y,g)<<"i"<<endl;
    else if((c.multiply(x,h)+c.multiply(y,g))==0)
        cout<<"z1*z2="<<c.multiply(x,g)-c.multiply(y,h)<<endl;
    else
        cout<<"z1*z2="<<c.multiply(x,g)-c.multiply(y,h)<<c.multiply(x,h)+c.multiply(y,g)<<"i"<<endl;

    if((-c.divide(x,h,g)+c.divide(y,g,h))>0)
        cout<<"z1/z2="<<c.divide(x,g,h)+c.divide(y,h,g)<<"+"<<-c.divide(x,h,g)+c.divide(y,g,h)<<"i"<<endl;
    else if((-c.divide(x,h,g)+c.divide(y,g,h))==0)
        cout<<"z1/z2="<<c.divide(x,g,h)+c.divide(y,h,g)<<endl;
    else 
        cout<<"z1/z2="<<c.divide(x,g,h)+c.divide(y,h,g)<<-c.divide(x,h,g)+c.divide(y,g,h)<<"i"<<endl;
    return 0;
}