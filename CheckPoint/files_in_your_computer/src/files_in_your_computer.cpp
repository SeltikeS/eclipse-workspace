//============================================================================
// Name        : files_in_your_computer.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <utility>
#include <map>
using namespace std;





class File {
public:
	enum FileType {
		MUSIC,
		IMAGE,
		MOVIE,
		OTHER
	};

	File(const string& formate, const int& size) {
		m_formate = formate;
		m_file_type = FormateToType(formate);
		m_size = size;
	}

	FileType FormateToType(const string& s) {
		if(s == "mp3" || s == "aac" || s == "flac") {
			return MUSIC;
		} else if(s == "jpg" || s == "bmp" || s == "gif") {
			return IMAGE;
		} else if(s == "mp4" || s == "avi" || s == "mkv") {
			return MOVIE;
		} else {
			return OTHER;
		}
	}

	FileType GetFileType() {
		return m_file_type;
	}

	int GetSize() {
		return m_size;
	}

private:
	FileType m_file_type;
	string m_formate;
	int m_size;
};


int GetSizeFromString(string& s) {
	s.pop_back();
	return stoi(s);
}

string GetFormateFromString(string& s) {
	string last;
	string preLast;
	stringstream tmp(s);
	while(!tmp.eof()) {
		preLast = last;
		getline(tmp, last, '.');
	}
	return last;
}


string solution(string &S) {
    stringstream ss(S);

    map<string, int> files;
    files["music"] = 0;
    files["image"] = 0;
    files["movie"] = 0;
    files["other"] = 0;

    string nextFile;

    while(getline(ss, nextFile, '\n')) {
    	stringstream sFile(nextFile);
    	pair<string, string> item;
    	sFile >> item.first >> item.second;

    	string formate = GetFormateFromString(item.first);
    	int size = GetSizeFromString(item.second);

    	File f(formate, size);

    	switch(f.GetFileType()) {
			case File::IMAGE :
				files["image"] += f.GetSize();
				break;
			case File::MUSIC :
				files["music"] += f.GetSize();
				break;
			case File::MOVIE :
				files["movie"] += f.GetSize();
				break;
			case File::OTHER :
				files["other"] += f.GetSize();
				break;
    	}
    }

    return "music " + to_string(files["music"]) + "b\n" +
		   "images " + to_string(files["image"]) + "b\n" +
		   "movies " + to_string(files["movie"]) + "b\n" +
		   "other " + to_string(files["other"]) + "b\n";
}


int main() {
	string in("my.song.mp3 11b\n"
	"greatSong.flac 1000b\n"
	"not3.txt 5b\n"
	"video.mp4 200b\n"
	"game.exe 100b\n"
	"mov!e.mkv 10000b\n");

//	string in("my.song.mp3 11b");
	cout << solution(in);
	return 0;
}
