#pragma once
#include<string>
class client {
private:
	int ID;
	std::string message;
	bool possesKey;
	char key[26];
	FILE *fp;
public:
	void SetDefaults();
	client();
	client(int id);
	~client();
	int GetID(void);
	void SetID(int id = 1);
	std::string GetMessage();
	void SetMessage(std::string msg);
	void SetPossesKey(bool state);
	void Decode();
};
