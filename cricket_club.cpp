#include <iostream>
#include <string>
#include <limits>
#include <cctype>

#include "vector.h"
#include "queue.h"
#include "stack.h"
#include <map> 

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
using namespace std;


class PractiseShedule
{
public:
    string practisedate;
    string practisevenue;
    string practisetime;

    PractiseShedule(const string& practisedate, const string& practisevenue, const string practisetime)
       :  practisedate(practisedate), practisevenue(practisevenue) ,practisetime(practisetime) {}

    void displayDetails(){
    
        cout << "\t"<<practisedate <<"\t"<< practisevenue <<"\t\t"<< practisetime<<"\t" << endl;
    }
};

class CricketEvent {
public:
    string eventName;
    string date;
    string time;
    string venue;
    
    CricketEvent(const string& name, const string& eventDate, const string& eventTime, const string& eventVenue)
        : eventName(name), date(eventDate), time(eventTime), venue(eventVenue) {}
    CricketEvent() = default; // Default constructor

    void displayDetails(){
        
        cout <<"\t"<< eventName <<"\t\t"<< venue <<"\t\t" << date <<"\t"<<time << endl;
    }
};

class User {
public:
    string username;
    string password;
    string fullName;
    int age;
    int highestScore;
    bool isBowler;
    bool isWicketKeeper;
    bool isBatsman;
    bool isTeamMember;

    User* left;
    User* right;
    
   

    User(const string& uname, const string& pwd, const string& name,
        int userAge, int score, bool bowler, bool wicket, bool batsman, bool teamMember)
        : username(uname), password(pwd), fullName(name), age(userAge), highestScore(score),
        isBowler(bowler), isWicketKeeper(wicket), isBatsman(batsman), isTeamMember(teamMember),
        left(nullptr), right(nullptr) {}

    void printUserDetails() const {
    cout << "\n\t\tUsername\t|\t" << username << endl;
    cout << "\t\tFull Name\t|\t" << fullName <<  endl;
    cout << "\t\tAge\t\t|\t" << age <<  endl;
    cout << "\t\tHighest Score\t|\t" << highestScore <<  endl;
    cout << "\t\tBowler\t\t|\t" << (isBowler ? "Yes" : "No") <<  endl;
    cout << "\t\t|Wicket Keeper\t|\t" << (isWicketKeeper ? "Yes" : "No") <<  endl;
    cout << "\t\tBatsman\t\t|\t" << (isBatsman ? "Yes" : "No") <<  endl;
    cout << "\t\tTeam Member\t|\t" << (isTeamMember ? "Yes" : "No")<<  endl;
}    
};


class AdminSystem {
private:
    User* userTree = nullptr;
    Queue<CricketEvent> eventQueue;
    Queue<PractiseShedule> sheduleQueue;
    Stack<string> adminInterfaceHistory;
    map<string, string> clientCredentials;
    string loggedInClient;

public:
    void run() {
       
        
        system("CLS");
    
        cout << "\n  ================== W E L C O M E   T O ================================================================\n" << endl;
        cout << endl;

        cout << "   FFFFF   U    U  TTTTTTT  U    U  RRRRR   EEEEE        SSSS   TTTTTTT    AA     RRRRR    SSSS  "    << endl;
        cout << "   F       U    U     T     U    U  R    R  E           S          T      A  A    R    R  S      "    << endl;
        cout << "   FFFF    U    U     T     U    U  RRRRR   EEEE         SSSS      T     AAAAAA   RRRRR    SSSS  "    << endl;
        cout << "   F       U    U     T     U    U  R   R   E                S     T     A    A   R   R        S "    << endl;
        cout << "   F        UUUU      T      UUUU   R    R  EEEEE        SSSS      T     A    A   R    R   SSSS  "    << endl;

        cout << endl;
        cout << "\n  ================================================================= C R I C K E T  C L U B  =============\n" << endl;
 string userType;

    
    User firstClient("samu", "samu@123", "Samu Dilakshika", 25, 250, true, false, true, true);
    userTree = insertUser(userTree, firstClient);
    clientCredentials[firstClient.username] = firstClient.password;

    User secondClient("sach", "sach@123", "Sachintha", 28, 500, false, true, false, true);
    userTree = insertUser(userTree, secondClient);
    clientCredentials[secondClient.username] = secondClient.password;

    User thirdClient("was", "was@123", "Wasana Sene1", 22, 10, true, false, true, false);
    userTree = insertUser(userTree, thirdClient);
    clientCredentials[thirdClient.username] = thirdClient.password;

    CricketEvent firstEvent("Match 1", "2023-01-10", "14:00", "A");
    eventQueue.enqueue(firstEvent);

    CricketEvent secondEvent("Match 2", "2023-02-15", "10:00", "B");
    eventQueue.enqueue(secondEvent);

    PractiseShedule firstSchedule("2023-01-10","B","10:00");
    sheduleQueue.enqueue(firstSchedule);
    PractiseShedule secondSchedule("2023-01-15","A","13:00");
    sheduleQueue.enqueue(secondSchedule);

    while (true) {
        cout <<GREEN<<"\t \t\n C L I E N T  O R  A D M I N ?\n"<< RESET <<endl;
        cout << "\t \t \t 1. Client "<<endl;
        cout << "\t \t \t 2. Admin " << endl;
        cout << " select your option: " ;
        cin >> userType;

        if (userType == "1") {
            system("CLS");
            handleClient();
        } else if (userType == "2") {
            system("CLS");
            handleAdmin();
        } else {
            cout << RED<<"Invalid user type. Please select 'Client' or 'Admin'." <<RESET<< endl;
        }
    }
}

    void handleClient() {
        string action;
        cout << "\t \t L O G I N   or   R E G I S T E R\n \n";
        cout << "\t \t \t 1. LOG IN \n "<<endl;
        cout << "\t \t \t 2. REGISTER" << endl;
        cout << " \nselect your option: " ;
    
        cin >> action;

        if (action == "2") {
            system("CLS");
            registerUser();
        } else if (action == "1") {
            system("CLS");
            clientLogin(); 
        } else {
            cout << RED<<"Invalid action. Please select 'login' or 'register'." <<RESET<< endl;
        }
    }

    void registerUser() {
    
        string username, password, fullName;
        int age, highestScore;
        bool isBowler, isWicketKeeper, isBatsman, isTeamMember;
        cout << "\t \t Registration Details\n \n";

        
        while (true) {
            cout << "\nEnter username (First Name): ";
            bool validInput = true;
            cin >> username;
            for (char c : username) {
                if (!isalpha(c)) {
                    validInput = false;
                    break;
                }
            }
            if (validInput) {break;} 
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << RED<<"\n\tInvalid! Please enter a name again (only alphabetic characters)." <<RESET<< endl;
            }
        }

        
        while (true) {
            cout <<YELLOW<< "\nPassword must be at least 5 characters long,contain at least one number, one letter, and one special character, and must not contain spaces."<<RESET<<
            "\nEnter password: ";
            bool validInput = true;
            cin >> password;
            if (password.length() < 5 || password.find(' ') != string::npos) {
                validInput = false;
            } 
            else {
                bool hasDigit = false;
                bool hasLetter = false;
                bool hasSpecialChar = false;
                for (char c : password) {
                    if (isdigit(c)) {
                        hasDigit = true;
                    } else if (isalpha(c)) {
                        hasLetter = true;
                    } else if (!isalnum(c)) {
                        hasSpecialChar = true;
                    }
                }
                if (!(hasDigit && hasLetter && hasSpecialChar)) {
                    validInput = false;
                }
            }
            if (validInput) {break;}
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << RED<<"\n\tInvalid password."<<RESET << endl;
            }
        }

        
        cout << "\nEnter full name (S. Perera): ";
        cin.ignore();
        getline(cin, fullName); //here we can use more than 1 strings. 


    
        bool validInput = false;

        while (true) {
            cout << "\nEnter age: ";
            string input;
            cin >> input;

            
            for (char c : input) {
                if (!isdigit(c)) {
                    validInput = false;
                    break;
                }
                validInput = true;
            }

            
            if (validInput) {
                age = stoi(input);

                
                if (cin.peek() == '\n') {
                    break;
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } else {
                
                cout << RED << "\n\tInvalid age type. Please re-enter age." << RESET << endl;
                
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        
        validInput = false;

        while (true) {
            cout << "\nEnter highest score: ";
            string input;
            cin >> input;

            
            for (char c : input) {
                if (!isdigit(c)) {
                    validInput = false;
                    break;
                }
                validInput = true;
            }

            
            if (validInput) {
                highestScore = stoi(input);

                
                if (cin.peek() == '\n') {
                    break;
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } else {
                
                cout << RED << "\n\tInvalid age type. Please re-enter age." << RESET << endl;
                
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        
        
        
        while (true) {
            cout << "\nAre you a bowler (1 for yes, 0 for no): ";
            if (cin >> isBowler && (isBowler == 0 || isBowler == 1)) {break;} 
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout <<RED<< "\n\tInvalid input. Please enter 1 for yes or 0 for no." <<RESET<< endl;
            }
        }

        
        while (true) {
            cout << "\nAre you a wicket keeper (1 for yes, 0 for no): ";
            if (cin >> isWicketKeeper && (isWicketKeeper == 0 || isWicketKeeper == 1)) {break;}
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << RED<<"\n\tInvalid input. Please enter 1 for yes or 0 for no."<<RESET << endl;
            }
        }

        
        while (true) {
            cout << "\nAre you a batsman (1 for yes, 0 for no): ";
            if (cin >> isBatsman && (isBatsman == 0 || isBatsman == 1)) {break;}
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << RED<<"\n\tInvalid input. Please enter 1 for yes or 0 for no." <<RESET<< endl;
            }
        }

        
        while (true) {
            cout << "\nAre you willing to participate as a team member (1 for yes, 0 for no): ";
            if (cin >> isTeamMember && (isTeamMember == 0 || isTeamMember == 1)) {break;}
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << RED<<"\n\tInvalid input. Please enter 1 for yes or 0 for no."<<RESET << endl;
            }
        }

        User newUser(username, password, fullName, age, highestScore, isBowler, isWicketKeeper, isBatsman, isTeamMember);
        userTree = insertUser(userTree, newUser);
        system("CLS");
        cout << "\n\n\t\t\t  U s e r   r e g i s t r a t i o n   s u c c e s s f u l  \n\n\n" << endl;

        
        clientCredentials[username] = password;
    }
        
    void clientLogin() {
        string username, password;
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;
        int x;

        if (clientCredentials.count(username) && clientCredentials[username] == password) {
            loggedInClient = username; // Track logged-in client
            cout << "\nClient login successful!" << endl;
            
            clientDetails();
            cout<< endl;
            cout << endl ;
            viewAllEvents(); // Display events entered by the admin
            cout<< endl;
            cout << endl;
            viewAllShedules();
            cout<<"PRESS 1  LOG OUT :";cin>>x;
            system("CLS");

        } else {
            cout << RED<<"\nClient login failed. Please check your password."<<RESET << endl;
        }
    }

    void clientDetails() {
    User* clientUser = findUserByUsername(userTree, loggedInClient);
    if (clientUser != nullptr) {
        cout << BLUE<<"\n\t\t ||| C l i e n t   D e t a i l s |||" <<RESET<< endl;
        clientUser->printUserDetails();
    } else {
        cout <<YELLOW <<"\n\tClient details not found."<<RESET << endl;
    }
    }

    User* findUserByUsername(User* root, const string& username) {
    if (root == nullptr || root->username == username) {
        return root;
    }

    if (username < root->username) {
        return findUserByUsername(root->left, username);
    } else {
        return findUserByUsername(root->right, username);
    }
    }

    User* insertUser(User* root, const User& newUser) {
    if (root == nullptr) {
        return new User(newUser);
    }

    if (newUser.username < root->username) {
        root->left = insertUser(root->left, newUser);
    } else if (newUser.username > root->username) {
        root->right = insertUser(root->right, newUser);
    } else {
        
        if (newUser.username < root->username) {
            root->left = insertUser(root->left, newUser);
        } else {
            root->right = insertUser(root->right, newUser);
        }
    }
  
    return root;
}

    void inOrderTraversal(User* root, vector<User*>& users) {
    if (root != nullptr) {
        inOrderTraversal(root->left, users);
        users.push_back(root);
        inOrderTraversal(root->right, users);
    }
}

    void displayUsers(User* root) {
    vector<User*> users;
    inOrderTraversal(root, users);

    
    if (!users.empty()) {
        cout << BLUE<<"\n ||| C L I E N T  D E T A I L S |||\n"<<RESET << endl;
        cout << "Username\tFull Name\t\tHighest Score\t\tAge\t\tBowler\t\tWicket Keeper\t\tBatsman\t\tTeam Member" << endl;

        for (const auto& user : users) {
            cout<<user->username<< "\t\t"<< user->fullName<<"\t\t"<< user->highestScore<<"\t\t\t"<<user->age<<"\t\t"<<user->isBowler<<"\t\t"<<user->isWicketKeeper<<"\t\t\t"<<user->isBatsman<<"\t\t"<<user->isTeamMember<<endl;
            }
    } else {
        cout << "\nNo users to display." << endl;
    }
}

    void handleAdmin() {
        int x;
        string adminUsername = "admin";
        string adminPassword = "admin123";
        adminInterfaceHistory.push("\nAdmin Event Management Menu");

        string username, password;
        cout << "\nEnter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;

        if (username == adminUsername && password == adminPassword) {
        cout <<GREEN<< "\n\t\tA d m i n   l o g i n   s u c c e s s f u l ! " << RESET <<endl;

        while (true) {
            cout <<BLUE<< "\n||| A d m i n    M a n a g e m e n t   M e n u |||"<<RESET << endl;
            cout << endl;
            cout << "\t1. Add an event" << endl;
            cout << endl;
            cout << "\t2. Add prctise shedule" << endl;
            cout << endl;
            cout << "\t3. View all events" << endl;
            cout << endl;
            cout << "\t4. View Practise Shedule" << endl;
            cout << endl;
            cout << "\t5. View client Details" << endl;
            cout << endl;
            cout << "\t6. Logout" << endl;

            int choice;
            cout << "\n\t\tEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    system("CLS");
                    addEvent();
                    adminInterfaceHistory.push("Event added successfully.");
                    cout<<"press 1 to go back :";cin>>x;
                    system("CLS");
                    
                    break;
                }
                case 2: {
                    system("CLS");
                    addpractise();
                    adminInterfaceHistory.push("Shedule added successfully.");
                    cout<<"press 1 to go back :";cin>>x;
                    system("CLS");
                    break;
                }
                
                case 3: {
                    system("CLS");
                    viewAllEvents();
                    adminInterfaceHistory.push("Viewed all events.");
                    cout<<"press 1 to go back :";cin>>x;
                    system("CLS");
                    break;
                }
                case 4: {
                    system("CLS");
                    viewAllShedules();
                    adminInterfaceHistory.push("Viewed all Shedules.");
                    cout<<"press 1 to go back :";cin>>x;
                    system("CLS");
                    break;
                }
                case 5: {
                    system("CLS");
                    ViewUserByUsername();
                    adminInterfaceHistory.push("Viewed users Details.");
                    cout<<"\npress 1 to go back :";
                    cin>>x;
                    system("CLS");
                    break;
                }
                
                 case 6: {
                    system("CLS");
                    adminInterfaceHistory.pop();
                    // system("CLS");
                    return;
                }
                default: {
                    system("CLS");
                    cout << RED<<"Invalid choice. Please enter a valid option."<<RESET << endl;
                    cout<<"Press 1 to go back :";cin>>x;
                    system("CLS");
                    break;
                }
            }
        }
    } else {
        cout <<RED<< "Admin login failed. Please check your credentials."<<RESET << endl;
    }
}

    void addEvent() {
        string eventName, eventDate, eventTime, eventVenue;
        cout << "Enter event name(Event X): ";
        cin.ignore();
        getline(cin, eventName);

        cout << "Enter event date (YYYY-MM-DD): ";
        cin >> eventDate;

        cout << "Enter event time(HH:SS): ";
        cin >> eventTime;

        cout << "Enter event venue AT STADIUM (A/B/C): ";
        cin >> eventVenue;

        CricketEvent newEvent(eventName, eventDate, eventTime, eventVenue);
        eventQueue.enqueue(newEvent);
        cout << "Event added successfully." << endl;
        
    }
    
    void addpractise()
 {
     string practisedate, practisevenue, practisetime;
     cout << "Enter Practise Date (YYYY-MM-DD): ";
     cin >> practisedate;

     cout << "Enter Practise Venue AT PRACTISE NET (A/B/C) : ";
     cin >> practisevenue;

     cout << " Enter Practise Time (HH:SS): ";
     
     cin >> practisetime; 

     PractiseShedule newshedule(practisedate, practisevenue, practisetime);
     sheduleQueue.enqueue(newshedule);
     cout << "Shedule added successfully " << endl;

 }

    void viewAllEvents() {
    if (eventQueue.Empty()) {
        cout << YELLOW<<"\n\tNo events to display." <<RESET<< endl;
    } else {
        cout << BLUE<<"\n\t\t\t||| E v e n t s |||\n"<<RESET << endl;
        cout<<"\tEvent"<<"\t\t"<<"Venue"<<"\t\t"<<"Date"<<"\t\t"<<"Time"<<endl;
        eventQueue.print();
    }
}

    void viewAllShedules() {
    if (sheduleQueue.Empty()) {
        cout << YELLOW<<"\n\tNo events to display."<<RESET << endl;
    } else {
        cout <<BLUE<< "\n\t\t||| P r a c t i c e  S h e d u l e s |||\n"<<RESET << endl;
        cout<<"\tDate"<<"\t\t"<<"Venue"<<"\t\t"<<"Time"<<endl;
        sheduleQueue.print();
    }
}

    void ViewUserByUsername() {
        if (userTree != nullptr) {
            
            displayUsers(userTree);
        } else {
            cout << "No users to display." << endl;
        }
    }
};

int main() {

    AdminSystem adminSystem;
    
    adminSystem.run();
    
    return 0;
}