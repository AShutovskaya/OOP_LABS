#include "FileUserManager.h"
#include<iostream>
#include<fstream>
using namespace std;
namespace AS {
	FileUserManager::FileUserManager()
	{
	}
	void FileUserManager:: SignIn(AS::User user) {
     
		actual_user = user;
		ofstream file("Authorization.txt");
		file << user.id << " " << user.login << " " << user.password << " " << user.name<<"\n";
		file.close();
		cout << "Succesful authorization!" << endl;
	}
	void FileUserManager::SignOut()
	{
		actual_user = AS::User();
		ofstream file("Authorization.txt");

		file<< "";
		file.close();

		cout << "Account logout completed!" << endl;
	}
	bool FileUserManager::IsAuthorized()
	{
		return ! actual_user.login.empty();
	}
	
    void FileUserManager::SignUp(std::string login, std::string name, std::string password) {
        AS::User user = user_repository.GetByName(login);

        if (user.login.empty()) {
            User user;
            user.id = user_repository.createNewId();
            user.login = login;
            user.name = name;
            user.password = password;

            user_repository.Add(user);
           
            std::cout << "You added new account!" << std::endl;

        }
        else {
            std::cout << "User with the same name already exists" << std::endl;
        }
    }


    void FileUserManager::Work() {
        User user = user_repository.checkLogin();

        if (!user.login.empty()) {
            this->SignIn(user);
        }

        while (true) {
            if (!IsAuthorized()) {
                std::cout << "1.Sign in" << std::endl;
                std::cout << "2.Sign up" << std::endl;
            }
            else {
                std::cout << "1.Sign out" << std::endl;
            }
            std::cout << "3.Finish" << std::endl;

            int choice;
            std::cin >> choice;

            if (choice == 1) {
                if (IsAuthorized()) {
                    SignOut();
                }
                else {
                    std::string login, password;
                    std::cout << "Enter login: ";
                    std::cin >> login;
                    std::cout << "Enter password: ";
                    std::cin >> password;

                    User user = user_repository.GetByName(login);
                    if (!user.login.empty() && user.password == password) {
                        SignIn(user);
                    }
                    else {
                        std::cout << "User is not found" << std::endl;
                    }
                }
            }
            else if (choice == 2) {
                std::string login, name, password;
                std::cout << "Enter login: ";
                std::cin >> login;
                std::cout << "Enter nickname: ";
                std::cin >> name;
                std::cout << "Enter password: ";
                std::cin >> password;

                SignUp(login, name, password);
            }
            else if (choice == 3) {
                break;
            }
        }
    }
}



