#include <string>

#ifndef CUBE_H
#define CUBE_H


class cube{

    private:

        int mass, acceleration;
        std::string color;
        static int countID;
        int cubeID;


    public:

        cube();
        cube(std::string, int, int);
        void inCube(std::string&, int&, int&);
        ~cube();

        void setMass(int);
        void setAcceleration(int);
        void setColor(std::string);

        int getMass() const;
        int getAcceleration() const;
        std::string getColor() const;
        int getForce() const;

        std::string toString() const;

        bool operator==(const cube&) const;
        bool operator!=(const cube&) const;
        bool operator>(const cube&) const;
        bool operator<(const cube&) const;
        bool operator>=(const cube&) const;
        bool operator<=(const cube&) const;

        cube operator++();
        cube operator++(int);
        cube operator--();
        cube operator--(int);

        friend std::ostream &operator<<(std::ostream&, const cube&);
        friend std::istream &operator>>(std::istream&, cube&);


    private:

        bool checkMass(int);
        bool checkAcceleration(int);

    };



#endif
