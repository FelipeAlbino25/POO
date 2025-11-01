namespace std
#ifndef PONTO
#define PONTO

{
    class Ponto
    {
        private:
            int x;
            int y;
        public:
            void print();
            int getX() const;
            int getY() const;
            void setX(int num);
            void setY(int num);
            Ponto();
            ~Ponto();
            Ponto(int x, int y);

    };
}  

#endif