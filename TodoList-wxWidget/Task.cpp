#include "Task.h"
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>

void saveTasksToFile(const std::vector<Task>& tasks, const std::string& fileName)
{
    // output file stream to write to the file
    std::ofstream ostream(fileName);

    ostream << tasks.size();

    // loop through the all tasks
    for (const Task& task : tasks) {
        std::string description = task.description;
        
		// replacing all the spaces with underscores to avoid issues when reading the file later
		std::replace(description.begin(), description.end(), ' ', '_');

        ostream << '\n' << description << ' ' << task.done;
    }
}

std::vector<Task> loadTaskFromFile(const std::string& fileName)
{
    return std::vector<Task>();
}
