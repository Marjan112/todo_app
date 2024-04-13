#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "TodoItem.hpp"

class TodoList {
public:
    TodoList();
    void add_todo(const std::string& todo);
    void display_todo() const;
    void save_todo();
    size_t elements() const;
    TodoItem& operator[](size_t index);
private:
    std::vector<TodoItem> todo_list;
};