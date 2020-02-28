#include<iostream>
using namespace std;

class ComplexNum{
private:
    int RealPart;
    int ImgPart;
public:
    ComplexNum(){
        RealPart=0;
        ImgPart=0;
    }
    ComplexNum(int r, int i){
        RealPart=r;
        ImgPart=i;
    }
    void setRealPart(int n){
        RealPart=n;
    }
    void setImgPart(int n){
        ImgPart=n;
    }
    int getRealPart(){
        return RealPart;
    }
    int getImgPart(){
        return ImgPart;
    }
    void Print(){
        cout<<RealPart;
        if (ImgPart>=0) cout<<"+";
        cout<<ImgPart<<"i"<<endl;
    }
    void Add(ComplexNum c){
        RealPart+=c.RealPart;
        ImgPart+=c.ImgPart;
    }
    ComplexNum operator+(ComplexNum c){
        ComplexNum o;
        o.RealPart=RealPart+c.RealPart;
        o.ImgPart=ImgPart+c.ImgPart;
        return o;
    }
    friend ostream& operator<<(ostream &os, const ComplexNum &c);
    friend istream& operator>>(istream &is, ComplexNum &c);
};

ostream& operator<<(ostream &os, const ComplexNum &c){
    os<<c.RealPart;
    if (c.ImgPart>=0) os<<"+";
    os<<c.ImgPart<<"i"<<endl;
    return os;
}
istream& operator>>(istream &is, ComplexNum &c){
    is>>c.RealPart;
    is>>c.ImgPart;
    return is;
}


int main(){
    ComplexNum c1(1,-1),c2(2,2);
    /*c1.setImgPart(1);c1.setRealPart(-1);
    c2.setImgPart(2);c2.setRealPart(-2);*/
    ///cout<<c1.RealPart<<" "<<c2.ImgPart;
    ///cout<<c1.getImgPart()<<" "<<c1.getRealPart()<<endl;
    ///cout<<c2.getImgPart()<<" "<<c2.getRealPart()<<endl;

    ComplexNum c3;
    c1.Print();
    c2.Print();
    c1.Add(c2);
    c1.Print();
    c3=c1+c2;
    ///c3.Print();
    cout<<c3<<endl;
    cout<<"xxxxxxxxxxxx";
    cin>>c3;
    cout<<c3;

}
