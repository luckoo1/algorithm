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
        //다리위에 트럭 한칸씩 전진
        if (!step.empty()) //다리가 비어있지 않으면
        {
            for (int i = 0; i < step.size(); i++)
            {
                step[i].second += 1; //한칸씩 전진
            }
        }

        //전진하고 난뒤에 다 건넌거 있는가 확인후 다리위에서 삭제
        if (!step.empty())
        {
            if (step[0].second > bridge_length) //만약 다 건넜다면
            {
                step.erase(step.begin()); //다리위에서 삭제하고
                finish_truck += 1;        //다건넌 트럭수 1더하기
            }
        };
        //다리위 무게 측정
        int temp_sum = 0;
        for (int i = 0; i < step.size(); i++)
        {
            temp_sum = temp_sum + step[i].first;
        }

        bridge_weight = temp_sum;

        //다리에 자리가 있고, 들어가야할 트럭이 있나 확인
        if (step.size() < bridge_length && !truck_weights.empty())
        {
            int first_truck = truck_weights.front();
            //들어가야할 트럭이 들어가면 다리위 무게가 초과되지 않는지 확인
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