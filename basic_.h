#pragma once

#include <vector>
#include <string>

using namespace std;

bool split(string& line_, string& Pname, vector<int>& V,int & ARRIVAL_)
{
	if (line_[0] != 'P')
	{
		return false;
	}

	V.clear();
	Pname = "";

	string tmpString = "";
	bool NB = true;
	bool AB = true;

	for (long long i = 0; i < line_.length(); i++)
	{
		char C = line_[i];
		if (NB && C != ':')
		{
			tmpString += C;
			continue;
		}

		if (NB && C == ':')
		{
			Pname = tmpString;
			tmpString = "";
			NB = false;
			line_ += ',';
			continue;
		}

		if (C == ',')
		{
			if (AB)
			{
				ARRIVAL_ = stoi(tmpString);
				AB = false;
			}
			else
			{
				int tmpS2i = stoi(tmpString);
				V.push_back(tmpS2i);
			}
			
			tmpString = "";
		}
		else
		{
			tmpString += C;
		}
	}
	return true;
}

struct pi
{
	string Name = "";
	vector<int>BurstCI;
	int arrival_time = 0;

	int Wait = 0;
	bool flag_IO = false;
	int indexofBurst = 0;
	int terminate_ = -1378;

	int Main_arrival_time = 0;
	float ResponseRatio = 0;
	int whenDidYou = -1;
	int howLoung = 0;
	
	int responseTime = -1378;
	////////////////////////////

	bool isempty()
	{
		return ( (this->indexofBurst) >= (this->BurstCI.size() ) );
	}

	int cpuBurst()
	{
		if (this->indexofBurst%2==0)
		{
			flag_IO = false;			
			this->indexofBurst += 1;

			return this->BurstCI[this->indexofBurst-1];
		}
		else
		{
			this->Wait = this->BurstCI[this->indexofBurst];
			this->flag_IO = true;
			this->indexofBurst += 1;
			return -1;
		}
	}
	////////////////////////

	pi(string n, vector<int>b,int Arrival)
	{
		this->Name = n;
		this->BurstCI = b;
		this->arrival_time = Arrival;

		this->Wait = 0;
		this->flag_IO = false;
		this->indexofBurst = 0;

		this->whenDidYou = -1;
		this->howLoung = 0;
		this->responseTime = -1378;
	}

	pi() {};

	pi(string n, int Arrival)
	{
		this->Name = n;
		this->arrival_time = Arrival;

		this->whenDidYou = -1;
		this->howLoung = 0;
		this->responseTime = -1378;
	}

	void operator = (const pi& R)
	{
		this->Name = R.Name;
		this->BurstCI = R.BurstCI;
		this->arrival_time = R.arrival_time;

		this->Wait = R.Wait;
		this->flag_IO = R.flag_IO;
		this->indexofBurst = R.indexofBurst;
		this->terminate_ = R.terminate_;

		this->Main_arrival_time = R.Main_arrival_time;
		this->ResponseRatio = R.ResponseRatio;
		this->whenDidYou = R.whenDidYou;
		this->howLoung = R.howLoung;


		this->responseTime = R.responseTime;
	}

	////////////////////////////////////////////////
};

///////////////////////////////
bool funOpi(const pi& a, const pi& b)
{
	return a.arrival_time < b.arrival_time;
}
///////////////////////////////

//////////////////////////////
bool funOpiRR(const pi& a, const pi& b)
{
	return a.ResponseRatio < b.ResponseRatio;
}
///////////////////////////////
