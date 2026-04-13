#include "Task.h"
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>

void SaveTasksToFile(const std::vector<Task>& tasks, const std::string& fileName)
{
    // output file stream to write to the file
    std::ofstream ostream(fileName);

    ostream << tasks.size();

    for (const Task& task : tasks) {
        std::string description = task.description;
		std::replace(description.begin(), description.end(), ' ', '_');

		// writing the description and the done status to the file
        ostream << '\n' << description << ' ' << task.done;
    }
}

std::vector<Task> LoadTasksFromFile(const std::string& fileName)
{
	// if the file does not exist, return an empty vector of tasks
    if (!std::filesystem::exists(fileName)) {
        return std::vector<Task>();
    }

    std::vector<Task> tasks;
	std::ifstream istream(fileName);

    int n;
    istream >> n;

    for (int i = 0; i < n; i++) {
        std::string description;
        bool done;

		istream >> description >> done;

        std::replace(description.begin(), description.end(), '_', ' ');
		tasks.push_back(Task{ description, done });
    }

    return tasks;
}
