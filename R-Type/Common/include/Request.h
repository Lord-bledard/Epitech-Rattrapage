#ifndef R_TYPE_REQUEST_H
#define R_TYPE_REQUEST_H

#include <string>
#include "RequestEnum.h"

struct Request {

    RequestType type;

    Request();
    Request(RequestType type);
};



/*
void initMessage(struct Request msg, MsgType type, std::string data)
{

    msg.type = type;
    strcpy(msg.data, data.c_str());
}

struct Request initMessagelocal(MsgType type, std::string data)
{
    struct Request msg;
    msg.type = type;
    strcpy(msg.data, data.c_str());
    return msg;
}
*/

#endif //R_TYPE_REQUEST_H
