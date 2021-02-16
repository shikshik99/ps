#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int garo, sero;
    for(int i = 1; i <= yellow; i++){
        if(!(yellow % i) && yellow / i <= i){
            garo = i, sero = yellow / i;
            if((garo * 2 + sero * 2 + 4) == brown) {answer.push_back(garo+2), answer.push_back(sero+2); return answer;}
        }        
    }
}