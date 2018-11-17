process =[]
b_time = []
a_time = []
f_time =[]
w_time =[]
sum =int(0)
print "No. of processes"
n = input()
print "Arrival time is set at 0 for every process"
a_time = [int(0) for i in range(n)]
print "Burst time of the processes"
b_time = [input() for i in range(n)]
for i in range(n):
    for j in range(n-i-1):
        if b_time[j] > b_time[j+1]:
            p2=b_time[j]
            b_time[j]=b_time[j+1]
            b_time[j]=p2
            p3=process[j]
            process[j]=process[j+1]
            process[j]=p3
print "Process Name"+"\t"+"Arrival time"+"\t"+"Burst time"
for i in range(n):
    print process[i],"\t",a_time[i],"\t",b_time[i]
    f_time = [int(a_time[i] + b_time[i]) for i in range(n)]
    w_time=[int(f_time[i]-a_time[i]) for i in range(n)]
for i in range(n):
        sum = sum + int(w_time[i])
print "waiting time of Process"
for i in range(n):
    print process[i],"\t",w_time[i]
print "Average waiting time ",sum/n