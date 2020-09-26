#include <iostream>
#include <windows.h>
#include <fstream>
#include <cmath>
using namespace std;

class piano{
	public:
void play(string str,int octa,float seconds){
	float ret;
	const float DO = 32.7032,DO_SH = 34.6478,RE = 36.7081
	,RE_SH = 38.8909,MI = 41.2034,FA = 43.6535
	,FA_SH = 46.2493,SOL = 48.9991,SOL_SH = 51.9130
	,LA = 55.0000,LA_SH = 58.2705,SI = 61.7354;
	if(str=="do") ret=DO * pow(2,octa-1);
	else if(str=="doS") ret=DO_SH * pow(2,octa-1);
	else if(str=="re") ret=RE * pow(2,octa-1);
	else if(str=="reS") ret=RE_SH * pow(2,octa-1);
	else if(str=="mi") ret=MI * pow(2,octa-1);
	else if(str=="fa") ret=FA * pow(2,octa-1);
	else if(str=="faS") ret=FA_SH * pow(2,octa-1);
	else if(str=="sol") ret=SOL * pow(2,octa-1);
	else if(str=="solS") ret=SOL_SH * pow(2,octa-1);
	else if(str=="la") ret=LA * pow(2,octa-1);
	else if(str=="laS") ret=LA_SH * pow(2,octa-1);
	else if(str=="si") ret=SI * pow(2,octa-1);
	else cout <<"잘못된 값";
	Beep(ret,seconds*1000);
	return;
}
void help(){
	cout << "피아노의 옥타브범위 -> 1~8" << endl;
	return;
}
};

int main(){
	ifstream ifs;
	piano pi;
	string str;
	int oct;
	float sec;
	ifs.open("piano.txt");
	if(ifs.is_open()){
		while(1){
			ifs >> str >> oct >> sec;
			pi.play(str,oct,sec);
		if(ifs.eof()){
		ifs.close();
		break;	
		}
	}
	}
	else cout << "파일이 존재하지않습니다.";
}
