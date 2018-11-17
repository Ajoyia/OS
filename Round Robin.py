b_time = []
process_name = []
order = []
wait = []
remaining_bt = []
turn_around = []
print "No. of processes"
n = input()
wait = [int(0) for i in range(n)]
print "Enter the name of the processes"
process_name = [str(raw_input()) for i in range(n)]
print "Enter  Quantum time for the processes "
quantum = input()
print "Priority Of Process"
order = [input() for i in range(n)]
print "Arrival time for the processes is set 0"
a_time = [int(0) for i in range(n)]
print " Burst time for the processes"
b_time = [input() for i in range(n)]
for i in range(n):
    for j in range(n - i - 1):
        if order[i] > order[i + 1]:
            p = order[i]
            order[i] = order[i + 1]
            order[i + 1] = order[i]
            p2 = process_name[i]
            process_name[i] = process_name[i + 1]
            process_name[i + 1] = p2
            p3 = b_time[i]
            b_time[i] = b_time[i + 1]
            b_time[i + 1] = 3
print "Process Name" + "\t" + "Process Order" + "\t" + "Burst Time" + "\t" + "Arrival Time"
for i in range(n):
    print process_name[i] + "\t", order[1], "\t", b_time[i], "\t", a_time[i]
remaining_bt = [int(b_time[i]) for i in range(n)]
for i in range(n):
    print remaining_bt[i]
t = int(0)
done = int(0)
while done == int(1):
    done = int(1) 
for i in range(n):
    if remaining_bt[i] > 0:
        done = int(0)
        if remaining_bt[i]>quantum:
            t = t + quantum
            remaining_bt[i] = remaining_bt[i] - quantum
        else :
            t = t + remaining_bt[i]
            wait[i] = t - b_time[i]
            if done == 1:
                break

print "Waiting time for the processes"
sum = int(0)
for i in range(n):
    print wait[i]
    sum = sum + wait[i]
print "Average waiting time"
print sum/n
turn_around=[int(b_time[i]+wait[i]) for i in range(n)]
print"Turn round time of the processes"
turn =int(0)
for i in range(n):
    print turn_around[i]
    turn = turn + turn_around[i]
print "Average turn around time"
print turn/n