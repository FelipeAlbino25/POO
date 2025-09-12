
using namespace std;

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

//ex: se tirássemos o namespace std, teríamos que especificar o nome da função:
// std:: cout << ""
// std:: cin << ""

class Horario{
    private:int hr;
    private:int min;
    private:int seg;

    public:
    Horario(int hr, int min, int seg){
        setHr(hr);
        setMin(min);
        setSeg(seg);
        cout << "Construtor chamado";
    }

    void showTimeMilitary(){
        cout << this->hr << ":"<<this->min <<":"<<this->seg;
    }

    public:void setHr(int hr){
        if(hr>=24 || hr<0){
            cout << "Error 400, data malformed";
            return;
        }
        this->hr = hr;
    }
    public:void setMin(int min){
        if(min>=60 || min<0){
            cout<<" Error 400, data malformed";
            return;
        }
        this->min = min;
    }
    public:void setSeg(int seg){
        if(seg>=60 || seg <0){
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
    private:string comment;
    private:double grade;

    public:
        Task(struct deliveryDate expectedFinishDate, string title, string description, string subject, bool submitted, string comment, double grade){
            this->expectedFinishDate = expectedFinishDate;
            this->title = title;
            this->description = description;
            this->subject = subject;
            this->submited = submited;
            this->comment = comment;
            this->grade = grade;
        }

        const struct deliveryDate getExpectedFinishDate() {
            return expectedFinishDate;
        }
        const string getTitle() {
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
            return comment;
        }
        double getGrade() {
            return grade;
        }

        void setExpectedFinishDate(const struct deliveryDate& expectedFinishDate) {
            this->expectedFinishDate = expectedFinishDate;
        }
        void setTitle(const string& title) {
            this->title = title;
        }
        void setDescription(const string& description) {
            this->description = description;
        }
        void setSubject(const string& subject) {
            this->subject = subject;
        }
        void setSubmited(bool submited) {
            this->submited=submited;
        }
        void postComment(const string& comment) {
            this->comment = comment;
        }
        void postGrade(double grade) {
            this->grade = grade;
        }
        void toString(){
            cout << "\n\nData: "<< this->expectedFinishDate.day<<"/"<<this->expectedFinishDate.month<<"/"<<this->expectedFinishDate.year <<"\nTitulo: "+this->title << "\nDescricao: "+this->description<< "\nMateria: "<<this->subject<<"\nEntregue: "<<this->submited<< "\nComentario: "<<this->comment<<"\n\n";
        }



};


int main(){

    struct deliveryDate date;
    date.day = 12;
    date.month = 9;
    date.year = 2025;
  
    Task *task1 = new Task(date,"title","description","subject",false,"comment",6.01);

    task1->toString();



}