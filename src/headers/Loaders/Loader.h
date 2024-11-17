#ifndef LOADER_H
#define LOADER_H

#include "nlohmann/json.hpp"

using json = nlohmann::json;


class Loader
{
  
public:

    virtual void loadFromJson(const json& j) = 0;

    virtual ~Loader() = 0;
};


#endif