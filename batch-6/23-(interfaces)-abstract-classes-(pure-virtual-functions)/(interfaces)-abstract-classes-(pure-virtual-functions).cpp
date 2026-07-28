#include iostream

using namespace std;

class clsMobile
{
public 
    virtual void SendMessage(string phoneNumber, string text) = 0;
    virtual void TakePicture() = 0;

};

class clsSmartPhone  public clsMobile
{

public

    void SendMessage(string phoneNumber, string text)
    {
         Implementation of sending message
    }

    void TakePicture()
    {
         Implementation of taking picture
    }

    void SendEmail(string emailAddress, string text)
    {
         Implementation of sending email
    }


};


int main()
{

    clsSmartPhone smartphone;

    smartphone.SendMessage(222444, Hi);

    return 0;
}