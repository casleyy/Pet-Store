#include <iostream>
using namespace std;

//pet sales system

//rank a

void UserInput(string& username, int& usercount);

//rank d & c
void DisplayMenu(); 
void ChooseMenu(char& choose, char &ordermore, float &payment, float &money, float &change, float &totalmoney); 



void Checkout(float &payment, float &money, float &change, float &totalmoney); 

int main()
{
    float payment;
    float money;
    float change;

    string username; 
    char newuser;


    char choose;
    char ordermore;

    struct userinfo {
        string clientname; 
        float collectmoney; 
    };


    float totalmoney = 0;; //for calculating all of the money of the client

    int usercount = 0;
    const int MAXUSER = 10;
    userinfo Clientinfo [MAXUSER];



    do {

        payment = 0;
        change = 0;
        money = 0;

        UserInput(username, usercount);

        ChooseMenu(choose, ordermore, payment, money, change, totalmoney);  

        totalmoney += money; 

        Clientinfo[usercount % MAXUSER] = { username, money }; //indexing into the array

        do {
            cout << "Is another user gonna order? (Y/N): ";
            cin >> newuser;

            if (newuser != 'y'&& newuser  != 'Y' && newuser != 'n' && newuser != 'N') {
                cout << "\n\nInvalid response! Please try again!";
            }
            else if (usercount > 10) {
                cout << "\n\nMaximum users (10) have already used this program"
                    << "\n\nThank you for using our service! Exiting program. . .";

                //show client user stuff... rank a
                cout << "- - -[CUSTOMER SUMMARY]- - -\n";
                for (int i = 0; i < usercount; i++) {
                    int index = i % MAXUSER;
                    cout << Clientinfo[index].clientname << " :Php " << Clientinfo[index].collectmoney << endl;
                }


                cout << "\n The total collected money from all clients is: Php" << totalmoney;
                exit(0); 
            }

        } while (newuser != 'y' && newuser != 'Y' && newuser != 'n' && newuser != 'N');

    } while (newuser == 'Y' || newuser == 'y' && usercount <= 10);
	
    cout << "Thank you for using our service ! Goodbye !\n\n";


    //show client user stuff... rank a
    cout << "- - -[CLIENT HISTORY- - -\n";
    for (int i = 0; i < usercount; i++) {
        int index = i % MAXUSER; 
        cout << Clientinfo[index].clientname << " :Php " << Clientinfo[index].collectmoney << endl;
    }


    cout << "\n The total collected money from all clients is: Php" << totalmoney;


    return 0;

}

void UserInput(string& username, int &usercount) {
    system("cls");
    cout << "- - -[USER INFO}- - -";
    cout << "\nHello Dear user!"
        << "\n\nPlease Enter Your name:";
    cin >> username;

    usercount++;

    cout << "\n Thank you so much ! and we hope our service here in the pet store pleases you!\n\n";


}

void DisplayMenu() {
    system("pause");
    system("cls");
    cout << "- - - -[MAIN MENU]- - - -\n"
        << "A.\tPet Food\tPhp200\n"
        << "B.\tPet Toy\t\tPhp150\n"
        << "C.\tPet Bed\t\tPhp230\n"
        << "D.\tPet Leash\tPhp125\n"
        << "E.\tPet Brush\tPhp175\n";
}

void ChooseMenu(char& choose, char &ordermore, float &payment, float &money, float &change, float &totalmoney) {

    float foodA = 200;
    float toysB = 150;
    float bedsC = 230;
    float leashD = 125;
    float brushE = 175;


    //making an array to display history called history that is onlyuntil 5
    string  History[5];
    float Prices[5];
    int CartCount = 0; //add everytime so it adds up unill 5 w ++



    do {
        do {
            float quantity = 0;

            DisplayMenu();
            cout << "\n\nWhat would you like to buy: ";
            cin >> choose;
            switch (toupper(choose)) {
            case 'A':
                cout << "\n\nYou have chosen A! Also known as Pet Food";

                do {
                    cout << "\n\nHow many sacs would you like to buy (quantity*amount): ";
                    cin >> quantity;

                    if (quantity <= 0) {
                        cout << "\n\nInvalid Input! Please try again! ";
                    }
                } while (quantity <= 0);
                payment += (foodA*quantity); 
                cout << "\n\nYour payment is now: Php " << payment; 

                //indexing this into histoy
                History[CartCount % 5] = { "Pet Food" };
                Prices [CartCount%5] = payment;  
                CartCount++;

                break;

            case 'B':
                cout << "\n\nYou have chosen B! Also known as Pet toy";

                do {
                    cout << "\n\nHow many toys would you like to buy (quantity*amount): ";
                    cin >> quantity; 

                    if (quantity <= 0) {
                        cout << "\n\nInvalid Input! Please try again! ";
                    }
                } while (quantity <= 0);
                payment += (toysB*quantity); 

                cout << "\n\nYour payment is now: Php " << payment;


                //indexing this into histoy
                History[CartCount % 5] = { "Pet Toy"};
                Prices[CartCount % 5] = payment; 
                CartCount++;

                break;
            case 'C':
                cout << "\n\nYou have chosen C! Also known as Pet Bed";

                do {
                    cout << "\n\nHow many beds would you like to buy (quantity*amount): ";
                    cin >> quantity; 

                    if (quantity <= 0) {
                        cout << "\n\nInvalid Input! Please try again! ";
                    }
                } while (quantity <= 0);

                payment += (bedsC*quantity); 

                cout << "\n\nYour payment is now: Php " << payment; 

                //indexing this into histoy
                History[CartCount % 5] = { "Pet Bed"};
                Prices[CartCount % 5] = payment; 
                CartCount++;

                break;
            case 'D':
                cout << "\n\nYou have chosen D! Also known as Pet Leash";

                do {
                    cout << "\n\nHow many leashes would you like to buy (quantity*amount): ";
                    cin >> quantity; 

                    if (quantity  <= 0) {
                        cout << "\n\nInvalid Input! Please try again! ";
                    }
                } while (quantity <= 0);

                payment += (leashD*quantity); 
                cout << "\n\nYour payment is now: Php " << payment;

                //indexing this into histoy
                History[CartCount % 5] = { "Pet Leash"};
                Prices[CartCount % 5] = payment; 
                CartCount++;

                break;
            case 'E':
                cout << "\n\nYou have chosen E! Also known as Pet Brush";

                do {
                    cout << "\n\nHow many brushes would you like to buy (quantity*amount): ";
                    cin >> quantity;

                    if (quantity <= 0) {
                        cout << "\n\nInvalid Input! Please try again! ";
                    }
                } while (quantity <= 0);
                payment += (brushE*quantity);  
                cout << "\n\nYour payment is now: Php " << payment;

                //indexing this into histoy
                History[CartCount % 5] = { "Pet Brush"};
                Prices[CartCount % 5] = payment; 
                CartCount++;
                break;
            default:
                cout << "\nThat is not a valid response! Please try again!";
                break;
            }

            do {
                cout << "\n\nWould you still like to order? (Y/N): ";
                cin >> ordermore; 

                if (ordermore != 'y' && ordermore != 'Y' && ordermore != 'n' && ordermore != 'N') {
                    cout << "\n\nInvalid response! Please try again!";
                }

                else if (ordermore == 'n' || ordermore == 'N') {
                    Checkout(payment, money, change, totalmoney);  

            

                    //displaying history
                    cout << "- - -[CLIENT HISTORY]- - -\n";

                    if (CartCount == 0) {
                        cout << "\n\nNo Transactions were made!";
                    }
                    else {
                        //displaying array
                        for (int i = 0; i < CartCount; i++) {
                            cout << History[i]  << " : Php " << Prices[i] << "\n";
                        }   
                    }

                    system("pause"); 

                }

            } while (ordermore != 'y' && ordermore != 'Y' && ordermore != 'n' && ordermore != 'N');
            system("cls");
        } while (ordermore == 'Y' || ordermore == 'y');
    } while (ordermore == 'Y' || ordermore == 'y'); 

}

void Checkout(float &payment, float &money, float &change, float &totalmoney) {
    do {
        system("pause");
        system("cls");

        cout << "- - -[CHECKOUT]- - -";
        cout << "\nTotal amount to pay: Php " << payment;
        cout << "\n\nPlease Enter the Amount you would like to pay: ";
        cin >> money;

        if (money < payment ) {
            cout << "\n\nInsufficient Funds ! Please Try Again!\n\n";
        }
        else if (money <= 0) {
            cout << "\n\nInvalid Input! Please Try Again!\n\n";
        }
        else {
            change = money - payment;
            cout << "\n\nYou have a change of: " << change << endl << endl;
            system("pause");
            system("cls");
        }

    } while (money < payment || money <= 0); 
}