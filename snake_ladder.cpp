#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int main()
{
    srand(time(0));
    int snk, lad, per;
    int ip, fp;
    cin >> snk;
    unordered_map<int, int> snakes;
    for(int i=0;i<snk;i++)
    {
        cin >> ip >> fp;
        snakes[ip] = fp;
    }
    cin >> lad;
    unordered_map<int, int> ladders;
    for(int i=0;i<lad;i++)
    {
        int ip, fp;
        cin >> ip >> fp;
        ladders[ip] = fp;
    }
    cin >> per;
    vector<pair<string, int>> person;
    for(int i=0;i<per;i++)
    {
        string name;
        cin >> name;
        person.push_back(make_pair(name,0));
    }
    int p = per, c = 0;
    while(1)
    {
        int x = (rand()%6)+1;
        int initial;
        if(snakes.find(person[c].second+x)!=snakes.end())
        {
            initial = person[c].second;
            person[c].second = snakes[person[c].second+x];
        }
        else if(ladders.find(person[c].second+x)!=ladders.end())
        {
            initial = person[c].second;
            person[c].second = ladders[person[c].second+x];
            if(person[c].second==100)
            {
                cout << person[c].first << " wins the game" << endl;
                break;
            }
        }
        else
        {
            if(person[c].second+x<=100)
            {
                initial = person[c].second;
                person[c].second+=person[c].second+x;
            }
            if(person[c].second==100)
            {
                cout << person[c].first << " wins the game" << endl;
                break;
            }
        }
        cout << person[c].first << " rolled a " << x << " and moved from " << initial << " to " << person[c].second << endl;
        c = (c+1)%per;
    }
    return 0;
}