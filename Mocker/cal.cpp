#include <vector>
#include <stdexcept>
class Cal
{
public:
	int getSum(int a, int b)
	{
		return a + b;
	}
	int getValue()
	{
		return x;
	}
private:
	int x = 100;
};

class TddTest
{
public:
	std::vector<int> process(std::vector<int>& input)
	{
		std::vector<int> out;
		for (const auto& element:input)
		{
			if (element > 10 || element == 4)
				throw std::invalid_argument("이상한값");
			int element_out = element + 1;
			element_out = element_out % 10;
			if (element_out == 4)
				element_out = 5;
			out.push_back(element_out);
		}
		
		return out;
	}
	
};


class DatabaseAPI
{
public:
	std::string getDBName()
	{
		return name;
	}

private:
	std::string name = "MySon_DB";
};

class LogSystem
{
public:
	std::string getLogMessage(std::string content);
	{
		std::string msg = "";
		msg += std::string("[") + DB.getDBName() + std::string("] ");
		msg += content + string("\n");
		return msg;
	}

private:
	DatabaseAPI DB;
};