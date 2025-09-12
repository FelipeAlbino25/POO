//aprendendo sobre metodos constantes
//metodos constantes são aqueles que nn alteram o objeto

//atributos constantes e como eles são implementados no construtor

//destructor

//dados static
/*
    são dados não do objeto, mas sim da classe
    todos os objetos da mesma classe vão partilhar do valor,
    se definissemos o comment como static "opa", todas as classes teriam o comentario
    definido como "opa"

    metodos static também existem sem ter nenhum objeto instanciado,
    podemos fazer Class :: staticMethod()

    metodos statics só podem acessar atributos static
*/



#include <iostream>
using namespace std;

struct deliveryDate {
    int year;
    int month;
    int day;
};

/*
enum subjectEnum{
    GEOMETRIA_ANALITICA =1,
    PROBEST =2,
    POO = 3,
    AED1 = 4,
    ARQ1 = 5,
    LOGICA_MATEMATICA =6,

};
*/

class Task{
    private: 
    string id;
    struct deliveryDate expectedFinishDate;
    string title;
    string description;
    string subject;
    bool submited;
    string comment;
    double grade;

    string validateId(string id){
        if(id.length() < 8 ){
            throw invalid_argument("id was malformed");
        }
        else{
            return id;
        }
    }

    public:
        Task(string id, struct deliveryDate expectedFinishDate, string title, string description, string subject, bool submitted, string comment, double grade): id (validateId(id)){
            setExpectedFinishDate(expectedFinishDate);
            setTitle(title);
            setDescription(description);
            setSubject(subject);
            setSubmited(submited);
            postComment(comment);
            postGrade(grade);
        }

        ~Task(){};

        struct deliveryDate getExpectedFinishDate() const{
            return expectedFinishDate;
        }
        string getTitle() const {
            return title;
        }
        string getDescription() const {
            return description;
        }
        string getSubject() const {
            return subject;
        }
        bool isSubmited() const{
            return submited;
        }
        string getComments() const{
            return comment;
        }
        double getGrade()const {
            return grade;
        }

        void setExpectedFinishDate(const struct deliveryDate& expectedFinishDate) {
            this->expectedFinishDate = expectedFinishDate;
        }
        void setTitle(const string& title) {
            if(title.length() < 8){
                throw invalid_argument("titulo precisa de pelo menos 8 caracteres");
            }
            this->title = title;
        }
        void setDescription(const string& description) {
            if(description.length()<10){
                throw invalid_argument("descricao precisa de pelo menos 10 caracteres");
            }
            this->description = description;
        }
        void setSubject(const string& subject) {
            if(subject.length() < 3){
                throw invalid_argument("a materia precisa de pelo menos 3 caracteres");
            }
            else{
                this->subject = subject;
            }
        }
        void setSubmited(bool submited) {
            this->submited=submited;
        }
        void postComment(const string& comment) {
            if(comment.length() <10){
                throw invalid_argument("comentario precisa de pelo menos 10 caracteres");
            }
            this->comment = comment;
        }
        void postGrade(double grade) {
            if(grade<0 || grade>10){
                throw invalid_argument("a nota precisa estar entre 0 e 10");
            }
            this->grade = grade;
        }
        void toString()const{
            cout << "\n\nData: "<< this->expectedFinishDate.day<<"/"<<this->expectedFinishDate.month<<"/"<<this->expectedFinishDate.year <<"\nTitulo: "+this->title << "\nDescricao: "+this->description<< "\nMateria: "<<this->subject<<"\nEntregue: "<<this->submited<< "\nComentario: "<<this->comment<<"\n\n";
        }

};

int main(){
    struct deliveryDate date;
    date.day = 12;
    date.month = 9;
    date.year = 2025;
    Task *t1 = new Task("12345678910",date,"Titulo Tarefa Teste","Descricao de uma tarefa aleatoria","Geometria Analitica", false, "Comentario aleatorio de um professor/aluno", 10.0);

    t1->toString();

    cout << t1->getSubject();
}
