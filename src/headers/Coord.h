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

    private:
        int x;
        int y;


};


#endif