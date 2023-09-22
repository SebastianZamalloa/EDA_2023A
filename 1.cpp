#include <iostream>
#include <vector>
#include <math.h>
#include <random>
#include<fstream>
#include <string> 

using namespace std;
int sum = 0;
 
vector<float> randomIntervales(int min, int max, int n) {
    random_device rd;
    mt19937 gen(rd()); 
    uniform_real_distribution<> dis(0.0, 1.0);

    vector<float> nums;

    for(int i = 0; i<n; i++){
        nums.push_back(dis(gen));
    }
    return nums;
}

vector<vector<float>> generatePoints(int howMany,int n){
    vector<vector<float>> result;
    while(howMany>0){
        result.push_back(randomIntervales(0,1,n));
        howMany--;
    }
    return result;
}

float euclidianDistance(vector<float> a, vector<float> b){
    float sum = 0.0;
    for(int i = 0; i<a.size();i++)
        sum += pow(a[i]-b[i],2);
    return sqrt(sum);
}

vector<float> euclidianPoints(vector<vector<float>> points){
    vector<float> distances;
    sum = 0;
    for(int i = 0; i<points.size();i++){
        for(int j = i+1; j<points.size(); j++){
            distances.push_back(euclidianDistance(points[i],points[j]));
            sum++;
        }
    }
    return distances;
}

int main()
{
    int n;
    cout<<"Ingresa n: ",cin>>n;
    vector<float> test = euclidianPoints(generatePoints(100,n));
    ofstream file;
    file.open("Generated/" + to_string(n) + ".txt", fstream::app);
    for(auto i:test){
        sum--;
        if(sum == 0){
            file << i;
            break;
        }
        file << i << endl;
    }
}