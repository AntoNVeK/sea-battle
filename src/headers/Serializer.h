#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "../nlohmann/json.hpp"

using json = nlohmann::json;


class Serializer
{
private:
    json __json;
  
public:
    Serializer();

    virtual void load() = 0;

    const json& get();



};


#endif