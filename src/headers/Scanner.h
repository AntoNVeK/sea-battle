#ifndef SCANNER_H
#define SCANNER_H
#include "Table.h"
#include "Coord.h"
#include "ISkill.h"
#include "Scanner.h"


class Scanner : public ISkill
{
public:

    Scanner(int x, int y);

    void use(Table& table) override;

    void install_reaction(std::function<void(ScannerResult state)> func) override;

    ~Scanner() override = default;
private:

    int _x;
    int _y;

    std::function<void(ScannerResult state)> _reaction;


};





#endif