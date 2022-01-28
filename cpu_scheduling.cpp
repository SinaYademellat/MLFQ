/*############################
#                            #
#       sina yademellat      #
#         9813027346         #
#           project          #
#            Os				 #
#                            #
#      ---------------       #
#                            #
#           MLQ              #
#       Q1 --> RR            #
#       Q2 --> HRRN          #
#                            #
#############################*/

#include "File2vector.h"

using namespace std;

int main()
{
	mypc A;
	A.readFile("test.txt");
	//A.test();
	//cout << "\n!!!!!!!!!!!!!!!!\n";
	A.runCpuSchaduling();
	//A.test();
	A.GanttChart_consol();
	//cout << "\n!!!!!!!!!!!!!!!!\n";
	//A.test();
	A.GanttChart_File("o.txt");
}


