#pragma once
#include<string>
#include<client.h>
class server {
protected:
	client *sender;
	client *receiver;
public:
	virtual void establishConnection(client *client1, client *client2) = 0;
	virtual void sendMessage(std::string str) = 0;
	void swapClients();
};
