#include "TodoList.hpp"

TodoList::TodoList() {
    std::fstream todo_file("todo.dat", std::ios::in | std::ios::binary);
        
    while(todo_file.peek() != EOF) {
        std::string description;
        std::getline(todo_file, description, '\0');
        bool completed;
        todo_file.read(reinterpret_cast<char*>(&completed), sizeof(bool));
        todo_list.push_back(TodoItem(description, completed));
    }
}

void TodoList::add_todo(const std::string& todo) {
    todo_list.push_back(TodoItem(todo));
}

void TodoList::display_todo() const {
    if(todo_list.empty()) {
        std::cout << "\nTodo list is empty.\n\n";
        return;
    }

    std::cout << "\nTodo List:\n";
        
    int todo_count = 1;
    for(const auto& todo : todo_list) {
        std::cout << todo_count++ << " | " << todo.get_todo() << " | " << (todo.get_status() ? "Completed" : "Not completed") << "\n";
    }

    std::cout << "\n";
}

void TodoList::save_todo() {
    std::fstream todo_file("todo.dat", std::ios::out | std::ios::binary);

    for(const auto& todo : todo_list) {
        std::string description = todo.get_todo();
        bool status = todo.get_status();
        todo_file.write(description.c_str(), description.size() + 1);
        todo_file.write(reinterpret_cast<char*>(&status), sizeof(bool));
    }
}

size_t TodoList::elements() const {
    return todo_list.size();
}

TodoItem& TodoList::operator[](size_t index) {
    return todo_list.at(index);
}