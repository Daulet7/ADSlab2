#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <map>

using namespace std;

void func(int n){
    for(int i = 0; i<n; i++){ 
        deque<string> seq;
        vector<string> answer;
        map<string, int> count;

        int t;
        cin >> t;

        for(int i =0; i<t; i++){
            string a;
            cin >> a;
            seq.push_back(a);
            count[a]++;

            while(!seq.empty() && count[seq.front()]>1){
                seq.pop_front();
            }

            if(seq.empty()){
                answer.push_back("-1");
            }
            else{
                answer.push_back(seq.front());
            }
        }

        for(int i = 0; i<answer.size(); i++){
            cout << answer[i] << " ";
        }

        cout << '\n';
        
    }
}

int main(){
    int n;
    cin >> n;
    func(n);
    return 0;
}