#pragma once
#include<server.h>
class msgServer:public server {
public:
	msgServer();
	void establishConnection(client *client1, client *client2);
	void sendMessage(std::string str);
};
