#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstring>
#include <stack>
#include<cstdio>
#include<ctime>
#include<fstream>
#include<utility>
#include<stdlib.h>
#include<windows.h>
#include<algorithm>
using namespace std;
typedef struct Graph { //线路图定义
	vector< vector<vector<int>> > arc; //存放公交名称
	int nvex; //节点数
	bool flag;
}graph;
typedef struct Station { //站点定义
	int Stationind; //编号
	string StationName; //名称
	int Routenum; //
	vector<struct Route*> routes; //经过的路线
}Station;
typedef struct Bus { //公交定义
	string name; //名称
	Station* start; //始发站 
	Station* end; //末站
	int price; //票价
	string startTime; //始发时
	vector<int> line; //线路
	int distance; //两站间距
}Bus;
typedef struct Route { //每站线路
	int des; //目标
	string indBus; //公交名称
}Route;
typedef struct BusMap { //总图
	vector<Bus*> Buses; //公交
	vector<Station*> Stations; //站点
	int Bus_num;
	int Station_num;
	bool flag;
}BusMap;
typedef struct Edge {
	int a, b, w,ind;//起点 终点 长度 下标
}Edge;
vector<pair<string, string>> account; //账户
int sign_flag = 0;
void Change(BusMap& Map, Graph& g, int start, int end); //函数声明
void ChangeMenu(BusMap& Map);
void MainMenu(BusMap& Map);
Graph* CreatGraph(BusMap& Map,Graph*g);
void DelStation(BusMap& Map);
void DelLine(BusMap& Map);
void printAll(BusMap& Map);
void print(BusMap& Map);
void PrintStation(BusMap& Map, int j);
void Initial(BusMap& Map);
string AddRoute(BusMap& Map, string tmp);
int AddStations(BusMap& Map, string tmp);
vector<string> Split(string& line);
string FindRoute(BusMap& Map, string name);
int FindStation(BusMap& Map, string name);
void UserMenu(BusMap& Map);
void AdmMenu(BusMap& Map);
void MainMenu(BusMap& Map);
int FindRoute(BusMap& Map, int ind);
vector<vector<int>> dfs_zero(Graph& g, vector<int>& visited, vector<vector<int>>& Allway, vector<int>& way, int a, int b, int m, int indpre);
vector<vector<int>> dfs_one(Graph& g, vector<int>& visited, vector<vector<int>>& Allway, vector<int>& way, int a, int b, int m, int indpre, int count);
vector<vector<int>> dfs_more(Graph& g, vector<int>& visited, vector<vector<int>>& Allway, vector<int>& way, int a, int b, int m, int indpre, int count);
void ChangeZero(BusMap& Map, Graph& g, int a, int b);
void ChangeOne(BusMap& Map, Graph& g, int a, int b);
void ChangeMore(BusMap& Map, Graph& g, int a, int b);
void FindBus(BusMap& Map);
vector<int> dijkstra_len(BusMap& Map, Graph& g, vector<int>& way, vector<int>& visited, vector<int>& pre, int a, int b, vector<int>dist);
void BestwayTwo(BusMap& Map);
void copy();
void AddStation(BusMap& Map);
void DelStation(BusMap& Map);
void ChangeName(BusMap& Map);
void ChangeRouteTime(BusMap& Map);
void ChangeRouteName(BusMap& Map);
void ChangeRoutePrice(BusMap& Map);
void ChangeRouteDis(BusMap& Map);
void restore(BusMap&Map);
void Manage(BusMap& Map);
void sign(BusMap& Map);
int FindStation(BusMap& Map, string name) { //是否存在站点 返回编号
	for (int i = 0; i < Map.Station_num; i++) {
		if (Map.Stations[i]->StationName == name) {
			return Map.Stations[i]->Stationind;
		}
	}
	return 0;
}
string FindRoute(BusMap& Map, string name) {//是否存在路线 返回路线名
	for (int i = 0; i < Map.Bus_num; i++) {
		if (Map.Buses[i]->name == name) {
			return Map.Buses[i]->name;
		}
	}
	return "0";
}
int FindRoute(BusMap& Map, int ind) {//是否存在路线 返回路线在数组中下标
	for (int i = 0; i < Map.Bus_num; i++) {
		if (atoi(Map.Buses[i]->name.c_str()) == ind) {
			return i;
		}
	}
	return 0;
}
vector<string> Split(string& line) {//按空格拆分文本
	vector<string> v;
	int pos = 0;
	int pos2 = 0;
	int len = line.length();
	while (pos < len) {
		pos2 = line.find(" ", pos);
		if (pos2 == -1) pos2 = len;
		v.push_back(line.substr(pos, pos2 - pos));
		pos = pos2 + 1;
	}
	return v;
}
int AddStations(BusMap& Map, string tmp) {//添加站点
	vector<string> str = Split(tmp);
	if (str.size()>0) {
		string name = str[1];
		string ind = str[0];
		int flag = FindStation(Map, str[1]);
		if (flag > 0) {
			cout << "站点存在,无需添加" << endl;
			return flag;
		}
		else {
			Station* st = new Station();
			Map.Stations.push_back(st);
			Map.Station_num++;
			st->StationName = name;
			st->Stationind = Map.Station_num;
			st->Routenum = 0;
			return st->Stationind;
		}
	}
}
string AddRoute(BusMap& Map, string tmp) {//添加路线
	vector<string> str = Split(tmp);
	int len = str.size();
	int start = atoi(str[4].c_str());
	int end = atoi(str[len - 1].c_str());
	string flag = FindRoute(Map, str[0]);//站点是否存在
	if (flag != "0") {
		cout << "路线存在,无需添加" << endl;
		return flag;
	}
	else {
		Bus* bus = new Bus();
		bus->name = str[0];//名称
		bus->price = atoi(str[1].c_str());//票价
		bus->startTime = str[2] + ":" + str[3];//始发时
		bus->distance = atoi(str[4].c_str());//距离
		bus->start = Map.Stations[start - 1];//起点站编号
		bus->end = Map.Stations[end - 1];//终点站编号
		for (int i = 5; i < len - 1; i++) {//循环读入经过站点编号
			bus->line.push_back(atoi(str[i].c_str()));
			Route* route = new Route();
			if (i == len - 1) {//终点站des=0
				route->des = 0;
			}
			else {
				route->des = atoi(str[i + 1].c_str());//线路上每站的下一站
			}
			route->indBus = bus->name;
			Map.Stations[atoi(str[i].c_str()) - 1]->Routenum++;//站点记录经过的线路数+1
			Map.Stations[atoi(str[i].c_str()) - 1]->routes.push_back(route);
		}
		bus->line.push_back(end);
		Route* route = new Route();
		route->des = 0;
		route->indBus = bus->name;
		Map.Stations[end - 1]->Routenum++;
		Map.Stations[end - 1]->routes.push_back(route);
		Map.Bus_num++;
		Map.Buses.push_back(bus);
	}
}
void Initial(BusMap& Map) {//初始化
	Map.Buses.clear();
	Map.Stations.clear();
	Map.Bus_num = Map.Station_num = 0;
	Map.flag = false;
	int index = 0;
	Map.Bus_num = 0;
	Map.Station_num = 0;
	ifstream instations;
	instations.open("stations.txt");
	if (!instations.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	string stations;
	cout << "调用txt文件初始化" << endl;
	while (getline(instations, stations)) {
		if (stations=="") {
			continue;
		}
		AddStations(Map, stations);
	}
	ifstream inroute;
	inroute.open("routes.txt");
	if (!inroute.is_open()) {
		cout << "文件打开失败" << endl;
		exit(0);
	}
	string route;
	cout << "调用txt文件初始化" << endl;
	while (getline(inroute, route)) {
		if (route=="") {
			continue;
		}
		AddRoute(Map, route);
	}
	instations.close();
	inroute.close();
	cout << "初始化完毕" << endl;
	Map.flag = true;
}
void PrintStation(BusMap& Map, int j) {//打印站点
	cout << Map.Buses[j]->name << "路公交" << endl;
	cout << "票价" << Map.Buses[j]->price << "元" << endl;
	cout << "首班车时间:" << Map.Buses[j]->startTime << endl;
	for (int i = 0; i < Map.Buses[j]->line.size(); i++) {
		int num = Map.Buses[j]->line[i] - 1;
		cout << Map.Stations[num]->StationName << "--";
	}
}
void print(BusMap& Map) {//显示某路线所有站点
	string s;
	cout << "输入查询线路" << endl;
	cin >> s;
	for (int i = 0; i < Map.Bus_num; i++) {
		if (Map.Buses[i]->name == s) {
			PrintStation(Map, i);
			cout << "查询完毕" << endl;
			return;
		}
	}
	cout << "查询失败" << endl;
}
void printAll(BusMap& Map) { //显示所有站点
	for (int i = 0; i < Map.Bus_num; i++) {
		PrintStation(Map, i);
		cout << "查询完毕" << endl;
		if (i == Map.Bus_num - 1) {
			return;
		}
	}
	cout << "查询失败" << endl;
}
Graph* CreatGraph(BusMap& Map, Graph* g) { //创建邻接矩阵用于换乘 最短路径查询
	g->nvex = Map.Station_num; //顶点数等于站点数
	g->arc.resize(Map.Station_num, vector<vector<int>>(Map.Station_num, vector<int>(0)));//初始化
	for (int i = 0; i < g->nvex; i++) {
		g->arc[i][i].push_back(0);
		for (int j = 0; j < Map.Stations[i]->Routenum; j++) {
			int ind = atoi(Map.Stations[i]->routes[j]->indBus.c_str());//储存公交名称
			if (Map.Stations[i]->routes[j]->des == 0) {
				continue;
			}
			g->arc[i][Map.Stations[i]->routes[j]->des - 1].push_back(ind);//无向图,矩阵对称
			g->arc[Map.Stations[i]->routes[j]->des - 1][i].push_back(ind);
		}
	}
	g->flag = true;
	cout << "初始化完成" << endl;
	return g;
}
vector<vector<int>> dfs_zero(Graph& g, vector<int>& visited, vector<vector<int>>& Allway, vector<int>& way, int a, int b, int m, int indpre) { //0次换乘
	way.push_back(m); 
	visited[m] = 1;//站点已访问
	if (b == m) {
		Allway.push_back(way); //储存一条换乘路径
	}
	for (int i = 0; i < g.nvex; i++) {
		if (g.arc[m][i].size() != 0 && visited[i] != 1) {//两站间有线路且站点未访问
			for (int j = 0; j < g.arc[m][i].size(); j++) {
				int ind = g.arc[m][i][j]; //ind 记录线路名称
				if (a == m) {
					way[0] = ind;//记录乘坐车辆名称
					indpre = ind;//indpre表示上一站乘坐的公交
				}
				if (ind == indpre && ind == way[0]) { //同一条公交线 继续递归
					dfs_zero(g, visited, Allway, way, a, b, i, ind);
				}
			}
		}
	}
	way.pop_back(); //回溯
	visited[m] = 0; //站点未访问
	return Allway;
}
vector<vector<int>> dfs_one(Graph& g, vector<int>& visited, vector<vector<int>>& Allway, vector<int>& way, int a, int b, int m, int indpre, int count) { //一次换乘
	way.push_back(m);
	visited[m] = 1;//站点已访问
	int ind = 0;
	if (b == m && count == 2) {//终点且换成次数为一次
		Allway.push_back(way);
	}
	else if (count < 2) {
		for (int i = 0; i < g.nvex; i++) {
			if (g.arc[m][i].size() != 0 && visited[i] != 1) {//两站间有线路且站点未访问
				for (int j = 0; j < g.arc[m][i].size(); j++) {
					ind = g.arc[m][i][j]; //ind 表示线路名称
					if (m == a) {//初始线路 视作一次换乘
						way[0] = ind;
						count++;
					}
					else if (ind != indpre && m != a ) { //新线路不等于初始线路 换乘
						way[1] = ind;
						way[2] = m;
						count++;
					}
					dfs_one(g, visited, Allway, way, a, b, i, ind, count);//递归
					visited[i] = 0;//站点未访问
					if (ind != indpre) { //回溯换乘次数
						count--;
					}
				}
			}
		}
	}
	way.pop_back(); //回溯
	return Allway;
}
bool cmp_way(vector<vector<int>>&Allway,vector<int>&way) {
	if (Allway.empty()||way.empty()||Allway.size()==1) {
		return true;
	}
	for (int i = 0; i < Allway.size();++i) {
		if (Allway[i].size()!=way.size()) {
			continue;
		}
		if (equal(way.begin(),way.end(),Allway[i].begin())) {
			return false;
		}
	}
	return true;
}
vector<vector<int>> dfs_more(Graph& g, vector<int>& visited, vector<vector<int>>& Allway, vector<int>& way, int a, int b, int m, int indpre, int count) { //多次换乘
	if (b == m && count >= 3) {//换乘次数大于1
		way.push_back(count);//在数组最后储存换乘次数
		Allway.push_back(way);
		way.pop_back();
		return Allway;
	}
	if (count >= 6) { //最多换乘5次 防止递归次数过多
		return Allway;
	}
	for (int i = 0; i < g.nvex; i++) {
		if (g.arc[m][i].size() != 0 && visited[i] != 1 && g.arc[m][i][0] != 0) {
			for (int j = 0; j < g.arc[m][i].size(); j++) {
				int ind = g.arc[m][i][j];
				if (m == a) {//初始线路
					way.push_back(ind + 100);
					count++;
				}
				if (ind != indpre && find(way.begin(), way.end(), ind+100) == way.end() && m != a) {
					way.push_back(ind + 100); //换乘时 存放线路名+100 区分站点
					count++;//换乘次数+1
				}
				way.push_back(i);
				visited[i] = 1;//站点已访问
				dfs_more(g, visited, Allway, way, a, b, i, ind, count);
				way.pop_back();//回溯
				if (*(way.end() - 1) > 100) { //回溯换乘次数
					way.pop_back();
					count--;
				}
			}
		}
	}
	visited[m] = 0; //站点未访问
	return Allway;
}
bool cmp_change(pair<int,int>&a,pair<int,int>&b) { //自定排序方式
	return a.first < b.first; //按二元组中第一个元素,即长度排序
}
void FindZero_len(BusMap&Map,vector<vector<int>>&Allway) {
		int i = 0;
		vector<pair<int, int>> res; //二元组数组 记录路程长度和下标
		for (i = 0; i < Allway.size();i++) {
			int len = Map.Buses[FindRoute(Map, Allway[i][0])]->distance * (Allway[i].size() - 1); //计算每条线路长度
			res.push_back(make_pair(len,i));//存入长度及在Allway中下标
		}
		sort(res.begin(),res.end(),cmp_change);//按长度排序
		for (i = 0; i < res.size(); i++) {//按排序后的下标输出
			int j = 0;
			int ind = res[i].second;
			int len = Map.Buses[FindRoute(Map, Allway[ind][0])]->distance * (Allway[ind].size() - 1); //计算总路程
			int price = Map.Buses[FindRoute(Map, Allway[ind][0])]->price; //计算票价
			cout << "线路" << i + 1 << "为:乘坐" << Allway[ind][0] << "路" <<" " <<"票价" <<price<<"元" << endl;//输出
			for (j = 1; j < Allway[ind].size() - 1; j++) {
				cout << Map.Stations[Allway[ind][j]]->StationName << "--";
			}
			cout << Map.Stations[Allway[ind][j]]->StationName << endl;
			cout << "总路程为:" << len << "公里" << endl;
			cout << "-----------------------------------" << endl;
		}
		cout << "查询完毕" << endl;
}
void FindZero_price(BusMap& Map, vector<vector<int>>& Allway) {
	int i = 0;
	vector<pair<int, int>> res;
	for (i = 0; i < Allway.size(); i++) {
		int price = Map.Buses[FindRoute(Map, Allway[i][0])]->price; //票价
		res.push_back(make_pair(price, i));
	}
	sort(res.begin(), res.end(), cmp_change);
	for (i = 0; i < res.size(); i++) {
		int j = 0;
		int ind = res[i].second;
		int len = Map.Buses[FindRoute(Map, Allway[ind][0])]->distance * (Allway[ind].size() - 1); //计算总路程
		int price = Map.Buses[FindRoute(Map, Allway[ind][0])]->price; //票价
		cout << "线路" << i + 1 << "为:乘坐" << Allway[ind][0] << "路" << " " << "票价" << price << "元" << endl;
		for (j = 1; j < Allway[ind].size() - 1; j++) {
			cout << Map.Stations[Allway[ind][j]]->StationName << "--";
		}
		cout << Map.Stations[Allway[ind][j]]->StationName << endl;
		cout << "总路程为:" << len << "公里" << endl;
		cout << "-----------------------------------" << endl;
	}
	cout << "查询完毕" << endl;
}
void ChangeZero(BusMap& Map, Graph& g, int a, int b) { //换乘0次
	int m = a;
	int ind = 0;
	vector<int> visited(g.nvex, 0);//经过的站点
	vector<vector<int>> Allway; //存放所有路径
	vector<int> way(1, 0);
	Allway = dfs_zero(g, visited, Allway, way, a - 1, b - 1, m - 1, ind);
	if (Allway.size() == 0) {//判断路径是否存在
		cout << "无法直达" << endl;
	}
	else {
		cout << "可以直达,选择查询方式:" << endl; //调用不同的排序方式
		cout << "\t\t********(1)按路程排序******************\n" << endl;
		cout << "\t\t********(2)按票价排序******************\n" << endl;
		int n;
		cin >> n;
		switch(n) {
		case 1:
			FindZero_len(Map,Allway);
			break;
		case 2:
			FindZero_price(Map,Allway);
			break;
		}
	}
	Change(Map, g, a, b);//返回上一界面
}
void FindOne_len(BusMap&Map,vector<vector<int>>&Allway) {
	vector<pair<int, int>> res;
	for (int i = 0; i < Allway.size();i++) {
		int dis = Map.Buses[FindRoute(Map, Allway[i][0])]->distance;//计算总距离
		int sum_dis = 0;
		for (int j = 3; j < Allway[i].size() - 1; j++) {
			sum_dis += dis;
			if (Allway[i][j] == Allway[i][2]) {
				dis = Map.Buses[FindRoute(Map, Allway[i][1])]->distance;//换乘后 更新距离
				continue;
			}
		}
		res.push_back(make_pair(sum_dis, i));//储存总距离和下标
	}
	sort(res.begin(), res.end(), cmp_change);
	int i = 0;
	for (i = 0; i < res.size(); i++) {
		int j = 0;
		int ind = res[i].second;
		int price = Map.Buses[FindRoute(Map, Allway[ind][0])]->price + Map.Buses[FindRoute(Map, Allway[ind][1])]->price; //两个线路的票价和
		cout << "线路" << i + 1 << "为:乘坐" << Allway[ind][0] << "路" << " " << "票价" << price << "元" << endl;
		int dis = Map.Buses[FindRoute(Map, Allway[ind][0])]->distance;
		int sum_dis = 0;
		for (j = 3; j < Allway[ind].size() - 1; j++) {
			cout << Map.Stations[Allway[ind][j]]->StationName << "--";
			sum_dis += dis;
			if (Allway[ind][j] == Allway[ind][2]) {
				cout << "在" << Map.Stations[Allway[ind][j]]->StationName << "站换乘" << Allway[ind][1] << "路--";
				dis = Map.Buses[FindRoute(Map, Allway[ind][1])]->distance;//换乘后 更新每站相距距离
				continue;
			}
		}
		cout << Map.Stations[Allway[ind][j]]->StationName << endl;
		cout << "总路程为:" << sum_dis << "公里" << endl;
		cout << "-----------------------------------" << endl;
	}
	cout << "查询完毕" << endl;
}
void FindOne_price(BusMap& Map, vector<vector<int>>& Allway) {
	vector<pair<int, int>> res;
	for (int i = 0; i < Allway.size(); i++) {
		int price = Map.Buses[FindRoute(Map, Allway[i][0])]->price + Map.Buses[FindRoute(Map, Allway[i][1])]->price;//计算总票价
		res.push_back(make_pair(price, i));//记录票价和下标
	}
	sort(res.begin(), res.end(), cmp_change);//排序
	int i = 0;
	for (i = 0; i < res.size(); i++) {
		int j = 0;
		int ind = res[i].second;
		int price = Map.Buses[FindRoute(Map, Allway[ind][0])]->price + Map.Buses[FindRoute(Map, Allway[ind][1])]->price; //两个线路的票价和
		cout << "线路" << i + 1 << "为:乘坐" << Allway[ind][0] << "路" << " " << "票价" << price << "元" << endl;
		int dis = Map.Buses[FindRoute(Map, Allway[ind][0])]->distance;
		int sum_dis = 0;
		for (j = 3; j < Allway[ind].size() - 1; j++) {
			cout << Map.Stations[Allway[ind][j]]->StationName << "--";
			sum_dis += dis;
			if (Allway[ind][j] == Allway[ind][2]) {
				cout << "在" << Map.Stations[Allway[ind][j]]->StationName << "站换乘" << Allway[ind][1] << "路--";
				dis = Map.Buses[FindRoute(Map, Allway[ind][1])]->distance;//换乘后 更新距离
				continue;
			}
		}
		cout << Map.Stations[Allway[ind][j]]->StationName << endl;
		cout << "总路程为:" << sum_dis << "公里" << endl;
		cout << "-----------------------------------" << endl;
	}
	cout << "查询完毕" << endl;
}
void ChangeOne(BusMap& Map, Graph& g, int a, int b) {
	int m = a;
	int ind = 0;
	int count = 0;//记录换乘次数
	vector<int> visited(g.nvex, 0);
	vector<vector<int>> Allway;
	vector<int> way(3, 0);//数组的前三个元素分别记录开始时乘坐线路 第一次换乘线路 换乘站点编号
	Allway = dfs_one(g, visited, Allway, way, a - 1, b - 1, m - 1, ind, count);
	if (Allway.size() == 0) {
		cout << "无法换乘一次到达" << endl;
	}
	else {
		cout << "可以直达,选择查询方式:" << endl;
		cout << "\t\t********(1)按路程排序******************\n" << endl;
		cout << "\t\t********(2)按票价排序******************\n" << endl;
		int n;
		cin >> n;
		switch (n) {
		case 1:
			FindOne_len(Map, Allway);//路程
			break;
		case 2:
			FindOne_price(Map, Allway);//票价
			break;
		}
	}
	Change(Map, g, a, b);//返回
}
void FindMore_len(BusMap& Map,vector<vector<int>>&Allway,int a) {
	vector<pair<int, int>> res;
	for (int i = 0; i < Allway.size();i++) {
		int dis = Map.Buses[FindRoute(Map, Allway[i][0] - 100)]->distance;//计算距离
		int sum_dis = 0;
		for (int j = 1; j < Allway[i].size() - 2; j++) {
			if (Allway[i][j] > 100) {//大于100说明记录的是线路名称,换乘
				dis = Map.Buses[FindRoute(Map, Allway[i][j] - 100)]->distance; //更新距离
				continue;
			}
			sum_dis += dis;//总距离
		}
		res.push_back(make_pair(sum_dis, i));
	}
	sort(res.begin(), res.end(), cmp_change);//排序
	int i = 0;
	for (i = 0; i < res.size(); i++) {
		int ind = res[i].second;
		int count = *(Allway[ind].end() - 1);
		int j = 0;
		int price = Map.Buses[FindRoute(Map, Allway[ind][0] - 100)]->price;
		int dis = Map.Buses[FindRoute(Map, Allway[ind][0] - 100)]->distance;
		int sum_dis = 0;
		cout << "线路" << i + 1 << "(换乘" << count - 1 << "站)为:乘坐" << Allway[ind][0] - 100 << "路" << endl;
		cout << Map.Stations[a - 1]->StationName << "--";
		for (j = 1; j < Allway[ind].size() - 2; j++) {
			if (Allway[ind][j] > 100) {
				cout << "在" << Map.Stations[Allway[ind][j - 1]]->StationName << "站换乘" << Allway[ind][j] - 100 << "路--";
				price += Map.Buses[FindRoute(Map, Allway[ind][j] - 100)]->price; //更新票价
				dis = Map.Buses[FindRoute(Map, Allway[ind][j] - 100)]->distance; //更新距离
				continue;
			}
			cout << Map.Stations[Allway[ind][j]]->StationName << "--";
			sum_dis += dis;
		}
		cout << Map.Stations[Allway[ind][j]]->StationName << endl << "总路程:" << sum_dis << "公里" << endl << "票价:" << price << "元" << endl;
		cout << "-----------------------------------" << endl;
	}
	cout << "查询完毕" << endl;
}
void FindMore_price(BusMap& Map, vector<vector<int>>& Allway, int a) {
	vector<pair<int, int>> res;
	for (int i = 0; i < Allway.size(); i++) {
		int price = Map.Buses[FindRoute(Map, Allway[i][0] - 100)]->price;
		for (int j = 1; j < Allway[i].size() - 2; j++) {
			if (Allway[i][j] > 100) {//换乘
				price += Map.Buses[FindRoute(Map, Allway[i][j] - 100)]->price; //更新票价
				continue;
			}
		}
		res.push_back(make_pair(price, i));
	}
	sort(res.begin(), res.end(), cmp_change);//排序
	int i = 0;
	for (i = 0; i < res.size(); i++) {
		int ind = res[i].second;
		int count = *(Allway[ind].end() - 1);
		int j = 0;
		int price = Map.Buses[FindRoute(Map, Allway[ind][0] - 100)]->price;
		int dis = Map.Buses[FindRoute(Map, Allway[ind][0] - 100)]->distance;
		int sum_dis = 0;
		cout << "线路" << i + 1 << "(换乘" << count - 1 << "站)为:乘坐" << Allway[ind][0] - 100 << "路" << endl;
		cout << Map.Stations[a - 1]->StationName << "--";
		for (j = 1; j < Allway[ind].size() - 2; j++) {
			if (Allway[ind][j] > 100) {
				cout << "在" << Map.Stations[Allway[ind][j - 1]]->StationName << "站换乘" << Allway[ind][j] - 100 << "路--";
				price += Map.Buses[FindRoute(Map, Allway[ind][j] - 100)]->price; //更新票价
				dis = Map.Buses[FindRoute(Map, Allway[ind][j] - 100)]->distance; //更新距离
				continue;
			}
			cout << Map.Stations[Allway[ind][j]]->StationName << "--";
			sum_dis += dis;
		}
		cout << Map.Stations[Allway[ind][j]]->StationName << endl << "总路程:" << sum_dis << "公里" << endl << "票价:" << price << "元" << endl;
		cout << "-----------------------------------" << endl;
	}
	cout << "查询完毕" << endl;
}
void FindMore_count(BusMap& Map, vector<vector<int>>& Allway, int a) {
	vector<pair<int, int>> res;
	for (int i = 0; i < Allway.size(); i++) {
		int count = *(Allway[i].end() - 1);//换乘次数
		res.push_back(make_pair(count, i));
	}
	sort(res.begin(), res.end(), cmp_change);//排序
	int i = 0;
	for (i = 0; i < res.size(); i++) {
		int ind = res[i].second;
		int count = *(Allway[ind].end() - 1);
		int j = 0;
		int price = Map.Buses[FindRoute(Map, Allway[ind][0] - 100)]->price;
		int dis = Map.Buses[FindRoute(Map, Allway[ind][0] - 100)]->distance;
		int sum_dis = 0;
		cout << "线路" << i + 1 << "(换乘" << count - 1 << "站)为:乘坐" << Allway[ind][0] - 100 << "路" << endl;
		cout << Map.Stations[a - 1]->StationName << "--";
		for (j = 1; j < Allway[ind].size() - 2; j++) {
			if (Allway[ind][j] > 100) {
				cout << "在" << Map.Stations[Allway[ind][j - 1]]->StationName << "站换乘" << Allway[ind][j] - 100 << "路--";
				price += Map.Buses[FindRoute(Map, Allway[ind][j] - 100)]->price; //更新票价
				dis = Map.Buses[FindRoute(Map, Allway[ind][j] - 100)]->distance; //更新距离
				continue;
			}
			cout << Map.Stations[Allway[ind][j]]->StationName << "--";
			sum_dis += dis;
		}
		cout << Map.Stations[Allway[ind][j]]->StationName << endl << "总路程:" << sum_dis << "公里" << endl << "票价:" << price << "元" << endl;
		cout << "-----------------------------------" << endl;
	}
	cout << "查询完毕" << endl;
}
void ChangeMore(BusMap& Map, Graph& g, int a, int b) {
	int m = a;
	int ind = 0;
	int count = 0;
	vector<int> visited(g.nvex, 0);
	visited[a - 1] = 1;
	vector<vector<int>> Allway;
	vector<int> way(0);
	vector<int> bus;
	Allway = dfs_more(g, visited, Allway, way, a - 1, b - 1, m - 1, ind, count);
	if (Allway.size() == 0) {
		cout << "无法换乘到达" << endl;
	}
	else {
		cout << "可以直达,选择查询方式:" << endl;
		cout << "\t\t********(1)按路程排序******************\n" << endl;
		cout << "\t\t********(2)按票价排序******************\n" << endl;
		cout << "\t\t********(3)按换乘次数排序******************\n" << endl;
		int n;
		cin >> n;
		switch (n) {
		case 1:
			FindMore_len(Map, Allway,a);//距离
			break;
		case 2:
			FindMore_price(Map, Allway,a);//票价
			break;
		case 3:
			FindMore_count(Map,Allway,a);//换乘次数
			break;
		}
	}
	Change(Map, g, a, b);//返回
}
void ChangeMenu(BusMap& Map) {
	int n;
	Graph* g = new Graph();
	g->flag = false;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t***********公交换乘查询系统************************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t********(1)初始化线路图****************************\n" << endl;
	cout << "\t\t********(2)查询两站之间的换乘路径******************\n" << endl;
	cout << "\t\t********(3)退出系统********************************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
label:cout << "输入操作编号" << endl;
	cin >> n;
	switch (n) {
	case 1:CreatGraph(Map, g); goto label; //创建路线图
	case 2:
		if (g->flag == true) { //判断路线图是否创建
			string m, n;
			cout << "输入查询的站点" << endl;
			cout << "起点:";
			cin >> m;
			cout << endl << "终点" << endl;
			cin >> n;
			int start = FindStation(Map, m); //找到起终站点编号
			int end = FindStation(Map, n);
			if (start == 0 || end == 0) { //站点输入错误
				cout << "不存在站点" << endl;
				goto label;
			}
			Change(Map, *g, start, end); //进入下一级界面
		}
		else {
			cout << "先初始化" << endl; goto label; //重新输入
		}
	case 3: //返回上一界面
		if (sign_flag==0) {
			UserMenu(Map);
		}
		else {
			AdmMenu(Map);
		}
	}
}
void Change(BusMap& Map, Graph& g, int start, int end) {
	int k;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t***********公交换乘查询系统************************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t********(1)查询直达线路****************************\n" << endl;
	cout << "\t\t********(2)查询换乘一次线路************************\n" << endl;
	cout << "\t\t********(3)查询换乘多次线路************************\n" << endl;
	cout << "\t\t********(4)返回************************************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
	cout << "输入操作编号" << endl;
	cin >> k;
	switch (k) {
	case 1:ChangeZero(Map, g, start, end);
	case 2:ChangeOne(Map, g, start, end);
	case 3:ChangeMore(Map, g, start, end);
	case 4:ChangeMenu(Map);
	}
}
void FindBus(BusMap& Map) { //查询经过某站点的所有线路
	string s;
	cout << "输入查询站点" << endl;
	cin >> s;
	int m = FindStation(Map, s);
	if (m == 0) {
		cout << "不存在站点" << endl;
	}
	else {
		for (int i = 0; i < Map.Stations[m - 1]->Routenum; i++) {
			cout << Map.Stations[m - 1]->routes[i]->indBus << "路" << " ";
		}
		cout <<"查询完毕" << endl;
	}
}
vector<int> dijkstra_len(BusMap& Map, Graph& g, vector<int>& way, vector<int>& visited, vector<int>& pre, int a, int b, vector<int>dist) { //最短路径
	dist.resize(g.nvex, 0);
	dist[a] = 0;
	visited[a] = 1;//站点已访问
	for (int i = 0; i < g.nvex; i++) {
		if (g.arc[a][i].size() != 0 && g.arc[a][i][0] != 0) {
			int min = 65535;
			int k;
			int flag = 0;
			for (k = 0; k < g.arc[a][i].size(); k++) {
				int ind = FindRoute(Map, g.arc[a][i][k]);//路线名称
				int dis = Map.Buses[ind]->distance; //选择两站间间距最短的线路
				if (min > dis) {//记录所选路径
					min = dis;
					flag = ind;
				}
			}
			dist[i] = min;
			pre[i] = a;  //修改前驱
			way[i] = flag; //记录两站之间最短线路
		}
	}
	int curr = a;
	for (int i = 0; i < g.nvex; i++) {//循环 到剩余站点的最短路径
		int tmp = 65535;
		for (int j = 0; j < g.nvex; j++) {
			if (!visited[j] && dist[j] < tmp) {
				tmp = dist[j];
				curr = j;
			}
		}
		visited[curr] = 1;
		for (int k = 0; k < g.nvex; k++) {
			int new_val = 65535;
			int min = 65535;
			int m;
			int flag = 0;
			if (!visited[k] && g.arc[curr][k].size() != 0 && g.arc[curr][k][0] != 0) {//更新最短路径
				for (m = 0; m < g.arc[curr][k].size(); m++) {
					int ind = FindRoute(Map, g.arc[curr][k][m]);
					int dis = Map.Buses[ind]->distance;
					if (min > dis) {
						min = dis;
						flag = ind;
					}
				}
				new_val = dist[curr] + min;
			}
			if (new_val < dist[k]) {
				dist[k] = new_val;
				pre[k] = curr;
				way[k] = flag;
			}
		}
	}
	stack<int>input; //栈 
	while (b != a) { //从终点到起点 前驱压进栈
		input.push(b);
		b = pre[b];//更新前驱
	}
	input.push(a);
	vector<int>path;
	while (input.size()) { //出栈 存放至path
		path.push_back(way[input.top()]); // 0-起点-线路-站点-线路....-线路-终点
		path.push_back(input.top());
		input.pop();
	}
	return path; //返回路径
}
void BestwayTwo(BusMap& Map) {
	Graph* g = new Graph();//创建路线图
	CreatGraph(Map, g);
	cout << "输入景点名称" << endl;
	vector<int> add; //记录所有游玩景点编号
	for (int i = 0; i < 2; i++) {
	label:string s;
		cin >> s;
		int n = FindStation(Map, s);
		if (n == 0) {
			cout << "不存在景点" << endl;//异常处理
			goto label;
		}
		add.push_back(n - 1);
	}
	int sum = 0;
	vector<int>path;
	int i = 0;
	int sum_price = 0;
	int s = Map.Station_num;
	cout << "距离最短线路:" << endl;
	for (i = 0; i < add.size()-1; i++) { //得到两游玩景点间的最短路径
		vector<int>dist(s, 65535);
		vector<int>visited(s, 0);
		vector<int>pre(s, -1);
		vector<int>way(s, 0);
		path = dijkstra_len(Map, *g, way, visited, pre, add[i], add[i + 1], dist);//迪杰斯特拉算法
		int m;
		int price = Map.Buses[path[2]]->price; //车票价
		for (m = 1; m <= path.size() - 2; m += 2) {//输出路径
			cout << Map.Stations[path[m]]->StationName << "---" << Map.Buses[path[m + 1]]->name << "路" << "---";
			if (strcmp(Map.Buses[path[m + 1]]->name.c_str(), Map.Buses[path[m - 1]]->name.c_str())&&m!=1) { //换乘更新票价
				price += Map.Buses[path[m + 1]]->price;
			}
			sum += Map.Buses[path[m + 1]]->distance; //更新距离
		}
		sum_price += price;
	}
	cout << Map.Stations[*(path.end() - 1)]->StationName << endl << "总路程:" << sum << "公里" << " "<<"票价:" <<sum_price<<"元" << endl;
	cout << "查询完成" << endl;
}
vector<vector<int>> BF_len(BusMap&Map,vector<vector<int>>&Allway,Graph&g,vector<int>&add,int a,int b) {
	int start = add[a];//获取起点编号
	int final = add[b];//终点编号
	int sum = 0;
	vector<int>path;
	int s = Map.Station_num;
	vector<int>dist(s, 65535);
	vector<int>visited(s, 0);
	vector<int>pre(s, -1);
	vector<int>way(s, 0);
	path=dijkstra_len(Map, g, way, visited, pre, start, final, dist);//求最短路径
	path.push_back(a);//在数组中储存起点和终点
	path.push_back(b);
	Allway.push_back(path);//将路线存入Allway
	return Allway;
}
bool cmp(Edge& a,Edge& b) {
	return a.w < b.w;//比较两条边的长度
}
int findfather(vector<int>&father,int x) {//判断是否形成回路
	if (x==father[x]) {
		return x;
	}
	int temp = findfather(father,father[x]);
	return temp;
}
void BestwayFour(BusMap&Map) {
	Graph* g = new Graph();//初始化线路图
	CreatGraph(Map, g);
	cout << "输入景点名称" << endl;
	vector<int> add; //记录所有游玩景点编号
	for (int i = 0; i < 4; i++) {
	label:string s;
		cin >> s;
		int n = FindStation(Map, s);//异常处理
		if (n == 0) {
			cout << "不存在景点" << endl;
			goto label;
		}
		add.push_back(n - 1);
	}
	vector<vector<int>> Allway;
	BF_len(Map, Allway, *g, add,0, 1);//依次获取两两景点间的最短路径
	BF_len(Map, Allway, *g, add,0, 2);
	BF_len(Map, Allway, *g, add,0, 3);
	BF_len(Map, Allway, *g, add,1, 2);
	BF_len(Map, Allway, *g, add,1, 3);
	BF_len(Map, Allway, *g, add, 2, 3);
	vector<Edge> edges;//边结构体
	int i;
	for (i = 0; i < Allway.size();i++) {
		int sum = 0;
		int j;
		for (j = 1; j < Allway[i].size()-4;j+=2) {
			sum+= Map.Buses[Allway[i][j+1]]->distance;//计算路程
		}
		edges.push_back({ Allway[i][j+1],Allway[i][j + 2],sum,i });//储存起点 终点 路程 下标
	}
	sort(edges.begin(),edges.end(),cmp);//排序
	vector<int>father(4);//辅助数组
	vector<int>res;
	int sum_len = 0;
	for (int i = 0; i < 4;i++) {//辅助数组初始化
		father[i] = i;
	}
	for (int i = 0; i < edges.size();i++) {
		int fa = findfather(father, edges[i].a);//起点
		int fb = findfather(father,edges[i].b);//终点
		if (fa!=fb) {//未形成回路
			int ind = edges[i].ind;//分四种情况处理
			if (res.size()==0||*(Allway[ind].end() - 2)==*(res.end()-1)) {
				res.push_back(*(Allway[ind].end() - 2));
				res.push_back(*(Allway[ind].end() - 1));
				sum_len += edges[i].w;
				father[fb] = fa;
			}
			else if (*(Allway[ind].end() - 1) == *(res.end() - 1)) {
				res.push_back(*(Allway[ind].end() - 1));
				res.push_back(*(Allway[ind].end() - 2));
				sum_len += edges[i].w;
				father[fa] = fb;
			}
			else if(*(res.begin())== *(Allway[ind].end() - 1)) {
				res.insert(res.begin(), *(Allway[ind].end() - 1));
				res.insert(res.begin(),*(Allway[ind].end() - 2));
				sum_len += edges[i].w;
				father[fb] = fa;
			}
			else if (*(res.begin()) == *(Allway[ind].end() - 2)) {
				res.insert(res.begin(), *(Allway[ind].end() - 2));
				res.insert(res.begin(), *(Allway[ind].end() - 1));
				sum_len += edges[i].w;
				father[fa] = fb;
			}
		}
	}
	int sum_price = 0;
	int m;
	int n = Map.Station_num;
	vector<int>path;
	cout << "距离最短路线:" << endl;
	for (i = 0; i < res.size(); i+=2) { //分别得到每两游玩景点间的最短路径
		vector<int>dist(n, 65535);
		vector<int>visited(n, 0);
		vector<int>pre(n, -1);
		vector<int>way(n, 0);
		path = dijkstra_len(Map, *g, way, visited, pre, add[res[i]], add[res[i + 1]], dist);
		int m;
		int price = Map.Buses[path[2]]->price; //车票价
		for (m = 1; m <= path.size() - 2; m += 2) {
			cout << Map.Stations[path[m]]->StationName << "---" << Map.Buses[path[m + 1]]->name << "路" << "---";
			if (strcmp(Map.Buses[path[m + 1]]->name.c_str(), Map.Buses[path[m - 1]]->name.c_str()) && m != 1) { //换乘更新票价
				price += Map.Buses[path[m + 1]]->price;
			}
		}
		sum_price += price;
	}
	cout << Map.Stations[*(path.end() - 1)]->StationName << endl << "总路程:" << sum_len << "公里" << " " << "票价:" << sum_price << "元" << endl;
	cout << "查询完成" << endl;
}
void copy() { //备份初始化文件
	ofstream out1("save_routes.txt");//创建线路备份文件
	ifstream in1("routes.txt");	
	ofstream out2("save_stations.txt");//创建站点备份文件
	ifstream in2("stations.txt");
	if (out2 << in2.rdbuf()&&out1 << in1.rdbuf()) {//复制
		cout << "复制成功" << endl;
	}
	else {
		cout << "复制失败" << endl;
	}
}
void AddStation(BusMap&Map) { //添加新站点
	cout << "输入增加站点名" << endl;
	string name;
	string str;
	cin >> name;
	if (FindStation(Map,name)!=0) {
		cout << "站点存在" << endl;
	}
	else {
		fstream in("stations.txt",ios::app);
		int count=++Map.Station_num; //新站点编号=已有站点数量+1
		in <<"\n"<<count << ' ' << name << endl;//写入文件
		in.close();
		cout << "增加成功" << endl;
	}
	fstream in("stations.txt", ios::in);
	fstream out("temp.txt", ios::out);
	string s;
	while (getline(in, s)) { 
		vector<string> tmp;
		tmp = Split(s);
		if (tmp.size() == 0) {
			continue;
		}
		out << s << "\n";//写入tmp文件
	}
	in.close();
	out.close();
	fstream outfile("stations.txt", ios::out);
	fstream infile("temp.txt", ios::in);
	while (getline(infile, str)) {
		outfile << str << "\n"; //写入初始化文件
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	Initial(Map);//重新初始化
}
void DelStation(BusMap&Map) { //删除站点
	string name;
	cout << "输入删除站点名称" << endl;
	cin >> name;
	fstream in("stations.txt",ios::in);
	fstream out("temp.txt",ios::out);
	string str;
	while (getline(in,str)) { //在文件中寻找待删除站点
		vector<string> tmp;
		tmp = Split(str);
		if (tmp.size()==0) {
			continue;
		}
		if (tmp[1]==name) {
			continue;
		}
		out << str << "\n";//写入tmp文件
	}
	in.close();
	out.close();
	fstream outfile("stations.txt",ios::out);
	fstream infile("temp.txt",ios::in);
	while (getline(infile,str)) {
		outfile << str << "\n"; //写入初始化文件
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	Initial(Map);//重新初始化
	cout << "删除完毕" << endl;
}
void ChangeName(BusMap&Map) { //变更站点名称
	cout << "输入变更站点的名称" << endl;
	string name;
	cin >> name;
	if (FindStation(Map,name)==0) {//是否存在该站点
		cout << "站点不存在" << endl;
		return;
	}
	fstream in("stations.txt", ios::in);
	fstream out("temp.txt", ios::out);//新建临时文件
	string str;
	int ind=FindStation(Map,name);
	name = to_string(ind) + " " + name;
	while (getline(in, str)) {
		if (str.find(name) != string::npos) {
			cout << "输入变更后的名称" << endl;
			string name_r;
			cin >> name_r;
			if (FindStation(Map,name_r)!=0) {
				cout << "站点存在" << endl;
				out << str << "\n";
			}
			else {
				out << to_string(ind)+" "+name_r << "\n"; //写入变更后名称
				continue;
			}
		}
		out << str << "\n";
	}
	in.close();
	out.close();
	fstream outfile("stations.txt", ios::out);
	fstream infile("temp.txt", ios::in);
	while (getline(infile, str)) {
		outfile << str << "\n"; //写入初始化文件
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	Initial(Map);
	cout << "替换完毕" << endl;
}
void ChangeRouteName(BusMap&Map) { //变更线路
	cout << "输入变更的线路" << endl;
	string name;
	cin >> name;
	if (FindRoute(Map,name) == "0") {
		cout << "线路不存在" << endl;
		return;
	}
	fstream in("routes.txt", ios::in);
	fstream out("temp.txt", ios::out);
	string str;
	while (getline(in, str)) {
		vector<string> tmp;
		tmp = Split(str);
		if (tmp[0]==name) {
			cout << "输入变更后的线路" << endl;
			string name_r;
			cin >> name_r;
			if (FindRoute(Map,name_r)=="0") {
				cout << "线路存在" << endl;
				continue;
			}
			tmp[0] = name_r;
			int i;
			for (i = 0; i < tmp.size()-1;i++) {
				out << tmp[i] << " ";
			}
			out <<tmp[i]<< "\n";
			continue;
		}
		out << str << "\n";
	}
	in.close();
	out.close();
	fstream outfile("routes.txt", ios::out);
	fstream infile("temp.txt", ios::in);
	while (getline(infile, str)) {
		outfile << str << "\n";
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	Initial(Map);
	cout << "替换完毕" << endl;
}
void ChangeRouteTime(BusMap&Map) { //变更线路始发时
	cout << "输入变更的线路" << endl;
	string name;
	cin >> name;
	if (FindRoute(Map, name) == "0") {
		cout << "线路不存在" << endl;
		return;
	}
	fstream in("routes.txt", ios::in);
	fstream out("temp.txt", ios::out);
	string str;
	while (getline(in, str)) {
		vector<string> tmp;
		tmp = Split(str);
		
		if (tmp[0] == name) {
			cout << "变更前始发时:" << tmp[2] << ":" << tmp[3] << endl;
			cout << "输入变更后的始发时" << endl;
			string hour;
			string min;
			cin >> hour >> min;
			if (hour>"24"||hour<"0"||min<"0"||min>"60") {
				cout << "时间错误" << endl;
				continue;
			}
			tmp[2] = hour;
			tmp[3] = min;
			int i;
			for (i = 0; i < tmp.size() - 1; i++) {
				out << tmp[i] << " ";
			}
			out << tmp[i] << "\n";
			continue;
		}
		out << str << "\n";
	}
	in.close();
	out.close();
	fstream outfile("routes.txt", ios::out);
	fstream infile("temp.txt", ios::in);
	while (getline(infile, str)) {
		outfile << str << "\n";
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	Initial(Map);
	cout << "替换完毕" << endl;
}
void ChangeRoutePrice(BusMap&Map) { //变更线路票价
	cout << "输入变更的线路" << endl;
	string name;
	cin >> name;
	if (FindRoute(Map, name) == "0") {
		cout << "线路不存在" << endl;
		return;
	}
	fstream in("routes.txt", ios::in);
	fstream out("temp.txt", ios::out);
	string str;
	while (getline(in, str)) {
		vector<string> tmp;
		tmp = Split(str);
		if (tmp[0] == name) {
			cout << "变更前票价:" << tmp[1] << "元" << endl;
			cout << "输入变更后的票价" << endl;
			string price;
			cin >> price;
			tmp[1] = price;
			int i;
			for (i = 0; i < tmp.size() - 1; i++) {
				out << tmp[i] << " ";
			}
			out << tmp[i] << "\n";
			continue;
		}
		out << str << "\n";
	}
	in.close();
	out.close();
	fstream outfile("routes.txt", ios::out);
	fstream infile("temp.txt", ios::in);
	while (getline(infile, str)) {
		outfile << str << "\n";
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	Initial(Map);
	cout << "替换完毕" << endl;
}
void ChangeRouteDis(BusMap&Map) { //变更线路两站间距
	cout << "输入变更的线路" << endl;
	string name;
	cin >> name;
	if (FindRoute(Map, name) == "0") {
		cout << "线路不存在" << endl;
		return;
	}
	fstream in("routes.txt", ios::in);
	fstream out("temp.txt", ios::out);
	string str;
	while (getline(in, str)) {
		vector<string> tmp;
		tmp = Split(str);
		if (tmp[0] == name) {
			cout << "变更前路程:两站间相距" << tmp[4] << "公里" << endl;
			cout << "输入变更后的间距" << endl;
			string dis;
			cin >> dis;
			tmp[4] = dis;
			int i;
			for (i = 0; i < tmp.size() - 1; i++) {
				out << tmp[i] << " ";
			}
			out << tmp[i] << "\n";
			continue;
		}
		out << str << "\n";
	}
	in.close();
	out.close();
	fstream outfile("routes.txt", ios::out);
	fstream infile("temp.txt", ios::in);
	while (getline(infile, str)) {
		outfile << str << "\n";
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	Initial(Map);
	cout << "替换完毕" << endl;
}
void ChangeLine(BusMap&Map) {
	cout << "输入修改线路编号" << endl;
	string name;
	cin >> name;
	if (FindRoute(Map, name) == "0") {//异常处理
		cout << "线路不存在" << endl;
		return;
	}
	fstream in("routes.txt", ios::in);
	fstream out("temp.txt", ios::out);//新建临时文件
	string str;
	while (getline(in, str)) {
		vector<string> tmp;
		tmp = Split(str);//拆分源文件
		if (tmp[0] == name) {//找到需要修该改的线路
			cout << "修改前线路为:" << " ";//打印修改前线路
			for (int i = 5; i < tmp.size();i++) {
				cout << Map.Stations[atoi(tmp[i].c_str())]->StationName << " ";
			}
			cout << endl<<"输入要修改的站点" << endl;
			string des;
			cin >> des;
			cout << "输入修改后站点" << endl;
			string st;
			cin >> st;
			if (FindStation(Map,st)==0) {//异常处理
				cout << "站点不存在" << endl;
			}
			else {
				for (int i = 5; i < tmp.size();i++) {//替换站点
					if (Map.Stations[atoi(tmp[i].c_str())]->StationName==des) {
						tmp[i] = to_string(FindStation(Map,st)-1);
					}
				}
			}
			int i;
			for (i = 0; i < tmp.size() - 1; i++) {//写入至临时文件
				if (tmp[i]==" ") {
					continue;
				}
				out << tmp[i] << " ";
			}
			out << tmp[i] << "\n";
			continue;
		}
		out << str << "\n";//直接写入
	}
	in.close();
	out.close();
	fstream outfile("routes.txt", ios::out);
	fstream infile("temp.txt", ios::in);
	while (getline(infile, str)) {//从临时文件写入原文件
		outfile << str << "\n";
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	Initial(Map);//重新初始化
	cout << "替换完毕" << endl;
}
void DelLine_Station(BusMap&Map) {
	cout << "输入修改线路编号" << endl;
	string name;
	cin >> name;
	if (FindRoute(Map, name) == "0") {//异常处理
		cout << "线路不存在" << endl;
		return;
	}
	fstream in("routes.txt", ios::in);
	fstream out("temp.txt", ios::out);//临时文件
	string str;
	while (getline(in, str)) {
		vector<string> tmp;
		tmp = Split(str);//拆分
		if (tmp[0] == name) {
			cout << "修改前线路为:" << " ";
			for (int i = 5; i < tmp.size(); i++) {
				cout << Map.Stations[atoi(tmp[i].c_str())]->StationName << " ";
			}
			cout << endl << "输入要删除的站点" << endl;
			string des;
			cin >> des;
			int i;
			for (i = 0; i < tmp.size() - 1; i++) {
				if (Map.Stations[atoi(tmp[i].c_str())]->StationName == des) {
					continue;//不写入站点
				}
				out << tmp[i] << " ";
			}
			out << tmp[i] << "\n";
			continue;
		}
		out << str << "\n";
	}
	in.close();
	out.close();
	fstream outfile("routes.txt", ios::out);
	fstream infile("temp.txt", ios::in);
	while (getline(infile, str)) {//重新写入
		outfile << str << "\n";
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	Initial(Map);
	cout << "删除完毕" << endl;
}
void AddLine_Station(BusMap& Map) {
	cout << "输入修改线路编号" << endl;
	string name;
	cin >> name;
	if (FindRoute(Map, name) == "0") {//异常处理
		cout << "线路不存在" << endl;
		return;
	}
	fstream in("routes.txt", ios::in);
	fstream out("temp.txt", ios::out);//临时文件
	string str;
	while (getline(in, str)) {
		vector<string> tmp;
		tmp = Split(str);//拆分
		if (tmp[0] == name) {
			cout << "修改前线路为:" << " ";
			for (int i = 5; i < tmp.size(); i++) {
				cout << Map.Stations[atoi(tmp[i].c_str())]->StationName << " ";
			}
			cout << endl << "输入要修改的下一站点" << endl;
			string des;
			cin >> des;
			cout << "输入修改后站点" << endl;
			string st;
			cin >> st;
			if (FindStation(Map, st) == 0) {
				cout << "站点不存在" << endl;
			}
			else {
				for (int i = 5; i < tmp.size(); i++) {
					if (Map.Stations[atoi(tmp[i].c_str())]->StationName == des) {
						tmp.insert(tmp.begin()+i,to_string(FindStation(Map, st)-1));//插入站点
						break;
					}
				}
			}
			int i;
			for (i = 0; i < tmp.size() - 1; i++) {
				if (tmp[i] == " ") {
					continue;
				}
				out << tmp[i] << " ";
			}
			out << tmp[i] << "\n";
			continue;
		}
		out << str << "\n";
	}
	in.close();
	out.close();
	fstream outfile("routes.txt", ios::out);
	fstream infile("temp.txt", ios::in);
	while (getline(infile, str)) {//重新写入
		outfile << str << "\n";
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	Initial(Map);
	cout << "替换完毕" << endl;
}
void AddNewLine(BusMap&Map) {
	vector<string> new_line;
	string name;
	label1:cout << "输入新增路线名:" << endl;//输入新线路信息
	cin >> name;
	if (FindRoute(Map,name)!="0") {
		cout << "路线存在" << endl;
		goto label1;
	}
	new_line.push_back(name);
	cout << "输入新增路线票价" << endl;
	string price;
	cin >> price;
	new_line.push_back(price);
	cout << "输入新增路线始发时" << endl;
	string hour, min;
	cin >> hour >> min;
	new_line.push_back(hour);
	new_line.push_back(min);
	cout << "输入新增路线两站间距" << endl;
	string len;
	cin >> len;
	new_line.push_back(len);
	cout << "输入站点数量" << endl;
	int num;
	cin >> num;
	cout << "输入站点" << endl;
	for (int i = 0; i < num;i++) {
		label:string st;
		cin >> st;
		if (FindStation(Map, st)==0) {//异常处理
			cout << "站点不存在,重新输入" << endl;
			goto label;
		}
		else {
			new_line.push_back(to_string(FindStation(Map, st)));
		}
	}
	fstream in("routes.txt", ios::app);//在原文件中写入新线路信息
	in << "\n";
	for (int i = 0; i < new_line.size();i++) {
		in << new_line[i] << " ";
	}
	in.close();
	cout << "增加成功" << endl;
	fstream in1("routes.txt", ios::in);//写入临时文件再写回,防止线路间空行
	fstream out1("temp.txt", ios::out);
	string s;
	while (getline(in1, s)) {
		vector<string> tmp;
		tmp = Split(s);
		if (tmp.size() == 0) {
			continue;
		}
		out1 << s << "\n";//写入tmp文件
	}
	in1.close();
	out1.close();
	fstream outfile("routes.txt", ios::out);
	fstream infile("temp.txt", ios::in);
	string str;
	while (getline(infile, str)) {
		outfile << str << "\n"; //写入初始化文件
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	Initial(Map);//重新初始化
}
void delLine(BusMap& Map) {
	label:cout << "输入要删除的线路" << endl;
	string name;
	cin >> name;
	if (FindRoute(Map,name)=="0") {//异常处理
		cout << "不存在线路" << endl;
		goto label;
	}
	fstream in1("routes.txt", ios::in);
	fstream out1("temp.txt", ios::out);
	string s;
	while (getline(in1, s)) {
		vector<string> tmp;
		tmp = Split(s);
		if (tmp[0] == name) {//不写入删除线路
			continue;
		}
		out1 << s << "\n";//写入tmp文件
	}
	in1.close();
	out1.close();
	fstream outfile("routes.txt", ios::out);
	fstream infile("temp.txt", ios::in);
	string str;
	while (getline(infile, str)) {
		outfile << str << "\n"; //写入初始化文件
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	cout << "删除成功" << endl;
	Initial(Map);//重新初始化
}
void restore(BusMap&Map) { //还原初始化文件
	ifstream f1("save_routes.txt");//备份文件路径
	ifstream f2("save_stations.txt");
	remove("routes.txt");//删除原文件
	remove("stations.txt");
	if (f1.good() && f2.good()) {
		ofstream in1("routes.txt");//创建新初始文件
		ofstream in2("stations.txt");
		if (in1<<f1.rdbuf()&&in2<<f2.rdbuf()) {//复制
			cout << "还原成功" << endl;
			Initial(Map);
		}
		else {
			cout << "还原失败" << endl;
		}
	}
	else {
		cout << "备份文件不存在" << endl;//异常处理
	}
}
void Manage(BusMap& Map) { //管理界面
	int n;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t***********站点管理********************************\n" << endl;
	cout << "\t\t********(1)备份初始化文件**************************\n" << endl;
	cout << "\t\t********(2)还原初始化文件**************************\n" << endl;
	cout << "\t\t********(3)增加站点********************************\n" << endl;
	cout << "\t\t********(4)删除站点********************************\n" << endl;
	cout << "\t\t********(5)修改站点名******************************\n" << endl;
	cout << "\t\t********(6)修改线路名称****************************\n" << endl;
	cout << "\t\t********(7)修改线路始发时**************************\n" << endl;
	cout << "\t\t********(8)修改线路票价****************************\n" << endl;
	cout << "\t\t********(9)修改线路路程****************************\n" << endl;
	cout << "\t\t********(10)修改线路途径站点***********************\n" << endl;
	cout << "\t\t********(11)插入线路途径站点***********************\n" << endl;
	cout << "\t\t********(12)删除线路途径站点***********************\n" << endl;
	cout << "\t\t********(13)建立新路线*****************************\n" << endl;
	cout << "\t\t********(14)删除路线*******************************\n" << endl;
	cout << "\t\t********(15)退出***********************************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
label:cout << "输入操作编号" << endl;
	cin >> n;
	switch (n) {
	case 1:
		copy();
		goto label;
	case 2:
		restore(Map);
		goto label;
	case 3:
		AddStation(Map);
		goto label;
	case 4:
		DelStation(Map);
		goto label;
	case 5:
		ChangeName(Map);
		goto label;
	case 6:
		ChangeRouteName(Map);
		goto label;
	case 7:
		ChangeRouteTime(Map);
		goto label;
	case 8:
		ChangeRoutePrice(Map);
		goto label;
	case 9:
		ChangeRouteDis(Map);
		goto label;
	case 10:
		ChangeLine(Map);
		goto label;
	case 11:
		AddLine_Station(Map);
		goto label;
	case 12:
		DelLine_Station(Map);
		goto label;
	case 13:
		AddNewLine(Map);
		goto label;
	case 14:
		delLine(Map);
		goto label;
	case 15:
		AdmMenu(Map);
		break;
	}
}
void sign(BusMap&Map) { //登录系统
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t***********智能公交查询系统(管理员登录)************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
	string name;
	string code;
	cout << "输入账号(admin):" << endl;
	cin >> name;
	cout << "输入密码(12345):" << endl;
	cin >> code;
	if (find(account.begin(), account.end(), make_pair(name, code)) == account.end()) {
		cout << "账号或密码错误" << endl;
		MainMenu(Map);
	}
	else {
		cout << "登录成功" << endl;
		sign_flag = 1;
		Sleep(1000);
		system("cls"); //清屏
	}
}
void AdmMenu(BusMap& Map) {
	if (sign_flag==0) {
		sign(Map);
	}
	int n;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t***********智能公交查询系统(管理员)****************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t********(1)初始化所有站点**************************\n" << endl;
	cout << "\t\t********(2)站点管理********************************\n" << endl;
	cout << "\t\t********(3)查询某号线所有站点**********************\n" << endl;
	cout << "\t\t********(4)查询经过某站点的所有公交线**************\n" << endl;
	cout << "\t\t********(5)查询两站之间的换乘路径******************\n" << endl;
	cout << "\t\t********(6)查询全部公交线及站点********************\n" << endl;
	cout << "\t\t********(7)查询景区间最短路径(两景点)**************\n" << endl;
	cout << "\t\t********(8)查询景区间最短路径(四景点)**************\n" << endl;
	cout << "\t\t********(9)退出系统********************************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
	label:cout << "输入操作编号" << endl;
	cin >> n;
	switch (n) {
	case 1:
		Initial(Map);
		goto label;
	case 2:
		Manage(Map);
		goto label;
	case 3:
		if (Map.flag == true) {
			print(Map);
		}
		else {
			cout << "先初始化" << endl;
		}
		goto label;
	case 4:
		FindBus(Map);
		goto label;
	case 5:
		if (Map.flag == true) {
			ChangeMenu(Map);
		}
		else {
			cout << "先初始化" << endl;
		}
		goto label;
	case 6:
		if (Map.flag == true) {
			printAll(Map);
		}
		else {
			cout << "先初始化" << endl;
		}
		goto label;
	case 7:
		if (Map.flag == true) {
			BestwayTwo(Map);
		}
		else {
			cout << "先初始化" << endl;
		}
		goto label;
	case 8:
		if (Map.flag == true) {
			BestwayFour(Map);
		}
		else {
			cout << "先初始化" << endl;
		}
		goto label;
	case 9:MainMenu(Map);
	}
}
void UserMenu(BusMap& Map) {
	int n;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t***********智能公交查询系统(用户)******************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t********(1)查询某号线所有站点**********************\n" << endl;
	cout << "\t\t********(2)查询经过某站点的所有公交线**************\n" << endl;
	cout << "\t\t********(3)查询两站之间的换乘路径******************\n" << endl;
	cout << "\t\t********(4)查询全部公交线及站点********************\n" << endl;
	cout << "\t\t********(5)查询景区间最短路径**********************\n" << endl;
	cout << "\t\t********(6)退出系统********************************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
label:	cout << "输入操作编号" << endl;
	cin >> n;
	switch (n) {
	case 1:
		if (Map.flag == true) {
			print(Map);
		}
		else {
			cout << "先初始化" << endl;
		}
		goto label;
	case 2:
		if (Map.flag == true) {
			FindBus(Map);
		}
		else {
			cout << "先初始化" << endl;
		}
		goto label;
	case 3:
		if (Map.flag == true) {
			ChangeMenu(Map);
		}
		else {
			cout << "先初始化" << endl;
		}
		goto label;
	case 4:
		if (Map.flag == true) {
			printAll(Map);
		}
		else {
			cout << "先初始化" << endl;
		}
		goto label;
	case 5:
		if (Map.flag == true) {
			BestwayTwo(Map);
		}
		else {
			cout << "先初始化" << endl;
		}
		goto label;
	case 6:MainMenu(Map);
	}
}
void MainMenu(BusMap& Map) {
	int n;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t***********智能公交查询系统************************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t********(1)管理员模式******************************\n" << endl;
	cout << "\t\t********(2)用户模式********************************\n" << endl;
	cout << "\t\t********(3)退出系统********************************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
label:	cout << "输入操作编号" << endl;
	cin >> n;
	switch (n) {
	case 1:
		AdmMenu(Map);
		goto label;
	case 2:
		cout << "登录成功" << endl;
		Sleep(1000);
		system("cls"); //清屏
		UserMenu(Map);
		goto label;
	case 3:
		cout << "欢迎再次使用" << endl;
		exit(0);
	}
}
int main() {
	BusMap* Map = new BusMap(); //初始化总图
	Map->flag = false;
	account.push_back(make_pair("admin","12345")); //添加账号信息
	MainMenu(*Map); //主界面
	return 0;
}