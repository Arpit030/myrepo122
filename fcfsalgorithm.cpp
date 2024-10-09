#include <iostream>
#include <vector>
using namespace std;
#define MAX 100

struct Process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void print_table(vector<Process>& p);
void print_gantt_chart(vector<Process>& p);

int main() {

    int n, sum_waiting_time = 0, sum_turnaround_time = 0;

    cout << "Enter total number of processes: ";
    cin >> n;
    vector<Process> p(n);
    cout << "Enter burst time for each process:\n";

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "P[" << i + 1 << "] : ";
        cin >> p[i].burst_time;
        p[i].waiting_time = p[i].turnaround_time = 0;
    }
    p[0].turnaround_time = p[0].burst_time;

    for (int i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
    for (int i = 0; i < n; i++) {
        sum_waiting_time += p[i].waiting_time;
        sum_turnaround_time += p[i].turnaround_time;
    }
    cout << endl;
    print_table(p);
    cout << std::endl;
    cout << "Total Waiting Time      : " << sum_waiting_time << endl;
    cout << "Average Waiting Time    : " << static_cast<double>(sum_waiting_time) / n << endl;
    cout << "Total Turnaround Time   : " << sum_turnaround_time << endl;
    cout << "Average Turnaround Time : " << static_cast<double>(sum_turnaround_time) / n << endl;

    cout << endl;
    cout << "          GANTT CHART WILL BE AS FOLLOWS          " << endl;

    print_gantt_chart(p);

    return 0;
}

void print_table(vector<Process>& p) {
    cout << "+-----+------------+--------------+-----------------+" << endl;
    cout << "| PID | Burst Time | Waiting Time | Turnaround Time |" << endl;
    cout << "+-----+------------+--------------+-----------------+" << endl;

    for (const Process& process : p) {
        cout << "| " << process.pid << "  |     " << process.burst_time << "     |      " << process.waiting_time<< "      |        " << process.turnaround_time << "       |" << endl;
        cout << "+-----+------------+--------------+-----------------+" << endl;
    }
}

void print_gantt_chart(vector<Process>& p) {
    cout << " ";
    for (const Process& process : p) {
        for (int j = 0; j < process.burst_time; j++) {
            cout << "--";
        }
        cout << " ";
    }
    cout << "\n|";

    for (const Process& process : p) {
        for (int j = 0; j < process.burst_time - 1; j++) {
            cout << " ";
        }
        cout << "P" << process.pid;
        for (int j = 0; j < process.burst_time - 1; j++) {
            cout << " ";
        }
        cout << "|";
    }
    cout << "\n ";
    for (const Process& process : p) {
        for (int j = 0; j < process.burst_time; j++) {
             cout << "--";
        }
        cout << " ";
    }
    cout << "\n";

    cout << "0";
    for (const Process& process : p) {
        for (int j = 0; j < process.burst_time; j++) {
            cout << "  ";
        }
        if (process.turnaround_time > 9) {
            cout << "\b";
        }
        cout << process.turnaround_time;
    }
    cout << "\n";
}
