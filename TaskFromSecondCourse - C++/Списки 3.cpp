//7.     ������� � �������������� �������
//void parseString(const  string &src, vector<set<string>> &dst),
//������� ���������� ������ �������� ����� dst �� ������ src �� ���������� ������� : 
//dst[i] � ��� ��������� ���� ���������� ����� �� ������ src; ��������� ������������� �� �������� ����� ���� �� ������� ��� �������.
//������: src = �the quick brown fox jumps over the lazy dog� = >
//	dst = { { �quick�, �brown�, �jumps� } ,{ �over�, �lazy� },{ �the�, �fox�, �dog } }

#include "stdafx.h"
#include "vector"
#include "algorithm"
#include "set"
#include "iostream"
#include "string"

using namespace std;  // ��� ��� �� �������������� ������������� ����-���� ����������� ����������� ������������ ����  

void test_auto(string src, int N); // �������� ����
void test();
string devide(const string &src, size_t &pos); // ����� �� �����
void print_vector_of_set(vector<set<string>> &dst);
bool sort_function(const set <string> A,const  set<string> B);
int is_there(const string &str, const vector<set<string>> &dst); // ���������, ���� �� ��������� ������ ����� ����� word � dst
void parseString(const  string &src, vector<set<string>> &dst); // �������, ������� ���������� �����������

int main()
{
	test_auto("the quick brown fox jumps over the lazy dog",1);
	test_auto("I love MIEM so much",2);
	test();
	return 0;
}
void parseString(const  string &src, vector<set<string>> &dst) {
	size_t pos = 0;
	while (pos < src.size()) {
		string word = devide(src, pos);
		int N = is_there(word, dst);
		if (N > -1) { dst[N].insert(word); }
		else dst.push_back({word});
	}
	sort(dst.begin(),dst.end(),sort_function);
	print_vector_of_set(dst);
}
void test_auto(const string  src, int N) {
	cout << "Test#" << N << endl << "Your line:" << endl << src << endl;
	vector<set<string>> dst;
	parseString(src, dst);
}
void test() {
	cout << "Test#" << endl << "Enter your line without punctuation marks:" << endl;
	string src;
	getline(cin, src);
	vector<set<string>> dst;
	parseString(src, dst);
}
string devide(const string &src, size_t &pos) {
	string word;
	while ((src[pos] != ' ') && (src[pos] != '\0')) {
		word.push_back(src[pos]);
		pos++;
	}
	pos++;
	return word;
}
int is_there(const string &str, const vector<set<string>> &dst) {
	int N = -1;
	for (size_t i = 0; i < dst.size(); i++) {
		auto it = dst[i].begin();
		string sit = *it;
		if (str.size() == sit.size()) return i;
	}
	return N;
}
void print_vector_of_set(vector<set<string>> &dst) {
	cout << "{";
	for (size_t i = 0; i < dst.size(); i++) {
		cout << "{";
		set <string>::iterator it = dst[i].begin();
		for (size_t j = 0; j < dst[i].size(); j++)
		{
			cout << *it;
			if (j != dst[i].size()- 1) cout << ",";
			it++;
		}
		cout << "}";
		if (i != dst.size() - 1) cout << ",";
	}
	cout << "}" << endl;
}
bool sort_function(const set <string> A,const  set<string> B) {
	return (*(A.begin())).size() > (*(B.begin())).size();
}