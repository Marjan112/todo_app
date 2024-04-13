#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

#include "TodoList.hpp"

int main() {
    TodoList todo_list;
    
    int choice;
    do {
        std::cout << "1. Add todo\n";
        std::cout << "2. List todos\n";
        std::cout << "3. Mark todo as completed\n";
        std::cout << "4. Save and exit\n";

        while(!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch(choice) {
            case 1: {
                std::string description;
                std::cout << "\nTodo description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                todo_list.add_todo(description);
                std::cout << "Added " << description << " in todo list.\n\n";
                break;
            }
            case 2: {
                todo_list.display_todo();
                break;
            }
            case 3: {
                std::cout << "\n";
                if(todo_list.elements() == 0) {
                    std::cout << "Todo list is empty.\n\n";
                    break;
                }

                size_t todo_index;
                do {
                    std::cout << "Todo index: ";
                    while(!(std::cin >> todo_index)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                } while(todo_index < 1 || todo_index > todo_list.elements());
                if(!todo_list[todo_index - 1].get_status()) {
                    todo_list[todo_index - 1].set_status(true);
                    std::cout << "Todo with the index " << todo_index << " is now marked as completed.\n\n";
                } else {
                    std::cout << "Todo with the index " << todo_index << " is already marked as completed.\n\n";
                }
                break;
            }
            case 4: {
                todo_list.save_todo();
                break;
            }
        }
    } while(choice != 4);
    return 0;
}