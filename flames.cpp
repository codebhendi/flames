#include <iostream>
#include <algorithm>

using namespace std;

string status(char x) {
	string rel;

	switch(x) {
		case 'F': rel = "Friendship";
				  break;

		case 'L': rel = "Love";
				  break;

		case 'A': rel = "Affair";
				  break;

		case 'M': rel = "Marriage";
				  break;

		case 'E': rel = "Enmity";
				  break;

		case 'S': rel = "Sex";
				  break;
	}

	return rel;
}

void generateFlames(int ctr) {
	string s = "FLAMES";

	for (int i = 6, j = 1; i > 1; i--, j++) {
		int temp = ctr % i;
		
		cout << endl << "Iteration[" << j << "] : " << s; 
		
		if (temp == 0) {
			temp = i;
		}

		s.erase(remove(s.begin(), s.end(), s.at(temp - 1)), s.end());
		string s1 = s.substr(temp - 1, s.length() - temp + 1);
		string s2 = s.substr(0, temp - 1);
		s = s1 + s2;
	}

	cout << endl << "Iteration[6] : " << s << endl;

	cout << endl << "Relationship : " << status(s[0]) << endl;

	return ;
}

void removeCommon(string name[]) {
	for (string::iterator i = name[0].begin(); i != name[0].end(); i++) {
		for (string::iterator j = name[1].begin(); j != name[1].end(); j++) {
			if (*i == *j) {
				*i = '*';
				*j = '*';
				break;
			}
		}
	}

	string x = name[0] + name[1];
	x.erase(remove(x.begin(), x.end(), '*'), x.end());

	int ctr = x.length();
	
	generateFlames(ctr);

	return ;
} 

void inputProcess() {
	string name[2];

	for (int i = 0; i < 2; i++) {
		cout << "Enter name[" << (i + 1) << "] : ";
		getline(cin, name[i]);
	
		name[i].erase(remove(name[i].begin(), name[i].end(), ' '), name[i].end());
		name[i].erase(remove(name[i].begin(), name[i].end(), '-'), name[i].end());
		name[i].erase(remove(name[i].begin(), name[i].end(), '\''), name[i].end());		
	
		transform(name[i].begin(), name[i].end(), name[i].begin(), ::tolower);
	}

	removeCommon(name);

	return ;
}

int main()
{
	inputProcess();

	return 0;
}
