#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;


class File {
protected:
  char * name;
  char user [50];
  int size;

private:
  void copy (const File & f) {
    this->name = new char [strlen(f.name)+1];
    strcpy(this->name, f.name);
    strcpy(this->user, f.user);
    this->size = f.size;
  }

public:
  File (char * name = "undefined", char * user = "unknow", int size = 4) {
    this->name = new char [strlen(name)+1];
    strcpy(this->name, name);
    strcpy(this->user, user);
    this->size = size;
  }

  File (const File & f) {
    copy(f);
  }

  File & operator = (const File & f) {
    if (this!=&f){
      delete [] name;
      copy(f);
    }
  }

  ~File () {
    delete [] name;  
  }
  

};

class 


int main() {

    int tc; // Test Case

    char name[255];
    char user_name[51];
    int size;
    char content[1000];

    cin >> tc;

    if (tc==1){
      // Testing constructor(s) & operator << for class File

      cin >> name;
      cin >> user_name;
      cin >> size;


      File f1;

      cout<< f1;

      File f2(name);
      cout<< f2;

      File f3(name, user_name);
      cout<< f3;

      File f4(name, user_name, size);
      cout<< f4;
    }
    else if (tc==2){
      // Testing constructor(s) & operator << for class TextFile
      cin >> name;
      cin >> user_name;
      cin >> size;
      cin >> content;

      TextFile tf1;
      cout<< tf1;

      TextFile tf4(name, user_name, size, content);
      cout<< tf4;
    }
    else if (tc==3){
      // Testing constructor(s) & operator << for class Folder
      cin >> name;
      cin >> user_name;

      Folder f3(name, user_name);
      cout<< f3;
    }
    else if (tc==4){
      // Adding files to folder
      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      File * f;
      TextFile *tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> size;
          f = new File(name,user_name, size);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> size;
          cin >> content;
          tf = new TextFile(name,user_name, size, content);
            dir += *tf;
        }
      }
      cout<<dir;
    }
    else if(tc==5){
      // Testing getMaxFile for folder

      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      File * f;
      TextFile *tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> size;
          f = new File(name,user_name, size);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> size;
          cin >> content;
          tf = new TextFile(name,user_name, size, content);
            dir += *tf;
        }
      }
      cout<< *(dir.getMaxFile());
    }
    else if(tc==6){
      // Testing operator [] for folder

      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      File * f;
      TextFile *tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> size;
          f = new File(name,user_name, size);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> size;
          cin >> content;
          tf = new TextFile(name,user_name, size, content);
            dir += *tf;
        }
      }

      cin >> sub; // Reading index of specific file
      cout<< *dir[sub];
    }
    else if(tc==7){
      // Testing function max_folder_size
      int folders_num;

      Folder dir_list[10];

      Folder dir;
      cin >> folders_num;

      for (int i=0; i<folders_num; ++i){
        cin >> name;
        cin >> user_name;
        dir = Folder(name, user_name);


        File * f;
        TextFile *tf;

        int sub, fileType;

        while (1){
          cin >> sub; // Should we add subfiles to this folder
          if (!sub) break;

          cin >>fileType;
          if (fileType == 1){ // Reading File
            cin >> name;
            cin >> user_name;
            cin >> size;
            f = new File(name,user_name, size);
              dir += *f;
          }
          else if (fileType == 2){
            cin >> name;
            cin >> user_name;
            cin >> size;
            cin >> content;
            tf = new TextFile(name,user_name, size, content);
              dir += *tf;
          }
        }
        dir_list[i] = dir;
      }

      cout<<max_folder_size(dir_list, folders_num);
    }
    return 0;
};
