#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

class File;

class Directory {
public:
    string name;
    map<string, File*> files;
    map<string, Directory*> dirs;
    Directory(string n) {
        name  = n;
        files.clear();
        dirs.clear();
    }
    
    vector<string> ListThings() {
        vector<string> result;
        for (auto dir : dirs) {
            result.push_back(dir.first);
        }
        for (auto file : files) {
            result.push_back(file.first);
        }
        sort(result.begin(), result.end());
        return result;
    }
};

class File {
 public:
    string name;
    string content;
    File(string n) {
        name = n;
        content = "";
    }
    File(string n, string c) {
        name = n;
        content = c;
    }
    
    void addContent(string h) {
        content = content+h;
    }
    
    string readContent() {
        return content;
    }
};

class FileSystem {
    Directory *root;
public:
    FileSystem() {
        root = new Directory("");
    }
    
    vector<string> ls(string path) {
        if (path == "/") {
            return root->ListThings();
        }
        int n = path.length(), start = 0;
        int end = getnext(path, start+1);
        auto current = root;
        while (end != n) {
            string curdir = path.substr(start+1, end-start-1);
            current = current->dirs[curdir];
            start = end;
            end = getnext(path, start+1);
        }
        
        string targetStr = path.substr(start+1, end-start-1);
        if (current->dirs.find(targetStr) != current->dirs.end()) {
            return current->dirs[targetStr]->ListThings();
        } else {
            return vector<string>{current->files[targetStr]->name};
        }
    }
    
    void mkdir(string path) {
        int n = path.length(), start = 0;
        int end = getnext(path, start+1);
        auto current = root;
        while (end != n) {
            string curdir = path.substr(start+1, end-start-1);
            if (current->dirs.find(curdir) == current->dirs.end()) {
                current->dirs[curdir] = new Directory(curdir);
            }
            current = current->dirs[curdir];
            start = end;
            end = getnext(path, start+1);
        }
        
        auto dirname = path.substr(start+1);
        current->dirs[dirname] = new Directory(dirname);
    }
    
    void addContentToFile(string filePath, string content) {
        int n = filePath.length(), start = 0;
        int end = getnext(filePath, start+1);
        auto current = root;
        while (end != n) {
            string curdir = filePath.substr(start+1, end-start-1);
            current = current->dirs[curdir];
            start = end;
            end = getnext(filePath, start+1);
        }
        
        string filename = filePath.substr(start+1);
        if (current->files.find(filename) == current->files.end()) {
            current->files[filename] = new File(filename, content);
        } else {
            current->files[filename]->addContent(content);
        }
    }
    
    string readContentFromFile(string filePath) {
        int n = filePath.length(), start = 0;
        int end = getnext(filePath, start+1);
        auto current = root;
        while (end != n) {
            string curdir = filePath.substr(start+1, end-start-1);
            current = current->dirs[curdir];
            start = end;
            end = getnext(filePath, start+1);
        }
        
        string filename = filePath.substr(start+1);
        return current->files[filename]->readContent();
    }
    
    int getnext(string s, int idx) {
        while (idx < s.length() && s[idx] != '/') idx++;
        return idx;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
