#ifndef PROFILEMAN_HH
#define PROFILEMAN_HH
#include <string>
#include <vector>
using namespace std;

struct Message {
    string destinatario;
    string mittente;
    string oggetto;
    string body;
    string timestamp;
    unsigned int len;

};

class Profile
{   private:
    string nome;
    string cognome;
    string email;
    string password;
    vector<Message> MessageRepo;
    public:
    Profile(string, string, string, string);
    void add_message(Message*);
    Message* write_message();
};

#endif