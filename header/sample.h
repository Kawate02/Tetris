#pragma once
class Sample
{
    public:
        Sample();
        ~Sample();
        void set(int num);
        int get();
    private:
        int num;
};