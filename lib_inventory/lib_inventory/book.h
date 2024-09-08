//
//  book.h
//  lib_inventory
//
//  Created by Kelly Yu on 3/12/23.
//

#ifndef book_h
#define book_h

class book{
    public:
        book(std::string name);
        void toggle_status();
        std::string get_name() const;
        bool get_status() const;
        
    private:
        std::string m_name;
        bool m_on_shelf = true;
};

inline book::book(std::string name){ m_name = name; }

inline void book::toggle_status(){ m_on_shelf = !m_on_shelf; }

inline std::string book::get_name() const{ return m_name; }

inline bool book::get_status() const{ return m_on_shelf; }

#endif /* book_h */
