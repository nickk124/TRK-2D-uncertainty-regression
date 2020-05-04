#include "exampleModels.h"

// LINEAR

//if you have a pivot point, it must be called as TRK::pivot.

double linear(double x, std::vector <double> params) {
	double a0 = params[0];
	double a1 = params[1];

	return a0 + a1 * (x - TRK::pivot);
}

double dLinear(double x, std::vector <double> params) {
	double a1 = params[1];

	return a1;
}

double ddLinear(double x, std::vector <double> params) {

	return 0;
}

double linearIntercept(std::vector <double> params){
    return params[0];
}
double linearSlope(std::vector <double> params){
    return params[1];
}

//double pivotLinear(std::vector <double> params1, std::vector <double> params2) {
//	double a01 = params1[0];
//	double a11 = params1[1];
//
//	double a02 = params2[0];
//	double a12 = params2[1];
//
//	return (a02 - a01) / (a11 - a12);
//}

// QUADRATIC
double quadratic(double x, std::vector <double> params) {
	double a0 = params[0];
	double a1 = params[1];
	double a2 = params[2];

	return a0 + a1 * (x) + a2 * std::pow((x), 2.0);
}

double dQuadratic(double x, std::vector <double> params) {
	double a1 = params[1];
	double a2 = params[2];

	return a1 + 2.0 * a2 * (x);
}

double ddQuadratic(double x, std::vector <double> params) {
	double a2 = params[2];

	return 2.0*a2;
}

//double pivotQuadratic(std::vector <double> params1, std::vector <double> params2) {
//	double a01 = params1[0];
//	double a11 = params1[1];
//	double a21 = params1[2];
//
//	double a02 = params2[0];
//	double a12 = params2[1];
//	double a22 = params2[2];
//
//	//take the + soln to the quadratic equation
//	return (a12 - a11 + std::sqrt(std::pow(a11 - a12, 2.0) - 4.0 * (a01 - a02) * (a21 - a22))) / (2.0 * (a21 - a22));
//}


// CUBIC
double cubic(double x, std::vector <double> params) {
	double a0 = params[0];
	double a1 = params[1];
	double a2 = params[2];
	double a3 = params[3];

	return a0 + a1 * (x) + a2 * std::pow((x), 2.0) + a3 * std::pow((x), 3.0);
}

double dCubic(double x, std::vector <double> params) {
	double a1 = params[1];
	double a2 = params[2];
	double a3 = params[3];

	return a1 + 2.0 * a2 * (x) + 3.0 * a3 * std::pow((x), 2.0);
}

double ddCubic(double x, std::vector <double> params) {
	double a2 = params[2];
	double a3 = params[3];

	return 2.0 * a2 + 6.0 * a3 * (x);
}

//double pivotCubic(std::vector <double> params1, std::vector <double> params2) {
//	std::vector <double> roots;
//	double finalroot;
//
//	double a01 = params1[0];
//	double a11 = params1[1];
//	double a21 = params1[2];
//	double a31 = params1[3];
//
//	double a02 = params2[0];
//	double a12 = params2[1];
//	double a22 = params2[2];
//	double a32 = params2[3];
//
//	double A = a31 - a32;
//	double B = a21 - a22;
//	double C = a11 - a12;
//	double D = a01 - a02;
//
//	double discriminant = 18.0*A*B*C*D - 4.0*std::pow(B, 3.0)*D + std::pow(B, 2.0)*std::pow(C, 2.0) - 4.0*A*std::pow(C, 3.0) - 27.0*std::pow(A, 2.0)*std::pow(D, 2.0);
//
//	if (discriminant > 0) {
//		std::vector <double> threeroots = cubicSolver(A, B, C, D);
//		finalroot = minMax(threeroots)[0]; //arbitrarily choose minimum
//	}
//	else if (discriminant < 0) {
//		finalroot = twoPointNR(cubic, dCubic, ddCubic, { D, C, B, A}, 0.0, -0.1);
//	}
//
//	return finalroot;
//}

// POWER LAW
double powerlaw(double x, std::vector <double> params) {
	double a0 = params[0];
	double a1 = params[1];

	return a0 * std::pow((x / std::pow(10.0, TRK::pivot)), a1);
}

double dPowerlaw(double x, std::vector <double> params) {
	double a0 = params[0];
	double a1 = params[1];

	return std::pow(10.0, -1.0*TRK::pivot) * a0 * a1 * std::pow(std::pow(10.0, -TRK::pivot) * x, a1 - 1.0);
}

double ddPowerlaw(double x, std::vector <double> params) {
	double a0 = params[0];
	double a1 = params[1];

	return std::pow(10.0, -2.0*TRK::pivot) * a0 * (a1 - 1.0) * a1 * std::pow(std::pow(10.0, -TRK::pivot) * x, a1 - 2.0);
}

//double pivotPowerLaw(std::vector <double> params1, std::vector <double> params2) {
//	double a01 = params1[0];
//	double a11 = params1[1];
//
//	double a02 = params2[0];
//	double a12 = params2[1];
//
//	return std::exp((std::log(a02) - std::log(a01))/(a11-a12));
//}

double powerlawIntercept(std::vector <double> params){
    return std::log10(params[0]);
}
double powerlawSlope(std::vector <double> params){
    return params[1];
}

// EXPONENTIAL
double exponential(double x, std::vector <double> params) {
	double a0 = params[0];
	double a1 = params[1];

	return a0 * std::pow(10, a1*(x - TRK::pivot));
}

double dExponential(double x, std::vector <double> params) {
	double a0 = params[0];
	double a1 = params[1];

	return std::pow(10, a1*(x - TRK::pivot)) * a0 * a1 * std::log(10.0);
}

double ddExponential(double x, std::vector <double> params) {
	double a0 = params[0];
	double a1 = params[1];

	return std::pow(10, a1*(x - TRK::pivot)) * a0 * std::pow(a1, 2.0) * std::pow(std::log(10.0) , 2.0);
}

//double pivotExponential(std::vector <double> params1, std::vector <double> params2) {
//	double a01 = params1[0];
//	double a11 = params1[1];
//
//	double a02 = params2[0];
//	double a12 = params2[1];
//
//	return -1.0 * std::log(a01 / a02) / ((a11 - a12) * std::log(10.0));
//}
double exponentialIntercept(std::vector <double> params){
    return std::log10(params[0]);
}
double exponentialSlope(std::vector <double> params){
    return params[1];
}

// LOGARITHMIC
double logarithmic(double x, std::vector <double> params) {
	double a0 = params[0];
    double a1 = params[0];

	return a0 + a1 * std::log10(x/TRK::pivot);
}

double dLogarithmic(double x, std::vector <double> params) {
	double a1 = params[1];

    return a1 / (x*std::log(10.0));
}

double ddLogarithmic(double x, std::vector <double> params) {
	double a1 = params[1];

	return -1.0 * a1 / (std::pow(x, 2.0) * std::log(10.0));
}

//double pivotLogarithmic(std::vector <double> params1, std::vector <double> params2) {
//	double a01 = params1[0];
//	double a11 = params1[1];
//
//	double a02 = params2[0];
//	double a12 = params2[1];
//
//	return std::pow(10.0, (a02 - a01) / (a11 - a12));
//}

double logarithmicIntercept(std::vector <double> params){
    return params[0];
}
double logarithmicSlope(std::vector <double> params){
    return params[1];
}