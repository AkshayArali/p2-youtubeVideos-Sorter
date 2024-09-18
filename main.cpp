//main.cpp
//Name: Akshay Nagaraj Aralikatti
//ID: 012624106
//ecst UserName: anaralikatti

//application/using

#include <iostream>
#include <string>
using namespace std;

#include "video.h"

//Initialing the maximum limit to the array size.
const int MAX = 100;

//Purpose: //The following function arranges the video objects with respect to sort input. 
//The function makes use of bubble sort.
// Input Parameters: vidoes objects, sort, no. of video objects.
// Output Parameters: Sorted Array.
// Return Value: nothing
void sort_arr(Video* (&videos)[MAX], string sort, int video_count){
    for(int last = video_count - 1 ; last > 0; last--)
    {
        for( int cur = 0; cur < last; cur++)
        {
          if(videos[cur]->compare(videos[cur+1], sort))  //'compare' takes the method based on sort and passes the respective values.
          {
            Video *tmp = videos[cur];
            videos[cur] = videos[cur+1];
            videos[cur+1] = tmp;
          }
        }
    }
}

int main()
{
    //iniatializing variable here.
    int result = 0;
    string sort;
    string title;
    string url;
    string comment;
    float length;
    int rating;
    int video_count = 0;
    
    getline(cin, sort);

    if(sort != "length" && sort != "rating" && sort != "title")
    {
        cerr << sort << " is not a legal sorting method, giving up.\n";
        result = 1;
    }
    
    Video* videos[MAX] = {NULL}; // Assigning memory to array of size MAX.

    while(getline(cin, title))  //While loop ensures the given input is not more than 100 and feeds the objects into empty arrays.
    {
        if(video_count == MAX)
        {
            cerr << "Too many videos, giving up" << endl; //Throwing the exception error.
            result = 1;
            break;
        }
        getline(cin, url);
        getline(cin, comment);
        
         if (!(cin >> length >> rating)) {
        cerr << "Invalid input for length or rating." << endl;
        result = 1;
        break;
    }

        cin.ignore();
        videos[video_count] =  new Video( title, url, comment, length, rating );
      
        video_count ++;
    }

    sort_arr(videos, sort, video_count); //Calling the sorting function to arrange the objects in accordance to sort.

    for(int i =0; i<video_count; i++)
        videos[i]->print(); //This is the main loop that prints out the sorted objects of the array.
    
    return result;
}