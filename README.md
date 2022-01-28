# MLFQ
multilevel feedback queue scheduling
##############################
#                            #
#       sina yademellat      #
#                            #
#            OS				       #
#                            #
#      ---------------       #
#                            #
#            MLQ             #
#        Q1 --> RR           #
#        Q2 --> HRRN         #
#                            #
##############################

input(.txt):
        >> Dispatch Latency
        >> Quantum
        >> Pi:Arrivaltime,Bursttime(CPU,IO,...,CPU)
output(.txt):
                 ------------------------------------------------------------------------------------------------------------------
                |Pi		|Pj		|P...       |pn		
                ------------------------------------------------------------------------------------------------------------------
  (terminate)   x		  y		  ...         n       		
                CPU Utilization : 
                Average Wating Time : 
                Average Turnaround Time : 
                Average Response Time : 
