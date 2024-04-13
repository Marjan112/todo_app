#include "TodoItem.hpp"

TodoItem::TodoItem(const std::string& todo, bool completed) : todo(todo), completed(completed) {}

std::string TodoItem::get_todo() const {
    return todo;
}

bool TodoItem::get_status() const {
    return completed;
}

void TodoItem::set_status(bool completed) {
    this->completed = completed;
}