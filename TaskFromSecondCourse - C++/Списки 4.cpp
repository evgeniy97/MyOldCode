//15.  —оздать и протестировать функцию
//void parseString(const  string &src, vector<set<string>> &dst),
//котора€ сформирует массив множеств строк dst из строки src по следующему правилу :
//dst[i] Ц это множество слов из строки src, заканчивающихс€ одной и той же буквой;
//множества отсортированы в обратном алфавитном пор€дке букв, которыми заканчиваютс€ их слова.
//ѕример: src = Фthis is the malt that lay in the house that jack builtФ = >
//dst = { { УlayФ },{ УbuiltФ, УmaltФ, ФthatФ },{ УisФ, УthisФ },{ ФinФ },{ УjackФ },{ УhouseФ, ФtheФ } }

#include "stdafx.h"
#include "vector"
#include "algorithm"
#include "set"
#include "iostream"
#include "string"

using namespace std;  // “ак как не предполагаетс€ использование чего-либо вылезающего стандартное пространство имен  

void test_auto(string src, int N); // «аданный тест
void test();
string devide(const string &src, size_t &pos); // ƒелим на слова
void print_vector_of_set(vector<set<string>> &dst);
bool sort_function(const set <string> A, const  set<string> B);
int is_there(const string &str, const vector<set<string>> &dst); // ѕровер€ем, есть ли множество, в котором слова заканчиваютс€ на ту же букву, что и слово word
void parseString(const  string &src, vector<set<string>> &dst); // ‘ункци€, которую необходимо реализовать

int main()
{
	test_auto("this is the malt that lay in the house that jack built", 1);
	test_auto("Just different words I have no idea", 2);
	test();
	return 0;
}

void parseString(const  string &src, vector<set<string>> &dst) {
	size_t pos = 0;
	while (pos < src.size()) {
		string word = devide(src, pos);
		int N = is_there(word, dst);
		if (N > -1) { dst[N].insert(word); }
		else dst.push_back({ word });
	}
	sort(dst.begin(), dst.end(), sort_function);
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
	for (size_t i = 0; i < dst.size(); i++) {
		auto it = dst[i].begin();
		if (*(str.end()-1) == *((*it).end()-1)) return i;
	}
	return -1;
} 
void print_vector_of_set(vector<set<string>> &dst) {
	cout << "{";
	for (size_t i = 0; i < dst.size(); i++) {
		cout << "{";
		set <string>::iterator it = dst[i].begin();
		for (size_t j = 0; j < dst[i].size(); j++)
		{
			cout << *it;
			if (j != dst[i].size() - 1) cout << ",";
			it++;
		}
		cout << "}";
		if (i != dst.size() - 1) cout << ",";
	}
	cout << "}" << endl;
}
bool sort_function(const set <string> A, const  set<string> B) {
	return *((*(A.begin())).end()-1) > *((*(B.begin())).end()-1);
}


