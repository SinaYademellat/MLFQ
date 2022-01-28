#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "basic_.h"
#include <queue>
#include <algorithm>

using namespace std;

class myQueue1
{
private:
	friend class mypc;
	vector<pi> Queue1Array;
	int index_;
public:
	void push(pi a)
	{
		Queue1Array.push_back(a);
		this->index_ += 1;
		this->heapify_push();
		
	}
	void heapify_push()
	{
		if (this->index_ == 1)
		{
			return ;
		}
		else
		{

			int tmpInexforheapify = this->index_;
			while (tmpInexforheapify != 1 && this->Queue1Array[tmpInexforheapify].arrival_time < this->Queue1Array[tmpInexforheapify /2].arrival_time )
			{
				swap(this->Queue1Array[tmpInexforheapify], this->Queue1Array[tmpInexforheapify / 2]);
				tmpInexforheapify = tmpInexforheapify / 2;
			}
		}
	}

	pi pop()
	{
		pi tmppiPop = this->Queue1Array[1];
		
		swap(this->Queue1Array[1], this->Queue1Array[this->index_]);
		this->index_ -= 1;

		this->heapify_pop();

		return tmppiPop;
	}
	void heapify_pop()
	{
		//this->index_ -= 1;
		this->Queue1Array.pop_back();
		int tmpindex_hp = 1;
		while (true)//tmpindex_hp< this->index_ && this->Queue1Array[tmpindex_hp].arrival_time > this->Queue1Array[tmpindex_hp*2].arrival_time
		{
			if (tmpindex_hp >= this->index_)
			{
				return;
			}
			else if(((tmpindex_hp * 2) + 0) <= this->index_ && this->Queue1Array[tmpindex_hp].arrival_time > this->Queue1Array[tmpindex_hp * 2].arrival_time)
			{
				if (!(((tmpindex_hp * 2) + 1) <= this->index_))
				{
					swap(this->Queue1Array[tmpindex_hp], this->Queue1Array[tmpindex_hp * 2]);
					tmpindex_hp = tmpindex_hp * 2;
					continue;
				}

				if (this->Queue1Array[tmpindex_hp * 2].arrival_time <= this->Queue1Array[(tmpindex_hp * 2)+1].arrival_time )
				{
					swap(this->Queue1Array[tmpindex_hp], this->Queue1Array[tmpindex_hp * 2]);
					tmpindex_hp = tmpindex_hp * 2;
				}
				else
				{
					swap(this->Queue1Array[tmpindex_hp], this->Queue1Array[(tmpindex_hp * 2) + 1]);
					tmpindex_hp = tmpindex_hp * 2;
					tmpindex_hp += 1;
				}
			
			}
			else if(((tmpindex_hp * 2) + 1)<= this->index_ && this->Queue1Array[tmpindex_hp].arrival_time > this->Queue1Array[(tmpindex_hp * 2)+1].arrival_time)
			{
				
				if (this->Queue1Array[(tmpindex_hp * 2) + 1].arrival_time <= this->Queue1Array[tmpindex_hp * 2].arrival_time )
				{
					swap(this->Queue1Array[tmpindex_hp], this->Queue1Array[(tmpindex_hp * 2) + 1]);
					tmpindex_hp = tmpindex_hp * 2;
					tmpindex_hp += 1;
				}
				else
				{
					swap(this->Queue1Array[tmpindex_hp], this->Queue1Array[tmpindex_hp * 2]);
					tmpindex_hp = tmpindex_hp * 2;
				}
			}
			else
			{
				return;
			}
		}
	}

	pi show()
	{
		return this->Queue1Array[1];
	}

	void test()
	{
		int sss = this->Queue1Array.size();
		int sTest = min(this->index_, sss );

		for (int i = 1; i < sss; i++)
		{
			cout << this->Queue1Array[i].Name << "  " << this->Queue1Array[i].arrival_time << endl;
		}
	}

	int size()
	{
		return this->Queue1Array.size();
	}

	myQueue1()
	{
	
		this->Queue1Array.clear();
		this->index_ = 0;
		pi tmp_Sina("SINAQueue", -1400); Queue1Array.push_back(tmp_Sina);

	}
};

class mypc
{
private:
	
	vector<pi>allpi;
	int L1, L2;
	int quantum = 0;
	//void multiLevelFeedbackQueueRR_HRRN();

	
	myQueue1 q1;
	vector<pi>q2;
	queue<pi>Q2;

	void setArrival_time();
	void sortAllpibyArrival_time();	
	//void setQ1();
	void setq1();

		/// <summary>
		/// test
		/// </summary>

	void showQi(int qnumber)
	{
		cout << "\n~~~~~~~<< showQi >>~~~~~~~~\n";
		if (qnumber==1)
		{
			cout << "q1: ";
			this->q1.test();
		}
		else if(qnumber==2)
		{
			cout << "Q2: ";	int s = Q2.size();// << Q2.size() << endl;
			for (int i = 1; i <= s; i++) { cout << Q2.front().Name << " , "; Q2.pop(); }

			cout << endl;
			cout << "q2: ";	//int s = 
			for (int i = 0 ; i < q2.size(); i++) { cout << q2[i].Name << " , ";}

		}
		else { cout << "ERROR--> showQi input"; }
		cout << "\n~~~~~~~[ showQi ]~~~~~~~~\n";

		//cour << "!!!!!!!!!!!!!!!!!!!!!!!\n";

	}

	bool workless();// { return true; }


	void set_Pi_In_allpi_For_Calculation(const pi& c);

	//void setResponseRatioPi(int time_);
	void runq2(int& Now_);

	//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
	float total_Time = 0;
	int numberOfPi = 0;
	//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO

	int dispatchlatency = 0;
	int numberdispatchlatency = 0;
	int NotAcustomer = 0;

public:
	void readFile(string p);
	void runCpuSchaduling();
	void test()
	{
		cout << "\n~~~~~~~~~~~~~~~\n";
		cout << "L1 : " << this->L1<<endl;
		cout << "L2 : " << this->L2<<endl;
		cout << "quantum : " << this->quantum <<endl;
		for (int i = 0; i < this->allpi.size(); i++)
		{
			//cout << "NAME IS --> " << this->allpi[i].Name << " T is -->  " << this->allpi[i].terminate_ << " || input>>  ";
			cout<<"NAME IS --> "  << this->allpi[i].Name
				<<" T is -->  " << this->allpi[i].terminate_ 
				<<" ^ MainA: "		<< this->allpi[i].Main_arrival_time 
				<<" ^ A-->  " << this->allpi[i].arrival_time  
				<<" ^ HowLougn--> "	<< this->allpi[i].howLoung			
				<<" ^ responseTime--> "	<< this->allpi[i].responseTime			
				
				<< " || input>>  ";

			for (int j= 0; j < this->allpi[i].BurstCI.size(); j++)
			{
				cout << this->allpi[i].BurstCI[j] << " , ";
			}
			cout << endl;
		}	
		cout << "\n~~~~~~~~~~~~~~~\n";


		this->showQi(1);
		this->showQi(2);
		cout << "\n~~~~~~~~~~~~~~~\n";
		
		//cout << "L1 : " << this->L1 << endl;
		//cout << "L2 : " << this->L2 << endl;
		//cout << "quantum : " << this->quantum << endl;
		//for (int i = 0; i < this->allpi.size(); i++)
		//{
		//	cout << "NAME IS --> " << this->allpi[i].Name << " : ";
		//	for (int j = 0; j < this->allpi[i].BurstCI.size(); j++)
		//	{
		//		cout << this->allpi[i].BurstCI[j] << " , ";
		//	}
		//	cout << "\tA: " << this->allpi[i].arrival_time << endl;
		//}
		//cout << "\n~~~~~~~~~~~~~~~\n";

	}


	/////////////////////
	void GanttChart_consol();

	void GanttChart_File(string p);

	/////////////////////////////
	//void showallpi();

};

///////////////////////////////////////////////////////

void mypc::setArrival_time()
{
	int tmparrival_time = this->allpi[0].arrival_time;
	for (int i = 0; i < this->allpi.size(); i++)
	{
		this->allpi[i].arrival_time -= tmparrival_time;

		this->allpi[i].Main_arrival_time = this->allpi[i].arrival_time;
	}

	this->numberOfPi = this->allpi.size();
}
void mypc::sortAllpibyArrival_time()
{
	sort(this->allpi.begin(),this->allpi.end(), funOpi);
	this->setArrival_time();
}
void mypc::setq1()
{
	this->sortAllpibyArrival_time();
	for (int i = 0; i < this->allpi.size(); i++)
	{
		this->q1.push(this->allpi[i]);
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////

void mypc::readFile(string p)
{

	ifstream F1(p);
	if (!F1.is_open())
	{
		perror("?? <-- input file --> ??");
		exit(-1);
	}

	string myText = "";
	int L = 0;
	while (!(F1.eof()))
	{
		getline(F1, myText);

		string tmpPname = ""; vector<int>tmpV; int tmpARRIVAL_;
		if (split(myText, tmpPname, tmpV, tmpARRIVAL_))
		{
			pi tmpPI(tmpPname, tmpV, tmpARRIVAL_);
			this->allpi.push_back(tmpPI);
		}
		else
		{

			//cout << "line(?): -> " << myText << endl;

			if (L==0)
			{
				// L1 ==> DL :(
				this->L1 = stoi(myText);
				//this->quantum = this->L1;
				this->dispatchlatency = this->L1;
			}
			else if(L==1)
			{
				// L2 ==> q :)

				//cout << myText << endl;
				this->L2 = stoi(myText);

				this->quantum = this->L2;

			}
			else
			{
				cout << "Error pro....should...p....\n";
				exit(-2);
			}
			
			L++;
		}
	}
	F1.close();
}

/////////////////////////////////////  //////////////////////////

void mypc::runCpuSchaduling()
{
	int TimeforGant = 0;
	this->setq1();
	pi currentprocess;
	//return;

	bool FIRSTDLNONONONO = false;

	while (true)
	{
		while (this->q1.size() > 1)
		{
			currentprocess = this->q1.show();
			if (!currentprocess.isempty())
			{
				cout << currentprocess.Name << " , " << currentprocess.arrival_time <<" TIME IS : "<< TimeforGant << endl;

				int cpuBurst = currentprocess.cpuBurst();
				if (cpuBurst == -1) //I/O BURST
				{
					//ResponseTime
					if (currentprocess.responseTime == -1378)
					{
						//cout << "\nYYYYYYYYYYY\n";
						currentprocess.responseTime = currentprocess.whenDidYou - currentprocess.Main_arrival_time;
					}

					currentprocess.arrival_time = currentprocess.arrival_time + currentprocess.Wait;
					//currentprocess.arrival_time = currentprocess.Wait;
					this->q1.pop();
					this->q1.push(currentprocess);

					if (this->workless())
					{
						//Be kariii
						//this->NotAcustomer += currentprocess.Wait;
						if (this->q2.size()==0)
						{
							cout << "\nBBBBBBBBBBBBB\n";
							TimeforGant += currentprocess.Wait;
						}
						else
						{
							continue;
						}
						
					}

					continue;
				}

				else if (currentprocess.arrival_time > TimeforGant)
				{
					//Be kariii 
					cout << "\nworkless==> cpu\n";

					int TMPNOCUS = (currentprocess.arrival_time - TimeforGant);
					this->NotAcustomer += TMPNOCUS;
					
					
					
					//How Lougn
					if (currentprocess.whenDidYou == -1 )
					{
						currentprocess.whenDidYou = currentprocess.Main_arrival_time;
					}
					currentprocess.howLoung += (TimeforGant - currentprocess.whenDidYou);

					TimeforGant += TMPNOCUS;

					//How Lougn2
					currentprocess.whenDidYou = TimeforGant;
				}

				int t = cpuBurst - this->quantum;

				this->q1.pop();
				if (t > 0)
				{
					// tanbih :)

					//How Lougn
					if (currentprocess.whenDidYou == -1)
					{
						currentprocess.whenDidYou = currentprocess.Main_arrival_time;
					}
					currentprocess.howLoung += (TimeforGant - currentprocess.whenDidYou);

					//DL
					if (FIRSTDLNONONONO)
					{
						TimeforGant += this->dispatchlatency;
						this->numberdispatchlatency += 1;

					}
					FIRSTDLNONONONO = true;

					TimeforGant += this->quantum;

					//How Lougn2
					currentprocess.whenDidYou = TimeforGant;

					currentprocess.BurstCI[currentprocess.indexofBurst - 1] -= this->quantum;
					this->Q2.push(currentprocess);
					this->q2.push_back(currentprocess);
				}
				else // <= 0
				{
					//How Lougn
					if (currentprocess.whenDidYou == -1)
					{
						currentprocess.whenDidYou = currentprocess.Main_arrival_time;
					}
					currentprocess.howLoung += (TimeforGant - currentprocess.whenDidYou);

					//DL
					if (FIRSTDLNONONONO)
					{
						TimeforGant += this->dispatchlatency;
						this->numberdispatchlatency += 1;
					}
					FIRSTDLNONONONO = true;
					
					TimeforGant += min(this->quantum, cpuBurst);


					//How Lougn2
					currentprocess.whenDidYou = TimeforGant;

					//this->Q1.pop();
					currentprocess.arrival_time = TimeforGant;
					this->q1.push(currentprocess);
				}

			}
			else
			{
				this->q1.pop();
				cout << "T-->"; cout << currentprocess.Name << " , " << currentprocess.arrival_time << endl;
				currentprocess.terminate_ = currentprocess.arrival_time;
				this->set_Pi_In_allpi_For_Calculation(currentprocess);
			}
			//this->Q1.pop();
		}

		if (this->q2.size() == 0)
		{
			cout << "\ntime(396) is --> " << TimeforGant << endl;
			this->total_Time = TimeforGant;
			return;
		}
		else
		{
			

			if (FIRSTDLNONONONO)
			{
				TimeforGant += this->dispatchlatency;
				this->numberdispatchlatency += 1;
			}
			FIRSTDLNONONONO = true;

			this->runq2(TimeforGant);

			cout << "OK";
		}
	}

	cout << "time is --> " << TimeforGant << endl;
}

/////////////////////////////////////  //////////////////////////

bool mypc::workless()
{
	if (this->q1.size()==2)
	{
		return true;
	}
	for (int idexWorkless = 2; idexWorkless < this->q1.size(); idexWorkless++)
	{
		if (!this->q1.Queue1Array[idexWorkless].flag_IO)
		{
			return false;
		}
	}
	return true;
}

void mypc::set_Pi_In_allpi_For_Calculation(const pi &c)
{
	for (int i = 0; i < this->allpi.size(); i++)
	{
		if (this->allpi[i].Name == c.Name)
		{
			this->allpi[i] = c;


			if (this->allpi[i].responseTime == -1378 && this->allpi[i].BurstCI.size())
			{
				this->allpi[i].responseTime = this->allpi[i].howLoung;
			}

			return;
		}
	}

	cout << "Erroor 123";
	exit(-1);
}

void mypc::runq2(int& Now_)
{

	//	R = w / nex
	//	w = now - timeA

	cout << "\n####runq2###\n";
	//set RR
	for (int i = 0; i < this->q2.size(); i++)
	{
		this->q2[i].indexofBurst -= 1;// NA NA NA NA
		int cpuBurst_ = this->q2[i].cpuBurst();

		if (cpuBurst_ == -1)
		{
			cout << "\nNAAAAAAAAA457\n";
			continue;
		}
		else if(cpuBurst_ ==0)
		{
			cout << "\ncpuBurst=0==> R=w/0 :/ \n";
			exit(-463);
		}
		else
		{
			/*int CCCC = this->q2[i].Main_arrival_time;
			int WW = Now_- CCCC;
			this->q2[i].ResponseRatio = WW / cpuBurst_;*/

			int CCCC = Now_ - this->q2[i].whenDidYou;
			int WW = this->q2[i].howLoung+CCCC;
			WW -= this->dispatchlatency;
			WW += 0.0;
			this->q2[i].howLoung = WW;
			this->q2[i].ResponseRatio =(float) WW / cpuBurst_;
		}
	}

	cout << "\n---#-----(SORT q2)-------#-----\n";
	sort(this->q2.begin(), this->q2.end(), funOpiRR);
	//cout << endl;
	cout << "q2: ";
	for (int i = 0; i < q2.size(); i++) { cout << q2[i].Name << " , "; }
	cout << "\n---#------[SORT q2]----#-----\n";

	////How Lougn
	//if (this->q2[this->q2.size() - 1].whenDidYou == -1)
	//{
	//	this->q2[this->q2.size() - 1].whenDidYou = this->q2[this->q2.size() - 1].Main_arrival_time;
	//}
	//this->q2[this->q2.size() - 1].howLoung += (Now_ - this->dispatchlatency - this->q2[this->q2.size() - 1].whenDidYou );
	////----


	//How Lougn2
	for (int i = 0; i < this->q2.size(); i++)
	{
		this->q2[i].whenDidYou = Now_ - this->dispatchlatency;
	}

	Now_ += this->q2[this->q2.size() - 1].BurstCI[this->q2[this->q2.size() - 1].indexofBurst - 1];
	
	//ResponseTime
	if (q2[this->q2.size() - 1].responseTime == -1378)
	{
		this->q2[this->q2.size() - 1].responseTime = Now_ - this->q2[this->q2.size() - 1].Main_arrival_time;
	}
	//----





	
	

	this->q2[this->q2.size() - 1].terminate_ = Now_;
	this->set_Pi_In_allpi_For_Calculation(this->q2[this->q2.size() - 1]);
	q2.pop_back();


	return;
}

void mypc::GanttChart_consol()
{
	cout << "\n^^^^^^^^^^^^ CONSOL ^^^^^^^^^^^^^^^^^^^^^^\n";
	//cout << "-----------\n";
	//cout << "pi : \n";
	//cout << "-----------\n";

	
	cout<<"total_Time: "<< this->total_Time<<" | numberOfPi: "<< this->numberOfPi<<endl;
	cout<<"numberdispatchlatency: "<< this->numberdispatchlatency<<" | NotAcustomer: "<< this->NotAcustomer<<endl;

	cout << endl;

	this->total_Time += 0.0;
	int timeWasted = this->NotAcustomer + (this->numberdispatchlatency * this->dispatchlatency);
	float CPUUtilization =( (this->total_Time- timeWasted) / this->total_Time ) * 100;
	cout << "CPU Utilization : " << CPUUtilization << "%\n";// << endl;

	long float sum_ = 0.0;
	for (int i = 0; i < this->allpi.size(); i++)
	{
		sum_ += this->allpi[i].howLoung;
	}
	cout << "Average Wating Time : " << (float)(sum_ / this->numberOfPi) << endl;

	//long float sum_ = 0.0;
	sum_ = 0.0;
	for (int i = 0; i < this->allpi.size(); i++)
	{
		int TMP_Turnaround= (this->allpi[i].terminate_ - this->allpi[i].Main_arrival_time);
		sum_ += TMP_Turnaround;
	}
	cout << "Average Turnaround Time : "<<(float) (sum_/ this->numberOfPi) << endl;
	
	
	sum_ = 0.0;
	for (int i = 0; i < this->allpi.size(); i++)
	{
		sum_ += this->allpi[i].responseTime;
	}
	cout << "Average Response Time : " << (float)(sum_ / this->numberOfPi) << endl;

	cout << "\n^^^^^^^^^^^^[ CONSOL ]^^^^^^^^^^^^^^^^^^^^^^\n";
}

void mypc::GanttChart_File(string p)
{
	ofstream F1(p);
	string UD = "------------------------------------------------------------------------------------------------------------------\n";
	
	F1 << UD;
	for (int i = 0; i < this->allpi.size(); i++)
	{
		F1 << "|" << this->allpi[i].Name << "\t\t";
	}
	
	F1 <<'\n'<< UD;
	
	for (int i = 0; i < this->allpi.size(); i++)
	{
		F1  << this->allpi[i].Main_arrival_time << "\t\t";
	}
	F1 << endl;

	this->total_Time += 0.0;
	int timeWasted = this->NotAcustomer + (this->numberdispatchlatency * this->dispatchlatency);
	float CPUUtilization = ((this->total_Time - timeWasted) / this->total_Time) * 100;
	F1 << "CPU Utilization : " << CPUUtilization << "%\n";// << endl;

	long float sum_ = 0.0;
	for (int i = 0; i < this->allpi.size(); i++)
	{
		sum_ += this->allpi[i].howLoung;
	}
	F1 << "Average Wating Time : " << (float)(sum_ / this->numberOfPi) << endl;

	//long float sum_ = 0.0;
	sum_ = 0.0;
	for (int i = 0; i < this->allpi.size(); i++)
	{
		int TMP_Turnaround = (this->allpi[i].terminate_ - this->allpi[i].Main_arrival_time);
		sum_ += TMP_Turnaround;
	}
	F1 << "Average Turnaround Time : " << (float)(sum_ / this->numberOfPi) << endl;


	sum_ = 0.0;
	for (int i = 0; i < this->allpi.size(); i++)
	{
		sum_ += this->allpi[i].responseTime;
	}
	F1 << "Average Response Time : " << (float)(sum_ / this->numberOfPi) << endl;

	F1.close();
}
