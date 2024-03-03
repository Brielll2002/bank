#include <iostream>
#include <string>
#include <locale.h>
#include <stdlib.h>

int main();

void marcacao(int x){
std::string linha;
for(int c = 0; c < x; c++){
    linha = linha + "-";
}
std::cout << "|" << linha << "|" << std::endl;
}

void welcome(int* accountNumber, int* PIN){

system("cls");
int account;
int pin;

std::cout << "\nWELCOME!\n" << std::endl;
std::cout << "Please enter your account number: ";
std::cin >> account;
std::cout << "\nEnter your PIN: ";
std::cin >> pin;

*accountNumber = account;
*PIN = pin;
}

void yourChoice(int* choice){
    int response;

    marcacao(50);
    std::cout << "\nMAIN MENU:\n" << std::endl;
    std::cout << "1 - Ver saldo" <<std::endl;
    std::cout << "2 - Sacar" <<std::endl;
    std::cout << "3 - Depositar" <<std::endl;
    std::cout << "4 - Sair" <<std::endl;
    std::cout << "\nEnter a choice: " <<std::endl;
    std::cin >> response;

    *choice = response;
}

void yourBalance(int balance, int choice){
    marcacao(50);
    std::cout << "Seu saldo é: " << balance << "." << std::endl;
    marcacao(50);

    system("pause");
    main();
}

void widthdraw(int* balance, int choice){
    int response;
    std::cout << "Digite o valor do saque: " << std::endl;
    std::cin >> response;

    if(response > *balance){
        marcacao(50);
        std::cout << "Saldo insuficiente. Seu saldo é: " << *balance << std::endl;
        marcacao(50);
        widthdraw(balance, choice);
    }
    else{
        *balance = *balance - response;
        marcacao(50);
        std::cout << "Saque realizado com sucesso! Seu saldo agora é: " << *balance << std::endl;
        marcacao(50);

        system("pause");
        main();
    }
}

void depositFunds(int* balance, int choice){
    int response;
    std::cout << "Digite o valor para depósito: " << std::endl;
    std::cin >> response;

    *balance = *balance + response;
    marcacao(50);
    std::cout << "Depósito realizado com sucesso. Seu saldo agora é: " << *balance << std::endl;
    marcacao(50);

    system("pause");
    main();
}

int main(){
setlocale(LC_ALL,"");

int accountNumber;
int PIN;
int choice;
int balance = 1420;


while(accountNumber != 123 || PIN != 123){
    welcome(&accountNumber, &PIN);
}

    yourChoice(&choice);
   switch(choice){
    case 1: yourBalance(balance, choice);
    break;

    case 2: widthdraw(&balance, choice);
    break;

    case 3: depositFunds(&balance, choice);
    break;

    case 4: system("exit");
    break;

    default: welcome(&accountNumber, &PIN);
   }

return 0;
}
