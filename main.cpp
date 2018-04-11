#include<iostream>
#include<server.h>
#include<client.h>
#include<msgServer.h>
#include<encodedServer.h>
using namespace std;
int main()
{
	client *client1 = new client();
	int idno;
	cout<<"enter client id number:";
	cin>>idno;
	client *client2 = new client(idno);
	
	server *mServer =  new msgServer();
	server *encodServer =  new encodedServer();

	mServer->establishConnection(client1, client2);	
	encodServer->establishConnection(client1, client2);
	char c1op;
	cout<<"Client "<< client1->GetID()<<", make a connection?(y/n)";
	cin>>c1op;	
	char c2op;
	cout<<"Client "<< client2->GetID()<<", make a connection?(y/n)";
	cin>>c2op;
	if(c1op=='n'||c2op=='n')
	{
		cout<<"No connection made\n"; //file
		return 0;
	}
	char econ;
	cout<<"Encrypted Connection?(y/n)";
	cin>>econ;
	char op1, op2;
	if(econ=='y')
	{	
		cout<<"Client "<<client1->GetID()<<", does client "<<client2->GetID()<<" get the key?(y/n)";
		cin>>op1;
		if(op1=='y')
			client2->SetPossesKey(true);
		cout<<"Client "<<client2->GetID()<<", does client "<<client1->GetID()<<" get the key?(y/n)";
		cin>>op2;
		if(op2=='y')
			client1->SetPossesKey(true);
	}	
	string carr;
	bool switchc = true;
	cin.ignore();
	bool toggle = true;
	do{
		if(switchc)
		{
			cout<<"Client "<<client1->GetID()<<":";
			switchc = false;
		}else{
			cout<<"Client "<<client2->GetID()<<":";
			switchc = true;
		}
		getline(cin, carr);
		if(econ=='y')
		{
			if(toggle)
			{
				toggle = false;
				if(op1=='n'){
					encodServer->swapClients();
					mServer->swapClients();
					encodServer->sendMessage(carr);
				}else{
					encodServer->swapClients();
					mServer->swapClients();
					mServer->sendMessage(carr);
				}
			}else{
				toggle = true;
				if(op2=='n'){
					encodServer->swapClients();
					mServer->swapClients();
					encodServer->sendMessage(carr);
				}else{
					encodServer->swapClients();
					mServer->swapClients();
					mServer->sendMessage(carr);
				}
			}
			
		}else{
			encodServer->swapClients();
			mServer->swapClients();
			mServer->sendMessage(carr);
		}
	}while(!carr.empty());
	return 0;
}
