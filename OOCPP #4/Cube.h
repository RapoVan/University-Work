#include <string>

#ifndef CUBE_H
#define CUBE_H


class Cube{

    private:

    int Mass, Acceleration;
    std::string Color;
    static int countID;
    int CubeID;

    public:

    Cube();
    ~Cube();

    void setMass(const int &Mass);
    void setAcceleration(const int &Acceleration);
    void setColor(const std::string &Color);

    int getMass();
    int getAcceleration();
    std::string getColor();

    std::string toString() const;

    bool operator==(const Cube &n) const;
    bool operator!=(const Cube &n) const;
    bool operator>(const Cube &n) const;
    bool operator<(const Cube &n) const;
    bool operator>=(const Cube &n) const;
    bool operator<=(const Cube &n) const;

    Cube operator++();
    Cube operator++(int);
    Cube operator--();
    Cube operator--(int);

    friend std::istream& operator>>(std::istream&, Cube&);
    friend std::ostream& operator<<(std::ostream&, const Cube&);

    private:

    bool checkMass(int);
    bool checkAcceleration(int);

    };



#endif
