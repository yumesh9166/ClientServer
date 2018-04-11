#include<iostream>
#include<client.h>
void client::SetDefaults()
{
	key[0]='B', key[1]='A', key[2]='D', key[3]='C',key[4]='F',key[5]='E',key[6]='H',key[7]='G',key[8]='J',key[9]='I',key[10]='L',key[11]='K',key[12]='N',key[13]='M',key[14]='P',key[15]='O',key[16]='R',key[17]='Q',key[18]='T',key[19]='S',key[20]='V',key[21]='U',key[22]='X',key[23]='W',key[24]='Z',key[25]='Y'; 
	message.clear();
	possesKey=false;
	fp = fopen("out.txt", "w");
	fclose(fp);
}
client::client()
{
	SetDefaults();
	SetID(1); //default client id is 1
}
client::client(int id) {
	SetDefaults();
	SetID(id);
}
client::~client()
{
}
int client::GetID(void) {
	return ID;
}
void client::SetID(int id) {
	ID = id;
}
std::string client::GetMessage()
{
	Decode();
	return message;
}
void client::SetMessage(std::string msg)
{
	std::string stn = std::string("");
	if(msg.compare(stn)==0)
		return;
	message.assign(msg);
	fp = fopen("out.txt", "a");
	fprintf(fp,"%s%d%s%s%s","Client ",GetID(),":",msg.c_str(),"\n"); //file
	//fprintf(fp,"%s%d%s%s%s","Client ",GetID(),":",GetMessage().c_str(),"\n"); //file
	fclose(fp);
}
void client::SetPossesKey(bool state)
{
	possesKey = state;
}
void client::Decode()
{
	if (possesKey)
	{
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
		message=tarr;
	}
}
