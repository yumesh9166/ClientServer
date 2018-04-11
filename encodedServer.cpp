#include<encodedServer.h>
encodedServer::encodedServer() {
	key[0]='B', key[1]='A', key[2]='D', key[3]='C',key[4]='F',key[5]='E',key[6]='H',key[7]='G',key[8]='J',key[9]='I',key[10]='L',key[11]='K',key[12]='N',key[13]='M',key[14]='P',key[15]='O',key[16]='R',key[17]='Q',key[18]='T',key[19]='S',key[20]='V',key[21]='U',key[22]='X',key[23]='W',key[24]='Z',key[25]='Y'; 
}
void encodedServer::establishConnection(client *senderclient, client *receiverclient) {
	sender = senderclient;
	receiver = receiverclient;
}
void encodedServer::sendMessage(std::string str) {
	str.assign(encodeMessage(str));
	receiver->SetMessage(str);
}
std::string encodedServer::encodeMessage(std::string message) {
	std::string codedstring("");
	const char *cptr = message.c_str();
	char tarr[100];
	int tarrindex = 0;
	for (register int i = 0; i < message.length(); i++)
	{
		int index = (int)cptr[i] - 65;
		char c = key[index];
		tarr[tarrindex++] = c;
	}
	tarr[tarrindex] = '\0';
	codedstring=tarr;
	return codedstring;
}
