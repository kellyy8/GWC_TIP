//
//  main.cpp
//  lib_inventory
//
//  Created by Kelly Yu on 3/12/23.
//

//TAKE-HOME PROMPT:
//The user can print out a list of each book and its status (“on shelf” or “checked out”)
//The user can add new books to the inventory. The default status of newly added books will be “on shelf”
//The user can toggle the status of each book between “on shelf” and “checked out”

#include <iostream>
#include "book.h"
#include "inventory.h"

int main(){
    std::vector<book*> inventory;
    class inventory library;

    std::string input;
    while(true){
        
        //output main menu
        std::cout << "p: Print a list of each book and its status." << std::endl;
        std::cout << "a: Add book to inventory." << std::endl;
        std::cout << "t: Toggle status of a book." << std::endl;
        std::cout << "r: Remove book from inventory." << std::endl;
        std::cout << "e: Exit program." << std::endl;
        std::cout << "Select an option: ";

        std::cin >> input;
        std::cout << std::endl;

        //check against invalid inputs
        if(input.length() != 1){
            std::cout << "Please enter a valid option.\n" << std::endl;
            continue;
        }

        //exit program
        if (input == "e" || input == "E"){
            return 0;
        }

        //PROMPT REQUIREMENT #1
        //print books in inventory if inventory is not empty
        else if(input == "p" || input == "P"){
            if(library.get_inventory_size() == 0){
                std::cout << "No books in inventory.\n" << std::endl;
                continue;
            }
            library.print_inventory();
        }
        
        //PROMPT REQUIREMENT #2
        //add book to inventory
        else if(input == "a" || input == "A"){
            std::cout << "Enter book name: ";
            std::cin >> input;
            
            //if book with such title is found (duplication), request new title or return to main menu
            while(!library.add_book(input)){
                std::cout << "Inventory already contains a book with that name." << std::endl;
                std::cout << "Enter a book name or 'm' to return to main menu: ";
                std::cin >> input;
                
                if(input == "m")
                    break;
            }
        }
        
        //PROMPT REQUIREMENT #3
        //toggle status of a book if inventory contains at least 1 book
        else if(input == "t" || input == "T"){
            if(library.get_inventory_size() == 0){
                std::cout << "No books in inventory.\n" << std::endl;
                continue;
            }

            std::cout << "Enter book name: ";
            std::cin >> input;

            //if no book with such title, request new title or return to main menu
            while(!library.toggle_status(input)){
                std::cout << "No book found with that name." << std::endl;
                std::cout << "Enter a valid name or 'm' to return to main menu: ";
                std::cin >> input;
                
                if(input == "m")
                    break;
            }
        }
        
        //remove book from inventory
        else if(input == "r" || input == "R"){
            if(library.get_inventory_size() == 0){
                std::cout << "No books in inventory.\n" << std::endl;
                continue;
            }
            
            std::cout << "Enter book name: ";
            std::cin >> input;

            //if no book with such title, request new title or return to main menu
            while(!library.remove_book(input)){
                std::cout << "No book found with that name." << std::endl;
                std::cout << "Enter a valid name or 'm' to return to main menu: ";
                std::cin >> input;
                
                if(input == "m")
                    break;
            }
        }
        
        //if input is invalid
        else{
            std::cout << "Please enter a valid option." << std::endl;
        }

        std::cout << std::endl;
    }
}

