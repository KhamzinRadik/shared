#include <fstream>
#include <iostream>
#include <string>
//салам
#include <nlohmann/Json.hpp>
#include <chrono>
#include <thread>
using json = nlohmann::json;
using namespace std;

class ConverterJSON {
public:
	nlohmann::json example;
	std::vector<std::string> soderjimoe;
	
	ConverterJSON()
	{
		std::string path_file = "C:\\Users\\Admin\\Source\\Repos\\KhamzinRadik\\shared\\config.json";
	
		ifstream file(path_file);


		if (!file.is_open()) 
		{ std::cout << " file not open " << endl;

		return;
		}
		else
		{
			std::cout<< "file open" << endl;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
		system("cls");
		
		example = nlohmann::json::parse(file);
		file.close();
		get_the_path();
		GetTextDocuments();
	}
	void get_the_path()
	{
		

	
		if (example.empty())
		{
			std::cout << "config file is missing. " << std::endl;
		}
		if (!example.contains("config"))
		{
			std::cout << " 	config file is empty " << std::endl;
		}
		else
		{

			std::cout << "name programm   : " << example["config"]["name"] << '\n';
			std::cout << "version programm: " << example["config"]["version"] << '\n';
			std::cout << "max_responses   :  " << example["config"]["max_responses"] << '\n';

		}
	
	}

	std::vector<std::string> GetTextDocuments()
		{
		std::string parth_file_txt = "C:\\Users\\Admin\\Source\\Repos\\KhamzinRadik\\shared\\resources\\";
		std::vector <std::string> txt_file;
		std::vector <std::string> put;
		for (auto& filename : example["files"])
			put.push_back(filename);

			for (int i = 0; i < put.size(); i++)
			{
			
			std::string str;

			ifstream file_txt(parth_file_txt + put[i]);

			if (file_txt.is_open())
			{
				std::getline(file_txt, str);
				txt_file.push_back(str);
			}
			else
			{
				std::cout << " file_txt not open " << endl;
			}



			}
			for (int i = 0; i < put.size(); i++)//вывод пути
			{
				std::cout <<"put "<<i<<" "<< put[i] << std::endl;

			}
			return txt_file;
		}
		
	
	

	/**
	* Метод считывает поле max_responses для определения предельного
	* количества ответов на один запрос
	* @return
	*/
	int GetResponsesLimit();






	/*
	* Метод получения запросов из файла requests.json
	* @return возвращает список запросов из файла requests.json
	*/
	std::vector<std::string> GetRequests();

	// Положить в файл answers.json результаты поисковых запросов

	void putAnswers(std::vector<std::vector<std::pair<int, float>>>answers);
	
};