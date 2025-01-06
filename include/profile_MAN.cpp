#include "profile_MAN.hh"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <sstream>
#include <filesystem>
#include <iomanip>

using namespace std;

string get_date() {
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm* now_tm = localtime(&now_time);

    ostringstream oss;
    oss << put_time(now_tm, "%Y-%m-%d %H:%M:%S"); 
    return oss.str();
}

Profile::Profile(string nome, string cognome, string email, string password )
{
    this->nome = nome;
    this->cognome = cognome;
    this->email = email;
    this->password = password;
}

Message* Profile::write_message(){

    struct Message* msg;

    cout << "Destinatario: ";
    cin >> msg->destinatario;

    cout << "\n\n";
    
    cout << "Oggetto: ";
    cin >> msg->oggetto;

    cout << "\n\n";

    cout << "Scrivi il messaggio: ";
    cin >> msg->body;

    
    msg->mittente = this->nome;
    msg->timestamp = get_date();

    msg->len = sizeof(msg);

    return msg;
    
}

void Profile::add_message(Message* msg)
{
    this->MessageRepo.push_back(*msg);
}

int Profile::create_profile_folder() {
    try {
        // Construct the folder path using email and name
        string folder_path = "Profiles/" + this->email + "_" + this->nome;

        // Create the directory using filesystem
        if (filesystem::create_directories(folder_path)) {
            cout << "Profile folder created successfully: " << folder_path << endl;
            return 0; // Success
        } else {
            cerr << "Profile folder already exists or could not be created." << endl;
            return 1; // Already exists or error
        }
    } catch (const exception& e) {
        // Handle any exceptions
        cerr << "Error creating profile folder: " << e.what() << endl;
        return -1; // Exception occurred
    }
}