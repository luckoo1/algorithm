#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    vector<pair<int, int>> step;

    int time = 0;
    int bridge_weight = 0;                  //다리위 트럭 무게
    int finish_truck = 0;                   //다건넌 트럭수
    int t_num_truck = truck_weights.size(); //총 트럭수

    while (finish_truck != t_num_truck) //트럭이 다 건넘
    {
        // cout << "time : " << time << endl;
        // for (int i = 0; i < step.size(); i++)
        // {
        //     cout << step[i].first << "," << step[i].second << endl;
        // }

        if (!step.empty())
        {
            for (int i = 0; i < step.size(); i++)
            {
                step[i].second += 1;
            }
        }

        for (int i = 0; i < step.size(); i++)
        {
            if (step[i].second > bridge_length)
            {
                step.erase(step.begin());
                finish_truck += 1;
            }
        };

        int temp_sum = 0;
        for (int i = 0; i < step.size(); i++)
        {
            temp_sum = temp_sum + step[i].first;
        }

        bridge_weight = temp_sum;

        if (step.size() < bridge_length && !truck_weights.empty())
        {
            int first_truck = truck_weights.front();

            if (bridge_weight + first_truck <= weight)
            {
                truck_weights.erase(truck_weights.begin());
                bridge_weight = bridge_weight + first_truck;
                step.push_back(make_pair(first_truck, 1));
            }
        }
        time += 1;
    }

    return time;
}

int main()
{
    int a1 = 2;
    int b1 = 10;
    vector<int> c1 = {7, 4, 5, 6};

    int a2 = 100;
    int b2 = 100;
    vector<int> c2 = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};

    int a3 = 100;
    int b3 = 100;
    vector<int> c3 = {10};

    int ans = solution(a1, b1, c1);
    cout << ans;
}