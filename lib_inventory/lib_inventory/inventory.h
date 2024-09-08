//
//  inventory.h
//  lib_inventory
//
//  Created by Kelly Yu on 3/12/23.
//

#ifndef inventory_h
#define inventory_h

#include <iostream>
#include <vector>
#include "book.h"

class inventory{
    public:
        ~inventory();
        int get_inventory_size() const;
        void print_inventory() const;                   //prompt requirement #1
        bool add_book(std::string name);                //prompt requirement #2
        bool toggle_status(std::string name);           //prompt requirement #3
        bool remove_book(std::string name);             //additional functionality

    private:
        std::vector<book*> m_books;
};

inline inventory::~inventory(){
    for(int i=0; i < m_books.size(); i++){
        delete m_books[i];
    }
}

inline int inventory::get_inventory_size() const{ return static_cast<int>(m_books.size()); }

//print the name and status of each book in inventory
inline void inventory::print_inventory() const{
    for(int i=0; i < m_books.size(); i++){
        std::cout << "Name: " << m_books[i]->get_name() << std::endl;
        std::cout << "Status: ";

        if(m_books[i]->get_status())
            std::cout << "on shelf" << std::endl;
        else
            std::cout << "checked out" << std::endl;
    }
}

inline bool inventory::add_book(std::string name){
    //check for duplication by book name
    for(int i=0; i< m_books.size(); i++){
        if(m_books[i]->get_name() == name){
            return false;
        }
    }
    
    m_books.push_back(new book(name));
    std::cout << "Added \"" << name << "\" into inventory." << std::endl;
    return true;
}

//update the status of a book in inventory
inline bool inventory::toggle_status(std::string name){
    for(int i=0; i < m_books.size(); i++){
        if(m_books[i]->get_name() == name){
            m_books[i]->toggle_status();
            std::cout << "Successfully toggled." << std::endl;
            return true;
        }
    }
                    
    return false;
}

inline bool inventory::remove_book(std::string name){
    std::vector<book*>::iterator it;
    for(it = m_books.begin(); it < m_books.end(); it++){
        if((*it)->get_name() == name){
            delete (*it);
            m_books.erase(it);
            std::cout << "Successfully removed book from inventory." << std::endl;
            return true;
        }
    }
    
    return false;
}


#endif /* inventory_h */
