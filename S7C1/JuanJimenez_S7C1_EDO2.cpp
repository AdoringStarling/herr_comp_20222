#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>


using namespace std;

double funcv(double yeux) {
	double k=50; //N/M
	double m=0.2; //kg
    return -(k/m)*yeux;
}

double Exponentiation(double x)
{
    double result = exp(-x);
    return result;
}

int main(){
	double t1=0;
	double t2=10;
	double h=0.01;
	int size=(t2-t1)/h;
    double yeux[size] = {};
	double yeuv[size] = {};
	double xeu[size] = {};
	yeux[0]=0.1;
	yeuv[0]=0;
	double tm=0;
	//Euler
    for (int i = 1; i < size; i++){
		tm=0.1+tm;
        yeuv[i]=yeuv[i-1]+(h*funcv(yeux[i-1]));
		yeux[i]=yeux[i-1]+(h*yeuv[i]);
		xeu[i]=tm;};
    ofstream myfile ("yeux.txt");
    if (myfile.is_open())
    {
		for(int count = 0; count < size; count ++){
            myfile << yeux[count] << " " ;
    }
		myfile.close();
      };
    ofstream myfile2 ("yeuv.txt");
    if (myfile2.is_open())
    {
		for(int count = 0; count < size; count ++){
            myfile2 << yeuv[count] << " " ;
    }
		myfile2.close();
      };
    ofstream myfile3 ("xeu.txt");
    if (myfile3.is_open())
    {
		for(int count = 0; count < size; count ++){
            myfile3 << xeu[count] << " " ;
    }
		myfile3.close();
      };
	//Runge Kutta
    double yrkx[size] = {};
	double yrkv[size] = {};
	yrkx[0]=0.1;
	yrkv[0]=0;
    for (int i = 1; i < size; i++){
		tm=0.1+tm;
		double k1x=h*yrkv[i-1];
		double k2x=h*(yrkv[i-1]+(k1x/2));
		double k3x=h*(yrkv[i-1]+(k2x/2));
		double k4x=h*(yrkv[i-1]+k3x);
		yrkx[i]=yrkx[i-1]+((1/6)*(k1x+(2*k2x)+(2*k3x)+k4x));
		double k1v=h*funcv(yrkx[i-1]);
		double k2v=h*funcv(yrkx[i-1]+(k1x/2));
		double k3v=h*funcv(yrkx[i-1]+(k2x/2));
		double k4v=h*funcv(yrkx[i-1]+k3x);
		yrkv[i]=yrkv[i-1]+((1/6)*(k1v+(2*k2v)+(2*k3v)+k4v));
		};
    ofstream yrkx1 ("yrkx.txt");
    if (yrkx1.is_open())
    {
		for(int count = 0; count < size; count ++){
            yrkx1 << yrkx[count] << " " ;
    }
		yrkx1.close();
      };
    ofstream yrkv1 ("yrkv.txt");
    if (yrkv1.is_open())
    {
		for(int count = 0; count < size; count ++){
            yrkv1 << yrkv[count] << " " ;
    }
		yrkv1.close();
      };
    return 0;
    }