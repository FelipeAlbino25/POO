#include <iostream>
#include <ctime>

//std - biblioteca padrão do c++
//namespace é o espaço de nome padrão do c++
//sem isso aq nn tem cout cin etc etc.

/**
 * operador de resolução de escopo:
 * o c++ diferencia as variáveis e funções em escopos diferentes,
 * a operação '::' nos permite 
 */

using namespace std;

//ex: se tirássemos o namespace std, teríamos que especificar o nome da função:
// std:: cout << ""
// std:: cin << ""

class Horario{
    private:int hr;
    private:int min;
    private:int seg;

    Horario(int hr, int min, int seg){

        if(hr>=24 || min>=60 || seg >=60){
            cout << "Error 404, data malformed";
            return;
        }

        this->hr = hr;
        this->min = min;
        this->seg = seg;
    }

    public:void showTimeMilitary(){
        cout << this->hr << ":"<<this->min <<":"<<this->seg;
    }

    public:void setHr(int hr){
        if(hr>=24){
            cout << "Error 400, data malformed";
            return;
        }
        this->hr = hr;
    }
    public:void setMin(int min){
        if(min>=60){
            cout<<" Error 400, data malformed";
            return;
        }
        this->min = min;
    }
    public:void setSeg(int seg){
        if(seg>=60){
            cout <<"Error 400, data malformed";
            return;
        }
        this->seg = seg;
    }
    public:int getHr(){
        return this->hr;
    }
    public:int getMin(){
        return this->min;
    }
    public:int getSeg(){
        return this->seg;
    }
};

struct deliveryDate {
    int year;
    int month;
    int day;
};

class Task{
    private:struct deliveryDate expectedFinishDate;
    private:string title;
    private:string description;
    private:string subject;
    private:bool submited;
    private:string comments;
    private:double grade;

    public:
        struct deliveryDate getExpectedFinishDate() {
            return expectedFinishDate;
        }
        string getTitle() {
            return title;
        }
        string getDescription() {
            return description;
        }
        string getSubject() {
            return subject;
        }
        bool isSubmited() {
            return submited;
        }
        string getComments() {
            return comments;
        }
        double getGrade() {
            return grade;
        }

        void setExpectedFinishDate(const struct deliveryDate& expectedFinishDate) {
            this->expectedFinishDate = expectedFinishDate;
        }
        void setTitle(const string& t) {
            title = t;
        }
        void setDescription(const string& d) {
            description = d;
        }
        void setSubject(const string& s) {
            subject = s;
        }
        void setSubmited(bool s) {
            submited = s;
        }
        void comment(const string& c) {
            comments = c;
        }
        void grade(double g) {
            grade = g;
        }



};


int main(){

    int x =10;
    cout << "x = "<<x;
    //no lugar do printf("x=%d",x)

}