////#include<dirent.h>
////#include<stdio.h>
////#include<stdlib.h>
////
////main(){
////DIR *dir;
////struct dirent *ent;
////if ((dir = opendir ("c:\\src\\")) != NULL) {
////  /* print all the files and directories within directory */
////  while ((ent = readdir (dir)) != NULL) {
////    printf ("%s\n", ent->d_name);
////  }
////  closedir (dir);
////} else {
////  /* could not open directory */
////  perror ("");
////  return EXIT_FAILURE;
////}
////}
//#include <windows.h>
//#include <tchar.h>
//#include <stdio.h>
//
//_tmain(int argc, TCHAR *argv[])
//{
//   WIN32_FIND_DATA FindFileData;
//   HANDLE hFind;
//
//   if( argc != 2 )
//   {
//      _tprintf(TEXT("Usage: %s [target_file]\n"), argv[0]);
//   }
//
//   _tprintf (TEXT("Target file is %s\n"), argv[1]);
//   hFind = FindFirstFile(argv[1], &FindFileData);
//   if (hFind == INVALID_HANDLE_VALUE) 
//   {
//      printf ("FindFirstFile failed (%d)\n", GetLastError());
//   } 
//   else 
//   {
//      _tprintf (TEXT("The first file found is %s\n"), 
//                FindFileData.cFileName);
//      FindClose(hFind);
//   }
//}
#include <string>
#include <iostream>
#include <boost/filesystem.hpp>
using namespace std;
using namespace boost::filesystem;

int main()
{
    path p("D:/AnyFolder");
    for (auto i = directory_iterator(p); i != directory_iterator(); i++)
    {
        if (!is_directory(i->path())) //we eliminate directories
        {
            cout << i->path().filename().string() << endl;
        }
        else
            continue;
    }
}
