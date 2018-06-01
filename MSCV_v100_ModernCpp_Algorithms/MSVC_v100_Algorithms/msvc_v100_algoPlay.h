#ifndef MSVC100ALGOPLAY__H
#define MSVC100ALGOPLAY__H

//Arguments and opinions about the use of getters and setters in classes
//aside, lets just create a Track class with some properties

class Track
{
private:
    int m_trackNumber;
    double m_speed;
    double m_posX;
    int m_classification;
public:
    Track(int trackNumber) : m_trackNumber(trackNumber) {}
    enum Classifcation{eFriend,eHostile,eNeutral,eUFO};
    void setTrackNumber(int trackNumber)
    { m_trackNumber = trackNumber;}
    void setSpeed(double speed)
    { m_speed = speed;}
    void setPosX(double posX)
    { m_posX = posX;}
    void setClassification(int classification)
    { m_classification = classification; }
    
    int TrackNumber()
    { return m_trackNumber;}
    double Speed()
    { return m_speed;}
    double PosX()
    { return m_posX;}
    int getClassification()
    { return m_classification; }
};


#endif