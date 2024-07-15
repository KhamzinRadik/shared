#include <fstream>
#include <iostream>
#include <string>
  // cfkfv
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
<<<<<<< HEAD
		ifstream file("C:\\Users\\Admin\\source\\repos\\KhamzinRadik\\shared\\config.json"); 
		//ifstream file{"config.json"};
		
=======
		std::string path_file = "D:\\gitClone\\shared\\config.json";
	
		ifstream file(path_file);


>>>>>>> ec83c18c5754ceb9c138dec048de77b2fdd3de24
		if (!file.is_open()) 
		{ std::cout << " file not open " << endl;

		return;
		}
		else
		{
			std::cout<< "file open" << endl;
		}
		std::this_thread::sleep_for(std::chrono::seconds(2));
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
		std::string parth_file_txt = "D:\\gitClone\\shared\\resources\\";
		std::vector <std::string> txt_file;
		std::vector <std::string> put;
		for (auto& filename : example["files"])
			put.push_back(filename);

			for (int i = 0; i < put.size(); i++)
			{
			
			std::string str;

<<<<<<< HEAD
			ifstream file_txt("C:\\Users\\Admin\\Source\\Repos\\KhamzinRadik\\shared\\resources\\" + put[i]);
		
=======
			ifstream file_txt(parth_file_txt + put[i]);

>>>>>>> ec83c18c5754ceb9c138dec048de77b2fdd3de24
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