#include<iostream>
#include<vector>
using namespace std;
int findPoisonedDuration(vector<int>& timeSeries, int duration) {
	if(timeSeries.empty() || duration <= 0) return 0;
	int total = 0;
	int pre = timeSeries[0];
	for(auto val:timeSeries){
		total += min(duration, val - pre);
		pre = val;
	}
	return total + duration;
}

int main(){
	vector<int>nums = {1,4};
	cout<<"Poisoned duration:"<<findPoisonedDuration(nums,4)<<endl;
	return 0;
}
