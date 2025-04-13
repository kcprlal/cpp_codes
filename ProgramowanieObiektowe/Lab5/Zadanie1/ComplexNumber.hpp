#include <iostream>
#include <exception>
class ComplexNumber
{
private:
    double m_re{};
    double m_im{};

public:
    ComplexNumber(double real = 0.0, double imag = 0.0) : m_re(real), m_im(imag) {};
    ~ComplexNumber() {};
    void printComplex()
    {
        std::cout << m_re << "   " << m_im << std::endl;
    }
    void setRe(double newRe)
    {
        m_re = newRe;
    }
    double getRe()
    {
        return m_re;
    }
    void setIm(double newIm)
    {
        m_im = newIm;
    }
    double getIm()
    {
        return m_im;
    }
    ComplexNumber operator+(const ComplexNumber &other) const
    {
        return ComplexNumber(m_re + other.m_re, m_im + other.m_im);
    }
    ComplexNumber &operator+=(const ComplexNumber &other)
    {
        m_re += other.m_re;
        m_im += other.m_im;

        return *this;
    }
    ComplexNumber operator-(const ComplexNumber &other) const
    {
        return ComplexNumber(m_re - other.m_re, m_im - other.m_im);
    }
    ComplexNumber &operator-=(const ComplexNumber &other)
    {
        m_re -= other.m_re;
        m_im -= other.m_im;
        return *this;
    }
    ComplexNumber operator*(const ComplexNumber &other) const
    {
        return ComplexNumber((m_re * other.m_re) - (m_im * other.m_im), (m_re * other.m_im) + (m_im * other.m_re));
    }
    ComplexNumber &operator*=(const ComplexNumber &other)
    {
        double temp_re = m_re * other.m_re - m_im * other.m_im;
        double temp_im = m_re * other.m_im + m_im * other.m_re;
        m_re = temp_re;
        m_im = temp_im;
        return *this;
    }
    ComplexNumber operator/(const ComplexNumber &other) const
    {
        try
        {
            double denominator = other.m_re * other.m_re + other.m_im * other.m_im;
            if (denominator == 0)
            {
                throw std::invalid_argument("You can't divide by 0! ");
            }
            return ComplexNumber(
                (m_re * other.m_re + m_im * other.m_im) / denominator,
                (m_im * other.m_re - m_re * other.m_im) / denominator);
        }
        catch (std::invalid_argument &error)
        {
            std::cerr << error.what() << std::endl;
            return ComplexNumber();
        }
    }
    ComplexNumber &operator/=(const ComplexNumber &other)
    {
        try
        {
            double denominator = other.m_re * other.m_re + other.m_im * other.m_im;
            if (denominator == 0)
            {
                throw std::invalid_argument("You can't divide by 0! ");
            }
            double temp_re = (m_re * other.m_re + m_im * other.m_im) / denominator;
            double temp_im = (m_im * other.m_re - m_re * other.m_im) / denominator;
            m_re = temp_re;
            m_im = temp_im;
            return *this;
        }
        catch (std::invalid_argument error)
        {
            std::cerr << error.what() << std::endl;
            return *this;
        }
    }
    bool operator==(const ComplexNumber &other) const
    {
        return m_re == other.m_re && m_im == other.m_im;
    }
    bool operator!=(const ComplexNumber &other) const
    {
        return m_re != other.m_re || m_im != other.m_im;
    }

    friend std::ostream &operator<<(std::ostream &os, const ComplexNumber &object)
    {
        os << object.m_re << " + " << object.m_im << "i";
        return os;
    }
    //---------------------------
    ComplexNumber operator+(double other) const
    {
        return ComplexNumber(m_re + other, m_im);
    }
    ComplexNumber &operator+=(double other)
    {
        m_re += other;
        return *this;
    }
    ComplexNumber operator-(double other) const
    {
        return ComplexNumber(m_re - other, m_im);
    }
    ComplexNumber &operator-=(double other)
    {
        m_re -= other;
        return *this;
    }
};
