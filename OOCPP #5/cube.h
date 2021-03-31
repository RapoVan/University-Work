#ifndef CUBE_H
#define CUBE_H

#include <string>

namespace box{

    class cube{

        private:

            class innerCube;
            innerCube *ptr;


        public:

            cube();
            cube(const std::string&, int, int);
            cube(const cube&);
            cube& operator =(const cube&);
            void init(int, const std::string&, int, int);
            ~cube();

            void setMass(int);
            void setAcceleration(int);
            void setColor(const std::string&);
            void setCubeId(int);

            int getMass() const;
            int getAcceleration() const;
            std::string getColor() const;
            int getCubeId() const;
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
}

#endif // CUBE_H
