#include<server.h>
void server::swapClients() {
	client *temp;
	temp = sender;
	sender = receiver;
	receiver = temp;
}
