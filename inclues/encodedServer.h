#pragma once
#include<server.h>
class encodedServer:public server {
	char key[26];
public:
	encodedServer();
	void establishConnection(client *client1, client *client2);
	void sendMessage(std::string str);
	std::string encodeMessage(std::string message);
};
