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

		// writing the description and the done status to the file
        ostream << '\n' << description << ' ' << task.done;
    }
}

std::vector<Task> loadTaskFromFile(const std::string& fileName)
{
	// if the file does not exist, return an empty vector of tasks
    if (!std::filesystem::exists(fileName)) {
        return std::vector<Task>();
    }

	// vector to store the tasks read from the file
    std::vector<Task> tasks;
	std::ifstream istream(fileName);

    int n;
	// reading the number of tasks from the file
    istream >> n;

    for (int i = 0; i < n; i++) {
		// reading the description and the done status of each task from the file
        std::string description;
        bool done;

		// // replacing all the underscores with spaces to get the original description
		istream >> description >> done;

        // replacing all the underscores with spaces to get the original description
        std::replace(description.begin(), description.end(), '_', ' ');
		tasks.push_back(Task{ description, done });
    }

    return tasks;
}
