#pragma once
#include <string>
#include <vector>

// struct so that the member's of Task are public by default.
struct Task
{
	std::string description;
	bool done;
};

// saveTasksToFile saves the task to the file
void saveTasksToFile(const std::vector<Task>& tasks, const std::string& fileName);

// loadTaskFromFile loads the task from the file
std::vector<Task> loadTaskFromFile(const std::string& fileName);