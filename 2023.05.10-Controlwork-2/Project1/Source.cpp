#include<iostream>
#include <cmath>

class Complex {
private:
    double re;
    double im;
public:
    Complex(double re = 0.0, double im = 0.0) : re(re), im(im) {}
    Complex(const Complex& comp) : re(comp.re), im(comp.im) {}
    ~Complex() {}
    Complex conj()
    {
        Complex a = Complex(re, -im);
        return a;
    }
    double arg()
    {
        double phi = atan2(im, re);
        return phi;
    }
    double abs()
    {
        double r = sqrt(re * re + im * im);
        return r;
    }

    Complex operator+(double d)
    {
        Complex sum(re + d, im);
        return sum;
    }
    Complex operator-(double d)
    {
        Complex sub(re - d, im);
        return sub;
    }
    Complex operator/(double d)
    {
        Complex quot(re / d, im / d);
        return quot;
    }
    Complex operator*(double d)
    {
        Complex prod(re * d, im * d);
        return prod;
    }

    friend Complex operator+(double d, Complex c)
    {
        Complex sum(c.re + d, c.im);
        return sum;
    }
    friend Complex operator-(double d, Complex c)
    {
        Complex sub(c.re - d, c.im);
        return sub;
    }
    friend Complex operator*(double d, Complex c)
    {
        Complex prod(c.re * d, c.im * d);
        return prod;
    }
    friend Complex operator/(double d, Complex c)
    {
        Complex quot = d * (c.conj()) / c.abs() / c.abs();
        return quot;
    }

    Complex operator+(Complex c)
    {
        Complex sum(this->re + c.re, this->im + c.im);
        return sum;
    }
    Complex operator-(Complex c)
    {
        Complex sub(this->re - c.re, this->im - c.im);
        return sub;
    }
    Complex operator*(Complex c)
    {
        Complex prod(this->re * c.re - im * c.im, this->re * c.im + this->im * c.re);
        return prod;
    }
    Complex operator/(Complex c)
    {
        Complex quot = (*this * c.conj()) / c.abs() / c.abs();
        return quot;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Complex& c)
    {
        stream << c.re <<  '+' << c.im << 'i';
        return stream;
    }
    Complex operator=(Complex c)
    {
        this->re = c.re;
        this->im = c.im;
    }
};
int main(int argc, char* argv[])
{
    Complex a(3.0, 5.0);
    Complex b(2.0, 3.0);
    Complex sum = a + b;
    Complex prod = a * b;
    Complex quot = a / b;
    std::cout << sum << std::endl;
    std::cout << prod << std::endl;
    std::cout << quot << std::endl;
    double s = a.abs();
    return EXIT_SUCCESS;
}