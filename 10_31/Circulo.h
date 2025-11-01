namespace std
#ifndef CIRCULO
#define CIRCULO

{
    class Circulo
    {
        private:
            int raio;
        public:
            void setRaio(int num);
            int getRaio() const;
            void print() const;
            Circulo();
            Circulo(int x, int y, int raio);
    };
}

#endif
