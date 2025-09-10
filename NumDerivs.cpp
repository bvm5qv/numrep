#include <functional>
#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <cmath>

constexpr double double_precision = 2.0E-53;

using FcnType = std::function<double(double)>;
using DiffFcnType = std::function<double(FcnType, const double, const double)>;

static double forwardDiff(FcnType f, const double x, const double h)
{
    return (f(x + h) - f(x)) / h;
}

static double centralDiff(FcnType f, const double x, const double h)
{
    return (f(x + h/2) - f(x - h/2)) / h;
}

static double extrapDiff(FcnType f, const double x, const double h)
{
    return (8*(f(x + h/4) - f(x - h/4)) - (f(x + h/2) - f(x - h/2)))/3/h;
}

static void findDiffErr(DiffFcnType diff, FcnType fcn, FcnType fcnDeriv, double x, const std::vector<double>& h_vec, std::vector<double>& rel_err_vec)
{
    for(const auto h : h_vec)
    {
        const double approx_deriv = diff(fcn,x,h);
        const double true_deriv = fcnDeriv(x);

        rel_err_vec.push_back(std::abs((true_deriv - approx_deriv)/true_deriv));
        std::cout << "At h = " << h << ": derivative = " << approx_deriv << " and relative error = " << rel_err_vec.back() << ".\n";
    }
    std::cout << "\n\n";
}

static inline double cos_deriv(double x) { return -std::sin(x); }

int main()
{
    std::vector<double> h_vec{};
    for(double h = 20; h >= double_precision; h /= 10) h_vec.push_back(h);

    FcnType expntl = static_cast<double(*)(double)>(std::exp);
    FcnType cosine = static_cast<double(*)(double)>(std::cos);
    FcnType cosder = static_cast<double(*)(double)>(cos_deriv);

    std::array<std::vector<double>, 9> expntlRelErr{};
    std::array<std::vector<double>, 9> cosineRelErr{};

    findDiffErr(forwardDiff, expntl, expntl, 0.1, h_vec, expntlRelErr[0]);
    findDiffErr(centralDiff, expntl, expntl, 0.1, h_vec, expntlRelErr[1]);
    findDiffErr(extrapDiff,  expntl, expntl, 0.1, h_vec, expntlRelErr[2]);
    findDiffErr(forwardDiff, expntl, expntl, 1.0, h_vec, expntlRelErr[3]);
    findDiffErr(centralDiff, expntl, expntl, 1.0, h_vec, expntlRelErr[4]);
    findDiffErr(extrapDiff,  expntl, expntl, 1.0, h_vec, expntlRelErr[5]);
    findDiffErr(forwardDiff, expntl, expntl, 100, h_vec, expntlRelErr[6]);
    findDiffErr(centralDiff, expntl, expntl, 100, h_vec, expntlRelErr[7]);
    findDiffErr(extrapDiff,  expntl, expntl, 100, h_vec, expntlRelErr[8]);

    findDiffErr(forwardDiff, cosine, cosder, 0.1, h_vec, cosineRelErr[0]);
    findDiffErr(centralDiff, cosine, cosder, 0.1, h_vec, cosineRelErr[1]);
    findDiffErr(extrapDiff,  cosine, cosder, 0.1, h_vec, cosineRelErr[2]);
    findDiffErr(forwardDiff, cosine, cosder, 1.0, h_vec, cosineRelErr[3]);
    findDiffErr(centralDiff, cosine, cosder, 1.0, h_vec, cosineRelErr[4]);
    findDiffErr(extrapDiff,  cosine, cosder, 1.0, h_vec, cosineRelErr[5]);
    findDiffErr(forwardDiff, cosine, cosder, 100, h_vec, cosineRelErr[6]);
    findDiffErr(centralDiff, cosine, cosder, 100, h_vec, cosineRelErr[7]);
    findDiffErr(extrapDiff,  cosine, cosder, 100, h_vec, cosineRelErr[8]);

    //exponential data ----------------------------------------------
    std::ofstream exp01;
    exp01.open("exp01.dat");
    for(int i = 0; i < h_vec.size() / 2.5; ++i)
    {
        if(expntlRelErr[0][i] != 0 && expntlRelErr[1][i] != 0 && expntlRelErr[2][i] != 0)
            exp01 << std::log10(h_vec[i]) << ' ' << std::log10(expntlRelErr[0][i]) << ' ' << std::log10(expntlRelErr[1][i]) << ' ' << std::log10(expntlRelErr[2][i]) << '\n';
    }
    exp01.close();

    std::ofstream exp1;
    exp1.open("exp1.dat");
    for(int i = 0; i < h_vec.size() / 2.5; ++i)
    {
        if(expntlRelErr[3][i] != 0 && expntlRelErr[4][i] != 0 && expntlRelErr[5][i] != 0)
            exp1 << std::log10(h_vec[i]) << ' ' << std::log10(expntlRelErr[3][i]) << ' ' << std::log10(expntlRelErr[4][i]) << ' ' << std::log10(expntlRelErr[5][i]) << '\n';
    }
    exp1.close();

    std::ofstream exp100;
    exp100.open("exp100.dat");
    for(int i = 0; i < h_vec.size() / 2.5; ++i)
    {
        if(expntlRelErr[6][i] != 0 && expntlRelErr[7][i] != 0 && expntlRelErr[8][i] != 0)
            exp100 << std::log10(h_vec[i]) << ' ' << std::log10(expntlRelErr[6][i]) << ' ' << std::log10(expntlRelErr[7][i]) << ' ' << std::log10(expntlRelErr[8][i]) << '\n';
    }
    exp100.close();


    //cosine data ---------------------------------------------------
    std::ofstream cos01;
    cos01.open("cos01.dat");
    for(int i = 0; i < h_vec.size() / 2.5; ++i)
    {
        if(cosineRelErr[0][i] != 0 && cosineRelErr[1][i] != 0 && cosineRelErr[2][i] != 0)
            cos01 << std::log10(h_vec[i]) << ' ' << std::log10(cosineRelErr[0][i]) << ' ' << std::log10(cosineRelErr[1][i]) << ' ' << std::log10(cosineRelErr[2][i]) << '\n';
    }
    cos01.close();

    std::ofstream cos1;
    cos1.open("cos1.dat");
    for(int i = 0; i < h_vec.size() / 2.5; ++i)
    {
        if(cosineRelErr[3][i] != 0 && cosineRelErr[4][i] != 0 && cosineRelErr[5][i] != 0)
            cos1 << std::log10(h_vec[i]) << ' ' << std::log10(cosineRelErr[3][i]) << ' ' << std::log10(cosineRelErr[4][i]) << ' ' << std::log10(cosineRelErr[5][i]) << '\n';
    }
    cos1.close();

    std::ofstream cos100;
    cos100.open("cos100.dat");
    for(int i = 0; i < h_vec.size() / 2.5; ++i)
    {
        if(cosineRelErr[6][i] != 0 && cosineRelErr[7][i] != 0 && cosineRelErr[8][i] != 0)
            cos100 << std::log10(h_vec[i]) << ' ' << std::log10(cosineRelErr[6][i]) << ' ' << std::log10(cosineRelErr[7][i]) << ' ' << std::log10(cosineRelErr[8][i]) << '\n';
    }
    cos100.close();

    return 0;
}








