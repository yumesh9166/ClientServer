#include<msgServer.h>
msgServer::msgServer() {

}
void msgServer::establishConnection(client *senderclient, client *receiverclient) {
	sender = senderclient;
	receiver = receiverclient;
}
void msgServer::sendMessage(std::string str)
{
	receiver->SetMessage(str);
}
