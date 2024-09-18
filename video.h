//Name: Akshay Nagaraj Aralikatti
//ecst: anaralikatti
//ID: 012624106

//Declaration

#ifndef VIDEO_H
#define VIDEO_H

class Video
{
    public:
        Video(string title, string url, string comment, float length, int rating);
        void print();
        bool compareRatings(Video *otherVideo);
        bool compareLengths(Video *otherVideo);
        bool compareTitles(Video *otherVideo);
        bool compare(Video *otherVideo, string sort);
    private:
        string m_title;
        string m_url;
        string m_comment;
        float m_length;
        int m_rating;
};

// bool compareRatings(Video *otherVideo);
// bool compareLengths(Video *otherVideo);
// bool compareTitles(Video *otherVideo);
// bool compare(Video *otherVideo, string sort);




#endif