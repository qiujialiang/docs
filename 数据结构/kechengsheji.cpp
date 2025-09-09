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
typedef struct Graph { //��·ͼ����
	vector< vector<vector<int>> > arc; //��Ź�������
	int nvex; //�ڵ���
	bool flag;
}graph;
typedef struct Station { //վ�㶨��
	int Stationind; //���
	string StationName; //����
	int Routenum; //
	vector<struct Route*> routes; //������·��
}Station;
typedef struct Bus { //��������
	string name; //����
	Station* start; //ʼ��վ 
	Station* end; //ĩվ
	int price; //Ʊ��
	string startTime; //ʼ��ʱ
	vector<int> line; //��·
	int distance; //��վ���
}Bus;
typedef struct Route { //ÿվ��·
	int des; //Ŀ��
	string indBus; //��������
}Route;
typedef struct BusMap { //��ͼ
	vector<Bus*> Buses; //����
	vector<Station*> Stations; //վ��
	int Bus_num;
	int Station_num;
	bool flag;
}BusMap;
typedef struct Edge {
	int a, b, w,ind;//��� �յ� ���� �±�
}Edge;
vector<pair<string, string>> account; //�˻�
int sign_flag = 0;
void Change(BusMap& Map, Graph& g, int start, int end); //��������
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
int FindStation(BusMap& Map, string name) { //�Ƿ����վ�� ���ر��
	for (int i = 0; i < Map.Station_num; i++) {
		if (Map.Stations[i]->StationName == name) {
			return Map.Stations[i]->Stationind;
		}
	}
	return 0;
}
string FindRoute(BusMap& Map, string name) {//�Ƿ����·�� ����·����
	for (int i = 0; i < Map.Bus_num; i++) {
		if (Map.Buses[i]->name == name) {
			return Map.Buses[i]->name;
		}
	}
	return "0";
}
int FindRoute(BusMap& Map, int ind) {//�Ƿ����·�� ����·�����������±�
	for (int i = 0; i < Map.Bus_num; i++) {
		if (atoi(Map.Buses[i]->name.c_str()) == ind) {
			return i;
		}
	}
	return 0;
}
vector<string> Split(string& line) {//���ո����ı�
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
int AddStations(BusMap& Map, string tmp) {//���վ��
	vector<string> str = Split(tmp);
	if (str.size()>0) {
		string name = str[1];
		string ind = str[0];
		int flag = FindStation(Map, str[1]);
		if (flag > 0) {
			cout << "վ�����,�������" << endl;
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
string AddRoute(BusMap& Map, string tmp) {//���·��
	vector<string> str = Split(tmp);
	int len = str.size();
	int start = atoi(str[4].c_str());
	int end = atoi(str[len - 1].c_str());
	string flag = FindRoute(Map, str[0]);//վ���Ƿ����
	if (flag != "0") {
		cout << "·�ߴ���,�������" << endl;
		return flag;
	}
	else {
		Bus* bus = new Bus();
		bus->name = str[0];//����
		bus->price = atoi(str[1].c_str());//Ʊ��
		bus->startTime = str[2] + ":" + str[3];//ʼ��ʱ
		bus->distance = atoi(str[4].c_str());//����
		bus->start = Map.Stations[start - 1];//���վ���
		bus->end = Map.Stations[end - 1];//�յ�վ���
		for (int i = 5; i < len - 1; i++) {//ѭ�����뾭��վ����
			bus->line.push_back(atoi(str[i].c_str()));
			Route* route = new Route();
			if (i == len - 1) {//�յ�վdes=0
				route->des = 0;
			}
			else {
				route->des = atoi(str[i + 1].c_str());//��·��ÿվ����һվ
			}
			route->indBus = bus->name;
			Map.Stations[atoi(str[i].c_str()) - 1]->Routenum++;//վ���¼��������·��+1
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
void Initial(BusMap& Map) {//��ʼ��
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
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	string stations;
	cout << "����txt�ļ���ʼ��" << endl;
	while (getline(instations, stations)) {
		if (stations=="") {
			continue;
		}
		AddStations(Map, stations);
	}
	ifstream inroute;
	inroute.open("routes.txt");
	if (!inroute.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		exit(0);
	}
	string route;
	cout << "����txt�ļ���ʼ��" << endl;
	while (getline(inroute, route)) {
		if (route=="") {
			continue;
		}
		AddRoute(Map, route);
	}
	instations.close();
	inroute.close();
	cout << "��ʼ�����" << endl;
	Map.flag = true;
}
void PrintStation(BusMap& Map, int j) {//��ӡվ��
	cout << Map.Buses[j]->name << "·����" << endl;
	cout << "Ʊ��" << Map.Buses[j]->price << "Ԫ" << endl;
	cout << "�װ೵ʱ��:" << Map.Buses[j]->startTime << endl;
	for (int i = 0; i < Map.Buses[j]->line.size(); i++) {
		int num = Map.Buses[j]->line[i] - 1;
		cout << Map.Stations[num]->StationName << "--";
	}
}
void print(BusMap& Map) {//��ʾĳ·������վ��
	string s;
	cout << "�����ѯ��·" << endl;
	cin >> s;
	for (int i = 0; i < Map.Bus_num; i++) {
		if (Map.Buses[i]->name == s) {
			PrintStation(Map, i);
			cout << "��ѯ���" << endl;
			return;
		}
	}
	cout << "��ѯʧ��" << endl;
}
void printAll(BusMap& Map) { //��ʾ����վ��
	for (int i = 0; i < Map.Bus_num; i++) {
		PrintStation(Map, i);
		cout << "��ѯ���" << endl;
		if (i == Map.Bus_num - 1) {
			return;
		}
	}
	cout << "��ѯʧ��" << endl;
}
Graph* CreatGraph(BusMap& Map, Graph* g) { //�����ڽӾ������ڻ��� ���·����ѯ
	g->nvex = Map.Station_num; //����������վ����
	g->arc.resize(Map.Station_num, vector<vector<int>>(Map.Station_num, vector<int>(0)));//��ʼ��
	for (int i = 0; i < g->nvex; i++) {
		g->arc[i][i].push_back(0);
		for (int j = 0; j < Map.Stations[i]->Routenum; j++) {
			int ind = atoi(Map.Stations[i]->routes[j]->indBus.c_str());//���湫������
			if (Map.Stations[i]->routes[j]->des == 0) {
				continue;
			}
			g->arc[i][Map.Stations[i]->routes[j]->des - 1].push_back(ind);//����ͼ,����Գ�
			g->arc[Map.Stations[i]->routes[j]->des - 1][i].push_back(ind);
		}
	}
	g->flag = true;
	cout << "��ʼ�����" << endl;
	return g;
}
vector<vector<int>> dfs_zero(Graph& g, vector<int>& visited, vector<vector<int>>& Allway, vector<int>& way, int a, int b, int m, int indpre) { //0�λ���
	way.push_back(m); 
	visited[m] = 1;//վ���ѷ���
	if (b == m) {
		Allway.push_back(way); //����һ������·��
	}
	for (int i = 0; i < g.nvex; i++) {
		if (g.arc[m][i].size() != 0 && visited[i] != 1) {//��վ������·��վ��δ����
			for (int j = 0; j < g.arc[m][i].size(); j++) {
				int ind = g.arc[m][i][j]; //ind ��¼��·����
				if (a == m) {
					way[0] = ind;//��¼������������
					indpre = ind;//indpre��ʾ��һվ�����Ĺ���
				}
				if (ind == indpre && ind == way[0]) { //ͬһ�������� �����ݹ�
					dfs_zero(g, visited, Allway, way, a, b, i, ind);
				}
			}
		}
	}
	way.pop_back(); //����
	visited[m] = 0; //վ��δ����
	return Allway;
}
vector<vector<int>> dfs_one(Graph& g, vector<int>& visited, vector<vector<int>>& Allway, vector<int>& way, int a, int b, int m, int indpre, int count) { //һ�λ���
	way.push_back(m);
	visited[m] = 1;//վ���ѷ���
	int ind = 0;
	if (b == m && count == 2) {//�յ��һ��ɴ���Ϊһ��
		Allway.push_back(way);
	}
	else if (count < 2) {
		for (int i = 0; i < g.nvex; i++) {
			if (g.arc[m][i].size() != 0 && visited[i] != 1) {//��վ������·��վ��δ����
				for (int j = 0; j < g.arc[m][i].size(); j++) {
					ind = g.arc[m][i][j]; //ind ��ʾ��·����
					if (m == a) {//��ʼ��· ����һ�λ���
						way[0] = ind;
						count++;
					}
					else if (ind != indpre && m != a ) { //����·�����ڳ�ʼ��· ����
						way[1] = ind;
						way[2] = m;
						count++;
					}
					dfs_one(g, visited, Allway, way, a, b, i, ind, count);//�ݹ�
					visited[i] = 0;//վ��δ����
					if (ind != indpre) { //���ݻ��˴���
						count--;
					}
				}
			}
		}
	}
	way.pop_back(); //����
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
vector<vector<int>> dfs_more(Graph& g, vector<int>& visited, vector<vector<int>>& Allway, vector<int>& way, int a, int b, int m, int indpre, int count) { //��λ���
	if (b == m && count >= 3) {//���˴�������1
		way.push_back(count);//��������󴢴滻�˴���
		Allway.push_back(way);
		way.pop_back();
		return Allway;
	}
	if (count >= 6) { //��໻��5�� ��ֹ�ݹ��������
		return Allway;
	}
	for (int i = 0; i < g.nvex; i++) {
		if (g.arc[m][i].size() != 0 && visited[i] != 1 && g.arc[m][i][0] != 0) {
			for (int j = 0; j < g.arc[m][i].size(); j++) {
				int ind = g.arc[m][i][j];
				if (m == a) {//��ʼ��·
					way.push_back(ind + 100);
					count++;
				}
				if (ind != indpre && find(way.begin(), way.end(), ind+100) == way.end() && m != a) {
					way.push_back(ind + 100); //����ʱ �����·��+100 ����վ��
					count++;//���˴���+1
				}
				way.push_back(i);
				visited[i] = 1;//վ���ѷ���
				dfs_more(g, visited, Allway, way, a, b, i, ind, count);
				way.pop_back();//����
				if (*(way.end() - 1) > 100) { //���ݻ��˴���
					way.pop_back();
					count--;
				}
			}
		}
	}
	visited[m] = 0; //վ��δ����
	return Allway;
}
bool cmp_change(pair<int,int>&a,pair<int,int>&b) { //�Զ�����ʽ
	return a.first < b.first; //����Ԫ���е�һ��Ԫ��,����������
}
void FindZero_len(BusMap&Map,vector<vector<int>>&Allway) {
		int i = 0;
		vector<pair<int, int>> res; //��Ԫ������ ��¼·�̳��Ⱥ��±�
		for (i = 0; i < Allway.size();i++) {
			int len = Map.Buses[FindRoute(Map, Allway[i][0])]->distance * (Allway[i].size() - 1); //����ÿ����·����
			res.push_back(make_pair(len,i));//���볤�ȼ���Allway���±�
		}
		sort(res.begin(),res.end(),cmp_change);//����������
		for (i = 0; i < res.size(); i++) {//���������±����
			int j = 0;
			int ind = res[i].second;
			int len = Map.Buses[FindRoute(Map, Allway[ind][0])]->distance * (Allway[ind].size() - 1); //������·��
			int price = Map.Buses[FindRoute(Map, Allway[ind][0])]->price; //����Ʊ��
			cout << "��·" << i + 1 << "Ϊ:����" << Allway[ind][0] << "·" <<" " <<"Ʊ��" <<price<<"Ԫ" << endl;//���
			for (j = 1; j < Allway[ind].size() - 1; j++) {
				cout << Map.Stations[Allway[ind][j]]->StationName << "--";
			}
			cout << Map.Stations[Allway[ind][j]]->StationName << endl;
			cout << "��·��Ϊ:" << len << "����" << endl;
			cout << "-----------------------------------" << endl;
		}
		cout << "��ѯ���" << endl;
}
void FindZero_price(BusMap& Map, vector<vector<int>>& Allway) {
	int i = 0;
	vector<pair<int, int>> res;
	for (i = 0; i < Allway.size(); i++) {
		int price = Map.Buses[FindRoute(Map, Allway[i][0])]->price; //Ʊ��
		res.push_back(make_pair(price, i));
	}
	sort(res.begin(), res.end(), cmp_change);
	for (i = 0; i < res.size(); i++) {
		int j = 0;
		int ind = res[i].second;
		int len = Map.Buses[FindRoute(Map, Allway[ind][0])]->distance * (Allway[ind].size() - 1); //������·��
		int price = Map.Buses[FindRoute(Map, Allway[ind][0])]->price; //Ʊ��
		cout << "��·" << i + 1 << "Ϊ:����" << Allway[ind][0] << "·" << " " << "Ʊ��" << price << "Ԫ" << endl;
		for (j = 1; j < Allway[ind].size() - 1; j++) {
			cout << Map.Stations[Allway[ind][j]]->StationName << "--";
		}
		cout << Map.Stations[Allway[ind][j]]->StationName << endl;
		cout << "��·��Ϊ:" << len << "����" << endl;
		cout << "-----------------------------------" << endl;
	}
	cout << "��ѯ���" << endl;
}
void ChangeZero(BusMap& Map, Graph& g, int a, int b) { //����0��
	int m = a;
	int ind = 0;
	vector<int> visited(g.nvex, 0);//������վ��
	vector<vector<int>> Allway; //�������·��
	vector<int> way(1, 0);
	Allway = dfs_zero(g, visited, Allway, way, a - 1, b - 1, m - 1, ind);
	if (Allway.size() == 0) {//�ж�·���Ƿ����
		cout << "�޷�ֱ��" << endl;
	}
	else {
		cout << "����ֱ��,ѡ���ѯ��ʽ:" << endl; //���ò�ͬ������ʽ
		cout << "\t\t********(1)��·������******************\n" << endl;
		cout << "\t\t********(2)��Ʊ������******************\n" << endl;
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
	Change(Map, g, a, b);//������һ����
}
void FindOne_len(BusMap&Map,vector<vector<int>>&Allway) {
	vector<pair<int, int>> res;
	for (int i = 0; i < Allway.size();i++) {
		int dis = Map.Buses[FindRoute(Map, Allway[i][0])]->distance;//�����ܾ���
		int sum_dis = 0;
		for (int j = 3; j < Allway[i].size() - 1; j++) {
			sum_dis += dis;
			if (Allway[i][j] == Allway[i][2]) {
				dis = Map.Buses[FindRoute(Map, Allway[i][1])]->distance;//���˺� ���¾���
				continue;
			}
		}
		res.push_back(make_pair(sum_dis, i));//�����ܾ�����±�
	}
	sort(res.begin(), res.end(), cmp_change);
	int i = 0;
	for (i = 0; i < res.size(); i++) {
		int j = 0;
		int ind = res[i].second;
		int price = Map.Buses[FindRoute(Map, Allway[ind][0])]->price + Map.Buses[FindRoute(Map, Allway[ind][1])]->price; //������·��Ʊ�ۺ�
		cout << "��·" << i + 1 << "Ϊ:����" << Allway[ind][0] << "·" << " " << "Ʊ��" << price << "Ԫ" << endl;
		int dis = Map.Buses[FindRoute(Map, Allway[ind][0])]->distance;
		int sum_dis = 0;
		for (j = 3; j < Allway[ind].size() - 1; j++) {
			cout << Map.Stations[Allway[ind][j]]->StationName << "--";
			sum_dis += dis;
			if (Allway[ind][j] == Allway[ind][2]) {
				cout << "��" << Map.Stations[Allway[ind][j]]->StationName << "վ����" << Allway[ind][1] << "·--";
				dis = Map.Buses[FindRoute(Map, Allway[ind][1])]->distance;//���˺� ����ÿվ������
				continue;
			}
		}
		cout << Map.Stations[Allway[ind][j]]->StationName << endl;
		cout << "��·��Ϊ:" << sum_dis << "����" << endl;
		cout << "-----------------------------------" << endl;
	}
	cout << "��ѯ���" << endl;
}
void FindOne_price(BusMap& Map, vector<vector<int>>& Allway) {
	vector<pair<int, int>> res;
	for (int i = 0; i < Allway.size(); i++) {
		int price = Map.Buses[FindRoute(Map, Allway[i][0])]->price + Map.Buses[FindRoute(Map, Allway[i][1])]->price;//������Ʊ��
		res.push_back(make_pair(price, i));//��¼Ʊ�ۺ��±�
	}
	sort(res.begin(), res.end(), cmp_change);//����
	int i = 0;
	for (i = 0; i < res.size(); i++) {
		int j = 0;
		int ind = res[i].second;
		int price = Map.Buses[FindRoute(Map, Allway[ind][0])]->price + Map.Buses[FindRoute(Map, Allway[ind][1])]->price; //������·��Ʊ�ۺ�
		cout << "��·" << i + 1 << "Ϊ:����" << Allway[ind][0] << "·" << " " << "Ʊ��" << price << "Ԫ" << endl;
		int dis = Map.Buses[FindRoute(Map, Allway[ind][0])]->distance;
		int sum_dis = 0;
		for (j = 3; j < Allway[ind].size() - 1; j++) {
			cout << Map.Stations[Allway[ind][j]]->StationName << "--";
			sum_dis += dis;
			if (Allway[ind][j] == Allway[ind][2]) {
				cout << "��" << Map.Stations[Allway[ind][j]]->StationName << "վ����" << Allway[ind][1] << "·--";
				dis = Map.Buses[FindRoute(Map, Allway[ind][1])]->distance;//���˺� ���¾���
				continue;
			}
		}
		cout << Map.Stations[Allway[ind][j]]->StationName << endl;
		cout << "��·��Ϊ:" << sum_dis << "����" << endl;
		cout << "-----------------------------------" << endl;
	}
	cout << "��ѯ���" << endl;
}
void ChangeOne(BusMap& Map, Graph& g, int a, int b) {
	int m = a;
	int ind = 0;
	int count = 0;//��¼���˴���
	vector<int> visited(g.nvex, 0);
	vector<vector<int>> Allway;
	vector<int> way(3, 0);//�����ǰ����Ԫ�طֱ��¼��ʼʱ������· ��һ�λ�����· ����վ����
	Allway = dfs_one(g, visited, Allway, way, a - 1, b - 1, m - 1, ind, count);
	if (Allway.size() == 0) {
		cout << "�޷�����һ�ε���" << endl;
	}
	else {
		cout << "����ֱ��,ѡ���ѯ��ʽ:" << endl;
		cout << "\t\t********(1)��·������******************\n" << endl;
		cout << "\t\t********(2)��Ʊ������******************\n" << endl;
		int n;
		cin >> n;
		switch (n) {
		case 1:
			FindOne_len(Map, Allway);//·��
			break;
		case 2:
			FindOne_price(Map, Allway);//Ʊ��
			break;
		}
	}
	Change(Map, g, a, b);//����
}
void FindMore_len(BusMap& Map,vector<vector<int>>&Allway,int a) {
	vector<pair<int, int>> res;
	for (int i = 0; i < Allway.size();i++) {
		int dis = Map.Buses[FindRoute(Map, Allway[i][0] - 100)]->distance;//�������
		int sum_dis = 0;
		for (int j = 1; j < Allway[i].size() - 2; j++) {
			if (Allway[i][j] > 100) {//����100˵����¼������·����,����
				dis = Map.Buses[FindRoute(Map, Allway[i][j] - 100)]->distance; //���¾���
				continue;
			}
			sum_dis += dis;//�ܾ���
		}
		res.push_back(make_pair(sum_dis, i));
	}
	sort(res.begin(), res.end(), cmp_change);//����
	int i = 0;
	for (i = 0; i < res.size(); i++) {
		int ind = res[i].second;
		int count = *(Allway[ind].end() - 1);
		int j = 0;
		int price = Map.Buses[FindRoute(Map, Allway[ind][0] - 100)]->price;
		int dis = Map.Buses[FindRoute(Map, Allway[ind][0] - 100)]->distance;
		int sum_dis = 0;
		cout << "��·" << i + 1 << "(����" << count - 1 << "վ)Ϊ:����" << Allway[ind][0] - 100 << "·" << endl;
		cout << Map.Stations[a - 1]->StationName << "--";
		for (j = 1; j < Allway[ind].size() - 2; j++) {
			if (Allway[ind][j] > 100) {
				cout << "��" << Map.Stations[Allway[ind][j - 1]]->StationName << "վ����" << Allway[ind][j] - 100 << "·--";
				price += Map.Buses[FindRoute(Map, Allway[ind][j] - 100)]->price; //����Ʊ��
				dis = Map.Buses[FindRoute(Map, Allway[ind][j] - 100)]->distance; //���¾���
				continue;
			}
			cout << Map.Stations[Allway[ind][j]]->StationName << "--";
			sum_dis += dis;
		}
		cout << Map.Stations[Allway[ind][j]]->StationName << endl << "��·��:" << sum_dis << "����" << endl << "Ʊ��:" << price << "Ԫ" << endl;
		cout << "-----------------------------------" << endl;
	}
	cout << "��ѯ���" << endl;
}
void FindMore_price(BusMap& Map, vector<vector<int>>& Allway, int a) {
	vector<pair<int, int>> res;
	for (int i = 0; i < Allway.size(); i++) {
		int price = Map.Buses[FindRoute(Map, Allway[i][0] - 100)]->price;
		for (int j = 1; j < Allway[i].size() - 2; j++) {
			if (Allway[i][j] > 100) {//����
				price += Map.Buses[FindRoute(Map, Allway[i][j] - 100)]->price; //����Ʊ��
				continue;
			}
		}
		res.push_back(make_pair(price, i));
	}
	sort(res.begin(), res.end(), cmp_change);//����
	int i = 0;
	for (i = 0; i < res.size(); i++) {
		int ind = res[i].second;
		int count = *(Allway[ind].end() - 1);
		int j = 0;
		int price = Map.Buses[FindRoute(Map, Allway[ind][0] - 100)]->price;
		int dis = Map.Buses[FindRoute(Map, Allway[ind][0] - 100)]->distance;
		int sum_dis = 0;
		cout << "��·" << i + 1 << "(����" << count - 1 << "վ)Ϊ:����" << Allway[ind][0] - 100 << "·" << endl;
		cout << Map.Stations[a - 1]->StationName << "--";
		for (j = 1; j < Allway[ind].size() - 2; j++) {
			if (Allway[ind][j] > 100) {
				cout << "��" << Map.Stations[Allway[ind][j - 1]]->StationName << "վ����" << Allway[ind][j] - 100 << "·--";
				price += Map.Buses[FindRoute(Map, Allway[ind][j] - 100)]->price; //����Ʊ��
				dis = Map.Buses[FindRoute(Map, Allway[ind][j] - 100)]->distance; //���¾���
				continue;
			}
			cout << Map.Stations[Allway[ind][j]]->StationName << "--";
			sum_dis += dis;
		}
		cout << Map.Stations[Allway[ind][j]]->StationName << endl << "��·��:" << sum_dis << "����" << endl << "Ʊ��:" << price << "Ԫ" << endl;
		cout << "-----------------------------------" << endl;
	}
	cout << "��ѯ���" << endl;
}
void FindMore_count(BusMap& Map, vector<vector<int>>& Allway, int a) {
	vector<pair<int, int>> res;
	for (int i = 0; i < Allway.size(); i++) {
		int count = *(Allway[i].end() - 1);//���˴���
		res.push_back(make_pair(count, i));
	}
	sort(res.begin(), res.end(), cmp_change);//����
	int i = 0;
	for (i = 0; i < res.size(); i++) {
		int ind = res[i].second;
		int count = *(Allway[ind].end() - 1);
		int j = 0;
		int price = Map.Buses[FindRoute(Map, Allway[ind][0] - 100)]->price;
		int dis = Map.Buses[FindRoute(Map, Allway[ind][0] - 100)]->distance;
		int sum_dis = 0;
		cout << "��·" << i + 1 << "(����" << count - 1 << "վ)Ϊ:����" << Allway[ind][0] - 100 << "·" << endl;
		cout << Map.Stations[a - 1]->StationName << "--";
		for (j = 1; j < Allway[ind].size() - 2; j++) {
			if (Allway[ind][j] > 100) {
				cout << "��" << Map.Stations[Allway[ind][j - 1]]->StationName << "վ����" << Allway[ind][j] - 100 << "·--";
				price += Map.Buses[FindRoute(Map, Allway[ind][j] - 100)]->price; //����Ʊ��
				dis = Map.Buses[FindRoute(Map, Allway[ind][j] - 100)]->distance; //���¾���
				continue;
			}
			cout << Map.Stations[Allway[ind][j]]->StationName << "--";
			sum_dis += dis;
		}
		cout << Map.Stations[Allway[ind][j]]->StationName << endl << "��·��:" << sum_dis << "����" << endl << "Ʊ��:" << price << "Ԫ" << endl;
		cout << "-----------------------------------" << endl;
	}
	cout << "��ѯ���" << endl;
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
		cout << "�޷����˵���" << endl;
	}
	else {
		cout << "����ֱ��,ѡ���ѯ��ʽ:" << endl;
		cout << "\t\t********(1)��·������******************\n" << endl;
		cout << "\t\t********(2)��Ʊ������******************\n" << endl;
		cout << "\t\t********(3)�����˴�������******************\n" << endl;
		int n;
		cin >> n;
		switch (n) {
		case 1:
			FindMore_len(Map, Allway,a);//����
			break;
		case 2:
			FindMore_price(Map, Allway,a);//Ʊ��
			break;
		case 3:
			FindMore_count(Map,Allway,a);//���˴���
			break;
		}
	}
	Change(Map, g, a, b);//����
}
void ChangeMenu(BusMap& Map) {
	int n;
	Graph* g = new Graph();
	g->flag = false;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t***********�������˲�ѯϵͳ************************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t********(1)��ʼ����·ͼ****************************\n" << endl;
	cout << "\t\t********(2)��ѯ��վ֮��Ļ���·��******************\n" << endl;
	cout << "\t\t********(3)�˳�ϵͳ********************************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
label:cout << "����������" << endl;
	cin >> n;
	switch (n) {
	case 1:CreatGraph(Map, g); goto label; //����·��ͼ
	case 2:
		if (g->flag == true) { //�ж�·��ͼ�Ƿ񴴽�
			string m, n;
			cout << "�����ѯ��վ��" << endl;
			cout << "���:";
			cin >> m;
			cout << endl << "�յ�" << endl;
			cin >> n;
			int start = FindStation(Map, m); //�ҵ�����վ����
			int end = FindStation(Map, n);
			if (start == 0 || end == 0) { //վ���������
				cout << "������վ��" << endl;
				goto label;
			}
			Change(Map, *g, start, end); //������һ������
		}
		else {
			cout << "�ȳ�ʼ��" << endl; goto label; //��������
		}
	case 3: //������һ����
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
	cout << "\t\t***********�������˲�ѯϵͳ************************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t********(1)��ѯֱ����·****************************\n" << endl;
	cout << "\t\t********(2)��ѯ����һ����·************************\n" << endl;
	cout << "\t\t********(3)��ѯ���˶����·************************\n" << endl;
	cout << "\t\t********(4)����************************************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
	cout << "����������" << endl;
	cin >> k;
	switch (k) {
	case 1:ChangeZero(Map, g, start, end);
	case 2:ChangeOne(Map, g, start, end);
	case 3:ChangeMore(Map, g, start, end);
	case 4:ChangeMenu(Map);
	}
}
void FindBus(BusMap& Map) { //��ѯ����ĳվ���������·
	string s;
	cout << "�����ѯվ��" << endl;
	cin >> s;
	int m = FindStation(Map, s);
	if (m == 0) {
		cout << "������վ��" << endl;
	}
	else {
		for (int i = 0; i < Map.Stations[m - 1]->Routenum; i++) {
			cout << Map.Stations[m - 1]->routes[i]->indBus << "·" << " ";
		}
		cout <<"��ѯ���" << endl;
	}
}
vector<int> dijkstra_len(BusMap& Map, Graph& g, vector<int>& way, vector<int>& visited, vector<int>& pre, int a, int b, vector<int>dist) { //���·��
	dist.resize(g.nvex, 0);
	dist[a] = 0;
	visited[a] = 1;//վ���ѷ���
	for (int i = 0; i < g.nvex; i++) {
		if (g.arc[a][i].size() != 0 && g.arc[a][i][0] != 0) {
			int min = 65535;
			int k;
			int flag = 0;
			for (k = 0; k < g.arc[a][i].size(); k++) {
				int ind = FindRoute(Map, g.arc[a][i][k]);//·������
				int dis = Map.Buses[ind]->distance; //ѡ����վ������̵���·
				if (min > dis) {//��¼��ѡ·��
					min = dis;
					flag = ind;
				}
			}
			dist[i] = min;
			pre[i] = a;  //�޸�ǰ��
			way[i] = flag; //��¼��վ֮�������·
		}
	}
	int curr = a;
	for (int i = 0; i < g.nvex; i++) {//ѭ�� ��ʣ��վ������·��
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
			if (!visited[k] && g.arc[curr][k].size() != 0 && g.arc[curr][k][0] != 0) {//�������·��
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
	stack<int>input; //ջ 
	while (b != a) { //���յ㵽��� ǰ��ѹ��ջ
		input.push(b);
		b = pre[b];//����ǰ��
	}
	input.push(a);
	vector<int>path;
	while (input.size()) { //��ջ �����path
		path.push_back(way[input.top()]); // 0-���-��·-վ��-��·....-��·-�յ�
		path.push_back(input.top());
		input.pop();
	}
	return path; //����·��
}
void BestwayTwo(BusMap& Map) {
	Graph* g = new Graph();//����·��ͼ
	CreatGraph(Map, g);
	cout << "���뾰������" << endl;
	vector<int> add; //��¼�������澰����
	for (int i = 0; i < 2; i++) {
	label:string s;
		cin >> s;
		int n = FindStation(Map, s);
		if (n == 0) {
			cout << "�����ھ���" << endl;//�쳣����
			goto label;
		}
		add.push_back(n - 1);
	}
	int sum = 0;
	vector<int>path;
	int i = 0;
	int sum_price = 0;
	int s = Map.Station_num;
	cout << "���������·:" << endl;
	for (i = 0; i < add.size()-1; i++) { //�õ������澰�������·��
		vector<int>dist(s, 65535);
		vector<int>visited(s, 0);
		vector<int>pre(s, -1);
		vector<int>way(s, 0);
		path = dijkstra_len(Map, *g, way, visited, pre, add[i], add[i + 1], dist);//�Ͻ�˹�����㷨
		int m;
		int price = Map.Buses[path[2]]->price; //��Ʊ��
		for (m = 1; m <= path.size() - 2; m += 2) {//���·��
			cout << Map.Stations[path[m]]->StationName << "---" << Map.Buses[path[m + 1]]->name << "·" << "---";
			if (strcmp(Map.Buses[path[m + 1]]->name.c_str(), Map.Buses[path[m - 1]]->name.c_str())&&m!=1) { //���˸���Ʊ��
				price += Map.Buses[path[m + 1]]->price;
			}
			sum += Map.Buses[path[m + 1]]->distance; //���¾���
		}
		sum_price += price;
	}
	cout << Map.Stations[*(path.end() - 1)]->StationName << endl << "��·��:" << sum << "����" << " "<<"Ʊ��:" <<sum_price<<"Ԫ" << endl;
	cout << "��ѯ���" << endl;
}
vector<vector<int>> BF_len(BusMap&Map,vector<vector<int>>&Allway,Graph&g,vector<int>&add,int a,int b) {
	int start = add[a];//��ȡ�����
	int final = add[b];//�յ���
	int sum = 0;
	vector<int>path;
	int s = Map.Station_num;
	vector<int>dist(s, 65535);
	vector<int>visited(s, 0);
	vector<int>pre(s, -1);
	vector<int>way(s, 0);
	path=dijkstra_len(Map, g, way, visited, pre, start, final, dist);//�����·��
	path.push_back(a);//�������д��������յ�
	path.push_back(b);
	Allway.push_back(path);//��·�ߴ���Allway
	return Allway;
}
bool cmp(Edge& a,Edge& b) {
	return a.w < b.w;//�Ƚ������ߵĳ���
}
int findfather(vector<int>&father,int x) {//�ж��Ƿ��γɻ�·
	if (x==father[x]) {
		return x;
	}
	int temp = findfather(father,father[x]);
	return temp;
}
void BestwayFour(BusMap&Map) {
	Graph* g = new Graph();//��ʼ����·ͼ
	CreatGraph(Map, g);
	cout << "���뾰������" << endl;
	vector<int> add; //��¼�������澰����
	for (int i = 0; i < 4; i++) {
	label:string s;
		cin >> s;
		int n = FindStation(Map, s);//�쳣����
		if (n == 0) {
			cout << "�����ھ���" << endl;
			goto label;
		}
		add.push_back(n - 1);
	}
	vector<vector<int>> Allway;
	BF_len(Map, Allway, *g, add,0, 1);//���λ�ȡ�������������·��
	BF_len(Map, Allway, *g, add,0, 2);
	BF_len(Map, Allway, *g, add,0, 3);
	BF_len(Map, Allway, *g, add,1, 2);
	BF_len(Map, Allway, *g, add,1, 3);
	BF_len(Map, Allway, *g, add, 2, 3);
	vector<Edge> edges;//�߽ṹ��
	int i;
	for (i = 0; i < Allway.size();i++) {
		int sum = 0;
		int j;
		for (j = 1; j < Allway[i].size()-4;j+=2) {
			sum+= Map.Buses[Allway[i][j+1]]->distance;//����·��
		}
		edges.push_back({ Allway[i][j+1],Allway[i][j + 2],sum,i });//������� �յ� ·�� �±�
	}
	sort(edges.begin(),edges.end(),cmp);//����
	vector<int>father(4);//��������
	vector<int>res;
	int sum_len = 0;
	for (int i = 0; i < 4;i++) {//���������ʼ��
		father[i] = i;
	}
	for (int i = 0; i < edges.size();i++) {
		int fa = findfather(father, edges[i].a);//���
		int fb = findfather(father,edges[i].b);//�յ�
		if (fa!=fb) {//δ�γɻ�·
			int ind = edges[i].ind;//�������������
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
	cout << "�������·��:" << endl;
	for (i = 0; i < res.size(); i+=2) { //�ֱ�õ�ÿ�����澰�������·��
		vector<int>dist(n, 65535);
		vector<int>visited(n, 0);
		vector<int>pre(n, -1);
		vector<int>way(n, 0);
		path = dijkstra_len(Map, *g, way, visited, pre, add[res[i]], add[res[i + 1]], dist);
		int m;
		int price = Map.Buses[path[2]]->price; //��Ʊ��
		for (m = 1; m <= path.size() - 2; m += 2) {
			cout << Map.Stations[path[m]]->StationName << "---" << Map.Buses[path[m + 1]]->name << "·" << "---";
			if (strcmp(Map.Buses[path[m + 1]]->name.c_str(), Map.Buses[path[m - 1]]->name.c_str()) && m != 1) { //���˸���Ʊ��
				price += Map.Buses[path[m + 1]]->price;
			}
		}
		sum_price += price;
	}
	cout << Map.Stations[*(path.end() - 1)]->StationName << endl << "��·��:" << sum_len << "����" << " " << "Ʊ��:" << sum_price << "Ԫ" << endl;
	cout << "��ѯ���" << endl;
}
void copy() { //���ݳ�ʼ���ļ�
	ofstream out1("save_routes.txt");//������·�����ļ�
	ifstream in1("routes.txt");	
	ofstream out2("save_stations.txt");//����վ�㱸���ļ�
	ifstream in2("stations.txt");
	if (out2 << in2.rdbuf()&&out1 << in1.rdbuf()) {//����
		cout << "���Ƴɹ�" << endl;
	}
	else {
		cout << "����ʧ��" << endl;
	}
}
void AddStation(BusMap&Map) { //�����վ��
	cout << "��������վ����" << endl;
	string name;
	string str;
	cin >> name;
	if (FindStation(Map,name)!=0) {
		cout << "վ�����" << endl;
	}
	else {
		fstream in("stations.txt",ios::app);
		int count=++Map.Station_num; //��վ����=����վ������+1
		in <<"\n"<<count << ' ' << name << endl;//д���ļ�
		in.close();
		cout << "���ӳɹ�" << endl;
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
		out << s << "\n";//д��tmp�ļ�
	}
	in.close();
	out.close();
	fstream outfile("stations.txt", ios::out);
	fstream infile("temp.txt", ios::in);
	while (getline(infile, str)) {
		outfile << str << "\n"; //д���ʼ���ļ�
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	Initial(Map);//���³�ʼ��
}
void DelStation(BusMap&Map) { //ɾ��վ��
	string name;
	cout << "����ɾ��վ������" << endl;
	cin >> name;
	fstream in("stations.txt",ios::in);
	fstream out("temp.txt",ios::out);
	string str;
	while (getline(in,str)) { //���ļ���Ѱ�Ҵ�ɾ��վ��
		vector<string> tmp;
		tmp = Split(str);
		if (tmp.size()==0) {
			continue;
		}
		if (tmp[1]==name) {
			continue;
		}
		out << str << "\n";//д��tmp�ļ�
	}
	in.close();
	out.close();
	fstream outfile("stations.txt",ios::out);
	fstream infile("temp.txt",ios::in);
	while (getline(infile,str)) {
		outfile << str << "\n"; //д���ʼ���ļ�
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	Initial(Map);//���³�ʼ��
	cout << "ɾ�����" << endl;
}
void ChangeName(BusMap&Map) { //���վ������
	cout << "������վ�������" << endl;
	string name;
	cin >> name;
	if (FindStation(Map,name)==0) {//�Ƿ���ڸ�վ��
		cout << "վ�㲻����" << endl;
		return;
	}
	fstream in("stations.txt", ios::in);
	fstream out("temp.txt", ios::out);//�½���ʱ�ļ�
	string str;
	int ind=FindStation(Map,name);
	name = to_string(ind) + " " + name;
	while (getline(in, str)) {
		if (str.find(name) != string::npos) {
			cout << "�������������" << endl;
			string name_r;
			cin >> name_r;
			if (FindStation(Map,name_r)!=0) {
				cout << "վ�����" << endl;
				out << str << "\n";
			}
			else {
				out << to_string(ind)+" "+name_r << "\n"; //д����������
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
		outfile << str << "\n"; //д���ʼ���ļ�
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	Initial(Map);
	cout << "�滻���" << endl;
}
void ChangeRouteName(BusMap&Map) { //�����·
	cout << "����������·" << endl;
	string name;
	cin >> name;
	if (FindRoute(Map,name) == "0") {
		cout << "��·������" << endl;
		return;
	}
	fstream in("routes.txt", ios::in);
	fstream out("temp.txt", ios::out);
	string str;
	while (getline(in, str)) {
		vector<string> tmp;
		tmp = Split(str);
		if (tmp[0]==name) {
			cout << "�����������·" << endl;
			string name_r;
			cin >> name_r;
			if (FindRoute(Map,name_r)=="0") {
				cout << "��·����" << endl;
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
	cout << "�滻���" << endl;
}
void ChangeRouteTime(BusMap&Map) { //�����·ʼ��ʱ
	cout << "����������·" << endl;
	string name;
	cin >> name;
	if (FindRoute(Map, name) == "0") {
		cout << "��·������" << endl;
		return;
	}
	fstream in("routes.txt", ios::in);
	fstream out("temp.txt", ios::out);
	string str;
	while (getline(in, str)) {
		vector<string> tmp;
		tmp = Split(str);
		
		if (tmp[0] == name) {
			cout << "���ǰʼ��ʱ:" << tmp[2] << ":" << tmp[3] << endl;
			cout << "���������ʼ��ʱ" << endl;
			string hour;
			string min;
			cin >> hour >> min;
			if (hour>"24"||hour<"0"||min<"0"||min>"60") {
				cout << "ʱ�����" << endl;
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
	cout << "�滻���" << endl;
}
void ChangeRoutePrice(BusMap&Map) { //�����·Ʊ��
	cout << "����������·" << endl;
	string name;
	cin >> name;
	if (FindRoute(Map, name) == "0") {
		cout << "��·������" << endl;
		return;
	}
	fstream in("routes.txt", ios::in);
	fstream out("temp.txt", ios::out);
	string str;
	while (getline(in, str)) {
		vector<string> tmp;
		tmp = Split(str);
		if (tmp[0] == name) {
			cout << "���ǰƱ��:" << tmp[1] << "Ԫ" << endl;
			cout << "���������Ʊ��" << endl;
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
	cout << "�滻���" << endl;
}
void ChangeRouteDis(BusMap&Map) { //�����·��վ���
	cout << "����������·" << endl;
	string name;
	cin >> name;
	if (FindRoute(Map, name) == "0") {
		cout << "��·������" << endl;
		return;
	}
	fstream in("routes.txt", ios::in);
	fstream out("temp.txt", ios::out);
	string str;
	while (getline(in, str)) {
		vector<string> tmp;
		tmp = Split(str);
		if (tmp[0] == name) {
			cout << "���ǰ·��:��վ�����" << tmp[4] << "����" << endl;
			cout << "��������ļ��" << endl;
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
	cout << "�滻���" << endl;
}
void ChangeLine(BusMap&Map) {
	cout << "�����޸���·���" << endl;
	string name;
	cin >> name;
	if (FindRoute(Map, name) == "0") {//�쳣����
		cout << "��·������" << endl;
		return;
	}
	fstream in("routes.txt", ios::in);
	fstream out("temp.txt", ios::out);//�½���ʱ�ļ�
	string str;
	while (getline(in, str)) {
		vector<string> tmp;
		tmp = Split(str);//���Դ�ļ�
		if (tmp[0] == name) {//�ҵ���Ҫ�޸øĵ���·
			cout << "�޸�ǰ��·Ϊ:" << " ";//��ӡ�޸�ǰ��·
			for (int i = 5; i < tmp.size();i++) {
				cout << Map.Stations[atoi(tmp[i].c_str())]->StationName << " ";
			}
			cout << endl<<"����Ҫ�޸ĵ�վ��" << endl;
			string des;
			cin >> des;
			cout << "�����޸ĺ�վ��" << endl;
			string st;
			cin >> st;
			if (FindStation(Map,st)==0) {//�쳣����
				cout << "վ�㲻����" << endl;
			}
			else {
				for (int i = 5; i < tmp.size();i++) {//�滻վ��
					if (Map.Stations[atoi(tmp[i].c_str())]->StationName==des) {
						tmp[i] = to_string(FindStation(Map,st)-1);
					}
				}
			}
			int i;
			for (i = 0; i < tmp.size() - 1; i++) {//д������ʱ�ļ�
				if (tmp[i]==" ") {
					continue;
				}
				out << tmp[i] << " ";
			}
			out << tmp[i] << "\n";
			continue;
		}
		out << str << "\n";//ֱ��д��
	}
	in.close();
	out.close();
	fstream outfile("routes.txt", ios::out);
	fstream infile("temp.txt", ios::in);
	while (getline(infile, str)) {//����ʱ�ļ�д��ԭ�ļ�
		outfile << str << "\n";
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	Initial(Map);//���³�ʼ��
	cout << "�滻���" << endl;
}
void DelLine_Station(BusMap&Map) {
	cout << "�����޸���·���" << endl;
	string name;
	cin >> name;
	if (FindRoute(Map, name) == "0") {//�쳣����
		cout << "��·������" << endl;
		return;
	}
	fstream in("routes.txt", ios::in);
	fstream out("temp.txt", ios::out);//��ʱ�ļ�
	string str;
	while (getline(in, str)) {
		vector<string> tmp;
		tmp = Split(str);//���
		if (tmp[0] == name) {
			cout << "�޸�ǰ��·Ϊ:" << " ";
			for (int i = 5; i < tmp.size(); i++) {
				cout << Map.Stations[atoi(tmp[i].c_str())]->StationName << " ";
			}
			cout << endl << "����Ҫɾ����վ��" << endl;
			string des;
			cin >> des;
			int i;
			for (i = 0; i < tmp.size() - 1; i++) {
				if (Map.Stations[atoi(tmp[i].c_str())]->StationName == des) {
					continue;//��д��վ��
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
	while (getline(infile, str)) {//����д��
		outfile << str << "\n";
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	Initial(Map);
	cout << "ɾ�����" << endl;
}
void AddLine_Station(BusMap& Map) {
	cout << "�����޸���·���" << endl;
	string name;
	cin >> name;
	if (FindRoute(Map, name) == "0") {//�쳣����
		cout << "��·������" << endl;
		return;
	}
	fstream in("routes.txt", ios::in);
	fstream out("temp.txt", ios::out);//��ʱ�ļ�
	string str;
	while (getline(in, str)) {
		vector<string> tmp;
		tmp = Split(str);//���
		if (tmp[0] == name) {
			cout << "�޸�ǰ��·Ϊ:" << " ";
			for (int i = 5; i < tmp.size(); i++) {
				cout << Map.Stations[atoi(tmp[i].c_str())]->StationName << " ";
			}
			cout << endl << "����Ҫ�޸ĵ���һվ��" << endl;
			string des;
			cin >> des;
			cout << "�����޸ĺ�վ��" << endl;
			string st;
			cin >> st;
			if (FindStation(Map, st) == 0) {
				cout << "վ�㲻����" << endl;
			}
			else {
				for (int i = 5; i < tmp.size(); i++) {
					if (Map.Stations[atoi(tmp[i].c_str())]->StationName == des) {
						tmp.insert(tmp.begin()+i,to_string(FindStation(Map, st)-1));//����վ��
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
	while (getline(infile, str)) {//����д��
		outfile << str << "\n";
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	Initial(Map);
	cout << "�滻���" << endl;
}
void AddNewLine(BusMap&Map) {
	vector<string> new_line;
	string name;
	label1:cout << "��������·����:" << endl;//��������·��Ϣ
	cin >> name;
	if (FindRoute(Map,name)!="0") {
		cout << "·�ߴ���" << endl;
		goto label1;
	}
	new_line.push_back(name);
	cout << "��������·��Ʊ��" << endl;
	string price;
	cin >> price;
	new_line.push_back(price);
	cout << "��������·��ʼ��ʱ" << endl;
	string hour, min;
	cin >> hour >> min;
	new_line.push_back(hour);
	new_line.push_back(min);
	cout << "��������·����վ���" << endl;
	string len;
	cin >> len;
	new_line.push_back(len);
	cout << "����վ������" << endl;
	int num;
	cin >> num;
	cout << "����վ��" << endl;
	for (int i = 0; i < num;i++) {
		label:string st;
		cin >> st;
		if (FindStation(Map, st)==0) {//�쳣����
			cout << "վ�㲻����,��������" << endl;
			goto label;
		}
		else {
			new_line.push_back(to_string(FindStation(Map, st)));
		}
	}
	fstream in("routes.txt", ios::app);//��ԭ�ļ���д������·��Ϣ
	in << "\n";
	for (int i = 0; i < new_line.size();i++) {
		in << new_line[i] << " ";
	}
	in.close();
	cout << "���ӳɹ�" << endl;
	fstream in1("routes.txt", ios::in);//д����ʱ�ļ���д��,��ֹ��·�����
	fstream out1("temp.txt", ios::out);
	string s;
	while (getline(in1, s)) {
		vector<string> tmp;
		tmp = Split(s);
		if (tmp.size() == 0) {
			continue;
		}
		out1 << s << "\n";//д��tmp�ļ�
	}
	in1.close();
	out1.close();
	fstream outfile("routes.txt", ios::out);
	fstream infile("temp.txt", ios::in);
	string str;
	while (getline(infile, str)) {
		outfile << str << "\n"; //д���ʼ���ļ�
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	Initial(Map);//���³�ʼ��
}
void delLine(BusMap& Map) {
	label:cout << "����Ҫɾ������·" << endl;
	string name;
	cin >> name;
	if (FindRoute(Map,name)=="0") {//�쳣����
		cout << "��������·" << endl;
		goto label;
	}
	fstream in1("routes.txt", ios::in);
	fstream out1("temp.txt", ios::out);
	string s;
	while (getline(in1, s)) {
		vector<string> tmp;
		tmp = Split(s);
		if (tmp[0] == name) {//��д��ɾ����·
			continue;
		}
		out1 << s << "\n";//д��tmp�ļ�
	}
	in1.close();
	out1.close();
	fstream outfile("routes.txt", ios::out);
	fstream infile("temp.txt", ios::in);
	string str;
	while (getline(infile, str)) {
		outfile << str << "\n"; //д���ʼ���ļ�
	}
	remove("temp.txt");
	outfile.close();
	infile.close();
	cout << "ɾ���ɹ�" << endl;
	Initial(Map);//���³�ʼ��
}
void restore(BusMap&Map) { //��ԭ��ʼ���ļ�
	ifstream f1("save_routes.txt");//�����ļ�·��
	ifstream f2("save_stations.txt");
	remove("routes.txt");//ɾ��ԭ�ļ�
	remove("stations.txt");
	if (f1.good() && f2.good()) {
		ofstream in1("routes.txt");//�����³�ʼ�ļ�
		ofstream in2("stations.txt");
		if (in1<<f1.rdbuf()&&in2<<f2.rdbuf()) {//����
			cout << "��ԭ�ɹ�" << endl;
			Initial(Map);
		}
		else {
			cout << "��ԭʧ��" << endl;
		}
	}
	else {
		cout << "�����ļ�������" << endl;//�쳣����
	}
}
void Manage(BusMap& Map) { //�������
	int n;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t***********վ�����********************************\n" << endl;
	cout << "\t\t********(1)���ݳ�ʼ���ļ�**************************\n" << endl;
	cout << "\t\t********(2)��ԭ��ʼ���ļ�**************************\n" << endl;
	cout << "\t\t********(3)����վ��********************************\n" << endl;
	cout << "\t\t********(4)ɾ��վ��********************************\n" << endl;
	cout << "\t\t********(5)�޸�վ����******************************\n" << endl;
	cout << "\t\t********(6)�޸���·����****************************\n" << endl;
	cout << "\t\t********(7)�޸���·ʼ��ʱ**************************\n" << endl;
	cout << "\t\t********(8)�޸���·Ʊ��****************************\n" << endl;
	cout << "\t\t********(9)�޸���··��****************************\n" << endl;
	cout << "\t\t********(10)�޸���·;��վ��***********************\n" << endl;
	cout << "\t\t********(11)������·;��վ��***********************\n" << endl;
	cout << "\t\t********(12)ɾ����·;��վ��***********************\n" << endl;
	cout << "\t\t********(13)������·��*****************************\n" << endl;
	cout << "\t\t********(14)ɾ��·��*******************************\n" << endl;
	cout << "\t\t********(15)�˳�***********************************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
label:cout << "����������" << endl;
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
void sign(BusMap&Map) { //��¼ϵͳ
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t***********���ܹ�����ѯϵͳ(����Ա��¼)************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
	string name;
	string code;
	cout << "�����˺�(admin):" << endl;
	cin >> name;
	cout << "��������(12345):" << endl;
	cin >> code;
	if (find(account.begin(), account.end(), make_pair(name, code)) == account.end()) {
		cout << "�˺Ż��������" << endl;
		MainMenu(Map);
	}
	else {
		cout << "��¼�ɹ�" << endl;
		sign_flag = 1;
		Sleep(1000);
		system("cls"); //����
	}
}
void AdmMenu(BusMap& Map) {
	if (sign_flag==0) {
		sign(Map);
	}
	int n;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t***********���ܹ�����ѯϵͳ(����Ա)****************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t********(1)��ʼ������վ��**************************\n" << endl;
	cout << "\t\t********(2)վ�����********************************\n" << endl;
	cout << "\t\t********(3)��ѯĳ��������վ��**********************\n" << endl;
	cout << "\t\t********(4)��ѯ����ĳվ������й�����**************\n" << endl;
	cout << "\t\t********(5)��ѯ��վ֮��Ļ���·��******************\n" << endl;
	cout << "\t\t********(6)��ѯȫ�������߼�վ��********************\n" << endl;
	cout << "\t\t********(7)��ѯ���������·��(������)**************\n" << endl;
	cout << "\t\t********(8)��ѯ���������·��(�ľ���)**************\n" << endl;
	cout << "\t\t********(9)�˳�ϵͳ********************************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
	label:cout << "����������" << endl;
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
			cout << "�ȳ�ʼ��" << endl;
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
			cout << "�ȳ�ʼ��" << endl;
		}
		goto label;
	case 6:
		if (Map.flag == true) {
			printAll(Map);
		}
		else {
			cout << "�ȳ�ʼ��" << endl;
		}
		goto label;
	case 7:
		if (Map.flag == true) {
			BestwayTwo(Map);
		}
		else {
			cout << "�ȳ�ʼ��" << endl;
		}
		goto label;
	case 8:
		if (Map.flag == true) {
			BestwayFour(Map);
		}
		else {
			cout << "�ȳ�ʼ��" << endl;
		}
		goto label;
	case 9:MainMenu(Map);
	}
}
void UserMenu(BusMap& Map) {
	int n;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t***********���ܹ�����ѯϵͳ(�û�)******************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t********(1)��ѯĳ��������վ��**********************\n" << endl;
	cout << "\t\t********(2)��ѯ����ĳվ������й�����**************\n" << endl;
	cout << "\t\t********(3)��ѯ��վ֮��Ļ���·��******************\n" << endl;
	cout << "\t\t********(4)��ѯȫ�������߼�վ��********************\n" << endl;
	cout << "\t\t********(5)��ѯ���������·��**********************\n" << endl;
	cout << "\t\t********(6)�˳�ϵͳ********************************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
label:	cout << "����������" << endl;
	cin >> n;
	switch (n) {
	case 1:
		if (Map.flag == true) {
			print(Map);
		}
		else {
			cout << "�ȳ�ʼ��" << endl;
		}
		goto label;
	case 2:
		if (Map.flag == true) {
			FindBus(Map);
		}
		else {
			cout << "�ȳ�ʼ��" << endl;
		}
		goto label;
	case 3:
		if (Map.flag == true) {
			ChangeMenu(Map);
		}
		else {
			cout << "�ȳ�ʼ��" << endl;
		}
		goto label;
	case 4:
		if (Map.flag == true) {
			printAll(Map);
		}
		else {
			cout << "�ȳ�ʼ��" << endl;
		}
		goto label;
	case 5:
		if (Map.flag == true) {
			BestwayTwo(Map);
		}
		else {
			cout << "�ȳ�ʼ��" << endl;
		}
		goto label;
	case 6:MainMenu(Map);
	}
}
void MainMenu(BusMap& Map) {
	int n;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t***********���ܹ�����ѯϵͳ************************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
	cout << "\t\t********(1)����Աģʽ******************************\n" << endl;
	cout << "\t\t********(2)�û�ģʽ********************************\n" << endl;
	cout << "\t\t********(3)�˳�ϵͳ********************************\n" << endl;
	cout << "\t\t***************************************************\n" << endl;
label:	cout << "����������" << endl;
	cin >> n;
	switch (n) {
	case 1:
		AdmMenu(Map);
		goto label;
	case 2:
		cout << "��¼�ɹ�" << endl;
		Sleep(1000);
		system("cls"); //����
		UserMenu(Map);
		goto label;
	case 3:
		cout << "��ӭ�ٴ�ʹ��" << endl;
		exit(0);
	}
}
int main() {
	BusMap* Map = new BusMap(); //��ʼ����ͼ
	Map->flag = false;
	account.push_back(make_pair("admin","12345")); //����˺���Ϣ
	MainMenu(*Map); //������
	return 0;
}