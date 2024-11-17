#include "../../headers/Serializers/Serializer.h"


Serializer::Serializer() : __json()
{}

const json& Serializer::get() 
{ return __json; }


Serializer::~Serializer()
{
    
}