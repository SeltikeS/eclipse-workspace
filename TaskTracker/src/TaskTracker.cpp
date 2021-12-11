//============================================================================
// Name        : TaskTracker.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


//// Перечислимый тип для статуса задачи
//enum class TaskStatus {
//	NEW,          // новая
//	IN_PROGRESS,  // в разработке
//	TESTING,      // на тестировании
//	DONE          // завершена
//};
//
//// Объявляем тип-синоним для map<TaskStatus, int>,
//// позволяющего хранить количество задач каждого статуса
//using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
	// Получить статистику по статусам задач конкретного разработчика
	const TasksInfo& GetPersonTasksInfo(const string& person) const {
		if(team.count(person) != 0) {
			return team.at(person);
		}
			else {
			throw invalid_argument("");
		}
	}

	// Добавить новую задачу (в статусе NEW) для конкретного разработчитка
	void AddNewTask(const string& person) {
		++team[person][TaskStatus::NEW];
	}

	// Обновить статусы по данному количеству задач конкретного разработчика,
	// подробности см. ниже
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
		vector<TaskStatus> current_tasks;
		// Add all current tasks to vector

		pair<TasksInfo, TasksInfo> update;
		if(team.count(person) != 0) {
			for(const auto& pers : team[person]) {
				int count = pers.second;
				for(int i = 0; i < count; ++i) {
					current_tasks.push_back(pers.first);
				}
			}

			int count = task_count;
			for(auto& item : current_tasks) {
				if(count > 0) {
					switch(item) {
						case TaskStatus::NEW :
							++update.first[TaskStatus::IN_PROGRESS];
							--team[person][TaskStatus::NEW];
							if(team[person][TaskStatus::NEW] == 0) {
								team[person].erase(TaskStatus::NEW);
							}
							++team[person][TaskStatus::IN_PROGRESS];
							break;
						case TaskStatus::IN_PROGRESS :
							++update.first[TaskStatus::TESTING];
							--team[person][TaskStatus::IN_PROGRESS];
							if(team[person][TaskStatus::IN_PROGRESS] == 0) {
								team[person].erase(TaskStatus::IN_PROGRESS);
							}
							++team[person][TaskStatus::TESTING];
							break;
						case TaskStatus::TESTING :
							++update.first[TaskStatus::DONE];
							--team[person][TaskStatus::TESTING];
							if(team[person][TaskStatus::TESTING] == 0) {
								team[person].erase(TaskStatus::TESTING);
							}
							++team[person][TaskStatus::DONE];
							break;
						case TaskStatus::DONE :
							break;
					}

				} else {
					if(item != TaskStatus::DONE) {
						++update.second[item];
					}
				}
				--count;
			}
		}

		tuple<TasksInfo, TasksInfo> t = make_tuple(update.first, update.second);
		return t;

		// CONTINUE

	}


private:
	map<string, TasksInfo> team;

};

//// Принимаем словарь по значению, чтобы иметь возможность
//// обращаться к отсутствующим ключам с помощью [] и получать 0,
//// не меняя при этом исходный словарь
//void PrintTasksInfo(TasksInfo tasks_info) {
//  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
//      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
//      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
//      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
//}
//
//int main() {
//  TeamTasks tasks;
//  tasks.AddNewTask("Ilia");
//  for (int i = 0; i < 3; ++i) {
//    tasks.AddNewTask("Ivan");
//  }
//  cout << "Ilia's tasks: ";
//  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
//  cout << "Ivan's tasks: ";
//  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//
//  TasksInfo updated_tasks, untouched_tasks;
//
//  tie(updated_tasks, untouched_tasks) =
//      tasks.PerformPersonTasks("Ivan", 2);
//  cout << "Updated Ivan's tasks: ";
//  PrintTasksInfo(updated_tasks);
//  cout << "Untouched Ivan's tasks: ";
//  PrintTasksInfo(untouched_tasks);
//
//  tie(updated_tasks, untouched_tasks) =
//      tasks.PerformPersonTasks("Ivan", 2);
//  cout << "Updated Ivan's tasks: ";
//  PrintTasksInfo(updated_tasks);
//  cout << "Untouched Ivan's tasks: ";
//  PrintTasksInfo(untouched_tasks);
//
//  return 0;
//}
