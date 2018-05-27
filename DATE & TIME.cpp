#include <iostream>
#include <ctime>

using namespace std;

int main( )
{
   // tra ve date/time hien tai dua tren system hien tai
   time_t hientai = time(0);
   
   // chuyen doi hientai thanh dang chuoi
   char* dt = ctime(&hientai);

   cout << "Date va Time dang local la: " << dt << endl;

   // chuyen doi hientai thanh dang tm struct cho UTC
   tm *gmtm = gmtime(&hientai);
   dt = asctime(gmtm);
   cout << "UTC date va time la: "<< dt << endl;
}
