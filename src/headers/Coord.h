#ifndef CELL_H
#define CELL_H


class Coord
{
    public:

        Coord(int x, int y);
        Coord();


        Coord(const Coord &other);
        Coord(Coord &&other);

        ~Coord() {};

        Coord& operator=(const Coord &other);
        Coord& operator=(Coord &&other);


        
        const int& GetX() const;
        const int& GetY() const;
        bool operator<(const Coord& other) const;

    private:
        int x;
        int y;


};


bool operator==(const Coord &_a, const Coord &_b);


bool operator==(Coord &_a, Coord &_b);


#endif