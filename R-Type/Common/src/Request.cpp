
#include <Request.h>

Request::Request()
{
    this->type = UNKNOWN;
}

Request::Request(RequestType type)
{
    this->type = type;
}

