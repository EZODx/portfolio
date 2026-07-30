#pragma once

#include <iostream>

using namespace std;

class InterfaceCommunication
{

public:
	virtual void SendEmail(string title, string body) = 0;
	virtual void SendFax(string title, string body) = 0;
	virtual void SendSMS(string title, string body) = 0;

};