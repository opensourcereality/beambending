#ifndef LOAD_H
#define LOAD_H

enum LoadType { single, uniform };

class Load
{
public:
    Load();
    void SetLoadType(LoadType loadType);
    LoadType GetLoadType() const;
    void SetMagnitude(double magnitude);
    double GetMagnitude() const;

private:
    double magnitude;
    LoadType loadType;

};

#endif // LOAD_H
