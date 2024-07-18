#include <fstream>
#include <iostream>
#include <string>
#include <nlohmann/Json.hpp>
#include <chrono>
#include <thread>
#include < stdio.h >
using json = nlohmann::json;
using namespace std;

class ConverterJSON {
public:
	nlohmann::json example;
	nlohmann::json Jrequests;

	std::vector<std::string> soderjimoe;
	std::vector<std::string> Grequests;
	int MAXrepost;

	ConverterJSON()
	{
		GetTextDocuments();
		
		GetResponsesLimit();

		GetRequests();

		for (const auto& str : soderjimoe) {
			std::cout << str << std::endl;
		}
		cout << "MAXrepost =" << MAXrepost <<std:: endl;
		for (const auto& str : Grequests) {
			std::cout << str << std::endl;
		}
		
	}

	std::vector<std::string> GetTextDocuments()
	{
		
		std::string path_file = "C:\\Users\\Admin\\Source\\Repos\\KhamzinRadik\\shared\\config.json";
		//std::string path_file = "D:\\gitClone\\KhamzinRadik\\shared\\config.json";
		

		ifstream file(path_file);


		if (!file.is_open())
		{
			std::cout << " file not open " << endl;
			return soderjimoe;
		}
		else
		{
			std::cout << "file open" << endl;
		}
		//std::this_thread::sleep_for(std::chrono::seconds(1));
		//system("cls");

		example = nlohmann::json::parse(file);
		file.close();

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
			
			
			
			soderjimoe.push_back("name: " + example["config"]["name"].get<std::string>());
			soderjimoe.push_back("version: " + example["config"]["version"].get<std::string>());
			soderjimoe.push_back("max_responses: " + std::to_string(example["config"]["max_responses"].get<int>()));
			
		}

		//////
		std::string parth_file_txt = "C:\\Users\\Admin\\Source\\Repos\\KhamzinRadik\\shared\\resources\\";
		//std::string parth_file_txt = "D:\\gitClone\\KhamzinRadik\\shared\\resources\\";
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
		/*for (int i = 0; i < put.size(); i++)//����� ����
		{
			std::cout << "put " << i << " " << put[i] << std::endl;

		}*/
		return soderjimoe;

	}
		
	
	

	/**
	* ����� ��������� ���� max_responses ��� ����������� �����������
	* ���������� ������� �� ���� ������
	* @return
	*/
	int GetResponsesLimit()
	{

		MAXrepost = (example["config"]["max_responses"].get<int>());
		std::string str = soderjimoe[soderjimoe.size() - 1];
		
		return MAXrepost;
	}






	/*
	* ����� ��������� �������� �� ����� requests.json
	* @return ���������� ������ �������� �� ����� requests.json
	*/
	std::vector<std::string> GetRequests()
	{
		
		
		std::string path_file = "C:\\Users\\Admin\\source\\repos\\shared\\requests.json";//�� ������ 
		//std::string path_file = "D:\\gitClone\\KhamzinRadik\\shared\\ConverterJSON.h";//����
		ifstream JRfile(path_file);

		if (!JRfile.is_open())
		{
			std::cout << " JR file not open " << endl;
			return Grequests;
		}
		else
		{
			
			std::cout << "JR file open" << endl;
			Jrequests = nlohmann::json::parse(JRfile);
			for (auto& filename : Jrequests["requests"])
				Grequests.push_back(filename);
		}

	
		

		JRfile.close();

		

		
		

		
		
		return Grequests;
	}

	// �������� � ���� answers.json ���������� ��������� ��������

	void putAnswers(std::vector<std::vector<std::pair<int, float>>>answers);
	
};