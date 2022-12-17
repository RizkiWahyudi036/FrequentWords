#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <fstream>

using namespace std;

int main() {
  ifstream file("dict.txt");

  // mengecek file
  if (!file.is_open()) {
    cerr << "File Tidak Ada" << endl;
    return 1;
  }

  string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

  stringstream ss(text);
  string word;
  map<string, int> wordCount;
  while (ss >> word) {
    wordCount[word]++;
  }
  cout << "Frekuensi Kata: " << endl;
  for (const auto& kv : wordCount) {
    cout << kv.first << ": " << kv.second << endl;
  }

  return 0;
}

