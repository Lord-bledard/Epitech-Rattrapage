#include "Server.h"


int main(int argc, char* argv[])
{

    Server server = Server();
    server.init(9999);
    server.run();

    return 0;
}