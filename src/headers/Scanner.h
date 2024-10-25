#ifndef SCANNER_H
#define SCANNER_H
#include "Table.h"
#include "Coord.h"
#include "ISkill.h"
#include "Scanner.h"


class Scanner : public ISkill
{
public:

    Scanner(Coord coord, SkillResult& results);

    void use(Table& table) override;

    ~Scanner() override = default;
private:

    Coord coord;


    SkillResult& results;


};





#endif