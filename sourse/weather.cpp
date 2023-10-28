#include<bits\stdc++.h>
#include<fstream>
#include<windows.h>
using namespace std;
string CWeather,MWeather,Warning,Temp;
int l;

struct weather{
	string Ctem,MAXtem,MINtem,UPtime,date,days,aqi,wind_direction,wind_speed,weather,rainful,rainful24,Warnings;
};
weather wea;

bool is_stringC(string a,int q);
int main()
{
    system("weather_M.py");
    system("weather.py");
    ifstream fin;
    fin.open("weathersource.log.txt",ios::in);
    if(fin.is_open() == false){
    	cout<<"\n";cout<<"\n";
        cout<<"fail to open log files!!\n";
        cout<<"ERROR[1001]\n";
        cout<<"\n";cout<<"\n";cout<<"\n";
        system("pause");
        return -1;
    }
    fin >> CWeather;
    fin.close();
    //cout<<CWeather<<endl;
    l = CWeather.size();
    
    
    for(int i = 0; i < l; i++){
    	if(CWeather[i] == 't' && is_stringC("temp",i) == 1){
    		//wea.Ctem = CWeather[i+7];//cout<<CWeather[i+7];
            //wea.Ctem += CWeather[i+8];//cout<<CWeather[i+8];
            int w = min(i+10,l);
			for (int r = i + 7; r <= w; r++){
				if(CWeather[r] != '\"') wea.Ctem += CWeather[r];
				else break;
			}
    	}
		if(CWeather[i] == 't' && is_stringC("time",i) == 1){
			wea.UPtime = CWeather[i+7];
			wea.UPtime += CWeather[i+8];
			wea.UPtime += CWeather[i+9];
			wea.UPtime += CWeather[i+10];
			wea.UPtime += CWeather[i+11];
		}
		if(CWeather[i] == 'w' && is_stringC("weather\"",i) == 1){
			
			int w = min(i+20,l);
			for (int r = i + 10; r <= w; r++){
				if(CWeather[r] != '\"') wea.weather += CWeather[r];
				else break;
			}
        }

        if(CWeather[i] == 'W' && is_stringC("WD\"",i) == 1){
			
			int w = min(i+12,l);
			for (int r = i + 5; r <= w; r++){
				if(CWeather[r] != '\"') wea.wind_direction += CWeather[r];
				else break;
			}
        }
        if(CWeather[i] == 'W' && is_stringC("WS\"",i) ){
            int w = min(i + 12, l);
            for(int r = i + 5; r <= w; r++){
                if(CWeather[r] != '\"') wea.wind_speed += CWeather[r];
                else break;
            }
            if(wea.wind_speed[0] == '0') wea.wind_direction = "无风";
        }
		
    }
/////////////////////////////////////////////////////////////////////////////
    fin.open("weather.log.txt",ios::in);
    if(fin.is_open() == false){
    	cout<<"\n";cout<<"\n";
        cout<<"fail to open log files!!\n";
        cout<<"ERROR[1001]\n";
        cout<<"\n";cout<<"\n";cout<<"\n";
        system("pause");
        return -1;
    }
    fin >> Temp;
    if(Temp == "var"){
        fin >> Temp;
        fin >> MWeather;
        Temp = "";
    }
    else{
        cout<<"ERROR[1002]\n";
        cout<<"\n";cout<<"\n";cout<<"\n";
        system("pause");
        return -2;
    }
    fin >> Temp;
    if(Temp == "alarmDZ101270101"){
        fin >> Warning;
        Temp = "";
    }
    else{
        cout<<"ERROR[1002]\n";
        cout<<"\n";cout<<"\n";cout<<"\n";
        system("pause");
        return -2;
    }
    fin.close();
    ////////
    int lW = Warning.size();
    bool if_E_warnings = 0,if_E_warning_content = 0;
    for (int i = 0; i <= 8; i++){
        if(Warning[i] == '[') {
            if_E_warning_content = 1;
            if(Warning[i+1] == ']'){
                wea.Warnings = "NONE";
                break;
            }
            else if(Warning[i+1] == '{'){
                if_E_warnings = 1;
                break;
            }
            else 
            {
                cout<<"ERROR[1003]\nWarnings Not Exist\n";
                cout<<"\n";cout<<"\n";cout<<"\n";
                system("pause");
                return -3;
            }
        }
    }
    if (if_E_warning_content == 0){
        cout<<"ERROR[1003]\nWarnings Not Exist\n";
        cout<<"\n";cout<<"\n";cout<<"\n";
        system("pause");
        return -3;
    }
    if (if_E_warnings == 1)
    {
        for (int i = 0; i < lW; i++)
        {
            if(Warning[i] == 'w' && Warning[i+1] == '5'){
                for (int q = i + 5; q <= lW; q++)
                {
                    if(Warning[q] != '\"') wea.Warnings += Warning[q];
                    else break;
                }
            }
            if(Warning[i] == 'w' && Warning[i+1] == '7'){
                for (int q = i + 5; q <= lW; q++)
                {
                    if(Warning[q] != '\"') wea.Warnings += Warning[q];
                    else break;
                }
            }
            
        }
        wea.Warnings += "预警";
    }
/* ^^^^^ Warning Part ^^^^^*/

    

	cout<<"现在天气:"<<wea.weather<<endl;
    cout<<"现在气温:"<<wea.Ctem<<"℃    更新时间:"<<wea.UPtime<<endl;
    cout<<"风向:"<<wea.wind_direction<<"  风速:"<<wea.wind_speed<<endl;
    //cout<<MWeather<<"   "<<Warning;
    if (if_E_warnings == 1) cout<<wea.Warnings<<endl;
    
    system("pause");
    return 0;

}



bool is_stringC(string a,int q)
{
    //cout<<a;
    int len = a.size();
    int m=0;
    for(int r = q; r <(q + len); r++){
        
        if(CWeather[r] != a[m])return 0;
        m++;
    }
    return 1;
}
